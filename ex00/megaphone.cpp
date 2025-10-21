/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolens <lbolens@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:22:58 by lbolens           #+#    #+#             */
/*   Updated: 2025/10/21 10:35:42 by lbolens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> //Pour std::cout, std::endl
#include <cctype> //Pour std::toupper
#include <string> //Pour std::string

class Megaphone {
    public:
        static void print(std::string str){
            for (size_t i = 0; i < str.length(); i++)
                std::cout << static_cast<char>(std::toupper(str[i])); //Doit cast en char car toupper retourne un int
        }
};

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }

    for (int i = 1; i < argc; i++)
    {
        std::string word(argv[i]); //Pour transformer argv[i] en std::string, (comme argv[i][j] en c)
        Megaphone::print(word);
    }
    std::cout << std::endl;
    return (0);
}