/**
 * @file end_program.c
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief File containing the functions to handle the end of the program.
 * @version 0.1
 * @date 2024-05-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "utils.h"
/**
 * @brief Function to free the memory allocated for the list.
 * 
 * @param lst 
 * @return t_list* 
 */
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
/**
 * @brief Function to free the memory allocated for the list.
 * 
 * @param lst 
 */
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
/**
 * @brief FUnciton to free the memory allocated for the intersections.
 * 
 * @param lst 
 */
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
/**
  @brief Function to manage the necessary memory to be freed.
 * 
 * @param prog 
 */
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
/**
 * @brief Function to close the program. And destroy the window.
 * 
 * @param prog 
 * @return int 
 */
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
