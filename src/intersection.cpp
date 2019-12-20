/*
** EPITECH PROJECT, 2019
** 104intersection_2019
** File description:
** calcul the intersection points from a ray
*/

#include "intersection.h"

using namespace std;

Intersection::Intersection(void)
{
}

int Intersection::compute(Argument &arg)
{
    // Calcul a b c
    if (calcul_abc(arg) == EXIT_ERROR)
        return EXIT_ERROR;
    // calcul lambda
    // Calcul des points
}

int Intersection::calcul_abc(Argument &arg)
{
    switch (arg.get_object_type()) {
        case SPHERE:
            if (calcul_abc_sphere(arg) == EXIT_ERROR)
                return EXIT_ERROR;
            break;
        case CYLINDER:
            if (calcul_abc_cylinder(arg) == EXIT_ERROR)
                return EXIT_ERROR;
            break;
        case CONE:
            if (calcul_abc_sphere(arg) == EXIT_ERROR)
                return EXIT_ERROR;
            break;
        default:
            cerr << "ERROR: invalid type of object in Intersection" << endl;
    }
    return EXIT_SUCCESS;
}

int Intersection::calcul_lambda(int a, int b, int c)
{

}

int Intersection::calcul_point(double lambda, Argument &arg)
{

}

int Intersection::calcul_abc_cylinder(Argument &arg)
{
    const coord_t *point = arg.get_point();
    const coord_t *vect = arg.get_vector();
    int radius = arg.get_radius_angle();

    m_a = (vect->x * vect->x) + (vect->y * vect->y);
    m_b = 2 * (vect->x * point->x + vect->y * point->y);
    m_c = (point->x * point->x) + (point->y * point->y) - SQRT(radius);
    return EXIT_SUCCESS;
}

int Intersection::calcul_abc_sphere(Argument &arg)
{
    const coord_t *point = arg.get_point();
    const coord_t *vect = arg.get_vector();
    int radius = arg.get_radius_angle();

    m_a = SQRT(vect->x) + SQRT(vect->y) + SQRT(vect->y);
    m_b = 2 * (vect->x * point->x + vect->y * point->y + vect->z * point->z);
    m_c = SQRT(point->x) + SQRT(point->y) + SQRT(point->z) - SQRT(radius);
    return EXIT_SUCCESS;
}

int Intersection::calcul_abc_cone(Argument &arg)
{
    const coord_t *point = arg.get_point();
    const coord_t *vect = arg.get_vector();
    int angle = (90 - arg.get_radius_angle());

    //m_a = SQRT(vect->x) + SQRT(vect->y) + SQRT(vect->y);
    //m_b = 2 * (vect->x * point->x + vect->y * point->y - 0);
    //m_c = SQRT(point->x) + SQRT(point->y);
    return EXIT_SUCCESS;
}
