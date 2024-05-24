/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:41:51 by bmonteir          #+#    #+#             */
/*   Updated: 2024/05/20 11:43:17 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	ft_validchar(char c)
{
	if (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		|| (c >= '0' && c <= '9') || (c >= '+' && c <= '.')
		|| c == ' ' || c == '\n')
		return (1);
	return (0);
}

/*scene_line_split, a variável info_qty é usada para armazenar o número 
 	esperado de elementos em uma linha para cada tipo de elemento da cena. 
 Esta matriz estática é inicializada com os números corretos para cada tipo 
 	de elemento, onde cada índice corresponde ao ID do elemento na cena.*/

static void	scene_line_split(t_scene *scene, int id)
{
	static int	info_qty[6] = {3, 4, 4, 4, 4, 6};
	int			i;

	i = 0;
	if (!scene->line)
	{
		ft_msg_error(scene, LINE);
		return ;
	}
	while (scene->line[i])
	{
		if (ft_validchar(scene->line[i] == 0))
			ft_msg_error(scene, LINE);
		if (ft_isspace(scene->line[i]))
			scene->line[i] = ' ';
		i++;
	}
	scene->split = ft_split(scene->line, ' ');
	if (id == 2 && (ft_strlen_2(scene->split) < 3
			|| ft_strlen_2(scene->split) > 4))
		ft_msg_error(scene, "err_id");
	if (id != 2 && ft_strlen_2(scene->split) != (size_t)info_qty[id])
		ft_msg_error(scene, "err_id");
}

static void	get_scene(t_scene *scene, int id)
{
	static t_arr_sc	ft_scene[6] = {get_1_amb, get_2_cam, get_3_light, get_4_sp,
		get_5_pl, get_6_cy};

	if (id < 3)
	{
		if (scene->qtys[id] > 0)
		{
			ft_msg_error(scene, ID);
			return ;
		}
	}
	scene_line_split(scene, id);
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

void	ft_scene_check(t_scene *scene, int fd)
{
	if (close(fd) < 0)
		return (ft_error(FILE_NF, scene));
	if (scene->msg_error)
		ft_error(scene->msg_error, scene);
	if (scene->qtys[0] == 0 || scene->qtys[1] == 0 || scene->qtys[2] == 0)
		ft_error(INFO_SCENE, scene);
}

void	ft_open_file(char *file, t_scene *scene)
{
	static char	*s[6] = {"A ", "C ", "L ", "sp", "pl", "cy"};
	int			fd;
	char		*ret;
	int			id;

	ft_bzero(scene, sizeof(t_scene));
	if (ft_chk_file(file))
		ft_error(RT_FILE, scene);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_error(FILE_NF, scene));
	ret = get_next_line(fd, NO);
	while (ret)
	{
		id = 0;
		while (id < 6 && ft_strncmp(ret, s[id], 2))
			id++;
		scene->line = ft_strdup(ret);
		if (id < 6 && !scene->msg_error)
			get_scene(scene, id);
		free(scene->line);
		free(ret);
		ret = get_next_line(fd, NO);
	}
	ft_scene_check(scene, fd);
}
