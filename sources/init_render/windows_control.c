/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 02:06:34 by mmoreira          #+#    #+#             */
/*   Updated: 2022/02/17 22:24:09 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	windows_close(t_hook *loop)
{
	t_list	*imgs;
	t_list	*lst;

	imgs = loop->imgs;
	ft_lstloop_stop(&loop->imgs);
	while (imgs)
	{
		lst = (t_list *)imgs->vol;
		ft_lstloop_stop(&lst);
		while (lst)
		{
			mlx_destroy_image(loop->mlx, ((t_img *)lst->vol)->ptr);
			lst = lst->next;
		}
		ft_lstclear((t_list **)&imgs->vol, free);
		imgs = imgs->next;
	}
	ft_lstclear(&loop->imgs, free);
	mlx_destroy_window(loop->mlx, loop->wind);
	loop->wind = NULL;
	free(loop->mlx);
	loop->mlx = NULL;
	exit(0);
	return (0);
}

static int	windows_image(t_hook *loop)
{
	void	*ptr;

	ptr = ((t_img *)((t_list *)loop->imgs->vol)->vol)->ptr;
	mlx_put_image_to_window(loop->mlx, loop->wind, ptr, 0, 0);
	return (0);
}

static int	windows_button(int button, t_hook *loop)
{
	if (button == LEFT_ARROW)
	{
		loop->imgs->vol = ((t_list *)loop->imgs->vol)->prev;
		windows_image(loop);
	}
	else if (button == RIGHT_ARROW)
	{
		loop->imgs->vol = ((t_list *)loop->imgs->vol)->next;
		windows_image(loop);
	}
	else if (button == UP_ARROW)
	{
		loop->imgs = loop->imgs->next;
		windows_image(loop);
	}
	else if (button == DOWN_ARROW)
	{
		loop->imgs = loop->imgs->prev;
		windows_image(loop);
	}
	else if (button == ESC_BUTTON)
		windows_close(loop);
	return (0);
}

int	windows_control(t_hook *loop, t_mundo *mundo)
{
	t_list	*imgs;
	int		width;
	int		height;

	width = mundo->rsl[0];
	height = mundo->rsl[1];
	free_mundo(mundo);
	loop->wind = mlx_new_window(loop->mlx, width, height, "MiniRT");
	imgs = loop->imgs;
	while (imgs)
	{
		ft_lstloop_start((t_list **)&imgs->vol);
		imgs = imgs->next;
	}
	ft_lstloop_start(&loop->imgs);
	windows_image(loop);
	mlx_hook(loop->wind, 9, 1L << 21, windows_image, loop);
	mlx_hook(loop->wind, 2, 1L << 0, windows_button, loop);
	mlx_hook(loop->wind, 33, 1L << 17, windows_close, loop);
	mlx_loop(loop->mlx);
	return (0);
}
