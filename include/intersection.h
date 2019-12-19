/*
** EPITECH PROJECT, 2019
** 104intersection_2019
** File description:
** header
*/

#ifndef H_INTERSECTION
#define H_INTERSECTION

#include "104intersection.h"

class Intersection
{
    public:
        Intersection(void);
        Intersection(Arguments *arg);
        int calcul_abc(Arguments *arg);
        int calcul_lambda(int a, int b, int c);
        int calcul_point(double lambda, Arguments *arg);

    private:
        int calcul_abc_cylinder(Arguments *arg);
        int calcul_abc_sphere(Arguments *arg);
        int calcul_abc_cone(Arguments *arg);
        Arguments *m_arg;
        int m_a;
        int m_b;
        int m_c;
        double m_point01[3];
        double m_point02[3];
};

#endif
