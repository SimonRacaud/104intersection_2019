/*
** EPITECH PROJECT, 2019
** 104intersection_2019
** File description:
** get and check the arguments of the programme
*/

#include "argument.h"

using namespace std;

Argument::Argument()
{
}

int Argument::set_arguments(int argc, char **argv)
{
    if (argc != 9) {
        cerr << "ERROR: Please give nine numbers as arguements" << endl;
        return EXIT_ERROR;
    }
    for (int i = 1; i < 9; i++) {
        if (!str_is_number(argv[i])) {
            cerr << "ERROR: An arguements is not a number" << endl;
            return EXIT_ERROR;
        }
    }
    if (convert_and_set_arguments(argv) == EXIT_ERROR) {
        cerr << "ERROR: Convert and set arguments" << endl;
        return EXIT_ERROR;
    } else if (check_arguments_value() == EXIT_ERROR) {
        cerr << "ERROR: Invalid value of argument" << endl;
        return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}

int Argument::str_is_number(char *str) const
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
            return 0;
    }
    return 1;
}

int Argument::convert_and_set_arguments(char **argv)
{
    m_type_object = atoi(argv[1]);
    m_point.x = atoi(argv[2]);
    m_point.y = atoi(argv[3]);
    m_point.z = atoi(argv[4]);
    m_vector.x = atoi(argv[5]);
    m_vector.y = atoi(argv[6]);
    m_vector.z = atoi(argv[7]);
    m_radius_angle = atoi(argv[8]);
    return EXIT_SUCCESS;
}

int Argument::check_arguments_value(void) const
{
    if (m_type_object > 3 || m_type_object < 1)
        return EXIT_ERROR;
    else if (m_radius_angle <= 0) {
        return EXIT_ERROR;
    }
    if (m_vector.x == 0 && m_vector.y == 0 && m_vector.z == 0) {
        return EXIT_ERROR;
    } else if (m_type_object == CONE && m_radius_angle >= 90) {
        return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}

const coord_t *Argument::get_point(void) const
{
    return &m_point;
}

const coord_t *Argument::get_vector(void) const
{
    return &m_vector;
}

int Argument::get_radius_angle(void) const
{
    return m_radius_angle;
}

int Argument::get_object_type(void) const
{
    return m_type_object;
}
