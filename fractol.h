/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <jpedro-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:25:34 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/02/01 17:01:08 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FRACTOL_H
# define FRACTOL_H

# include "Libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <X11/keysym.h>
# include <X11/X.h>

#define ERROR_MESSAGE "Please enter a valid input"
#define WIDTH 800
#define HEIGTH 800

// COLORS
#define BLACK   0x000000  // Black
#define WHITE   0xFFFFFF  // White
#define RED     0xFF0000  // Bright Red
#define GREEN   0x00FF00  // Bright Green
#define BLUE    0x0000FF  // Bright Blue
#define YELLOW  0xFFFF00  // Bright Yellow
#define CYAN    0x00FFFF  // Cyan
#define MAGENTA 0xFF00FF  // Magenta
#define ORANGE  0xFFA500  // Orange
#define PURPLE  0x800080  // Purple
#define PINK    0xFFC0CB  // Pink
#define TURQUOISE 0x40E0D0 // Turquoise
#define LIME    0x00FF00  // Lime
#define FUCHSIA 0xFF00FF  // Fuchsia
#define VIOLET  0x8A2BE2  // Violet
#define INDIGO  0x4B0082  // Indigo
#define TEAL    0x008080  // Teal
#define MAGENTA2 0xD100D1  // Neon Magenta
#define LAVENDER 0xE6E6FA  // Lavender

/*
	complex value
*/
typedef struct s_complex
{
	// real number
	double	x;
	// imaginary i
	double	y;
}	t_complex;

/*
IMAGE
	pixels buffer
	values from mlx_get_addr()
 */
typedef struct s_img
{
	void	*img_ptr; // pointer to image struct
	char	*pixels_ptr; // points to the pixel
	int		bpp; // bits per pixel
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
	//MLX
	void	*mlx_connection; // mlx_init()
	void	*mlx_window; // mlx_new_window()
	//IMAGE
	t_img	img;
	//Hooks member variables
	double	escaped_value; // hypotenuse
	int		iterations_defenition; // value tight with image quality and rendering speed 
	double	shift_x;
	double	shift_y;
}			t_fractal;

// init.c
void	ft_fractal_init(t_fractal *fractal);

// render.c
void	ft_handle_pixel(int x, int y, t_fractal *fractal);
void	ft_fractal_render(t_fractal *fractal);


// math.utils
double	ft_map(double unscaled_num, double new_min, double new_max, double old_max);
t_complex	ft_sum_complex(t_complex z1, t_complex z2);
t_complex	ft_square_complex(t_complex	z);

// events
int	ft_key_handle(int keysym, t_fractal *fractal);
int	ft_close_handle(t_fractal *fractal);

#endif