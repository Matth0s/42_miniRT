/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 03:21:28 by mmoreira          #+#    #+#             */
/*   Updated: 2021/04/27 01:49:20 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../includes/miniRT.h"

void	pl_intersection_I(t_pl *pl, t_ray *ray)
{
	t_vet	v1;
	double	i[3];
	double	t;

	if (vet_dot(pl->norm, ray->drct))
	{
		if (vet_dot(pl->norm, ray->drct) > 0)
			pl->norm = vet_mult_div(pl->norm, -1, 1);
		i[0] = vet_dot(pl->norm, ray->orig);
		i[1] = vet_dot(pl->norm, pl->orig);
		i[2] = vet_dot(pl->norm, ray->drct);
		t = (i[1] - i[0]) / i[2];
		if (t > 0 && t < ray->t)
		{
			ray->t = t;
			ray->norm = pl->norm;
			v1 = vet_mult_div(ray->drct, ray->t, 1);
			ray->hit = vet_sum_sub(ray->orig, v1, 1);
			v1 = vet_mult_div(ray->norm, EPSILON, 1);
			ray->hit = vet_sum_sub(ray->hit, v1, 1);
			ray->color = pl->color;
		}
	}
}
