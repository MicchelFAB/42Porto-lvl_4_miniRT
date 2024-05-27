/**
 * @file mlx_auxiliar.c
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief File with functions to handle the mlx events.(UNUSED)
 * @version 0.1
 * @date 2024-05-24 * 
 * @note This file is part of the MiniRT project.
 * 
 * @copyright Copyright (c) 2024 * 
 */
#include "minirt.h"
#include "minirt_bonus.h"
/**
 * @brief Function to print the key pressed.
 * @param keycode 
 * @param param 
 * @return int 
 */
int	ft_button_print(int keycode, void *param)
{
	(void)param;
	printf("Key pressed hex: %x\n", keycode);
	return (0);
}
/**
 * @brief Function to print the mouse movement coordinates.
 * @param x 
 * @param y 
 * @param prog 
 * @return int 
 */
int	ft_mouse(int x, int y, t_world *prog)
{
	(void)prog;
	printf("Mouse moved to x: %d, y: %d\n", x, y);
	return (0);
}
/**
 * @brief Function to print the mouse click.
 * @param button 
 * @param x 
 * @param y 
 * @param prog 
 * @return int 
 */
int	ft_mouse_click(int button, int x, int y, t_world *prog)
{
	(void)prog;
	printf("Mouse clicked button: %d at x: %d, y: %d\n", button, x, y);
	return (0);
}
/**
 * @brief Function to print the mouse release.
 * @param button 
 * @param x 
 * @param y 
 * @param prog 
 * @return int 
 */
int	ft_mouse_release(int button, int x, int y, t_world *prog)
{
	(void)prog;
	printf("Mouse released button: %d at x: %d, y: %d\n", button, x, y);
	return (0);
}
/**
 * @brief Function to check if the main arguments are valid. For the bonus part.
 * @param ac 
 */
void	ft_check_main_bonus(int ac)
{
	if (ac != 2 || (RATIO < 1 || RATIO > 2) || (WIDTH_B < 50 || WIDTH_B > 1900))
	{
		ft_putstr_fd("\033[1m\033[38;5;199mError\033[0m\n", STDERR_FILENO);
		if (ac != 2)
			ft_putstr_fd("Invalid number of arguments", STDERR_FILENO);
		else if (RATIO < 1 || RATIO > 2)
			ft_putstr_fd("Invalid aspect ratio", STDERR_FILENO);
		else if (WIDTH_B < 50 || WIDTH_B > 1900)
			ft_putstr_fd("Invalid width", STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
