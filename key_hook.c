/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 12:46:41 by cjacquet          #+#    #+#             */
/*   Updated: 2017/08/24 18:03:12 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_hook(int keycode, t_env *env)
{
	if (keycode == 35)
	{
		env->color_picker = (env->color_picker) ? 0 : 1;
		if (env->color_picker)
		{
			if (env->music)
			{
				system("killall afplay");
				/*system("afplay fractol_song.mp3 &");*/
				system("afplay psych.mp3 &");
			}
		}
		else
		{
			if (env->music)
			{
				system("killall afplay");
				system("afplay wait.mp3 &");
			}
		}
	}
	key_hook2(keycode, env);
	return (1);
}

int		key_hook2(int keycode, t_env *env)
{
	if (keycode == 37)
		env->c_lock = (env->c_lock) ? 0 : 1;
	if ((keycode >= 18 && keycode <= 23) || keycode == 26 || keycode == 28
			|| keycode == 25)
	{
		if (keycode == 18)
			env->fract_name = 0;
		if (keycode == 19)
			env->fract_name = 1;
		if (keycode == 20)
			env->fract_name = 2;
		if (keycode == 21)
			env->fract_name = 3;
		if (keycode == 23)
			env->fract_name = 4;
		if (keycode == 22)
			env->fract_name = 5;
		if (keycode == 26)
			env->fract_name = 6;
		if (keycode == 28)
			env->fract_name = 7;
		if (keycode == 25)
			env->fract_name = 8;
		maj_var(env);
	}
	key_hook3(keycode, env);
	return (1);
}

int		key_hook3(int keycode, t_env *env)
{
	if (keycode == 4)
	{
		printf("key before env->help : %d \n", env->help);
		if (env->help)
			destroy_help(env);
		else
			create_help(env);
		printf("key after env->help : %d \n", env->help);
	}
	if (keycode == 46)
	{
		if (env->music)
		{
			env->music = 0;
			system("killall afplay");
		}
		else
		{
			env->music = 1;
			if (env->color_picker == 0)
				system("afplay wait.mp3 &");
			else
			{
			/*	system("afplay fractol_song.mp3 &"); */
				system("afplay psych.mp3 &");
			}
		}
	}
	if (keycode == 24)
	{
		env->zoom *= 0.9;
		env->move *= 0.9;
		env->min_x *= 0.9;
		env->min_y *= 0.9;
		env->max_x *= 0.9;
		env->max_y *= 0.9;
		draw(env);
	}
	if (keycode == 27)
	{
		env->zoom *= 1.1;
		env->move *= 1.1;
		env->min_x *= 1.1;
		env->min_y *= 1.1;
		env->max_x *= 1.1;
		env->max_y *= 1.1;
		draw(env);
	}
	if (keycode == 38)
		env->move_r = (env->move_r) ? 0 : 1;
	if (keycode == 40)
		env->move_i = (env->move_i) ? 0 : 1;
	env->max_i += (keycode == 69 && env->max_i < 500) ? 1 : 0;
	env->max_i -= (keycode == 78 && env->max_i > 1) ? 1 : 0;
	env->px = (keycode == LEFT) ? env->px + env->move : env->px;
	env->px = (keycode == RIGHT) ? env->px - env->move : env->px;
	env->py = (keycode == DOWN) ? env->py - env->move : env->py;
	env->py = (keycode == UP) ? env->py + env->move : env->py;
	if (keycode == 6)
		maj_var(env);
	if (keycode == 53 || keycode == 12)
		error_str("It's the end of fractol as we know it!", env, 2);
	draw(env);
	return (0);
}
