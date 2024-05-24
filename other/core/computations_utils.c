/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computations_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:20:07 by mamaral-          #+#    #+#             */
/*   Updated: 2024/05/10 18:47:40 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

bool	ft_lst_contains(t_list *lst, t_shapes *shape)
{
	t_list	*temp;

	temp = lst;
	while (temp)
	{
		if (temp->content == shape)
			return (true);
		temp = temp->next;
	}
	return (false);
}

void	ft_lst_remove(t_list **lst, t_shapes *shape)
{
	t_list	*temp;
	t_list	*prev;

	temp = *lst;
	prev = NULL;
	while (temp != NULL)
	{
		if (temp->content == shape)
		{
			if (prev == NULL)
				*lst = temp->next;
			else
				prev->next = temp->next;
			free(temp);
			return ;
		}
		prev = temp;
		temp = temp->next;
	}
}

double	ft_check_containers(t_list *containers)
{
	t_shapes	*last;

	if (containers)
		last = ft_lst_last(containers)->content;
	if (!containers)
		return (1.0);
	else
		return (last->material.refractive_index);
}
