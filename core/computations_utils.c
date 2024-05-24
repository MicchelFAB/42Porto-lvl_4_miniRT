/**
 * @file computations_utils.c
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief File containing functions to prepare computations and calculate the
 * surface color of an object.
 * @version 0.1
 * @date 2024-05-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "core.h"
/**
 * @brief Check if a list contains a shape.
 * 
 * @param lst The list.
 * @param shape The shape.
 * @return true If the list contains the shape.\
 * @return false If the list does not contain the shape.
 */
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
/**
 * @brief Remove a shape from a list.
 * 
 * @param lst The list.
 * @param shape The shape.
 */
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
/**
 * @brief Check the refractive indices of the containers.
 * 
 * @param containers The list of containers.
 * @return double The refractive index.
 */
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
