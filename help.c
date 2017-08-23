/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 13:46:58 by cjacquet          #+#    #+#             */
/*   Updated: 2017/08/20 19:23:00 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_help(t_env *env)
{
	int	d;
	int	h;

	d = 2;
	h = W_HEIGHT + 100;
	mlx_put_image_to_window(env->mlx, env->win, env->img_b, -120, h - 200);
	mlx_put_image_to_window(env->mlx, env->win, env->img_b, -120, h - 100);
	mlx_put_image_to_window(env->mlx, env->win, env->img_b, -120, h - 220);
	mlx_string_put(env->mlx, env->win, d, h - 220, 0x00FF00000,
			"All these commands are available");
	mlx_string_put(env->mlx, env->win, d, h - 200, 0x00FFFFFF,
			"Music: (m) ON/OFF");
	mlx_string_put(env->mlx, env->win, d, h - 180, 0x00FFFFFF,
			"Psyche mode: (p) ON/OFF");
	mlx_string_put(env->mlx, env->win, d, h - 160, 0x00FFFFFF,
			"Center zoom: (+) In / (-) Out");
	mlx_string_put(env->mlx, env->win, d, h - 140, 0x00FFFFFF,
			"Move: arrow keys (<)left (>)right (^)up (v)down");
	mlx_string_put(env->mlx, env->win, d, h - 120, 0x00FFFFFF,
			"Lock Julia const.: (l)ock");
	mlx_string_put(env->mlx, env->win, d, h - 100, 0x00FFFFFF,
			"Mandelbrot: (1)| Var. of Newton: (4)");
	print_help2(d, h, env);
}

void	print_help2(int d, int h, t_env *env)
{
	mlx_string_put(env->mlx, env->win, d, h - 80, 0x00FFFFFF,
			"Julia: (2)     | Burning ship: (5)");
	mlx_string_put(env->mlx, env->win, d, h - 60, 0x00FFFFFF,
			"Newton: (3)    | Beach: (6)  | Melting-pot: (7)");
	mlx_string_put(env->mlx, env->win, d, h - 40, 0x00FFFFFF,
			"Quit: (esc) or (q)");
	mlx_string_put(env->mlx, env->win, d, h - 20, 0x00FFFFFF,
			"Help menu: (h) open/close");
}

void	create_help(t_env *env)
{
	print_help(env);
	env->help = 1;
}

void	destroy_help(t_env *env)
{
	env->help = 0;
}
