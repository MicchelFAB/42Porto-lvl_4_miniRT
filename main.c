/**
 * @file main.c
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief Main file for the program.
 * @version 0.1
 * @date 2024-05-22 * 
 * @note This file is part of the MiniRT project.
 * 
 * @copyright Copyright (c) 2024 * 
 */
#include "minirt.h"
/**
 * @brief Function to set the shapes.
 * @param lst 
 * @param scene 
 */
static void	set_shapes(t_list **lst, t_scene *scene)
{
	t_list		*new;
	t_shapes	*shapes;

	new = scene->objects;
	while (new)
	{
		shapes = new->content;
		shapes->material.ambient = ft_oper_specular(scene->ambient.color, '*',
				scene->ambient.ratio);
		new = new->next;
	}
	*lst = scene->objects;
}
/**
 * @brief Set the up world object * 
 * @param scene 
 * @return t_world* 
 */
static t_world	*setup_world(t_scene *scene)
{
	t_world	*w;

	w = ft_create_world();
	set_shapes(&w->objects, scene);
	w->lights = scene->lights_list;
	return (w);
}
/**
 * @brief Check the main arguments.
 * @param ac 
 */
void	ft_check_main(int ac)
{
	if (ac != 2 || (RATIO < 1 || RATIO > 2) || (WIDTH < 50 || WIDTH > 1900))
	{
		ft_putstr_fd("\033[1m\033[38;5;199mError\033[0m\n", STDERR_FILENO);
		if (ac != 2)
			ft_putstr_fd("Invalid number of arguments", STDERR_FILENO);
		else if (RATIO < 1 || RATIO > 2)
			ft_putstr_fd("Invalid aspect ratio", STDERR_FILENO);
		else if (WIDTH < 50 || WIDTH > 1900)
			ft_putstr_fd("Invalid width", STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
/**
  * @brief Main function.
 * @param ac 
 * @param av 
 * @return int 
 * @see ft_check_main
 */
int	main(int ac, char **av)
{
	t_world	*w;
	t_scene	scene;

	ft_check_main(ac);
	ft_open_file(av[1], &scene);
	w = setup_world(&scene);
	w->camera = ft_setup_camera(&scene);
	w->canvas = ft_render(w->camera, w);
	ft_open_window(w);
	ft_set_hooks(w);
	ft_panel_window(&w->img, WIDTH, WIDTH / RATIO, w->canvas.pixels);
	mlx_put_image_to_window(w->mlx, w->win, w->img.img, 0, 0);
	mlx_loop(w->mlx);
}
