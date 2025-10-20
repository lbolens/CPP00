/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasbolens <lucasbolens@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:04:18 by lucasbolens       #+#    #+#             */
/*   Updated: 2025/10/17 11:32:44 by lucasbolens      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Print {
    public:
        static void print_it(char c) {
            std::cout << c;
        };
};

class Uppercase {
    public:
        static void get_up(char c) {
            char up =  c - 32;
            Print::print_it(up);
        };
};

int main(int argc, char **argv)
{
    int i = 1;

    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;

    while (argv[i])
    {
        int j = 0;
        while (argv[i][j])
        {
            if (argv[i][j] == ' ')
                Print::print_it(' ');
            else if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
                Uppercase::get_up(argv[i][j]);
            else if (argv[i][j] >= 'A' && argv[i][j] <= 'Z')
                Print::print_it(argv[i][j]);
            else
                Print::print_it(argv[i][j]);
            j++;
        }
        i++;
    }
    std::cout << std::endl;
    return (0);
}