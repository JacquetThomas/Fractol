/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 11:12:45 by cjacquet          #+#    #+#             */
/*   Updated: 2017/08/28 18:51:54 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_hook(int button, int x, int y, t_env *env)
{
	t_plex			m;

	y -= 100;
	m = map(x, y, env, 1);
	if (x >= 0 && x < W_WIDTH && y >= 0 && y < W_HEIGHT)
	{
		if (button == SCROLL_UP || button == 1)
		{
			env->min_x = m.r - ((m.r - env->min_x) / 2);
			env->min_y = m.i - ((m.i - env->min_y) / 2);
			env->max_x = m.r + ((env->max_x - m.r) / 2);
			env->max_y = m.i + ((env->max_y - m.i) / 2);
		//	env->px = m.r;
		//	env->py = m.i;
		//	zoom(24, env);
		}
		if (button == SCROLL_DOWN || button == 2)
		{
		//	env->px = m.r;
		//	env->py = m.i;
		//	zoom(27, env);
		}
	}
	draw(env);
	return (1);
}

int		mouse_move(int x, int y, t_env *env)
{
	y -= 100;
	if (env->c_lock == 0)
	{
		env->julia = map(x, y, env, 2);
		if (x > W_WIDTH)
			env->julia.r = 1;
		else if (x < 0)
			env->julia.r = -1;
		if (y > W_HEIGHT)
			env->julia.i = 1;
		else if (y < 0)
			env->julia.i = -1;
	}
	return (1);
}

int		exit_cross(t_env *env)
{
	if (env->music)
		system("killall afplay");
	ft_putendl("It's the end of fractol as we know it!");
	exit(0);
	return (0);
}
