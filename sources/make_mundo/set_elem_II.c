/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_elem_II.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 02:28:17 by mmoreira          #+#    #+#             */
/*   Updated: 2021/04/27 01:48:24 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

int	set_plane(char **info, t_mundo *mundo)
{
	t_pl	*pl;

	if (!(check_info(info, 4)))
		return (0);
	pl = (t_pl *)malloc(sizeof(t_pl));
	if (!(pl))
		return (0);
	if (!(make_vet(*(info + 1), &pl->orig))
		|| !(make_vet(*(info + 2), &pl->norm))
		|| !(make_vet(*(info + 3), &pl->color)))
	{
		free(pl);
		return (0);
	}
	pl->type = PLANE;
	ft_lstadd_back(&mundo->objs, ft_lstnew(pl));
	mundo->o += 1;
	return (1);
}

int	set_sphere(char **info, t_mundo *mundo)
{
	t_sp	*sp;

	if (!(check_info(info, 4)))
		return (0);
	sp = (t_sp *)malloc(sizeof(t_sp));
	if (!(sp))
		return (0);
	if (!(make_vet(*(info + 1), &sp->orig))
		|| !(make_double(*(info + 2), &sp->diam))
		|| !(make_vet(*(info + 3), &sp->color)))
	{
		free(sp);
		return (0);
	}
	sp->type = SPHERE;
	ft_lstadd_back(&mundo->objs, ft_lstnew(sp));
	mundo->o += 1;
	return (1);
}

int	set_square(char **info, t_mundo *mundo)
{
	t_sq	*sq;

	if (!(check_info(info, 5)))
		return (0);
	sq = (t_sq *)malloc(sizeof(t_sq));
	if (!(sq))
		return (0);
	if (!(make_vet(*(info + 1), &sq->orig))
		|| !(make_vet(*(info + 2), &sq->norm))
		|| !(make_double(*(info + 3), &sq->side))
		|| !(make_vet(*(info + 4), &sq->color)))
	{
		free(sq);
		return (0);
	}
	sq->type = SQUARE;
	ft_lstadd_back(&mundo->objs, ft_lstnew(sq));
	mundo->o += 1;
	return (1);
}

int	set_triangle(char **info, t_mundo *mundo)
{
	t_tr	*tr;
	t_vet	v1;
	t_vet	v2;

	if (!(check_info(info, 5)))
		return (0);
	tr = (t_tr *)malloc(sizeof(t_tr));
	if (!(tr))
		return (0);
	if (!(make_vet(*(info + 1), &tr->p1))
		|| !(make_vet(*(info + 2), &tr->p2))
		|| !(make_vet(*(info + 3), &tr->p3))
		|| !(make_vet(*(info + 4), &tr->color)))
	{
		free(tr);
		return (0);
	}
	v1 = vet_sum_sub(tr->p2, tr->p1, 0);
	v2 = vet_sum_sub(tr->p3, tr->p1, 0);
	tr->norm = vet_cross(v1, v2);
	tr->type = TRIANGLE;
	ft_lstadd_back(&mundo->objs, ft_lstnew(tr));
	mundo->o += 1;
	return (1);
}

int	set_cylinder(char **info, t_mundo *mundo)
{
	t_cy	*cy;

	if (!(check_info(info, 6)))
		return (0);
	cy = (t_cy *)malloc(sizeof(t_cy));
	if (!(cy))
		return (0);
	if (!(make_vet(*(info + 1), &cy->orig))
		|| !(make_vet(*(info + 2), &cy->norm))
		|| !(make_double(*(info + 3), &cy->diam))
		|| !(make_double(*(info + 4), &cy->heig))
		|| !(make_vet(*(info + 5), &cy->color)))
	{
		free(cy);
		return (0);
	}
	cy->type = CYLINDER;
	ft_lstadd_back(&mundo->objs, ft_lstnew(cy));
	mundo->o += 1;
	return (1);
}
