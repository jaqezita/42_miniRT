/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:05:30 by jaqribei          #+#    #+#             */
/*   Updated: 2023/08/07 02:58:08 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*aux;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	if (new == NULL)
	{
		return (NULL);
	}
	aux = new;
	while (lst->next != NULL)
	{
		new->next = ft_lstnew(f(lst->next->content));
		if (new->next == NULL)
		{
			ft_lstclear(&aux, del);
			return (NULL);
		}
		lst = lst->next;
		new = new->next;
	}
	return (aux);
}
