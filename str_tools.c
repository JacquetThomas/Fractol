/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 10:56:05 by cjacquet          #+#    #+#             */
/*   Updated: 2017/08/29 14:54:07 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		is_fract_name(char *str)
{
	if (!ft_strcmp(str, "Mandelbrot"))
		return (0);
	if (!ft_strcmp(str, "Julia"))
		return (1);
	if (!ft_strcmp(str, "Newton"))
		return (2);
	else
		return (42);
}
