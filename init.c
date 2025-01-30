/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <jpedro-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 23:08:17 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/01/30 23:33:04 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
	IF MALLOC GOES BAD
*/
static void	malloc_error(void)
{
	ft_putstr_fd("Problems with malloc", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

/*
INIT
	mlx
	listneing events
	hooks data
*/
void	ft_fractal_init(t_fractal *fractal)
{
	//MLX connections
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
		malloc_error(); //TODO
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, 
										HEIGTH, fractal->name);
	if (fractal->mlx_window == NULL)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, WIDTH,
										HEIGTH);
	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
}
