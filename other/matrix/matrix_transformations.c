/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transformations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmonteir <bmonteir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:19:06 by mamaral-          #+#    #+#             */
/*   Updated: 2024/05/14 12:29:06 by bmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

// Creates a matrix that moves points in space. Having w = 0 makes sure that
// vectors are not affected by translation.
t_matrix	ft_create_translation_matrix(double x, double y, double z)
{
	t_matrix	m;

	m = ft_create_matrix(4, 4, YES);
	m.data[0][3] = x;
	m.data[1][3] = y;
	m.data[2][3] = z;
	return (m);
}

// Creates a matrix that enlarges or shrinks points in space.
t_matrix	ft_create_scaling_matrix(double x, double y, double z)
{
	t_matrix	m;

	m = ft_create_matrix(4, 4, YES);
	m.data[0][0] = x;
	m.data[1][1] = y;
	m.data[2][2] = z;
	return (m);
}

// Creates a matrix that rotates points in space. The angle is in radians.
t_matrix	ft_create_rotation_matrix(char axis, double r)
{
	t_matrix	m;

	m = ft_create_matrix(4, 4, YES);
	if (axis == 'x')
	{
		m.data[1][1] = cos(r);
		m.data[1][2] = -sin(r);
		m.data[2][1] = sin(r);
		m.data[2][2] = cos(r);
	}
	else if (axis == 'y')
	{
		m.data[0][0] = cos(r);
		m.data[0][2] = sin(r);
		m.data[2][0] = -sin(r);
		m.data[2][2] = cos(r);
	}
	else if (axis == 'z')
	{
		m.data[0][0] = cos(r);
		m.data[0][1] = -sin(r);
		m.data[1][0] = sin(r);
		m.data[1][1] = cos(r);
	}
	return (m);
}

t_matrix	ft_view_transform_matrix(t_point from, t_point to, t_vec3 up)
{
	t_vec3		forward;
	t_vec3		upn;
	t_vec3		left;
	t_vec3		true_up;
	t_matrix	orientation;

	upn = ft_normalize(up);
	forward = ft_normalize(ft_operations(to, '-', from));
	left = ft_cross(forward, upn);
	true_up = ft_cross(left, forward);
	orientation = ft_create_matrix(4, 4, NO);
	orientation.data[0][0] = left.x;
	orientation.data[0][1] = left.y;
	orientation.data[0][2] = left.z;
	orientation.data[1][0] = true_up.x;
	orientation.data[1][1] = true_up.y;
	orientation.data[1][2] = true_up.z;
	orientation.data[2][0] = -forward.x;
	orientation.data[2][1] = -forward.y;
	orientation.data[2][2] = -forward.z;
	orientation.data[3][3] = 1;
	return (ft_multiply_matrix(orientation,
			ft_create_translation_matrix(-from.x, -from.y, -from.z)));
}
