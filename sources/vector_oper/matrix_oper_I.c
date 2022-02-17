/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_oper_I.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 01:52:56 by mmoreira          #+#    #+#             */
/*   Updated: 2022/02/17 18:53:49 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vet	mat_dot_vet(t_mat mat, t_vet vet)
{
	t_vet	v1;

	v1.x = mat.c1.x * vet.x + mat.c2.x * vet.y + mat.c3.x * vet.z;
	v1.y = mat.c1.y * vet.x + mat.c2.y * vet.y + mat.c3.y * vet.z;
	v1.z = mat.c1.z * vet.x + mat.c2.z * vet.y + mat.c3.z * vet.z;
	return (v1);
}

double	mat_det(t_mat mat)
{
	double	t[4];

	t[0] = mat.c1.x * mat.c2.y * mat.c3.z;
	t[1] = mat.c2.x * mat.c3.y * mat.c1.z;
	t[2] = mat.c3.x * mat.c1.y * mat.c2.z;
	t[3] = t[0] + t[1] + t[2];
	t[0] = mat.c2.x * mat.c1.y * mat.c3.z;
	t[1] = mat.c1.x * mat.c3.y * mat.c2.z;
	t[2] = mat.c3.x * mat.c2.y * mat.c1.z;
	t[3] = t[3] - t[0] - t[1] - t[2];
	return (t[3]);
}

t_mat	mat_invert(t_mat mat)
{
	t_mat	m1;
	double	t[4];

	t[3] = mat_det(mat);
	t[0] = (mat.c2.y * mat.c3.z - mat.c3.y * mat.c2.z) / t[3];
	t[1] = -(mat.c1.y * mat.c3.z - mat.c3.y * mat.c1.z) / t[3];
	t[2] = (mat.c1.y * mat.c2.z - mat.c2.y * mat.c1.z) / t[3];
	m1.c1 = vet_create(t[0], t[1], t[2]);
	t[0] = -(mat.c2.x * mat.c3.z - mat.c3.x * mat.c2.z) / t[3];
	t[1] = (mat.c1.x * mat.c3.z - mat.c3.x * mat.c1.z) / t[3];
	t[2] = -(mat.c1.x * mat.c2.z - mat.c2.x * mat.c1.z) / t[3];
	m1.c2 = vet_create(t[0], t[1], t[2]);
	t[0] = (mat.c2.x * mat.c3.y - mat.c3.x * mat.c2.y) / t[3];
	t[1] = -(mat.c1.x * mat.c3.y - mat.c3.x * mat.c1.y) / t[3];
	t[2] = (mat.c1.x * mat.c2.y - mat.c2.x * mat.c1.y) / t[3];
	m1.c3 = vet_create(t[0], t[1], t[2]);
	return (m1);
}
