/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_auxiliar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:41:44 by mamaral-          #+#    #+#             */
/*   Updated: 2024/05/19 19:38:18 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "minirt_bonus.h"

int	ft_button_print(int keycode, void *param)
{
	(void)param;
	printf("Key pressed hex: %x\n", keycode);
	return (0);
}

int	ft_mouse(int x, int y, t_world *prog)
{
	(void)prog;
	printf("Mouse moved to x: %d, y: %d\n", x, y);
	return (0);
}

int	ft_mouse_click(int button, int x, int y, t_world *prog)
{
	(void)prog;
	printf("Mouse clicked button: %d at x: %d, y: %d\n", button, x, y);
	return (0);
}

int	ft_mouse_release(int button, int x, int y, t_world *prog)
{
	(void)prog;
	printf("Mouse released button: %d at x: %d, y: %d\n", button, x, y);
	return (0);
}

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
