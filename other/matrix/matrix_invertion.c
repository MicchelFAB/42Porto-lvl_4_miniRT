/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_invertion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:18:23 by mamaral-          #+#    #+#             */
/*   Updated: 2024/05/10 19:35:59 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

// Returns the minor of a matrix. The minor of an element is the determinant of
// the submatrix that remains after removing the row and column of the element.
double	ft_get_minor(t_matrix a, int row, int col)
{
	t_matrix	submatrix;
	double		determinant;

	submatrix = ft_get_submatrix(a, row, col);
	determinant = ft_get_determinant(submatrix);
	return (determinant);
}

// Returns the cofactor of a matrix. The cofactor of an element is the minor of
// that element multiplied by -1 if the sum of the row and column is odd.
double	ft_get_cofactor(t_matrix a, int row, int col)
{
	double	minor;

	minor = ft_get_minor(a, row, col);
	if ((row + col) % 2 == 0)
		return (minor);
	else
		return (-minor);
}

// Returns the determinant of a matrix.
double	ft_get_determinant(t_matrix a)
{
	int		i;
	double	determinant;

	determinant = 0;
	if (a.rows != a.cols)
		return (0);
	else if (a.rows == 2 && a.cols == 2)
		return (a.data[0][0] * a.data[1][1] - a.data[0][1] * a.data[1][0]);
	else
	{
		i = -1;
		while (++i < a.cols)
			determinant += a.data[0][i] * ft_get_cofactor(a, 0, i);
	}
	return (determinant);
}

// Returns the inverse of a matrix. The inverse of a matrix is the matrix that
// when multiplied by the original matrix gives the identity matrix.
t_matrix	ft_create_invert_matrix(t_matrix a)
{
	int			i;
	int			j;
	t_matrix	m;
	double		cofactor;
	double		determinant;

	i = -1;
	m = ft_create_matrix(a.rows, a.cols, NO);
	determinant = ft_get_determinant(a);
	if (determinant == 0)
		return (ft_create_matrix(0, 0, NO));
	while (++i < a.rows)
	{
		j = -1;
		while (++j < a.cols)
		{
			cofactor = ft_get_cofactor(a, i, j);
			m.data[j][i] = cofactor / ft_get_determinant(a);
		}
	}
	return (m);
}

// Returns true if a matrix is invertible and false otherwise.
bool	ft_is_invertible(t_matrix a)
{
	if (ft_get_determinant(a) == 0)
		return (false);
	return (true);
}
