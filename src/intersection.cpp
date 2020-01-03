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
    switch (arg.get_object_type()) {
        case CYLINDER:
            if (check_cylinder_infinite_points(arg))
                return EXIT_SUCCESS;
            else if (check_specific_case_cylinder(arg))
                return EXIT_SUCCESS;
            break;
        case CONE:
            if (check_cone_infinite_points(arg))
                return EXIT_SUCCESS;
            break;
    }
    if (calcul_abc(arg) == EXIT_ERROR)
        return EXIT_ERROR;
    else if (calcul_lambda(m_a, m_b, m_c, arg) == EXIT_ERROR)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}

int Intersection::check_specific_case_cylinder(Argument &arg)
{
    const coord_t *point = arg.get_point();
    const coord_t *vect = arg.get_vector();
    double distance_origine_point;

    distance_origine_point = sqrt(SQR(point->x) + SQR(point->y) + SQR(point->z));
    if (distance_origine_point < arg.get_radius_angle()) {
        if (vect->x == 0 && vect->y == 0)
            return 1;
    }
    return 0;
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

int Intersection::check_cylinder_infinite_points(Argument &arg)
{
    const coord_t *point = arg.get_point();
    const coord_t *vect = arg.get_vector();
    double distance_origine_point;

    distance_origine_point = round(sqrt(SQR(point->x) + SQR(point->y) + SQR(point->z)));
    if (distance_origine_point == arg.get_radius_angle()) {
        if (vect->z != 0 && vect->y == 0 && vect->x == 0) {
            for (int i = 0; i < 3; i++)
                add_point(0, arg);
            return 1;
        }
    }
    return EXIT_SUCCESS;
}

int Intersection::check_cone_infinite_points(Argument &arg)
{
    const coord_t *point = arg.get_point();
    const coord_t *vect = arg.get_vector();
    double tan_angle = tan((90 - arg.get_radius_angle()) * (3.14159f / 180.0f));
    int null_counter = 0;
    double result;
    //printf("angle %f \n", tan_angle);

    for (int i = 1; i <= 3; i++) {
        result = (SQR(point->x + i * vect->x) + SQR(point->y + i * vect->y) - (SQR(point->z + i * vect->z) / SQR(tan_angle)));
        //printf("result %f \n", result);
        result = round(result * 10000) / 10000;
        if (result == 0) {
            null_counter++;
        }
    }
    if (null_counter == 3) {
        for (int i = 0; i < 3; i++)
            add_point(0, arg);
        return 1;
    }
    return EXIT_SUCCESS;
}
