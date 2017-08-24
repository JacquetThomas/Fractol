/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 11:12:45 by cjacquet          #+#    #+#             */
/*   Updated: 2017/08/23 21:37:38 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(t_env *env)
{
		env->move *= 0.9;
//		env->min_x *= 0.9;
		env->min_y *= 0.9;
		env->max_x *= 0.9;
//		env->max_y *= 0.9;
//		draw(env);
/*	if (keycode == 27)
	{
		env->move *= 1.1;
		env->min_x *= 1.1;
		env->min_y *= 1.1;
		env->max_x *= 1.1;
		env->max_y *= 1.1;
		draw(env);
	}*/
}

int		mouse_hook(int button, int x, int y, t_env *env)
{
	t_plex		m;
	int			xneg;
	int			yneg;
//	t_plex		diff;

	y -= 100;
	m = map(x, y, env, 0);
	printf("m.x : %f // m.y : %f\n", m.r, m.i);
	xneg = (m.r < 0) ? 1 : 0;
	yneg = (m.i < 0) ? 1 : 0;
	m.r = fabs(m.r);
	m.i = fabs(m.i);
//	diff.r = 
	if (button == SCROLL_UP || button == 1)
	{
//		if (m.r < 0)
//			env->px += env->move * m.r * 2;
		if (xneg == 0)
		{
//			ft_putendl("1");
//			env->max_y *= 0.9;// * (m.i * 1 / env->max_y);
		//	zoom_in(env);
//			env->px -= env->move * m.r * 2;
		}
//		if (m.i < 0)
//			env->py -= env->move * 2 * m.i;
		if (yneg == 0)
		{
//			ft_putendl("2");
//			env->min_x *= 0.9;// * (m.r * 1 / env->min_x);
//			env->py += env->move * m.i * 2;
		}
	}
	if (button == SCROLL_DOWN || button == 2)
	{
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
