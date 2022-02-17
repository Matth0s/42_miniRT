/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sq_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 03:21:07 by mmoreira          #+#    #+#             */
/*   Updated: 2022/02/17 21:49:49 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	sq_intersection_i(t_sq *sq, t_ray *ray, double t)
{
	t_mat	mat;
	t_vet	hit;
	t_vet	vet;

	hit = vet_sum(ray->orig, vet_mult(ray->drct, t));
	hit = vet_sub(hit, sq->orig);
	if (sq->norm.y == 1 || sq->norm.y == -1)
		mat.c1 = vet_create(1, 0, 0);
	else
		mat.c1 = vet_cross(vet_create(0, 1, 0), sq->norm);
	vet_norm(&mat.c1);
	mat.c2 = vet_cross(sq->norm, mat.c1);
	mat.c3 = sq->norm;
	mat = mat_invert(mat);
	vet = mat_dot_vet(mat, hit);
	if (fabs(vet.x) <= (sq->side / 2) && fabs(vet.y) <= (sq->side / 2))
		return (1);
	return (0);
}

void	sq_intersection(t_sq *sq, t_ray *ray)
{
	t_vet	v1;
	double	i[3];
	double	t;

	if (vet_dot(sq->norm, ray->drct))
	{
		if (vet_dot(sq->norm, ray->drct) > 0)
			sq->norm = vet_mult(sq->norm, -1);
		i[0] = vet_dot(sq->norm, ray->orig);
		i[1] = vet_dot(sq->norm, sq->orig);
		i[2] = vet_dot(sq->norm, ray->drct);
		t = (i[1] - i[0]) / i[2];
		if (t > 0 && t < ray->t && (sq_intersection_i(sq, ray, t)))
		{
			ray->t = t;
			ray->norm = sq->norm;
			v1 = vet_mult(ray->drct, ray->t);
			ray->hit = vet_sum(ray->orig, v1);
			v1 = vet_mult(ray->norm, EPSILON);
			ray->hit = vet_sum(ray->hit, v1);
			ray->color = sq->color;
		}
	}
}
