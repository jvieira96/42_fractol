/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <jpedro-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:15:08 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/02/01 17:09:00 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
	Esc or press x in window to exit
	prototype : int (*f)(void *param)
*/
int	ft_close_handle(t_fractal *fractal)
{
		mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		exit(EXIT_SUCCESS);
}

/*
	Keypress prototype
	int (*f)(int keycode, void *param)
*/
int	ft_key_handle(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		ft_close_handle(fractal);
	else if (keysym == XK_Left)
		fractal->shift_x += 0.5;
	else if (keysym == XK_Right)
		fractal->shift_x -= 0.5;
	else if (keysym == XK_Up)
		fractal->shift_y += 0.5;
	else if (keysym == XK_Down)
		fractal->shift_y -= 0.5;
	else if (keysym == XK_0)
		fractal->iterations_defenition += 10;
	else if (keysym == XK_minus)
		fractal->iterations_defenition -= 10;
	// refresh the image
	ft_fractal_render(fractal);
	return (0);
}