/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 17:06:59 by thor              #+#    #+#             */
/*   Updated: 2020/10/30 10:32:37 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void transl_objet_z(t_data *type, double pos, int indice)
{
    if (indice == 0)
    {
        if (type->key.type == triangle_d)
        {
            type->clone.objet->pos.z += pos;
            type->clone.objet->pos1.z += pos;
            type->clone.objet->pos2.z += pos;
        }
        else
        {
            // write (1,"i am here\n",10);
            type->clone.objet->pos.z += pos;
        }
    }
    if (indice == 1)
    {
        if (type->key.type == triangle_d)
        {
            type->clone.objet->pos.z -= pos;
            type->clone.objet->pos1.z -= pos;
            type->clone.objet->pos2.z -= pos;
        }
        else
        {
        //    write (1,"i am here\n",10);
            type->clone.objet->pos.z -= pos;
        }
    }
}