/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 03:56:55 by mmoreira          #+#    #+#             */
/*   Updated: 2021/04/27 01:48:41 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

static void	adapt_screen(void *ptr, t_mundo *mundo)
{
	int	x;
	int	y;

	mlx_get_screen_size(ptr, &x, &y);
	if (mundo->R[0] > x)
		mundo->R[0] = x;
	if (mundo->R[1] > y)
		mundo->R[1] = y;
}

void	init_render(int argc, t_mundo *mundo)
{
	t_hook	loop;
	t_list	*cams;
	t_img	*img;
	int		i;

	loop.mlx = mlx_init();
	loop.imgs = NULL;
	adapt_screen(loop.mlx, mundo);
	cams = mundo->cams;
	i = 1;
	ft_printf("/******************\n");
	while (cams)
	{
		ft_printf("|  Renderizando a imagem da camera %d\n", i);
		img = make_image(mundo, (t_cam *)cams->vol, loop.mlx);
		ft_lstadd_back(&loop.imgs, ft_lstnew(img));
		cams = cams->next;
		i++;
	}
	ft_printf("|  Renderização completa\n\\__________________\n");
	if (argc == 2)
		windows_control(&loop, mundo);
	else
		bitmap_control(&loop, mundo);
}
