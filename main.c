/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 13:47:56 by cjacquet          #+#    #+#             */
/*   Updated: 2017/08/20 11:50:10 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_env	env;

	if (ac == 2 && (env.fract_name = is_fract_name(av[1])) != 42)
	{
		init_mlx(&env);
		mlx_hook(env.win, 17, (1L << 17), exit_cross, &env);
		mlx_hook(env.win, 2, 0, key_hook, &env);
		mlx_hook(env.win, 6, (1L << 6), mouse_move, &env);
		mlx_mouse_hook(env.win, mouse_hook, &env);
		mlx_loop_hook(env.mlx, draw, &env);
		mlx_loop(env.mlx);
	}
	else
		error_str(USAGE, &env, 0);
}
