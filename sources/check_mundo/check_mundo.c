/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mundo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 03:04:41 by mmoreira          #+#    #+#             */
/*   Updated: 2022/02/17 04:41:48 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	check_color(t_vet vet)
{
	if (vet.x < 0 || vet.x > 255)
		return (0);
	if (vet.y < 0 || vet.y > 255)
		return (0);
	if (vet.z < 0 || vet.z > 255)
		return (0);
	return (1);
}

int	error_print_II(int indicator, int i)
{
	ft_printf("Error\n");
	if (indicator == 1)
	{
		ft_printf("Tu quer ver uma cena que tu não boto nada?\n");
		ft_printf("Brinca mais que a brincadeira você\n");
	}
	if (indicator == 2)
		ft_printf("O diametro no objeto %d é pra testar o bagulho?\n", i);
	if (indicator == 3)
		ft_printf("O objeto %d ta voando baixo com essa altura ai\n", i);
	if (indicator == 4)
		ft_printf("A cor do objeto %d é inovadora\n", i);
	if (indicator == 5)
		ft_printf("Passar uma normal pro objeto %d zerada é sacanagem\n", i);
	if (indicator == 6)
		ft_printf("Lado negativo pro quadrado %d transcendeu brother\n", i);
	if (indicator == 7)
		ft_printf("O triangulo %d em uma linha só ta na moda agora\n", i);
	return (0);
}

int	error_print_I(int indicator, int i)
{
	ft_printf("Error\n");
	if (indicator == 1)
		ft_printf("Tu não declarou nenhuma resolução pra tela brother\n");
	if (indicator == 2)
		ft_printf("Tu não boto nenhuma luz ambiente brother\n");
	if (indicator == 3)
		ft_printf("A força da luz desse teu ambiente ai ta uma maravilha\n");
	if (indicator == 4)
		ft_printf("A cor desse ambiente ai ta nervosa\n");
	if (indicator == 5)
		ft_printf("Vamo rever a força dessa lampada numero %d ai\n", i);
	if (indicator == 6)
		ft_printf("A cor dessa tua lampada %d ta engraçada em\n", i);
	if (indicator == 7)
		ft_printf("Meu bom, como tu vai ver o bagulho sem camera?\n");
	if (indicator == 8)
	{
		ft_printf("A camera %d ta de marola. ", i);
		ft_printf("Aqui nós só trabalha com angulo entre 0 e 180\n");
	}
	if (indicator == 9)
		ft_printf("A direção da tua camera %d não existe brother\n", i);
	return (0);
}

int	check_mundo(t_mundo *mundo)
{
	if (!(check_screan_abnt(mundo)))
		return (0);
	if (!(check_lamps(mundo)))
		return (0);
	if (!(check_cams(mundo)))
		return (0);
	if (!(check_objs_I(mundo)))
		return (0);
	return (1);
}
