/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:39:30 by mamaral-          #+#    #+#             */
/*   Updated: 2024/05/20 11:04:24 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_BONUS_H
# define MINIRT_BONUS_H

# define THREADS	16
# define WIDTH_B	1024

# include "minirt.h"
# include "utils.h"
# include <pthread.h>

typedef struct s_context
{
	int		num_threads;
	t_world	*image;
	int		initial_height;
	int		final_height;
}	t_context;

void		ft_open_file_bonus(char *file, t_scene *scene);
void		ft_render_bonus_thread(t_context *fun);
void		ft_start_thread(t_world *scene);

#endif