/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_oper_I.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 01:33:35 by mmoreira          #+#    #+#             */
/*   Updated: 2022/02/17 19:25:16 by mmoreira         ###   ########.fr       */
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

t_vet	vet_sum(t_vet v1, t_vet v2)
{
	return (vet_create(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z));
}

t_vet	vet_sub(t_vet v1, t_vet v2)
{
	return (vet_create(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z));
}

t_vet	vet_mult(t_vet v1, double n)
{
	return (vet_create(v1.x * n, v1.y * n, v1.z * n));
}

t_vet	vet_div(t_vet v1, double n)
{
	return (vet_create(v1.x / n, v1.y / n, v1.z / n));
}
