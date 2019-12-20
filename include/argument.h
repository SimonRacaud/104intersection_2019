/*
** EPITECH PROJECT, 2019
** 104intersection_2019
** File description:
** header
*/

#ifndef H_ARG
#define H_ARG

#include "104intersection.h"

class Argument
{
    public:
        Argument();
        ~Argument() = default;
        int set_arguments(int argc, char **argv);
        int get_object_type(void) const;
        const coord_t *get_point(void) const;
        const coord_t *get_vector(void) const;
        int get_radius_angle(void) const;

    private:
        int str_is_number(char *str) const;
        int convert_and_set_arguments(char **argv);
        int check_arguments_value(void) const;
        int m_type_object;
        coord_t m_point;
        coord_t m_vector;
        int m_radius_angle;
};

#endif
