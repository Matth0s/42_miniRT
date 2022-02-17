/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 03:21:28 by mmoreira          #+#    #+#             */
/*   Updated: 2022/02/17 21:55:09 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	pl_intersection(t_pl *pl, t_ray *ray)
{
	t_vet	v1;
	double	i[3];
	double	t;

	if (vet_dot(pl->norm, ray->drct))
	{
		if (vet_dot(pl->norm, ray->drct) > 0)
			pl->norm = vet_mult(pl->norm, -1);
		i[0] = vet_dot(pl->norm, ray->orig);
		i[1] = vet_dot(pl->norm, pl->orig);
		i[2] = vet_dot(pl->norm, ray->drct);
		t = (i[1] - i[0]) / i[2];
		if (t > 0 && t < ray->t)
		{
			ray->t = t;
			ray->norm = pl->norm;
			v1 = vet_mult(ray->drct, ray->t);
			ray->hit = vet_sum(ray->orig, v1);
			v1 = vet_mult(ray->norm, EPSILON);
			ray->hit = vet_sum(ray->hit, v1);
			ray->color = pl->color;
		}
	}
}
