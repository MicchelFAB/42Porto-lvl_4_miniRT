/**
 * @file utils.h
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief Include file for the utils functions.
 * @version 0.1
 * @date 2024-05-22 * 
 * @note This file is part of the MiniRT project.
 * 
 * @copyright Copyright (c) 2024 * 
 */
#ifndef UTILS_H
# define UTILS_H

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "minirt.h"
# include "minirt_bonus.h"
# include "structs.h"

/**********END*PROGRAM***********/
t_list		*ft_lst_last(t_list *lst);
void		ft_free_list(t_list **lst);
void		ft_free_intersections(t_intersections **lst);
void		ft_free_all_allocated_memory(t_world *prog);
int			ft_close(t_world *prog);

/**********MLX*AUXILIAR**********/
int			ft_button_print(int keycode, void *param);
int			ft_mouse(int x, int y, t_world *prog);
int			ft_mouse_click(int button, int x, int y, t_world *prog);
int			ft_mouse_release(int button, int x, int y, t_world *prog);
void		ft_check_main_bonus(int ac);

/**********MLX*HOOK**************/
int			ft_esc(int keycode, t_world *img);
void		ft_set_hooks(t_world *prog);
int			ft_button_press(int keycode, t_world *img);
int			ft_button_release(int keycode, t_world *img);
int			ft_release_aux(int keycode, t_world *img);

/**********MLX*ROTATION**********/
t_matrix	ft_rotate_camera(t_world *cam);
t_matrix	ft_move_camera(t_world *cam);
t_matrix	ft_handdle_keys(t_world *prog);
void		ft_button_down(t_world *img, int keycode);

/**********MLX*UTILS*************/
void		ft_mlx_pixel_put(t_image *data, int x, int y, t_color color);
void		ft_panel_window(t_image *data, int x, int y, t_color **color);
void		ft_panel_render(t_image *d, t_point up_lft, t_point dw_rht,
				t_color **c);
void		ft_open_window(t_world *prog);

/**********MLX*UTILS*BONUS*******/
void		ft_set_hooks_bonus(t_world *prog);
int			ft_update(void *wrd);
void		ft_open_window_bonus(t_world *prog);

#endif