/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <jpedro-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:25:34 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/01/30 23:47:35 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FRACTOL_H
# define FRACTOL_H

#include "Libft/libft.h"
#include "minilibx-linux/mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#define ERROR_MESSAGE "Please enter a valid input"
#define WIDTH 800
#define HEIGTH 800

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
}			t_fractal;

// init.c
void	ft_fractal_init(t_fractal *fractal);

// render.c
void	ft_handle_pixel(int x, int y, t_fractal *fractal);
void	ft_fractal_render(t_fractal *fractal);


// math.utils
double	ft_map(double unscaled_num, double new_min, double new_max, 
			double old_min, double old_max);
			
#endif