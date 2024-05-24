/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:17:48 by mamaral-          #+#    #+#             */
/*   Updated: 2024/05/20 11:43:36 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	ft_validchar_bonus(char c)
{
	if (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) || (c >= '0'
			&& c <= '9') || (c >= '+' && c <= '.') || c == ' ' || c == '\n')
		return (1);
	return (0);
}

/*scene_line_split, a variável info_qty é usada para armazenar o número
	esperado de elementos em uma linha para cada tipo de elemento da cena.
 Esta matriz estática é inicializada com os números corretos para cada tipo
	de elemento, onde cada índice corresponde ao ID do elemento na cena.*/

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

static void	get_scene_bonus(t_scene *scene, int id)
{
	static t_arr_sc	ft_scene[9] = {get_1_amb, get_2_cam_bonus, get_3_light,
		get_4_sp_bonus, get_5_pl_bonus, get_6_cy_bonus, get_7_co, get_8_cb,
		get_9_tr};

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

void	ft_open_file_bonus(char *file, t_scene *scene)
{
	static char	*s[9] = {"A ", "C ", "L ", "sp", "pl", "cy", "co", "cb", "tr"};
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
