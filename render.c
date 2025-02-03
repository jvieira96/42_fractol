/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <jpedro-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 23:34:17 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/02/03 18:30:04 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
	put a pixel in the image buffr
*/
static void	ft_my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

/*
	JULIA
	./factol julia <real> <>
	z = pixel_pointer + constant->real
*/
void	ft_julia(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	// first iteration
	z.x = (ft_map(x, -2, 2, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.y = (ft_map(y, 2, -2, HEIGTH) * fractal->zoom) + fractal->shift_y;
	// pixel coordinate (x,y) scaled to fit mandelbrot needs
	c.x = fractal->julia_x;
	c.y = fractal->julia_y;
	// how many times we want to iterate z^2 + c to see if scapes to infinity
	// this value will define the image quality
	while (i < fractal->iterations_defenition)
	{
		z = ft_sum_complex(ft_square_complex(z), c);
		// the value escaped ?
		// if hypotenuse > 2 i assume the pixel escaped
		// pythagrean theorem a^2 + b^2 = c^2
		if ((z.x * z.x) + (z.y * z.y) > fractal->escaped_value)
		{
			color = ft_map(i, BLACK, WHITE, fractal->iterations_defenition);
			ft_my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
	ft_my_pixel_put(x, y, &fractal->img, BLACK);
}

/*
	MANDELBROT
	z = z^2 + c
	z in the first iteration is (0,0)
	c is the actual pixel
*/
void	ft_mandelbrot(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	// first iteration
	z.x = 0.0;
	z.y = 0.0;
	// pixel coordinate (x,y) scaled to fit mandelbrot needs
	c.x = (ft_map(x, -2, 2, WIDTH) * fractal->zoom) + fractal->shift_x;
	c.y = (ft_map(y, 2, -2, HEIGTH) * fractal->zoom) + fractal->shift_y;
	// how many times we want to iterate z^2 + c to see if scapes to infinity
	// this value will define the image quality
	while (i < fractal->iterations_defenition)
	{
		z = ft_sum_complex(ft_square_complex(z), c);
		// the value escaped ?
		// if hypotenuse > 2 i assume the pixel escaped
		// pythagrean theorem a^2 + b^2 = c^2
		if ((z.x * z.x) + (z.y * z.y) > fractal->escaped_value)
		{
			color = ft_map(i, BLACK, WHITE, fractal->iterations_defenition);
			ft_my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
	ft_my_pixel_put(x, y, &fractal->img, BLACK);
}

void	ft_fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGTH)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (!ft_strncmp(fractal->name, "mandelbrot", 10))
				ft_mandelbrot(x, y, fractal);
			else
				ft_julia(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_connection, 
							fractal->mlx_window,
							fractal->img.img_ptr, 0, 0);
}