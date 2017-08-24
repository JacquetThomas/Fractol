/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 17:18:09 by cjacquet          #+#    #+#             */
/*   Updated: 2017/08/24 18:09:51 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		menger_calc(int x, int y, t_env *env)
{
	x *= env->zoom;
	y *= env->zoom;
	while (x > 0 || y > 0)
	{
		if (x % 3 == 1 && y % 3 == 1)
			return (0);
		x /= 3;
		y /= 3;
	}
	return (1);
}

void	menger(t_env *env)
{
	int		y;
	int		x;
	int		i;

	x = 1;
	printf("env->zoom : %f\n", env->zoom);
	while (x < W_WIDTH)
	{
		y = 1;
		while (y < W_HEIGHT)
		{
			i = menger_calc(x, y, env);
			pixel_put_image((i == 1) ? MENGER : BLACK, x, y, env);
			y++;
		}
		x++;
	}
}
