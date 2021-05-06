/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 02:06:34 by mmoreira          #+#    #+#             */
/*   Updated: 2021/04/27 01:48:50 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

static int	windows_close(t_hook *loop)
{
	t_list	*lst;

	lst = loop->imgs;
	ft_lstloop_stop(&loop->imgs);
	while (lst)
	{
		mlx_destroy_image(loop->mlx, ((t_img *)lst->vol)->ptr);
		lst = lst->next;
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

	ptr = ((t_img *)loop->imgs->vol)->ptr;
	mlx_put_image_to_window(loop->mlx, loop->wind, ptr, 0, 0);
	return (0);
}

static int	windows_button(int button, t_hook *loop)
{
	if (button == LEFT_ARROW)
	{
		loop->imgs = loop->imgs->prev;
		windows_image(loop);
	}
	else if (button == RIGHT_ARROW)
	{
		loop->imgs = loop->imgs->next;
		windows_image(loop);
	}
	else if (button == ESC_BUTTON)
		windows_close(loop);
	return (0);
}

int	windows_control(t_hook *loop, t_mundo *mundo)
{
	int	width;
	int	height;

	width = mundo->R[0];
	height = mundo->R[1];
	free_mundo(mundo);
	loop->wind = mlx_new_window(loop->mlx, width, height, "MiniRT");
	ft_lstloop_start(&loop->imgs);
	windows_image(loop);
	mlx_hook(loop->wind, 9, 1L << 21, windows_image, loop);
	mlx_hook(loop->wind, 2, 1L << 0, windows_button, loop);
	mlx_hook(loop->wind, 33, 1L << 17, windows_close, loop);
	mlx_loop(loop->mlx);
	return (0);
}
