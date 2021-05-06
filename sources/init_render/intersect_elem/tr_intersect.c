/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tr_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 03:20:47 by mmoreira          #+#    #+#             */
/*   Updated: 2021/04/27 01:49:31 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../includes/miniRT.h"

static int	tr_intersection_III(t_vet norm, t_vet hit, t_vet v1, t_vet v2)
{
	t_vet	left;
	t_vet	right;
	t_vet	cross;

	left = vet_sum_sub(hit, v1, 0);
	right = vet_sum_sub(v2, v1, 0);
	cross = vet_cross(left, right);
	if (vet_dot(norm, cross) > 0)
		return (1);
	return (0);
}

static int	tr_intersection_II( t_tr *tr, t_ray *ray, double t)
{
	t_vet	hit;

	hit = vet_sum_sub(ray->orig, vet_mult_div(ray->drct, t, 1), 1);
	if ((tr_intersection_III(tr->norm, hit, tr->p1, tr->p2)
			&& tr_intersection_III(tr->norm, hit, tr->p2, tr->p3)
			&& tr_intersection_III(tr->norm, hit, tr->p3, tr->p1))
		|| (tr_intersection_III(tr->norm, hit, tr->p1, tr->p3)
			&& tr_intersection_III(tr->norm, hit, tr->p3, tr->p2)
			&& tr_intersection_III(tr->norm, hit, tr->p2, tr->p1)))
		return (1);
	return (0);
}

void	tr_intersection_I( t_tr *tr, t_ray *ray)
{
	t_vet	v1;
	double	i[3];
	double	t;

	if (vet_dot(tr->norm, ray->drct))
	{
		if (vet_dot(tr->norm, ray->drct) > 0)
			tr->norm = vet_mult_div(tr->norm, -1, 1);
		i[0] = vet_dot(tr->norm, ray->orig);
		i[1] = vet_dot(tr->norm, tr->p1);
		i[2] = vet_dot(tr->norm, ray->drct);
		t = (i[1] - i[0]) / i[2];
		if (t > 0 && t < ray->t && (tr_intersection_II(tr, ray, t)))
		{
			ray->t = t;
			ray->norm = tr->norm;
			v1 = vet_mult_div(ray->drct, ray->t, 1);
			ray->hit = vet_sum_sub(ray->orig, v1, 1);
			v1 = vet_mult_div(ray->norm, EPSILON, 1);
			ray->hit = vet_sum_sub(ray->hit, v1, 1);
			ray->color = tr->color;
		}
	}
}
