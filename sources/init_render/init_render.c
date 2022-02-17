/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 03:56:55 by mmoreira          #+#    #+#             */
/*   Updated: 2022/02/17 22:24:09 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	adapt_screen(void *ptr, t_mundo *mundo)
{
	int	x;
	int	y;

	mlx_get_screen_size(ptr, &x, &y);
	if (mundo->rsl[0] > x)
		mundo->rsl[0] = x;
	if (mundo->rsl[1] > y)
		mundo->rsl[1] = y;
}

static void	image_rotation_cams(t_mundo *mundo, t_hook *loop, t_list *lst)
{
	t_list	*rots;
	t_list	*cams;
	t_img	*img;
	int		i[2];

	i[1] = 1;
	rots = mundo->rots;
	while (rots)
	{
		i[0] = 0;
		lst = NULL;
		cams = (t_list *)rots->vol;
		while (cams)
		{
			ft_printf("|  Renderizando a imagem da camera %d", ++i[0]);
			ft_printf(" da rotação %d\n", i[1]);
			img = make_image(mundo, (t_cam *)cams->vol, loop->mlx);
			ft_lstadd_back(&lst, ft_lstnew(img));
			cams = cams->next;
		}
		i[1]++;
		ft_lstadd_back(&loop->imgs, ft_lstnew(lst));
		rots = rots->next;
	}
}

static void	image_default_cams(t_mundo *mundo, t_hook *loop, t_list *lst)
{
	t_list	*cams;
	t_img	*img;
	int		i;

	i = 0;
	lst = NULL;
	cams = mundo->cams;
	while (cams)
	{
		ft_printf("|  Renderizando a imagem da camera %d\n", ++i);
		img = make_image(mundo, (t_cam *)cams->vol, loop->mlx);
		ft_lstadd_back(&lst, ft_lstnew(img));
		cams = cams->next;
	}
	if (lst)
		ft_lstadd_back(&loop->imgs, ft_lstnew(lst));
}

void	init_render(int argc, t_mundo *mundo)
{
	t_hook	loop;
	t_list	*lst;

	loop.mlx = mlx_init();
	loop.imgs = NULL;
	lst = NULL;
	adapt_screen(loop.mlx, mundo);
	ft_printf("/******************\n");
	image_default_cams(mundo, &loop, lst);
	image_rotation_cams(mundo, &loop, lst);
	ft_printf("|  Renderização completa\n\\__________________\n");
	if (argc == 2)
		windows_control(&loop, mundo);
	else
		bitmap_control(&loop, mundo);
}
