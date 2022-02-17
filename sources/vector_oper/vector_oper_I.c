/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_oper_I.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 01:33:35 by mmoreira          #+#    #+#             */
/*   Updated: 2022/02/17 04:41:48 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vet	vet_create(double x, double y, double z)
{
	t_vet	vet;

	vet.x = x;
	vet.y = y;
	vet.z = z;
	return (vet);
}

t_vet	vet_sum_sub(t_vet v1, t_vet v2, int i)
{
	t_vet	vet;

	if (i)
		vet = vet_create(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
	else
		vet = vet_create(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
	return (vet);
}

t_vet	vet_mult_div(t_vet v1, double n, int i)
{
	t_vet	vet;

	if (i)
		vet = vet_create(v1.x * n, v1.y * n, v1.z * n);
	else
		vet = vet_create(v1.x / n, v1.y / n, v1.z / n);
	return (vet);
}
