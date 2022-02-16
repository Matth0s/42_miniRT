/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstloop_stop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 21:08:34 by mmoreira          #+#    #+#             */
/*   Updated: 2021/09/20 10:15:15 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstloop_stop(t_list **lst)
{
	if (!(*lst))
		return ;
	if (!((*lst)->prev))
		return ;
	((*lst)->prev)->next = NULL;
	(*lst)->prev = NULL;
}
