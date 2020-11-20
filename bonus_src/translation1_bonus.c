/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 17:06:59 by thor              #+#    #+#             */
/*   Updated: 2020/11/20 13:15:47 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

void	transl_objet_x(t_data *type, double pos, int indice)
{
	if (indice == 0)
	{
		if (type->key.type == TRIANGLE_D)
		{
			type->clone.objet->pos.x += pos;
			type->clone.objet->pos1.x += pos;
			type->clone.objet->pos2.x += pos;
		}
		else
			type->clone.objet->pos.x += pos;
	}
	if (indice == 1)
	{
		if (type->key.type == TRIANGLE_D)
		{
			type->clone.objet->pos.x -= pos;
			type->clone.objet->pos1.x -= pos;
			type->clone.objet->pos2.x -= pos;
		}
		else
			type->clone.objet->pos.x -= pos;
	}
}

void	transl_objet_y(t_data *type, double pos, int indice)
{
	if (indice == 0)
	{
		if (type->key.type == TRIANGLE_D)
		{
			type->clone.objet->pos.y += pos;
			type->clone.objet->pos1.y += pos;
			type->clone.objet->pos2.y += pos;
		}
		else
			type->clone.objet->pos.y += pos;
	}
	if (indice == 1)
	{
		if (type->key.type == TRIANGLE_D)
		{
			type->clone.objet->pos.y -= pos;
			type->clone.objet->pos1.y -= pos;
			type->clone.objet->pos2.y -= pos;
		}
		else
			type->clone.objet->pos.y -= pos;
	}
}

void	transl_objet_z(t_data *type, double pos, int indice)
{
	if (indice == 0)
	{
		if (type->key.type == TRIANGLE_D)
		{
			type->clone.objet->pos.z += pos;
			type->clone.objet->pos1.z += pos;
			type->clone.objet->pos2.z += pos;
		}
		else
			type->clone.objet->pos.z += pos;
	}
	if (indice == 1)
	{
		if (type->key.type == TRIANGLE_D)
		{
			type->clone.objet->pos.z -= pos;
			type->clone.objet->pos1.z -= pos;
			type->clone.objet->pos2.z -= pos;
		}
		else
			type->clone.objet->pos.z -= pos;
	}
}
