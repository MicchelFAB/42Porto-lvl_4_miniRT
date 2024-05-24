/**
 * @file get_scene_objs_bonus_2.c
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief File complementary to get_scene_bonus.c containing the elements of scene for the bonus part.
 * @version 0.1
 * @date 2024-05-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "parse.h"
/**
 * @brief Function to check if the bonus list is valid.
 * 
 * @param scene 
 * @return int 
 */
int	ft_check_bonus_list(t_scene *scene)
{
	if (scene->bonus_qtys[0] > 1 || scene->bonus_qtys[1] > 1 || scene->bonus_qtys[2] > 1 || scene->bonus_qtys[3] > 1)
		return (0);
	return (1);
}
/**
 * @brief Function to reset the bonus quantity.
 * 
 * @param bonus_qtys 
 */
void	ft_reset_qty(int *bonus_qtys)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		bonus_qtys[i] = 0;
		i++;
	}
}
/**
 * @brief Function to get the bonus list.
 * 
 * @param scene 
 * @param id 
 */
void	ft_get_bonus_list(t_scene *scene, int id)
{
	char	**split_bonus;

	if (scene->split[id] == NULL)
		return ;
	ft_reset_qty(scene->bonus_qtys);
	while (scene->split[id])
	{
		split_bonus = ft_split(scene->split[id], '|');
		if (ft_strlen(split_bonus[0]) != 2)
			ft_msg_error(scene, "Invalid bonus identifier");
		if (ft_strncmp(split_bonus[0], "pt", 2) == 0)
			ft_get_patern(split_bonus, scene);
		else if (ft_strncmp(split_bonus[0], "px", 2) == 0)
			ft_get_imgxpm(split_bonus, scene);
		else if (ft_strncmp(split_bonus[0], "rf", 2) == 0)
			ft_get_reflective(split_bonus, scene);
		else if (ft_strncmp(split_bonus[0], "gl", 2) == 0)
			ft_get_glass(split_bonus, scene);
		ft_split_free(split_bonus);
		id++;
	}
}
/**
 * @brief Get the camera arguments for bonus part
 * 
 * @param scene 
 */
void	get_2_cam_bonus(t_scene *scene)
{
	double	fov;

	fov = ft_get_int(scene->split[3], C_FOV, scene);
	if (!(fov >= 0 && fov <= 180))
		ft_msg_error(scene, C_FOV);
	fov *= M_PI_4 / 45;
	scene->camera = ft_create_camera(WIDTH_B, WIDTH_B / RATIO, fov);
	scene->camera->point = ft_get_coord(scene->split[1], C_COORD, scene);
	if (scene->camera->point.x == scene->camera->point.y && scene->camera->point.y == scene->camera->point.z)
		ft_msg_error(scene,
			"Camera point X, Y and Z cannot be equal at LEAST one of them must be different\n");
	scene->camera->normalized = ft_get_coord(scene->split[2], C_NORM, scene);
	if (!ft_isnormal(scene->camera->normalized))
		ft_msg_error(scene, C_NORM);
	scene->camera->point = ft_point(scene->camera->point.x,	scene->camera->point.y, scene->camera->point.z);
	scene->camera->normalized = ft_vector(scene->camera->normalized.x, scene->camera->normalized.y, scene->camera->normalized.z);
}
/**
 * @brief Get the triangle object
 * 
 * @param scene 
 */
void	get_9_tr(t_scene *scene)
{
	scene->new = ft_create_shape_bonus(TRIANGLE);
	scene->new->triangle->p1 = ft_get_coord(scene->split[1], TR_P1, scene);
	scene->new->triangle->p1 = ft_vector(scene->new->triangle->p1.x, scene->new->triangle->p1.y, scene->new->triangle->p1.z);
	scene->new->triangle->p2 = ft_get_coord(scene->split[2], TR_P2, scene);
	scene->new->triangle->p2 = ft_vector(scene->new->triangle->p2.x, scene->new->triangle->p2.y, scene->new->triangle->p2.z);
	scene->new->triangle->p3 = ft_get_coord(scene->split[3], TR_P3, scene);
	scene->new->triangle->p3 = ft_vector(scene->new->triangle->p3.x, scene->new->triangle->p3.y, scene->new->triangle->p3.z);
	ft_set_triangle_points(scene->new->triangle, scene->new->triangle->p1, scene->new->triangle->p2, scene->new->triangle->p3);
	scene->new->material.color = ft_get_colour(scene->split[4], TR_RGB, scene);
	scene->new->material.color = ft_color(ft_normalize_color(scene->new->material.color.x), ft_normalize_color(scene->new->material.color.y), ft_normalize_color(scene->new->material.color.z));
	ft_get_bonus_list(scene, 5);
	if (!ft_check_bonus_list(scene))
		ft_msg_error(scene, "Invalid number of bonus identifier");
	ft_set_shape_transform(scene->new, ft_create_scaling_matrix(0.9, 0.9, 0.9));
}
