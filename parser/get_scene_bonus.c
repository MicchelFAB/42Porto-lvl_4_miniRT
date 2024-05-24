/**
 * @file get_scene_bonus.c
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief File containing the elements of scene for the bonus part.
 * @version 0.1
 * @date 2024-05-23 * 
 * @note This file is part of the MiniRT project.
 * 
 * @copyright Copyright (c) 2024 * 
 */
#include "parse.h"
/**
 * @brief Function to get the type of the pattern.
 * @param type 
 * @param scene 
 * @return t_style 
 */
t_style	ft_get_type(char *type, t_scene *scene)
{
	if (ft_strncmp(type, "stripes", 7) == 0)
		return (STRIPES);
	else if (ft_strncmp(type, "gradient", 8) == 0)
		return (GRADIENT);
	else if (ft_strncmp(type, "ring", 4) == 0)
		return (RING);
	else if (ft_strncmp(type, "checkers", 8) == 0)
		return (CHECKERS);
	else
		ft_msg_error(scene, "Invalid pattern type");
	return (0);
}
/**
 * @brief Function to get the pattern.
 * @param split 
 * @param scene 
 */
void	ft_get_patern(char **split, t_scene *scene)
{
	if (ft_strlen_2(split) != 4)
	{
		ft_msg_error(scene, "Invalid number of arguments for pattern");
		return ;
	}
	scene->new->material.pattern.type = ft_get_type(split[1], scene);
	scene->new->material.pattern.a = ft_get_colour(split[2], RGB_BONUS, scene);
	scene->new->material.pattern.a = ft_color(ft_normalize_color(scene->new->material.pattern.a.x), ft_normalize_color(scene->new->material.pattern.a.y), ft_normalize_color(scene->new->material.pattern.a.z));
	scene->new->material.pattern.b = ft_get_colour(split[3], RGB_BONUS, scene);
	scene->new->material.pattern.b = ft_color(ft_normalize_color(scene->new->material.pattern.b.x), ft_normalize_color(scene->new->material.pattern.b.y), ft_normalize_color(scene->new->material.pattern.b.z));
	scene->new->material.pattern = ft_create_pattern(scene->new->material.pattern.type, scene->new->material.pattern.a, scene->new->material.pattern.b);
	scene->bonus_qtys[0]++;
}
/**
 * @brief Function to get the image xpm.
 * @param split 
 * @param scene 
 */
void	ft_get_imgxpm(char **split, t_scene *scene)
{
	if (ft_strlen_2(split) != 2)
	{
		ft_msg_error(scene, "Invalid number of arguments for image xpm");
		return ;
	}
	scene->new->material.pattern = ft_create_xpm_pattern(XPM, split[1], scene);
	scene->bonus_qtys[1]++;
}
/**
 * @brief Function to get the reflective values.
 * @param split 
 * @param scene 
 */
void	ft_get_reflective(char **split, t_scene *scene)
{
	if (ft_strlen_2(split) != 3)
	{
		ft_msg_error(scene, "Invalid number of arguments for reflaction");
		return ;
	}
	scene->new->material.shininess = ft_get_size(split[1], RF_SHIN, scene);
	if (scene->new->material.shininess < 0 || scene->new->material.shininess > 2000)
		ft_msg_error(scene, "Invalid value for shininess");
	scene->new->material.reflective = ft_get_size(split[2], RF_REF, scene);
	if (scene->new->material.reflective < 0	|| scene->new->material.reflective > 1)
		ft_msg_error(scene, "Invalid value for reflectivity");
	scene->bonus_qtys[2]++;
}
/**
 * @brief Function to get the refractive values.
 * @param split 
 * @param scene 
 */
void	ft_get_glass(char **split, t_scene *scene)
{
	t_color	clr;

	clr = scene->new->material.color;
	if (ft_strlen_2(split) != 3)
	{
		ft_msg_error(scene, "Invalid number of arguments for glass");
		return ;
	}
	scene->new->material.transparency = ft_get_size(split[1], GL_TRANS, scene);
	if (scene->new->material.transparency < 0 || scene->new->material.transparency > 1)
		ft_msg_error(scene, "Invalid value for transparency");
	scene->new->material.refractive_index = ft_get_size(split[2], GL_REFLEC, scene);
	scene->new->material.color = ft_color(clr.x / 2, clr.y / 2, clr. z / 2);
	scene->bonus_qtys[3]++;
}
