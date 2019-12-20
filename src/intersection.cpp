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
    debug_display("Point", arg.get_point());
    debug_display("Vector", arg.get_vector());  // DEBUG
    printf("\n");

    if (calcul_abc(arg) == EXIT_ERROR)
        return EXIT_ERROR;
    else if (calcul_lambda(m_a, m_b, m_c, arg) == EXIT_ERROR)
        return EXIT_ERROR;
    for (unsigned int i = 0; i < m_points.size(); i++) { // DEBUG
        printf("coord %f %f %f\n", m_points[i].x, m_points[i].y, m_points[i].z);
    }
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

int Intersection::calcul_lambda(double a, double b, double c, Argument &arg)
{
    double delta = SQR(b) - 4 * a * c;
    double lambda[2];

    printf("ABC: %f %f %f \n", a, b, c);
    printf("DELTA: %f \n\n", delta); // DEBUG
    if (delta < 0)
        return EXIT_SUCCESS;
    else if (delta == 0) {
        lambda[0] = (-b) / (2 * a);
        add_point(lambda[0], arg);
    } else {
        lambda[0] = ((-b) + sqrt(delta)) / (2 * a);
        lambda[1] = ((-b) - sqrt(delta)) / (2 * a);
        add_point(lambda[0], arg);
        add_point(lambda[1], arg);
    }
    return EXIT_SUCCESS;
}

int Intersection::add_point(double lambda, Argument &arg)
{
    const coord_t *point = arg.get_point();
    const coord_t *vect = arg.get_vector();
    coord_t new_point;

    new_point.x = point->x + lambda * vect->x;
    new_point.y = point->y + lambda * vect->y;
    new_point.z = point->z + lambda * vect->z;
    m_points.push_back(new_point);
    return EXIT_SUCCESS;
}

int Intersection::calcul_abc_cylinder(Argument &arg)
{
    const coord_t *point = arg.get_point();
    const coord_t *vect = arg.get_vector();
    double radius = arg.get_radius_angle();

    m_a = (vect->x * vect->x) + (vect->y * vect->y);
    m_b = 2 * (vect->x * point->x + vect->y * point->y);
    m_c = (point->x * point->x) + (point->y * point->y) - SQR(radius);
    return EXIT_SUCCESS;
}

int Intersection::calcul_abc_sphere(Argument &arg)
{
    const coord_t *point = arg.get_point();
    const coord_t *vect = arg.get_vector();
    double radius = arg.get_radius_angle();

    m_a = SQR(vect->x) + SQR(vect->y) + SQR(vect->z);
    m_b = 2 * (vect->x * point->x + vect->y * point->y + vect->z * point->z);
    m_c = SQR(point->x) + SQR(point->y) + SQR(point->z) - SQR(radius);
    return EXIT_SUCCESS;
}

int Intersection::calcul_abc_cone(Argument &arg)
{
    const coord_t *point = arg.get_point();
    const coord_t *vect = arg.get_vector();
    double tan_angle = tan((90 - arg.get_radius_angle()) * (3.14159f / 180.0f));

    m_a = SQR(vect->x) + SQR(vect->y) - (SQR(vect->z) / SQR(tan_angle));
    m_b = 2 * (vect->x * point->x + vect->y * point->y - ((point->z * vect->z) / SQR(tan_angle)));
    m_c = SQR(point->x) + SQR(point->y) - (SQR(point->z) / SQR(tan_angle));
    return EXIT_SUCCESS;
}
