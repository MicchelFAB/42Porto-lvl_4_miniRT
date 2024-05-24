/**
 * @file parse_utils.c
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief File containing the utility functions for the parsing.
 * @version 0.1
 * @date 2024-05-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "parse.h"
/**
 * @brief Function to record an error message on struct.
 * 
 * @param scene 
 * @param code
 * @see error.h 
 */
void	ft_msg_error(t_scene *scene, char *code)
{
	if (!scene->msg_error)
		scene->msg_error = code;
}
/**
 * @brief Function to free of the scene objects.
 * 
 * @param scene 
 */
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
/**
 * @brief Function to determine the size of a string array.
 * 
 * @param s 
 * @return size_t 
 */
size_t	ft_strlen_2(char **s)
{
	size_t	l;

	l = 0;
	while (s[l] != 0)
		l++;
	return (l);
}
/**
 * @brief Reverse of the strcmp function.
 * 
 * @param s1 
 * @param s2 
 * @param n 
 * @return int 
 */
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
/**
 * @brief Function to free the string array.
 * 
 * @param s 
 */
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
