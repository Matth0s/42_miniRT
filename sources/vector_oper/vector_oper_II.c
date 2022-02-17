/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_oper_II.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 01:50:12 by mmoreira          #+#    #+#             */
/*   Updated: 2022/02/17 19:24:39 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	vet_norm(t_vet *vet)
{
	double	i;

	i = sqrt(vet_dot(*vet, *vet));
	if (i < 1 - EPSILON || i > 1 + EPSILON)
	{
		vet->x /= i;
		vet->y /= i;
		vet->z /= i;
	}
}

double	vet_dot(t_vet v1, t_vet v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vet	vet_cross(t_vet v1, t_vet v2)
{
	t_vet	vet;

	vet.x = v1.y * v2.z - v1.z * v2.y;
	vet.y = v1.z * v2.x - v1.x * v2.z;
	vet.z = v1.x * v2.y - v1.y * v2.x;
	return (vet);
}

t_vet	vet_color_mult(t_vet v1, t_vet v2)
{
	return (vet_create(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z));
}

void	vet_color_norm(t_vet *vet, int i)
{
	if (i)
		*vet = vet_div(*vet, 255);
	else
		*vet = vet_mult(*vet, 255);
	if (vet->x > 255)
		vet->x = 255;
	else if (vet->x < 0)
		vet->x = 0;
	if (vet->y > 255)
		vet->y = 255;
	else if (vet->y < 0)
		vet->y = 0;
	if (vet->z > 255)
		vet->z = 255;
	else if (vet->z < 0)
		vet->z = 0;
}
