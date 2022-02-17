/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_oper_II.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 01:50:12 by mmoreira          #+#    #+#             */
/*   Updated: 2022/02/17 04:41:48 by mmoreira         ###   ########.fr       */
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

t_vet	vet_mat_dot(t_mat mat, t_vet vet)
{
	t_vet	v1;

	v1.x = mat.c1.x * vet.x + mat.c2.x * vet.y + mat.c3.x * vet.z;
	v1.y = mat.c1.y * vet.x + mat.c2.y * vet.y + mat.c3.y * vet.z;
	v1.z = mat.c1.z * vet.x + mat.c2.z * vet.y + mat.c3.z * vet.z;
	return (v1);
}
