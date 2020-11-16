/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 11:19:08 by sqatim            #+#    #+#             */
/*   Updated: 2020/11/14 14:56:58 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_ERROR_H
#define PRINT_ERROR_H

#include "minirt.h"
void ft_print(t_data *type, char *name, int number);
void ft_print_cont(t_data *type, char *name, int object, int error);
void print_error_type(t_data *type);

#endif