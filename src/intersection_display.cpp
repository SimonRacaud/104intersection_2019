/*
** EPITECH PROJECT, 2019
** 104intersection_2019
** File description:
** calcul the intersection points from a ray
*/

#include "intersection.h"

using namespace std;

int Intersection::display(void)
{
    if (m_arg == NULL)
        return EXIT_ERROR;
    display_line_one();
    display_line_two();
    display_intersection();
    return EXIT_SUCCESS;
}

void Intersection::display_line_one(void)
{
    switch (m_arg->get_object_type()) {
        case SPHERE:
            printf("Sphere of radius %d\n", m_arg->get_radius_angle());
            break;
        case CYLINDER:
            printf("Cylinder of radius %d\n", m_arg->get_radius_angle());
            break;
        case CONE:
            printf("Cone with a %d degree angle\n", m_arg->get_radius_angle());
            break;
        default:
            cerr << "ERROR2: invalid type of object in Intersection" << endl;
    }
}

void Intersection::display_line_two(void)
{
    const coord_t *point = m_arg->get_point();
    const coord_t *vect = m_arg->get_vector();

    printf("Line passing through the point (%.f, %.f, %.f)", point->x, point->y, point->z);
    printf(" and parallel to the vector (%.f, %.f, %.f)\n", vect->x, vect->y, vect->z);
}

void Intersection::display_intersection(void)
{
    int nbr_points = m_points.size();

    if (nbr_points == 0) {
        printf("No intersection point.\n");
    } else if (nbr_points == 1 || nbr_points == 2) {
        printf("%lu intersection points:\n", m_points.size());
        for (unsigned int i = 0; i < m_points.size(); i++) {
            printf("(%.3f, %.3f, %.3f)\n", m_points[i].x, m_points[i].y, m_points[i].z);
        }
    } else {
        printf("There is an infinite number of intersection points.\n");
    }
}
