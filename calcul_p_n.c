/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_p_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thor <thor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 18:59:27 by thor              #+#    #+#             */
/*   Updated: 2020/10/20 14:00:25 by sqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void sphere_p_n(t_data *type, double has_inter)
{
    t_vector produit;

    produit = vector_scal(type->objet->t, type->ray.direction);
    type->objet->point = vector_add(type->ray.origin, produit);
    type->objet->normal = vector_sub(type->objet->point, type->objet->pos);
    type->objet->normal = unit_vector(type->objet->normal);
}

void plane_p_n(t_data *type, double has_inter)
{
    t_vector produit;
    double a;

    a = vector_dot(type->ray.direction, type->objet->v);
    produit = vector_scal(type->objet->t, type->ray.direction);
    type->objet->point = vector_add(type->ray.origin, produit);
    type->objet->normal = type->objet->v;
    if (a > 0)
        type->objet->normal = vector_scal(-1, type->objet->normal);
}

void square_p_n(t_data *type, double has_inter)
{
    t_vector produit;

    double a;
    a = vector_dot(type->ray.direction, type->objet->v);
    produit = vector_scal(type->objet->t, type->ray.direction);
    type->objet->point = vector_add(type->ray.origin, produit);

    type->objet->normal = type->objet->v;

    if (a > 0)
        type->objet->normal = vector_scal(-1, type->objet->normal);
}

void cylinder_p_n(t_data *type, double has_inter)
{
    t_vector produit;
    double m;
    t_vector o_p;
    t_vector scal;
    t_vector sub;
    t_vector x;

    type->objet->v = unit_vector(type->objet->v);
    produit = vector_scal(type->objet->t, type->ray.direction);
    type->objet->point = vector_add(type->ray.origin, produit);
    x = vector_sub(type->ray.origin, type->objet->pos);
    m = vector_dot(type->ray.direction, type->objet->v) * type->objet->t + vector_dot(x, type->objet->v);
    sub = vector_sub(type->objet->point, type->objet->pos);
    scal = vector_scal(m, type->objet->v);
    type->objet->normal = vector_sub(sub, scal);
    if (vector_dot(type->ray.direction, type->objet->normal) > 0.000)
        type->objet->normal = vector_scal(-1, type->objet->normal);
    type->objet->normal = unit_vector(type->objet->normal);
}

void triangle_p_n(t_data *type, double has_inter)
{
    t_vector produit;
    t_vector edge1;
    t_vector edge2;

    edge1 = vector_sub(type->objet->pos1, type->objet->pos);
    edge2 = vector_sub(type->objet->pos2, type->objet->pos);
    produit = vector_scal(type->objet->t, type->ray.direction);
    type->objet->point = vector_add(type->ray.origin, produit);
    type->objet->normal = vector_cross(edge1, edge2);
    type->objet->normal = unit_vector(type->objet->normal);
}
