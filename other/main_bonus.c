/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmonteir <bmonteir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 23:36:12 by mamaral-          #+#    #+#             */
/*   Updated: 2024/05/19 19:00:10 by bmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

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

static t_world	*setup_world(t_scene *scene)
{
	t_world	*w;

	w = ft_create_world();
	set_shapes(&w->objects, scene);
	w->lights = scene->lights_list;
	return (w);
}

void	ft_duplicate_camera(t_world *w)
{
	w->zero = ft_calloc(1, sizeof(t_camera));
	if (!w->zero)
		ft_error("System error\n", NULL);
	ft_memcpy(w->zero, w->camera, sizeof(t_camera));
}

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
