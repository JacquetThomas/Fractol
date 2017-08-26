/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 11:12:45 by cjacquet          #+#    #+#             */
/*   Updated: 2017/08/26 15:13:34 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(t_env *env)
{
	env->move *= 0.9;
	env->min_x *= 0.9;
	env->min_y *= 0.9;
	env->max_x *= 0.9;
	env->max_y *= 0.9;
	draw(env);
}

/*
** x1 = x-h, x2 = x+h, y1 = y-h et y2 = y+h
*/
int		mouse_hook(int button, int x, int y, t_env *env)
{
	t_plex		m;
	double		h;

	h = 0; //1 / env->zoom;
	y -= 100;
	m = map(x, y, env, 0);
	m.r = fabs(m.r);
	m.i = fabs(m.i);
	printf("m.x : %f // m.y : %f\n", m.r, m.i);
	if (button == SCROLL_UP || button == 1)
	{
		env->min_x -= m.r ;//- h;
		env->max_x += m.r ;//+ h;
		env->min_y -= m.i ;//- h;
		env->max_y += m.i ;//+ h;
	}
	if (button == SCROLL_DOWN || button == 2)
	{
		env->min_x = m.r + h;
		env->max_x = m.r - h;
		env->min_y = m.i - h;
		env->max_y = m.i + h;
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
	printf("1adresse env %p\n", env);
	if (env->help)
		destroy_help(env);
	exit(0);
	return (0);
}
