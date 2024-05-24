/**
 * @file mlx_hook.c
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief File with functions to handle the mlx events.
 * @version 0.1
 * @date 2024-05-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "utils.h"
/**
 * @brief Function to close the program. If the ESC key is pressed.
 * 
 * @param keycode 
 * @param img 
 * @return int 
 */
int	ft_esc(int keycode, t_world *img)
{
	if (keycode == KEY_ESC)
		ft_close(img);
	return (0);
}
/**
 * @brief Function to handdle the close event.
 * 
 * @param prog 
 */
void	ft_set_hooks(t_world *prog)
{
	mlx_hook(prog->win, KeyPress, KeyPressMask, ft_esc, prog);
	mlx_hook(prog->win, DestroyNotify, ButtonPressMask, ft_close, prog);
}
/**
 * @brief Function to handle the key pressed.
 * 
 * @param keycode 
 * @param img 
 * @return int 
 */
int	ft_button_press(int keycode, t_world *img)
{
	if (keycode == KEY_ESC)
		ft_close(img);
	else if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S
		|| keycode == KEY_D || keycode == KEY_Q || keycode == KEY_E
		|| keycode == KEY_R || keycode == KEY_UP || keycode == KEY_DOWN
		|| keycode == KEY_LEFT || keycode == KEY_RIGHT || keycode == KEY_PLUS
		|| keycode == KEY_MINUS)
		ft_button_down(img, keycode);
	return (0);
}
/**
 * @brief Function to handle the key release.
 * 
 * @param keycode 
 * @param img 
 */
void	ft_button_release2(int keycode, t_world *img)
{
	if (keycode == KEY_UP)
		img->key.row5.up = 0;
	else if (keycode == KEY_DOWN)
		img->key.row6.down = 0;
	if (keycode == KEY_LEFT)
		img->key.row6.left = 0;
	else if (keycode == KEY_RIGHT)
		img->key.row6.right = 0;
	if (keycode == KEY_PLUS)
		img->key.row2.plus = 0;
	else if (keycode == KEY_MINUS)
		img->key.row2.minus = 0;
}
/**
 * @brief Function to handle the key release.
 * 
 * @param keycode 
 * @param img 
 * @return int 
 */
int	ft_button_release(int keycode, t_world *img)
{
	img->key.status_key = 0;
	if (keycode == KEY_W)
		img->key.row3.w = 0;
	else if (keycode == KEY_A)
		img->key.row4.a = 0;
	if (keycode == KEY_S)
		img->key.row4.s = 0;
	else if (keycode == KEY_D)
		img->key.row4.d = 0;
	if (keycode == KEY_Q)
		img->key.row3.q = 0;
	else if (keycode == KEY_E)
		img->key.row3.e = 0;
	else if (keycode == KEY_R)
		img->key.row3.r = 0;
	ft_button_release2(keycode, img);
	return (0);
}
