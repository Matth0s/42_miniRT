/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_intersect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 03:20:05 by mmoreira          #+#    #+#             */
/*   Updated: 2022/02/17 21:51:36 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	set_intersection(t_list *objs, t_ray *ray)
{
	t_list	*lst;

	lst = objs;
	while (lst)
	{
		if (((t_pl *)lst->vol)->type == PLANE)
			pl_intersection(((t_pl *)lst->vol), ray);
		if (((t_sp *)lst->vol)->type == SPHERE)
			sp_intersection(((t_sp *)lst->vol), ray);
		if (((t_sq *)lst->vol)->type == SQUARE)
			sq_intersection(((t_sq *)lst->vol), ray);
		if (((t_tr *)lst->vol)->type == TRIANGLE)
			tr_intersection(((t_tr *)lst->vol), ray);
		if (((t_cy *)lst->vol)->type == CYLINDER)
			cy_intersection(((t_cy *)lst->vol), ray);
		lst = lst->next;
	}
}
