#ifndef INTERSECTION_H
#define INTERSECTION_H

#include <geometry.h>

/*
    Ray-Face-intersection
    @param ray, a ray doing the intersecting;
    @param face, a face being intersected;

    @return:
        -1                  : there is no intersection
        non-negative number : the distance along the direction for the ray to intersect
*/
float Ray_Face_intersect(Ray ray, Face face);

/*
    Ray-Box-intersection
    @param ray, a ray doing the intersecting;
    @param box, a hitbox being intersected;

    @return:
        -1                  : there is no intersection
        0-6                 : the nearest plane of the box hit by the ray.
*/
int Ray_Box_intersect(Ray ray, Hitbox box);


/*
    Ray-Sphere-intersection
    @param ray, a ray doing the intersecting;
    @param sphere, a sphere being intersected;

    @return:
        -1                  : there is no intersection
        non-negative number : the distance along the direction for the ray to intersect
*/
float Ray_Sphere_intersect(Ray ray, Sphere sphere);

bool Plane_Plane(Face P1, Face P2);

bool Box_Plane(Hitbox box, Face plane);


#endif