/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmonteir <bmonteir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 19:27:05 by bmonteir          #+#    #+#             */
/*   Updated: 2024/05/11 19:38:06 by bmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_MAP_H
# define KEY_MAP_H

// . -------------------------------------------------------------------.
// | [Esc] [F1][F2][F3][F4][F5][F6][F7][F8][F9][F0][F10][F11][F12] o o o|
// |                                                                    |
// | [`][1][2][3][4][5][6][7][8][9][0][-][=][_<_] [I][H][U] [N][/][*][-]|
// | [|-][Q][W][E][R][T][Y][U][I][O][P][{][}][\ ] [D][E][D] [7][8][9]|+||
// | [CAP][A][S][D][F][G][H][J][K][L][;]['][ENTE]           [4][5][6]|_||
// | [^][\][Z][X][C][V][B][N][M][,][.][/] [__^__]    [^]    [1][2][3]| ||
// | [c]   [a][________________________][a]   [c] [<][V][>] [ 0  ][.]|_||
// `--------------------------------------------------------------------'

// DEFINES ---------------------------------------------------------------------
// | [Esc] [F1][F2][F3][F4][F5][F6][F7][F8][F9][F0][F10][F11][F12] o o o|
# define KEY_ESC	0xff1b
# define KEY_F1		0xffbe
# define KEY_F2		0xffbf
# define KEY_F3		0xffc0
# define KEY_F4		0xffc1
# define KEY_F5		0xffc2
# define KEY_F6		0xffc3
# define KEY_F7		0xffc4
# define KEY_F8		0xffc5
# define KEY_F9		0xffc6
# define KEY_F10	0xffc7
# define KEY_F11	0xffc8
# define KEY_F12	0xffc9

// | [`][1][2][3][4][5][6][7][8][9][0][-][=][_<_] [I][H][U] [N][/][*][-]|
# define KEY_TIL	0x60
# define KEY_1		0x31
# define KEY_2		0x32
# define KEY_3		0x33
# define KEY_4		0x34
# define KEY_5		0x35
# define KEY_6		0x36
# define KEY_7		0x37
# define KEY_8		0x38
# define KEY_9		0x39
# define KEY_0		0x30
# define KEY_MINUS	0x2d
# define KEY_PLUS	0x3d
# define KEY_BKSP	0xff08
# define KEY_INS	0xff63
# define KEY_HOME	0xff50
# define KEY_PGUP	0xff55
# define KEY_N_LCK	0xff7f
# define KEY_N_SLA	0xffaf
# define KEY_N_AST	0xffaa
# define KEY_N_MIN	0xffad

// | [|-][Q][W][E][R][T][Y][U][I][O][P][{][}][\ ] [D][E][D] [7][8][9]|+||
# define KEY_TAB	0xff09
# define KEY_Q		0x71
# define KEY_W		0x77
# define KEY_E		0x65
# define KEY_R		0x72
# define KEY_T		0x74
# define KEY_Y		0x79
# define KEY_U		0x75
# define KEY_I		0x69
# define KEY_O		0x6f
# define KEY_P		0x70
# define KEY_OBRA	0x5b
# define KEY_CBRA	0x5d
# define KEY_BKSL	0x5c
# define KEY_DEL	0xffff
# define KEY_END	0xff57
# define KEY_PGDN	0xff56
# define KEY_N_7	0xff95
# define KEY_N_8	0xff97
# define KEY_N_9	0xff9a
# define KEY_N_PLU	0xffab

// | [CAP][A][S][D][F][G][H][J][K][L][;]['][ENTE] [4][5][6]|_||
# define KEY_CAPS	0xffe5
# define KEY_A		0x61
# define KEY_S		0x73
# define KEY_D		0x64
# define KEY_F		0x66
# define KEY_G		0x67
# define KEY_H		0x68
# define KEY_J		0x6a
# define KEY_K		0x6b
# define KEY_L		0x6c
# define KEY_COL	0x3b
# define KEY_QUOT	0x27
# define KEY_ENT	0xff0d
# define KEY_N_4	0xff96
# define KEY_N_5	0xff9d
# define KEY_N_6	0xff98

// | [^][\][Z][X][C][V][B][N][M][,][.][/] [__^__] [^] [1][2][3]| ||
# define KEY_L_SHFT	0xffe1
# define KEY_Z		0x7a
# define KEY_X		0x78
# define KEY_C		0x63
# define KEY_V		0x76
# define KEY_B		0x62
# define KEY_N		0x6e
# define KEY_M		0x6d
# define KEY_LTS	0x2c
# define KEY_GTS	0x2e
# define KEY_BKLS	0x2f
# define KEY_R_SHFT	0xffe2
# define KEY_UP		0xff52
# define KEY_N_1	0xff9c
# define KEY_N_2	0xff99
# define KEY_N_3	0xff9b
# define KEY_N_ENT	0xff8d

// | [c] [a][________________________][a] [m][c] [<][V][>][	0 ][.]|_||
# define KEY_L_CTRL	0xffe3
# define KEY_L_ALT	0xffe9
# define KEY_SPACE	0x20
# define KEY_R_ALT	0xffea
# define KEY_MENU	0xff67
# define KEY_R_CTRL	0xffe4
# define KEY_LEFT	0xff51
# define KEY_DOWN	0xff54
# define KEY_RIGHT	0xff53
# define KEY_N_0	0xff9e
# define KEY_N_DOT	0xff9f

typedef struct s_row1
{
	int		esc;
	int		f1;
	int		f2;
	int		f3;
	int		f4;
	int		f5;
	int		f6;
	int		f7;
	int		f8;
	int		f9;
	int		f10;
	int		f11;
	int		f12;
}	t_row1;

typedef struct s_row2
{
	int		tilde;
	int		one;
	int		two;
	int		three;
	int		four;
	int		five;
	int		six;
	int		seven;
	int		eight;
	int		nine;
	int		zero;
	int		minus;
	int		plus;
	int		backspace;
	int		insert;
	int		home;
	int		pgup;
	int		n_lck;
	int		n_sla;
	int		n_ast;
	int		n_min;
}	t_row2;

typedef struct s_row3
{
	int		tab;
	int		q;
	int		w;
	int		e;
	int		r;
	int		t;
	int		y;
	int		u;
	int		i;
	int		o;
	int		p;
	int		o_bra;
	int		c_bra;
	int		bksl;
	int		del;
	int		end;
	int		pgdn;
	int		n7;
	int		n8;
	int		n9;
	int		nplu;
}	t_row3;

typedef struct s_row4
{
	int		caps;
	int		a;
	int		s;
	int		d;
	int		f;
	int		g;
	int		h;
	int		j;
	int		k;
	int		l;
	int		col;
	int		quot;
	int		enter;
	int		n4;
	int		n5;
	int		n6;
}	t_row4;

typedef struct s_row5
{
	int		l_shft;
	int		z;
	int		x;
	int		c;
	int		v;
	int		b;
	int		n;
	int		m;
	int		lts;
	int		gts;
	int		bkls;
	int		r_shft;
	int		up;
	int		n1;
	int		n2;
	int		n3;
	int		nent;
}	t_row5;

typedef struct s_row6
{
	int		l_ctrl;
	int		l_alt;
	int		space;
	int		r_alt;
	int		menu;
	int		r_ctrl;
	int		left;
	int		down;
	int		right;
	int		n0;
	int		n_dot;
}	t_row6;
typedef struct s_key_map
{
	int		status_key;
	t_row1	row1;
	t_row2	row2;
	t_row3	row3;
	t_row4	row4;
	t_row5	row5;
	t_row6	row6;
}	t_key_map;

#endif

/* Complementary Functions

int	ft_update(void *unused)
{
    t_world	*w;
	int	height;

    w = (t_world *)unused;
	height = WIDTH / RATIO;
    // Destroy the old image
    mlx_destroy_image(w->mlx, w->img.img);

    // Create a new image
    w->img.img = mlx_new_image(w->mlx, WIDTH, height);
    w->img.addr = mlx_get_data_addr(w->img.img, &w->img.bpp,
			&w->img.line_length, &w->img.endian);

    ft_crazy_clock(w);
    mlx_put_image_to_window(w->mlx, w->win, w->img.img, 0, 0);
	usleep(100000);
    return (0);
}

void	ft_draw_world(t_world *w)
{
	// t_vec3	v;
	// int		height;

	// height = WIDTH / RATIO;
	// v = (t_vec3){WIDTH, height, 0, 0};
	// ft_projectile(w, v);
	mlx_loop_hook(w->mlx, ft_update, w);
	mlx_loop(w->mlx);
}

t_vec3	ft_multiply_matrix_tuple(t_matrix a, t_vec3 b)
{
	t_matrix	m;

	m = ft_create_matrix(4, 1, NO);
	m.data[0][0] = b.x;
	m.data[1][0] = b.y;
	m.data[2][0] = b.z;
	m.data[3][0] = b.w;
	m = ft_multiply_matrix(a, m);
	if (m.data[3][0] != 0)
		return ((t_vec3){m.data[0][0] / m.data[3][0], m.data[1][0]
			/ m.data[3][0], m.data[2][0] / m.data[3][0], 1});
	else
		return ((t_vec3){m.data[0][0], m.data[1][0], m.data[2][0], 0});
}

 */