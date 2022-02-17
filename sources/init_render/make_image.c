/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 03:53:03 by mmoreira          #+#    #+#             */
/*   Updated: 2022/02/17 04:41:48 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	image_pixel_put(t_img *img, int x, int y, t_vet color)
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
	char			*pixel;

	red = (unsigned char)color.x;
	green = (unsigned char)color.y;
	blue = (unsigned char)color.z;
	pixel = img->addr + y * img->line_len + x * (img->bits_pixel / 8);
	*(unsigned int *)pixel = (red << 16 | green << 8 | blue);
}

static void	image_create(t_img *img, void *mlx, int width, int height)
{
	int	bp;
	int	ll;
	int	ed;

	img->ptr = mlx_new_image(mlx, width, height);
	img->addr = mlx_get_data_addr(img->ptr, &bp, &ll, &ed);
	img->bits_pixel = bp;
	img->line_len = ll;
	img->endian = ed;
}

static void	image_view(int *R, t_cam *cam, t_view *view)
{
	t_mat	mat;
	double	c_width;
	double	c_height;

	c_width = 2 * tan((cam->ang * M_PI) / (180 * 2));
	c_height = c_width * (double)R[1] / R[0];
	if (cam->drct.y == 1 || cam->drct.y == -1)
		mat.c1 = vet_create(1, 0, 0);
	else
		mat.c1 = vet_cross(cam->drct, vet_create(0, 1, 0));
	vet_norm(&mat.c1);
	mat.c2 = vet_cross(mat.c1, cam->drct);
	mat.c3 = cam->drct;
	mat.c1 = vet_mult_div(mat.c1, c_width, 1);
	mat.c2 = vet_mult_div(mat.c2, c_height, 1);
	view->init = vet_sum_sub(cam->orig, vet_mult_div(mat.c1, 2, 0), 0);
	view->init = vet_sum_sub(view->init, vet_mult_div(mat.c2, 2, 0), 1);
	view->init = vet_sum_sub(view->init, mat.c3, 1);
	view->mat = mat;
	view->cam = *cam;
}

t_img	*make_image(t_mundo *mundo, t_cam *cam, void *mlx)
{
	t_view	view;
	t_img	*img;
	t_vet	color;
	int		x;
	int		y;

	img = (t_img *)malloc(sizeof(t_img));
	if (!(img))
		return (img);
	image_view(mundo->R, cam, &view);
	image_create(img, mlx, mundo->R[0], mundo->R[1]);
	y = 0;
	while (y < mundo->R[1])
	{
		x = 0;
		while (x < mundo->R[0])
		{
			color = raytracer(mundo, view, x, y);
			image_pixel_put(img, x, y, color);
			x++;
		}
		y++;
	}
	return (img);
}
