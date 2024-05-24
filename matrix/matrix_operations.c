/**
 * @file matrix_operations.c
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief File containing the matrix operations.
 * @version 0.1
 * @date 2024-05-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "matrix.h"
/**
 * @brief Creates a matrix.
 * 
 * @param rows The number of rows.
 * @param cols The number of columns.
 * @param identity_matrix If the matrix is an identity matrix.
 * @return t_matrix The created matrix.
 */
t_matrix	ft_create_matrix(int rows, int cols, bool identity_matrix)
{
	int			i;
	int			j;
	t_matrix	m;

	i = 0;
	m = (t_matrix){0};
	m.rows = rows;
	m.cols = cols;
	if (rows > MATRIX_SIZE || cols > MATRIX_SIZE || (identity_matrix
			&& rows != cols))
		return (ft_create_matrix(0, 0, NO));
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (identity_matrix && i == j)
				m.data[i][j] = 1;
			else
				m.data[i][j] = 0;
			j++;
		}
		i++;
	}
	return (m);
}
/**
 * @brief Multiplies two matrices.
 * 
 * @param a The first matrix.
 * @param b The second matrix.
 * @return t_matrix The multiplied matrix.
 */
t_matrix	ft_multiply_matrix(t_matrix a, t_matrix b)
{
	int			i;
	int			j;
	int			k;
	double		s;
	t_matrix	m;

	i = -1;
	m = ft_create_matrix(a.rows, b.cols, NO);
	if (a.cols != b.rows)
		return (ft_create_matrix(0, 0, NO));
	while (++i < a.rows)
	{
		j = -1;
		while (++j < b.cols)
		{
			s = 0;
			k = -1;
			while (++k < a.cols)
				s += a.data[i][k] * b.data[k][j];
			m.data[i][j] = s;
		}
	}
	return (m);
}
/**
 * @brief Multiplies a matrix by a tuple.
 * 
 * @param a The matrix.
 * @param b The tuple.
 * @return t_vec3 The multiplied tuple.
 */
t_vec3	ft_multiply_matrix_tuple(t_matrix a, t_vec3 b)
{
	t_vec3	result;

	result.x = a.data[0][0] * b.x + a.data[0][1] * b.y + a.data[0][2] * b.z
		+ a.data[0][3] * b.w;
	result.y = a.data[1][0] * b.x + a.data[1][1] * b.y + a.data[1][2] * b.z
		+ a.data[1][3] * b.w;
	result.z = a.data[2][0] * b.x + a.data[2][1] * b.y + a.data[2][2] * b.z
		+ a.data[2][3] * b.w;
	result.w = a.data[3][0] * b.x + a.data[3][1] * b.y + a.data[3][2] * b.z
		+ a.data[3][3] * b.w;
	return (result);
}
/**
 * @brief Transposes a matrix.
 * 
 * @param a The matrix.
 * @return t_matrix The transposed matrix.
 */
t_matrix	ft_transpose_matrix(t_matrix a)
{
	int			i;
	int			j;
	t_matrix	m;

	i = -1;
	m = ft_create_matrix(a.cols, a.rows, NO);
	while (++i < a.rows)
	{
		j = -1;
		while (++j < a.cols)
			m.data[j][i] = a.data[i][j];
	}
	return (m);
}
/**
 * @brief Compares two matrices.
 * 
 * @param a The first matrix.
 * @param b The second matrix.
 * @return bool True if the matrices are equal, false otherwise.
 */
bool	ft_matrix_compare(t_matrix a, t_matrix b)
{
	int	i;
	int	j;

	if (a.rows != b.rows || a.cols != b.cols)
		return (false);
	i = -1;
	while (++i < a.rows)
	{
		j = -1;
		while (++j < a.cols)
		{
			if (!ft_double_compare(a.data[i][j], b.data[i][j]))
				return (false);
		}
	}
	return (true);
}
