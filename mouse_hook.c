/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 11:12:45 by cjacquet          #+#    #+#             */
/*   Updated: 2017/08/28 11:05:33 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** x1 = x-h, x2 = x+h, y1 = y-h et y2 = y+h
*/

int		mouse_hook(int button, int x, int y, t_env *env)
{
	t_plex			m;

	y -= 100;
	m = map(x, y, env, 1);
	printf("m.x : %f // m.y: %f\n", m.r, m.i);
	if (x >= 0 && x < W_WIDTH && y >= 0 && y < W_HEIGHT)
	{
		if (button == SCROLL_UP || button == 1)
		{
			env->px = m.r;
			env->py = m.i;
			zoom_in(env);
		}
		if (button == SCROLL_DOWN || button == 2)
		{
			env->px = m.r;
			env->py = m.i;
			zoom_out(env);
		}
		printf("px : %f // yy: %f\n", env->px, env->py);
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
