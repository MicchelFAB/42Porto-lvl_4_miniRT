/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:56:13 by bmonteir          #+#    #+#             */
/*   Updated: 2024/05/13 11:47:59 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules.h"

void	ft_intersect(t_intersections **i, t_shapes *s, t_ray r)
{
	t_ray	ray;

	ray = ft_transform_ray(r, s->inverted);
	if (s->type == SPHERE)
		ft_sphere_intersections(i, s, ray);
	if (s->type == PLANE)
		ft_plane_intersections(i, s, ray);
	if (s->type == CYLINDER)
		ft_cylinder_intersections(i, s, ray);
}

// Creates (with malloc) a new intersection.
t_intersection	*ft_create_intersection(double t, t_shapes *s)
{
	t_intersection	*i;

	i = malloc(sizeof(t_intersection));
	if (!i)
		return (NULL);
	i->t = t;
	i->object = s;
	return (i);
}

// Adds the intersection to the intersections list in a sorted way.
void	ft_add_sorted_intersection(t_intersections **lst, t_shapes *s, double t)
{
	t_intersections	*new;
	t_intersections	*tmp;
	t_intersection	*i;

	i = ft_create_intersection(t, s);
	new = ft_lstnew(i);
	if (!*lst)
		*lst = new;
	else
	{
		tmp = *lst;
		if (((t_intersection *)tmp->content)->t > t)
		{
			new->next = tmp;
			*lst = new;
		}
		else
		{
			while (tmp->next && ((t_intersection *)tmp->next->content)->t < t)
				tmp = tmp->next;
			new->next = tmp->next;
			tmp->next = new;
		}
	}
}

// Returns the intersection with the smallest positive t value. The hit is the
// intersection that is closest to the ray origin.
t_intersection	*ft_hit(t_intersections *i)
{
	t_intersection	*hit;

	hit = NULL;
	while (i)
	{
		if (((t_intersection *)i->content)->t - EPSILON > 0)
		{
			if (!hit || ((t_intersection *)i->content)->t < hit->t)
				hit = i->content;
		}
		i = i->next;
	}
	return (hit);
}
