/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 15:26:20 by cjacquet          #+#    #+#             */
/*   Updated: 2017/07/27 12:19:26 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	free_all(t_env *env)
{
	if (env->win)
		mlx_destroy_window(env->mlx, env->win);
}