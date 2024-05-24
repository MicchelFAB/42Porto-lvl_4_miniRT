/**
 * @file parse_bonus.c
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief File containing the parsing functions for the bonus part.
 * @version 0.1
 * @date 2024-05-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "parse.h"
/**
 * @brief Function to check if the character is valid.
 * 
 * @param c 
 * @return int 
 */
static int	ft_validchar_bonus(char c)
{
	return (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) || (c >= '0' && c <= '9') || (c >= '+' && c <= '.') || c == ' ' || c == '\n');
}
/**
 * @brief Function to split the line.
 * 
 * @param scene 
 * @param id 
 */
static void	scene_line_split_bonus(t_scene *scene, int id)
{
	static int	info_qty[9] = {3, 4, 4, 4, 4, 6, 6, 5, 5};
	int			i;

	i = 0;
	if (!scene->line)
	{
		ft_msg_error(scene, LINE);
		return ;
	}
	while (scene->line[i])
	{
		if (ft_validchar_bonus(scene->line[i] == 0))
			ft_msg_error(scene, LINE);
		if (ft_isspace(scene->line[i]))
			scene->line[i] = ' ';
		i++;
	}
	scene->split = ft_split(scene->line, ' ');
	if (id < 3 && (ft_strlen_2(scene->split) != (size_t)info_qty[id]))
		ft_msg_error(scene, "err_id_1");
	if (id >= 3 && (ft_strlen_2(scene->split) < (size_t)info_qty[id]))
		ft_msg_error(scene, "err_id_2");
}
/**
 * @brief Function to get the scene.
 * 
 * @param scene 
 * @param id 
 */
static void	get_scene_bonus(t_scene *scene, int id)
{
	static t_arr_sc	ft_scene[9] = {get_1_amb, get_2_cam_bonus, get_3_light, get_4_sp_bonus, get_5_pl_bonus, get_6_cy_bonus, get_7_co, get_8_cb, get_9_tr};

	if (id < 2)
	{
		if (scene->qtys[id] > 0)
			ft_msg_error(scene, ID);
	}
	scene_line_split_bonus(scene, id);
	if (scene->msg_error)
	{
		ft_split_free(scene->split);
		return ;
	}
	ft_scene[id](scene);
	if (id == 2)
		ft_add_lights(&scene->lights_list, scene->lights);
	if (id > 2)
		ft_add_shapes(&scene->objects, scene->new);
	ft_split_free(scene->split);
	scene->qtys[id]++;
}
/**
 * @brief Function to open the file.
 * 
 * @param file 
 * @param scene 
 */
void	ft_open_file_bonus(char *file, t_scene *scene)
{
	static char	*s[9] = {"A ", "C ", "L ", "sp", "pl", "cy", "co", "cb", "tr"};
	int			fd;
	char		*ret;
	int			id;

	ft_bzero(scene, sizeof(t_scene));
	if (ft_strnrcmp(file, ".rt", 3) != 0)
		ft_error(RT_FILE, scene);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_error(FILE_NF, scene));
	ret = get_next_line(fd, NO);
	while (ret)
	{
		id = 0;
		while (id < 9 && ft_strncmp(ret, s[id], 2))
			id++;
		scene->line = ft_strdup(ret);
		if (id < 9 && !scene->msg_error)
			get_scene_bonus(scene, id);
		free(scene->line);
		free(ret);
		ret = get_next_line(fd, NO);
	}
	ft_scene_check(scene, fd);
}
