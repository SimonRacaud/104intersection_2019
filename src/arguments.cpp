/*
** EPITECH PROJECT, 2019
** 104intersection_2019
** File description:
** get and check the arguments of the programme
*/

#include "arguments.h"

using namespace std;

Arguments::Arguments()
{
    m_type_object = -1;
    for (int i = 0; i < 3; i++) {
        m_point[i] = 0;
        m_vector[i] = 0;
    }
    m_radius_angle = 0;
}

int Arguments::set_arguments(int argc, char **argv)
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

int Arguments::str_is_number(char *str) const
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
            return 0;
    }
    return 1;
}

int Arguments::convert_and_set_arguments(char **argv)
{
    m_type_object = atoi(argv[1]);
    m_point[0] = atoi(argv[2]);
    m_point[1] = atoi(argv[3]);
    m_point[2] = atoi(argv[4]);
    m_vector[0] = atoi(argv[5]);
    m_vector[1] = atoi(argv[6]);
    m_vector[2] = atoi(argv[7]);
    m_radius_angle = atoi(argv[8]);
    return EXIT_SUCCESS;
}

int Arguments::check_arguments_value(void) const
{
    if (m_type_object > 3 || m_type_object < 1)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}

const int *Arguments::get_point(void) const
{
    return m_point;
}

const int *Arguments::get_vector(void) const
{
    return m_vector;
}

int Arguments::get_radius_angle(void) const
{
    return m_radius_angle;
}

int Arguments::get_object_type(void) const
{
    return m_type_object;
}
