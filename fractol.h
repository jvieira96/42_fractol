/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <jpedro-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:25:34 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/02/04 17:42:09 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "Libft/libft.h"
# include "mlx_linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define ERROR_MESSAGE "Please enter mandelbrot or julia <value1> <value2>\n"
# define WIDTH 800
# define HEIGTH 800

// COLORS
# define BLACK   0x000000
# define WHITE   0xFFFFFF
# define RED     0xFF0000
# define GREEN   0x00FF00
# define BLUE    0x0000FF
# define YELLOW  0xFFFF0
# define CYAN    0x00FFFF
# define MAGENTA 0xFF00FF
# define ORANGE  0xFFA500
# define PURPLE  0x800080
# define PINK    0xFFC0CB
# define TURQUOISE 0x40E0D0
# define LIME    0x00FF00
# define FUCHSIA 0xFF00FF
# define VIOLET  0x8A2BE2
# define INDIGO  0x4B0082
# define TEAL    0x008080
# define MAGENTA2 0xD100D1
# define LAVENDER 0xE6E6FA

/*
	complex value
*/
typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

/*
IMAGE
	pixels buffer
	values from mlx_get_addr()
 */
typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}			t_img;

/*
FRACTAL ID
	MLX
	Image
	hook values
*/
typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	escaped_value;
	int		iterations_defenition;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}			t_fractal;

// init.c
void		ft_fractal_init(t_fractal *fractal);

// render.c
void		ft_handle_pixel(int x, int y, t_fractal *fractal);
void		ft_julia(int x, int y, t_fractal *fractal);
void		ft_mandelbrot(int x, int y, t_fractal *fractal);
void		ft_fractal_render(t_fractal *fractal);

// math.utils
double		ft_map(double unscaled_num, double new_min,
				double new_max, double old_max);
t_complex	ft_sum_complex(t_complex z1, t_complex z2);
t_complex	ft_square_complex(t_complex	z);
double		ft_atodbl(char	*str, double fractional_part,
				double power, int int_part);

// events
int			ft_key_handle(int keysym, t_fractal *fractal);
int			ft_mouse_handle(int button, int x, int y, t_fractal *fractal);
int			ft_close_handle(t_fractal *fractal);

#endif