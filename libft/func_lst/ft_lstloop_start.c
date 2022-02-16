/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstloop_start.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 21:08:34 by mmoreira          #+#    #+#             */
/*   Updated: 2021/09/20 10:15:11 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstloop_start(t_list **lst)
{
	t_list	*temp;

	if (!(*lst))
		return ;
	temp = ft_lstlast(*lst);
	(*lst)->prev = temp;
	temp->next = *lst;
}
