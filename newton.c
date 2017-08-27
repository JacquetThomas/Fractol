/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 13:32:45 by cjacquet          #+#    #+#             */
/*   Updated: 2017/08/27 22:34:21 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		newton_calc(int x, int y, t_env *env)
{
	t_calc	c;
	double	tmp;

	c.point = map(x, y, env, 1);
	c.new.r = c.point.r;
	c.new.i = c.point.i;
	env->iter = 0;
	while (++env->iter < env->max_i)
	{
		c.old = c.new;
		tmp = (c.new.r * c.new.r + c.new.i * c.new.i) * (c.new.r * c.new.r + c.new.i * c.new.i);
		c.new.r = (2 * c.new.r * tmp + c.new.r * c.new.r - c.new.i * c.new.i) / (3.0 * tmp);
		c.new.i = (2 * c.new.i * (tmp - c.old.r)) / (3.0 * tmp);
		//c.new = c_sous(c.old, c_div(f(c.old, env->nvar), df(c.old, env->nvar)));
		tmp = (c.new.r - c.old.r) * (c.new.r - c.old.r) + (c.new.i - c.old.i) * (c.new.i - c.old.i);
		if (tmp > 0.000001)
			return (env->iter);
	}
	return (env->iter);
}

t_plex	f(t_plex plx, int nvar)
{
	t_plex	new;
	t_plex	un;
	t_plex	quinze;
	t_plex	seize;

	un.r = 1.0;
	un.i = 0.0;
	quinze.r = 15.0;
	quinze.i = 0.0;
	seize.r = 16.0;
	seize.i = 0.0;
	if (!nvar)
		new = c_sous(c_mul(c_mul(plx, plx), plx), un);
	else
		new = c_sous(c_add(c_mul(c_mul(c_mul(c_mul(plx, plx), plx), plx), plx),
					c_mul(c_mul(plx, plx), quinze)), seize);
	return (new);
}

t_plex	df(t_plex plx, int nvar)
{
	t_plex	new;
	t_plex	trois;
	t_plex	huit;
	t_plex	vindix;

	trois.r = 3.0;
	trois.i = 0.0;
	huit.r = 8.0;
	huit.i = 0.0;
	vindix.r = 90.0;
	vindix.i = 0.0;
	if (!nvar)
		new = c_mul(trois, c_mul(plx, plx));
	else
		new = c_add(c_mul(c_mul(c_mul(plx, plx), plx), vindix),
				c_mul(c_mul(plx, plx), huit));
	return (new);
}

void	newton(t_env *env)
{
	int		y;
	int		x;
	int		i;

	x = 1;
	while (x < W_WIDTH)
	{
		y = 1;
		while (y < W_HEIGHT)
		{
			i = newton_calc(x, y, env);
			pixel_put_image(get_color(i * 360 / env->max_i, 1,
						0.8 * (i < env->max_i), env), x, y, env);
			y++;
		}
		x++;
	}
}
