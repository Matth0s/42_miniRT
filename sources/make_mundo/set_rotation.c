/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 05:14:15 by mmoreira          #+#    #+#             */
/*   Updated: 2022/02/17 21:48:21 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_cam	*create_cam_rotate(t_rot *rot, t_vet u, t_vet v, double theta)
{
	t_cam	*cam;
	t_vet	o;
	t_vet	ul;
	t_vet	vl;

	cam = (t_cam *)malloc(sizeof(t_cam));
	o = vet_sum(rot->orig, vet_mult(rot->norm, rot->heig));
	ul = vet_mult(u, cos(theta) * rot->diam / 2);
	vl = vet_mult(v, sin(theta) * rot->diam / 2);
	cam->orig = vet_sum(o, vet_sum(ul, vl));
	cam->drct = vet_sub(rot->orig, cam->orig);
	vet_norm(&cam->drct);
	cam->ang = rot->ang;
	return (cam);
}

static void	set_cams_rotate(t_rot *rot, t_list **lst)
{
	t_cam	*cam;
	t_vet	u;
	t_vet	v;
	int		i;

	if (rot->norm.y == 1 || rot->norm.y == -1)
		v = vet_create(1, 0, 0);
	else
		v = vet_cross(vet_create(0, 1, 0), rot->norm);
	u = vet_cross(v, rot->norm);
	i = -1;
	while (++i < rot->cams)
	{
		cam = create_cam_rotate(rot, u, v, i * 2 * M_PI / rot->cams);
		ft_lstadd_back(lst, ft_lstnew(cam));
	}
}

static int	check_error(t_rot *rot)
{
	if (rot->ang < 0 || rot->ang > 180)
		return (0);
	if (rot->diam < 1)
		return (0);
	if (rot->cams < 1)
		return (0);
	if (!(sqrt(vet_dot(rot->norm, rot->norm))))
		return (0);
	vet_norm(&rot->norm);
	return (1);
}

int	set_rotation(char **info, t_mundo *mundo)
{
	t_rot	rot;
	t_list	*lst;

	if (!(check_info(info, 7)))
		return (0);
	if (!(make_vet(*(info + 1), &rot.orig))
		|| !(make_vet(*(info + 2), &rot.norm))
		|| !(make_double(*(info + 3), &rot.cams))
		|| !(make_double(*(info + 4), &rot.diam))
		|| !(make_double(*(info + 5), &rot.heig))
		|| !(make_double(*(info + 6), &rot.ang)))
		return (0);
	if (!(check_error(&rot)))
		return (0);
	lst = NULL;
	set_cams_rotate(&rot, &lst);
	ft_lstadd_back(&mundo->rots, ft_lstnew(lst));
	mundo->rt += 1;
	return (1);
}
