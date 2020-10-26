/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thor <thor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 17:06:59 by thor              #+#    #+#             */
/*   Updated: 2020/04/02 18:23:48 by thor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void transl_objet_z(t_data *type, double pos, int indice)
{
    if (indice == 0)
    {
        if (type->key.type == triangle_d)
        {
            type->clo.objet->pos.z += pos;
            type->clo.objet->pos1.z += pos;
            type->clo.objet->pos2.z += pos;
        }
        else
            type->clo.objet->pos.z += pos;
    }
    if (indice == 1)
    {
        if (type->key.type == triangle_d)
        {
            type->clo.objet->pos.z -= pos;
            type->clo.objet->pos1.z -= pos;
            type->clo.objet->pos2.z -= pos;
        }
        else
            type->clo.objet->pos.z -= pos;
    }
}