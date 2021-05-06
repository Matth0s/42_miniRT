/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfirst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 21:49:52 by mmoreira          #+#    #+#             */
/*   Updated: 2021/04/15 18:13:33 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstfirst(t_list *lst)
{
	t_list	*temp;

	if (!(lst))
		return (lst);
	temp = lst;
	while (temp->prev)
		temp = temp->prev;
	return (temp);
}
