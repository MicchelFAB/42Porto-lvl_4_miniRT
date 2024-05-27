/**
 * @file matrix_invertion.c
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief File containing the functions to invert a matrix.
 * @version 0.1
 * @date 2024-05-22 * 
 * @note This file is part of the MiniRT project.
 * 
 * @copyright Copyright (c) 2024 * 
 */
#include "matrix.h"
/**
 * @brief Get the minor of a matrix.
 * @param a The matrix.
 * @param row The row.
 * @param col The column.
 * @return double The minor.
 */
double	ft_get_minor(t_matrix a, int row, int col)
{
	t_matrix	submatrix;
	double		determinant;

	submatrix = ft_get_submatrix(a, row, col);
	determinant = ft_get_determinant(submatrix);
	return (determinant);
}
/**
 * @brief Get the cofactor of a matrix.
 * @param a The matrix.
 * @param row The row.
 * @param col The column.
 * @return double The cofactor.
 */
double	ft_get_cofactor(t_matrix a, int row, int col)
{
	double	minor;
	t_matrix	submatrix;

	submatrix = ft_get_submatrix(a, row, col);
	minor = ft_get_determinant(submatrix);
	if ((row + col) % 2 == 0)
		return (minor);
	else
		return (-minor);
}
/**
 * @brief Get the determinant of a matrix.
 * @param a The matrix.
 * @return double The determinant.
 */
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
/**
 * @brief Creates the invert matrix of a matrix.
 * @param a The matrix.
 * @return t_matrix The invert matrix.
 */
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
/**
 * @brief Check if a matrix is invertible.
 * @param a The matrix.
 * @return true If the matrix is invertible.\
 * @return false If the matrix is not invertible.
 */
bool	ft_is_invertible(t_matrix a)
{
	if (ft_get_determinant(a) == 0)
		return (false);
	return (true);
}
