/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 11:12:45 by cjacquet          #+#    #+#             */
/*   Updated: 2017/08/20 15:18:24 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		mouse_hook(int button, int x, int y, t_env *env)
{
	t_plex		m;
	t_plex		diff;

	y -= 100;
	m = map(x, y, env, 0);
	diff.r = (env->max_x - env->min_x) / (2 * env->zoom);
	diff.i = (env->max_y - env->min_y) / (2 * env->zoom);
	printf("diffx : %f / diffy : %f\nmx : %f / my : %f\n", diff.r, diff.i, m.r, m.i);
	if (button == SCROLL_UP || button == 1)
	{
		env->min_x += diff.r; /*mx + diffx;*/
		env->min_y += diff.i; /*my + diffy;*/
		env->max_x -= diff.r; /*mx - diffx;*/
		env->max_y -= diff.i; /*my - diffy;*/
	}
	if (button == SCROLL_DOWN || button == 2)
	{
		env->min_x = m.r - diff.r;
		env->min_y = m.i - diff.i;
		env->max_x = m.r + diff.r;
		env->max_y = m.i + diff.i;
	}
	draw(env);
	return (1);
}

int		mouse_move(int x, int y, t_env *env)
{
	y -= 100;
	if (env->c_lock == 0)
	{
		env->julia.r = ((1.0 / (W_WIDTH / 2)) * x) - 1.0;
		env->julia.i = ((1.0 / (W_HEIGHT / 2)) * y) - 1.0;
		if (x > W_WIDTH)
			env->julia.r = 1;
		else if (x < 0)
			env->julia.r = -1;
		if (y > W_HEIGHT)
			env->julia.i = 1;
		else if (y < 0)
			env->julia.i = -1;
		env->mouse_x = x;
		env->mouse_y = y;
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
