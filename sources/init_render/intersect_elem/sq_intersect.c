/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sq_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 03:21:07 by mmoreira          #+#    #+#             */
/*   Updated: 2021/04/27 01:49:28 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../includes/miniRT.h"

static int	sq_intersection_II(t_sq *sq, t_ray *ray, double t)
{
	t_mat	mat;
	t_vet	hit;
	t_vet	vet;

	hit = vet_sum_sub(ray->orig, vet_mult_div(ray->drct, t, 1), 1);
	hit = vet_sum_sub(hit, sq->orig, 0);
	if (sq->norm.y == 1 || sq->norm.y == -1)
		mat.c1 = vet_create(1, 0, 0);
	else
		mat.c1 = vet_cross(vet_create(0, 1, 0), sq->norm);
	vet_norm(&mat.c1);
	mat.c2 = vet_cross(sq->norm, mat.c1);
	mat.c3 = sq->norm;
	mat = mat_invert(mat);
	vet = vet_mat_dot(mat, hit);
	if (fabs(vet.x) <= (sq->side / 2) && fabs(vet.y) <= (sq->side / 2))
		return (1);
	return (0);
}

void	sq_intersection_I(t_sq *sq, t_ray *ray)
{
	t_vet	v1;
	double	i[3];
	double	t;

	if (vet_dot(sq->norm, ray->drct))
	{
		if (vet_dot(sq->norm, ray->drct) > 0)
			sq->norm = vet_mult_div(sq->norm, -1, 1);
		i[0] = vet_dot(sq->norm, ray->orig);
		i[1] = vet_dot(sq->norm, sq->orig);
		i[2] = vet_dot(sq->norm, ray->drct);
		t = (i[1] - i[0]) / i[2];
		if (t > 0 && t < ray->t && (sq_intersection_II(sq, ray, t)))
		{
			ray->t = t;
			ray->norm = sq->norm;
			v1 = vet_mult_div(ray->drct, ray->t, 1);
			ray->hit = vet_sum_sub(ray->orig, v1, 1);
			v1 = vet_mult_div(ray->norm, EPSILON, 1);
			ray->hit = vet_sum_sub(ray->hit, v1, 1);
			ray->color = sq->color;
		}
	}
}
