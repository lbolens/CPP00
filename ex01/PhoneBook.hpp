/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolens <lbolens@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:08:15 by lbolens           #+#    #+#             */
/*   Updated: 2025/10/21 10:19:16 by lbolens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>

#define RESET "\033[0m"
#define BLUE  "\033[1;34m"

enum Commands {
    ADD,
    SEARCH,
    EXIT,
    UNKNOWN,
};

class Contacts {
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string secret;

        std::string truncate(const std::string &str) const;

    public:
        void set_contact(void);
        void print_contacts(int index) const;
        void print_index(void) const;
};


class PhoneBook {
    private:
        Contacts contacts[8];
        int nbr;
        int next;

    public:
        PhoneBook();
        void add_contact(void);
        void search(void) const;
};

Commands get_enum(const std::string &command);

#endif
