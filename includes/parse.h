/**
 * @file parse.h
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief Include file for the parsing functions.
 * @version 0.1
 * @date 2024-05-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef PARSE_H
# define PARSE_H

# include "error.h"
# include "minirt.h"

typedef void			(*t_arr_sc)(t_scene *);

/****************COLOUR************/
bool		ft_is_rgb(int n);
double		ft_normalize_color(double color);
int			ft_rgb_to_int(t_color color);
t_vec3		ft_get_colour(char *str, char *code, t_scene *scene);
t_color		ft_int_to_rgb(int color);

/****************COORDINATES*******/
bool		ft_isdouble(char *str);
int			ft_isnormal(t_vec3 n);
t_vec3		ft_get_coord(char *str, char *code, t_scene *scene);
t_vec3		ft_get_normal(char *str, char *code, t_scene *scene);
int			ft_check_rep_char(char *str, char c);

/****************INT***************/
bool		ft_str_isint(char *str);
int			ft_get_int(char *str, char *code, t_scene *scene);
int			ft_get_posint(char *str, char *code, t_scene *scene);
double		ft_get_fov(char *str, char *code, t_scene *scene);

/****************RATIO**************/
double		ft_atod(const char *str);
double		ft_get_double(char *str, char *code, t_scene *scene);
double		ft_get_ratio(char *str, char *code, t_scene *scene);
double		ft_get_size(char *str, char *code, t_scene *scene);
void		ft_check_lim_color(t_vec3 color, t_scene *scene, char *code);

/****************SCENE*ELEMENTS****/
/*AMBIENT*/
void		get_1_amb(t_scene *scene);
/*CAMERA*/
void		get_2_cam(t_scene *scene);
t_camera	*ft_setup_camera(t_scene *scene);
/*LIGHT*/
void		get_3_light(t_scene *scene);

/****************SCENE*OBJ*********/
/*SPHERE*/
void		get_4_sp(t_scene *scene);
/*PLANE*/
void		get_5_pl(t_scene *scene);
/*CYLINDER*/
void		get_6_cy(t_scene *scene);

/****************SCENE*OBJ*BONUS****/
/*SPHERE*BONUS*/
void		get_4_sp_bonus(t_scene *scene);
/*PLANE*BONUS*/
void		get_5_pl_bonus(t_scene *scene);
/*CYLINDER*BONUS*/
void		get_6_cy_bonus(t_scene *scene);
/*CONE*BONUS*/
void		get_7_co(t_scene *scene);
/*CUBE*BONUS*/
void		get_8_cb(t_scene *scene);
/*TRIANGLE*BONUS*/
void		get_9_tr(t_scene *scene);

/****************SCENE*TRANSF******/
void		ft_sphere_transform(t_shapes *new);
void		ft_plane_transform(t_shapes *new);
void		ft_cylinder_transform(t_shapes *new);

/****************SCENE*TRANSF*BONUS*****/
void		ft_cone_transform(t_shapes *new);
void		ft_cube_transform(t_shapes *new);

/****************PARSE*UTILS*******/
void		ft_msg_error(t_scene *scene, char *code);
void		ft_error(char *msg, t_scene *scene);
size_t		ft_strlen_2(char **s);
int			ft_strnrcmp(const char *s1, const char *s2, size_t n);
void		ft_split_free(char **s);
void		ft_free_all_scene(t_scene *scene);

/****************PARSE*************/
void		ft_scene_check(t_scene *scene, int fd);
void		ft_open_file(char *file, t_scene *scene);
void		ft_error(char *msg, t_scene *scene);

/****************PARSE*BONUS*****/
void		ft_add_lights(t_list **lst, t_light *light);
void		ft_open_file_bonus(char *file, t_scene *scene);
void		ft_get_bonus_list(t_scene *scene, int id);
int			ft_check_bonus_list(t_scene *scene);

void		ft_get_glass(char **split, t_scene *scene);
void		ft_get_patern(char **split, t_scene *scene);
t_style		ft_get_type(char *type, t_scene *scene);
void		ft_get_imgxpm(char **split, t_scene *scene);
void		ft_get_reflective(char **split, t_scene *scene);

void		get_2_cam_bonus(t_scene *scene);

/****************CALLS*************/
int			ft_clamp(int value);

#endif