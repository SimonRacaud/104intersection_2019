/*
** EPITECH PROJECT, 2019
** 104intersection_2019
** File description:
** calcul the intersection points from a ray
*/

#include "intersection.h"

using namespace std;

Intersection::Intersection(void)
: m_arg(NULL)
{
}

int Intersection::compute(Argument &arg)
{
    m_arg = &arg;
    if (calcul_abc(arg) == EXIT_ERROR)
        return EXIT_ERROR;
    else if (calcul_lambda(m_a, m_b, m_c, arg) == EXIT_ERROR)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
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
            if (calcul_abc_cone(arg) == EXIT_ERROR)
                return EXIT_ERROR;
            break;
        default:
            cerr << "ERROR: invalid type of object in Intersection" << endl;
    }
    return EXIT_SUCCESS;
}
