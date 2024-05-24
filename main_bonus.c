/**
 * @file main_bonus.c
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief File containing the main function for the bonus part of the project.
 * @version 0.1
 * @date 2024-05-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "minirt_bonus.h"
/**
 * @brief Function to print the instructions on the terminal.
 * 
 */
void	ft_print_instruct(void)
{
	ft_putstr_fd("\n        USE THE [R] KEY TO RESET THE CAMERA POSITION\n", 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("       Rotating Camera                   Moving Camera\n", 1);
	ft_putstr_fd("\n    ↑    Y                            ↑    Y\n", 1);
	ft_putstr_fd("   [W]   |    Z                      [↑]   |    Z\n", 1);
	ft_putstr_fd("         |   /                             |   / \n", 1);
	ft_putstr_fd("   KEY   |  /[E]⟳                    KEY   |  /[+]↗\n", 1);
	ft_putstr_fd("         | /[Q]⟲                           | /[-] ↙\n", 1);
	ft_putstr_fd("   [S]   |/                          [↓]   |/       \n", 1);
	ft_putstr_fd("    ↓    +-----------> X              ↓    +-----------", 1);
	ft_putstr_fd("> X\n", 1);
	ft_putstr_fd("          ←[A] KEY [D]→                  ←[←] KEY [→]→\n", 1);
	ft_putstr_fd("\n   KEYS [A][D] - MOVE THE X AXIS    KEYS [←](LEFT ", 1);
	ft_putstr_fd("ARROW KEY)[→](RIGHT ARROW KEY) - MOVE THE X AXIS\n", 1);
	ft_putstr_fd("   KEYS [W][S] - MOVE THE Y AXIS    KEYS [↑](UP ", 1);
	ft_putstr_fd("ARROW KEY)  [↓](DOWN ARROW KEY)  - MOVE THE Y AXIS\n", 1);
	ft_putstr_fd("   KEYS [Q][E] - MOVE THE Z AXIS    KEYS [+](PLUS KEY)", 1);
	ft_putstr_fd("      [-](MINUS KEY)       - MOVE THE Z AXIS\n", 1);
}
/**
 * @brief Set the shapes object
 * 
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
 * @brief Set the up world object
 * 
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
 * @brief FUnction to save the moment zero of the camera view.
 * 
 * @param w 
 */
void	ft_duplicate_camera(t_world *w)
{
	w->zero = ft_calloc(1, sizeof(t_camera));
	if (!w->zero)
		ft_error("System error\n", NULL);
	ft_memcpy(w->zero, w->camera, sizeof(t_camera));
}
/**
 * @brief Main function for the bonus part of the project.
 * 
 * @param ac 
 * @param av 
 * @return int 
 */
int	main(int ac, char **av)
{
	t_world	*w;
	t_scene	scene;

	ft_check_main_bonus(ac);
	ft_open_file_bonus(av[1], &scene);
	w = setup_world(&scene);
	ft_print_instruct();
	w->camera = ft_setup_camera(&scene);
	ft_duplicate_camera(w);
	w->canvas = ft_create_aperture(w->camera->hsize, w->camera->vsize);
	ft_open_window_bonus(w);
	ft_set_hooks_bonus(w);
	ft_start_thread(w);
	printf("Press [ESC] to exit\n");
	mlx_put_image_to_window(w->mlx, w->win, w->img.img, 0, 0);
	mlx_loop(w->mlx);
}
