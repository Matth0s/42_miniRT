/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 02:00:23 by mmoreira          #+#    #+#             */
/*   Updated: 2021/04/27 01:48:38 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

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

static int	bitmap_create(t_img *img, int *R, int i)
{
	t_bitmap	bmp;
	char		*name;
	char		*numb;
	int			fd;

	numb = ft_itoa(i);
	name = ft_strjoin("imagem_", numb);
	fd = bitmap_open(name);
	if (fd == -1)
	{
		free(numb);
		free(name);
		return (0);
	}
	bitmap_set(fd, R, &bmp);
	if (i == 1)
		ft_printf("/******************\n");
	ft_printf("|  Criando o bitmap da camera %d\n", i);
	i = R[1];
	while (--i >= 0)
		write(fd, &img->addr[i * img->line_len], img->line_len);
	free(numb);
	free(name);
	close(fd);
	return (1);
}

void	bitmap_control(t_hook *loop, t_mundo *mundo)
{
	t_list	*imgs;
	int		R[2];
	int		i;

	i = 1;
	R[0] = mundo->R[0];
	R[1] = mundo->R[1];
	free_mundo(mundo);
	imgs = loop->imgs;
	while (imgs)
	{
		if (!(bitmap_create((t_img *)imgs->vol, R, i)))
			ft_printf("|  Deu merda na criação da imagem %d\n", i);
		imgs = imgs->next;
		i++;
	}
	imgs = loop->imgs;
	while (imgs)
	{
		mlx_destroy_image(loop->mlx, ((t_img *)imgs->vol)->ptr);
		imgs = imgs->next;
	}
	ft_printf("|  Criação de todos os bitmap completa\n\\__________________\n");
	ft_lstclear(&loop->imgs, free);
	free(loop->mlx);
}
