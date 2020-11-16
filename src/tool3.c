/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 11:07:29 by sqatim            #+#    #+#             */
/*   Updated: 2020/11/16 16:14:42 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	max(double a, double b)
{
	double result;

	result = (a >= b) ? a : b;
	return (result);
}

double	min(double a, double b)
{
	double result;

	result = (a <= b) ? a : b;
	return (result);
}
