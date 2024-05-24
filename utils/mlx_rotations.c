/**
 * @file mlx_rotations.c
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief FIle with functions to handle the mlx events.
 * @version 0.1
 * @date 2024-05-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "utils.h"
/**
 * @brief Function that rotates the camera according to the key pressed.
 * 
 * @param cam 
 * @return t_matrix 
 */
t_matrix	ft_rotate_camera(t_world *cam)
{
	t_matrix	tra;

	tra = cam->camera->transform;
	if (cam->key.row4.a)
		tra = ft_multiply_matrix(tra, ft_create_rotation_matrix('y', -M_PI_4 / 4));
	else if (cam->key.row4.d)
		tra = ft_multiply_matrix(tra, ft_create_rotation_matrix('y', M_PI_4 / 4));
	if (cam->key.row3.w)
		tra = ft_multiply_matrix(tra, ft_create_rotation_matrix('x', -M_PI_4 / 4));
	else if (cam->key.row4.s)
		tra = ft_multiply_matrix(tra, ft_create_rotation_matrix('x', M_PI_4 / 4));
	if (cam->key.row3.q)
		tra = ft_multiply_matrix(tra, ft_create_rotation_matrix('z', -M_PI_4 / 4));
	else if (cam->key.row3.e)
		tra = ft_multiply_matrix(tra, ft_create_rotation_matrix('z', M_PI_4 / 4));
	return (tra);
}
/**
 * @brief Function that moves the camera according to the key pressed.
 * 
 * @param cam 
 * @return t_matrix 
 */
t_matrix	ft_move_camera(t_world *cam)
{
	t_matrix	tra;

	tra = cam->camera->transform;
	if (cam->key.row5.up)
		tra = ft_multiply_matrix(tra, ft_create_translation_matrix(0, 0, -1));
	else if (cam->key.row6.down)
		tra = ft_multiply_matrix(tra, ft_create_translation_matrix(0, 0, 1));
	if (cam->key.row6.left)
		tra = ft_multiply_matrix(tra, ft_create_translation_matrix(1, 0, 0));
	else if (cam->key.row6.right)
		tra = ft_multiply_matrix(tra, ft_create_translation_matrix(-1, 0, 0));
	if (cam->key.row2.plus)
		tra = ft_multiply_matrix(tra, ft_create_translation_matrix(0, 1, 0));
	else if (cam->key.row2.minus)
		tra = ft_multiply_matrix(tra, ft_create_translation_matrix(0, -1, 0));
	return (tra);
}
/**
 * @brief Function to handle the keys pressed.
 * 
 * @param prog 
 * @return t_matrix 
 */
t_matrix	ft_handdle_keys(t_world *prog)
{
	if (prog->key.row4.a || prog->key.row4.d || prog->key.row3.w
		|| prog->key.row4.s || prog->key.row3.q || prog->key.row3.e)
		return (ft_rotate_camera(prog));
	else if (prog->key.row5.up || prog->key.row6.down || prog->key.row6.left
		|| prog->key.row6.right || prog->key.row2.plus || prog->key.row2.minus)
		return (ft_move_camera(prog));
	else if (prog->key.row3.r)
		return (prog->zero->transform);
	return ((t_matrix){0});
}
/**
 * @brief Function to handle the key press.
 */
void	ft_button_down2(t_world *img, int keycode)
{
	if (keycode == KEY_UP)
		img->key.row5.up = 1;
	else if (keycode == KEY_DOWN)
		img->key.row6.down = 1;
	if (keycode == KEY_LEFT)
		img->key.row6.left = 1;
	else if (keycode == KEY_RIGHT)
		img->key.row6.right = 1;
	if (keycode == KEY_PLUS)
		img->key.row2.plus = 1;
	else if (keycode == KEY_MINUS)
		img->key.row2.minus = 1;
}
/**
 * @brief Function to handle the key press.
 * 
 * @param img 
 * @param keycode 
 */
void	ft_button_down(t_world *img, int keycode)
{
	img->key.status_key = 1;
	if (keycode == KEY_W)
		img->key.row3.w = 1;
	else if (keycode == KEY_S)
		img->key.row4.s = 1;
	if (keycode == KEY_A)
		img->key.row4.a = 1;
	else if (keycode == KEY_D)
		img->key.row4.d = 1;
	if (keycode == KEY_Q)
		img->key.row3.q = 1;
	else if (keycode == KEY_E)
		img->key.row3.e = 1;
	else if (keycode == KEY_R)
		img->key.row3.r = 1;
	else
		ft_button_down2(img, keycode);
}
