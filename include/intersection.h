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

#define SQRT(nbr) (nbr * nbr)

class Argument;

class Intersection
{
    public:
        Intersection(void);
        ~Intersection(void) = default;
        int compute(Argument &arg);

    private:
        int calcul_lambda(int a, int b, int c);
        int calcul_point(double lambda, Argument &arg);
        int calcul_abc(Argument &arg);
        int calcul_abc_cylinder(Argument &arg);
        int calcul_abc_sphere(Argument &arg);
        int calcul_abc_cone(Argument &arg);
        double m_a;
        double m_b;
        double m_c;
        std::vector<double [3]> m_points;
};

#endif
