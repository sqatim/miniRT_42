/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 11:17:39 by sqatim            #+#    #+#             */
/*   Updated: 2020/11/16 11:06:02 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_print(t_data *type, char *name, int number)
{
	ft_putstr_fd(name, 1);
	ft_putstr_fd(" : line ", 1);
	ft_putnbr_fd(type->parcing.error, 1);
	if (number == 1)
		ft_putstr_fd(" : miss element\n", 1);
	else if (number == 2)
		ft_putstr_fd(" : an error in pos\n", 1);
	else if (number == 3)
		ft_putstr_fd(" : an error in orientation vector\n", 1);
	else if (number == 4)
		ft_putstr_fd(" : an error in rgb\n", 1);
	else if (number == 5)
		ft_putstr_fd(" : an error in translation\n", 1);
	else if (number == 6)
		ft_putstr_fd(" : an error in rotation\n", 1);
	else if (number == 7)
		ft_putstr_fd(" : out of limit of element\n", 1);
}

void	ft_print_cont(t_data *type, char *name, int object, int error)
{
	ft_putstr_fd(name, 1);
	ft_putstr_fd(" : line ", 1);
	ft_putnbr_fd(type->parcing.error, 1);
	if (object == RESOLUTION_D)
		(error == 1) ? ft_putstr_fd(" : an error in width\n", 1)\
			: ft_putstr_fd(" : an error in height\n", 1);
	else if (object == AMBIENT_D || object == LIGHT_D)
		ft_putstr_fd(" : an error in intensity\n", 1);
	else if (object == SPHERE_D)
		ft_putstr_fd(" : an error in radius\n", 1);
	else if (object == SQUARE_D)
		ft_putstr_fd(" : an error in height\n'", 1);
	else if (object == CYLINDER_D)
		(error = 1) ? ft_putstr_fd(" : an error in radius\n", 1)\
			: ft_putstr_fd(" : an error in height\n\n", 1);
	else if (object == CAMERA_D)
		ft_putstr_fd(" : an error in fov\n", 1);
	free_exit(type, 1);
}

void	print_error_type(t_data *type)
{
	ft_putstr_fd("Check type of line ", 1);
	ft_putnbr_fd(type->parcing.error, 1);
	free_exit(type, 1);
}
