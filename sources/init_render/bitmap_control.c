/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 02:00:23 by mmoreira          #+#    #+#             */
/*   Updated: 2022/02/17 10:05:14 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	bitmap_write(int fd, t_bitmap bmp)
{
	write(fd, &bmp.type, 2);
	write(fd, &bmp.size, 4);
	write(fd, &bmp.reserved1, 2);
	write(fd, &bmp.reserved2, 2);
	write(fd, &bmp.offset, 4);
	write(fd, &bmp.dib_header_size, 4);
	write(fd, &bmp.width_px, 4);
	write(fd, &bmp.height_px, 4);
	write(fd, &bmp.num_planes, 2);
	write(fd, &bmp.bits_per_pixel, 2);
	write(fd, &bmp.compression, 4);
	write(fd, &bmp.image_size_bytes, 4);
	write(fd, &bmp.x_resolution_ppm, 4);
	write(fd, &bmp.y_resolution_ppm, 4);
	write(fd, &bmp.num_colors, 4);
	write(fd, &bmp.important_colors, 4);
}

static void	bitmap_set(int fd, int *R, t_bitmap *bmp)
{
	bmp->type = 0x4D42;
	bmp->size = ((R[0] + R[1]) * 4) + 54;
	bmp->reserved1 = 0x0;
	bmp->reserved2 = 0x0;
	bmp->offset = 54;
	bmp->dib_header_size = 40;
	bmp->width_px = R[0];
	bmp->height_px = R[1];
	bmp->num_planes = 1;
	bmp->bits_per_pixel = 32;
	bmp->compression = 0;
	bmp->image_size_bytes = (R[0] + R[1]) * 4;
	bmp->x_resolution_ppm = 2000;
	bmp->y_resolution_ppm = 2000;
	bmp->num_colors = 0;
	bmp->important_colors = 0;
	bitmap_write(fd, *bmp);
}

static int	bitmap_open(char *name)
{
	char	*file;
	int		fd;

	file = ft_strjoin(name, ".bmp");
	fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	free(file);
	if (fd == -1)
		return (-1);
	return (fd);
}

static int	bitmap_create(t_img *img, int *R, int i, int j)
{
	t_bitmap	bmp;
	char		*name;
	char		*numb;
	int			fd;

	numb = ft_itoa(i);
	name = ft_strjoin("imagem_", numb);
	fd = bitmap_open(name);
	free(numb);
	free(name);
	if (fd == -1)
		return (0);
	bitmap_set(fd, R, &bmp);
	if (i == 1)
		ft_printf("/******************\n");
	ft_printf("|  Criando o bitmap da camera %d", i);
	if (j)
		ft_printf(" da rotação %d", j);
	write(1, "\n", 1);

	i = R[1];
	while (--i >= 0)
		write(fd, &img->addr[i * img->line_len], img->line_len);
	close(fd);
	return (1);
}

void	bitmap_control(t_hook *loop, t_mundo *mundo)
{
	t_list	*imgs;
	t_list	*lst;
	int		i[2];

	i[1] = 0;
	imgs = loop->imgs;
	while (imgs)
	{
		i[0] = 0;
		lst = (t_list*)imgs->vol;
		while (lst)
		{
			if (!(bitmap_create((t_img *)lst->vol, mundo->R, ++i[0], i[1])))
				ft_printf("|  Deu merda na criação de uma das imagem\n");
			mlx_destroy_image(loop->mlx, ((t_img *)lst->vol)->ptr);
			lst = lst->next;
		}
		ft_lstclear((t_list**)&imgs->vol, free);
		imgs = imgs->next;
		i[1]++;
	}
	ft_printf("|  Criação de todos os bitmap completa\n\\__________________\n");
	ft_lstclear(&loop->imgs, free);
	free_mundo(mundo);
	free(loop->mlx);
}
