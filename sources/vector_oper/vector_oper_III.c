/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_oper_III.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 01:52:56 by mmoreira          #+#    #+#             */
/*   Updated: 2021/04/27 01:48:05 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/miniRT.h"

t_vet	vet_color_mult(t_vet v1, t_vet v2)
{
	return (vet_create(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z));
}

void	vet_color_norm(t_vet *vet, int i)
{
	if (i)
		*vet = vet_mult_div(*vet, 255, 0);
	else
		*vet = vet_mult_div(*vet, 255, 1);
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
