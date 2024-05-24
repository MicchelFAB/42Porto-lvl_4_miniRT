/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:04:34 by mamaral-          #+#    #+#             */
/*   Updated: 2024/05/16 14:55:37 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	ft_msg_error(t_scene *scene, char *code)
{
	if (!scene->msg_error)
		scene->msg_error = code;
}

void	ft_free_all_scene(t_scene *scene)
{
	t_list	*tmp;

	while (scene->objects)
	{
		tmp = scene->objects->next;
		ft_free_shapes((t_shapes *)(scene->objects->content));
		free(scene->objects);
		scene->objects = tmp;
	}
	while (scene->lights_list)
	{
		tmp = scene->lights_list;
		scene->lights_list = scene->lights_list->next;
		free(tmp->content);
		free(tmp);
	}
	free(scene->camera);
}

size_t	ft_strlen_2(char **s)
{
	size_t	l;

	l = 0;
	while (s[l] != 0)
		l++;
	return (l);
}

int	ft_strnrcmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	if (n == 0)
		return (0);
	i = ft_strlen(s1);
	if (i <= n)
		return (1);
	j = ft_strlen(s2);
	while (s1[--i] == s2[--j])
	{
		n--;
		if (n == 0)
			return (0);
	}
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[j]));
}

void	ft_split_free(char **s)
{
	size_t	i;
	size_t	len;

	if (!s || !*s)
		return ;
	len = ft_strlen_2(s);
	i = 0;
	while (i < len)
	{
		free(s[i++]);
	}
	free(s);
}
