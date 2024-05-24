/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmonteir <bmonteir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:52:22 by bmonteir          #+#    #+#             */
/*   Updated: 2024/05/11 19:38:08 by bmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_plane_intersections(t_intersections **i, t_shapes *p, t_ray r)
{
	double	t;

	if (fabs(r.direction.y) < EPSILON || ft_double_compare(0.0, r.direction.y))
		return ;
	t = -r.origin.y / r.direction.y;
	ft_add_sorted_intersection(i, p, t);
}
