/*
** EPITECH PROJECT, 2019
** 104intersection_2019
** File description:
** header
*/

#ifndef H_INTERSECTION
#define H_INTERSECTION

#include "104intersection.h"
#include <vector>
#include <cmath>

#define SQR(nbr) (nbr * nbr)

class Argument;

class Intersection
{
    public:
        Intersection(void);
        ~Intersection(void) = default;
        int compute(Argument &arg);
        int display(void);

    private:
        int check_specific_case_cylinder(Argument &arg);
        int check_cylinder_infinite_points(Argument &arg);
        int check_cone_infinite_points(Argument &arg);
        int calcul_lambda(double a, double b, double c, Argument &arg);
        int add_point(double lambda, Argument &arg);
        int calcul_abc(Argument &arg);
        int calcul_abc_cylinder(Argument &arg);
        int calcul_abc_sphere(Argument &arg);
        int calcul_abc_cone(Argument &arg);
        void display_line_one(void);
        void display_line_two(void);
        void display_intersection(void);
        Argument *m_arg;
        double m_a;
        double m_b;
        double m_c;
        std::vector<coord_t> m_points;
};

#endif
