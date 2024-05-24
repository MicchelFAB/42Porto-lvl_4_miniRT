/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmonteir <bmonteir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:37:16 by mamaral-          #+#    #+#             */
/*   Updated: 2024/05/11 19:38:11 by bmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHS_H
# define MATHS_H

# include <stdbool.h>
# include "structs.h"
# define EPSILON 0.00001

/**********VECTOR*CRIATION**********/

t_vec3		ft_tuple(double x, double y, double z, double w);
t_vec3		ft_color(double r, double g, double b);
t_vec3		ft_point(double x, double y, double z);
t_vec3		ft_vector(double x, double y, double z);

/**********VECTOR*OPERATIONS********/
t_vec3		ft_operations(t_vec3 a, char op, t_vec3 b);
t_vec3		ft_oper_specular(t_vec3 a, char op, double b);
double		ft_dot(t_vec3 a, t_vec3 b);
t_vec3		ft_cross(t_vec3 a, t_vec3 b);
bool		ft_double_compare(double a, double b);

/**********VECTOR*OPER*ADITIONAL**/
t_vec3		ft_negate(t_vec3 vec);
double		ft_length(t_vec3 vec);
t_vec3		ft_normalize(t_vec3 vec);

#endif
