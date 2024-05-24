/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:55:49 by mamaral-          #+#    #+#             */
/*   Updated: 2024/05/14 09:40:37 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_list	*ft_lst_last(t_list *lst)
{
	t_list	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void	ft_free_list(t_list **lst)
{
	t_list	*temp;
	t_list	*next;

	temp = *lst;
	while (temp)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	*lst = NULL;
}

// Frees the intersections list.
void	ft_free_intersections(t_intersections **lst)
{
	t_intersections	*tmp;

	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp->content);
		free(tmp);
	}
}

void	ft_free_all_allocated_memory(t_world *prog)
{
	t_list	*tmp;

	while (prog->objects)
	{
		tmp = prog->objects->next;
		ft_free_shapes((t_shapes *)(prog->objects->content));
		free(prog->objects);
		prog->objects = tmp;
	}
	while (prog->lights)
	{
		tmp = prog->lights;
		prog->lights = prog->lights->next;
		free(tmp->content);
		free(tmp);
	}
	ft_free_canvas(prog->canvas);
	free(prog->camera);
	if (prog->zero)
		free(prog->zero);
	free(prog);
}

int	ft_close(t_world *prog)
{
	mlx_destroy_image(prog->mlx, prog->img.img);
	mlx_destroy_window(prog->mlx, prog->win);
	mlx_destroy_display(prog->mlx);
	free(prog->mlx);
	ft_free_all_allocated_memory(prog);
	printf("CLOSED\n");
	exit(EXIT_SUCCESS);
}
