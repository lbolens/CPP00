/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolens <lbolens@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:08:06 by lbolens           #+#    #+#             */
/*   Updated: 2025/10/20 16:09:56 by lbolens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>

#define RESET "\033[0m"
#define BLUE "\033[1;34m"

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

        std::string truncate(const std::string &str) const {
            if (str.length() > 10)
                return str.substr(0, 9) + ".";
            return str;
        }

    public:
        void set_contact(void) {
            do {
                std::cout << "First name: ";
                std::getline(std::cin >> std::ws, first_name);
                if (std::cin.eof()) return;
                if (first_name.empty()) {
                    std::cout << "Can't put an empty field.\n";
                    std::cin.clear();
                }
            } while (first_name.empty());

            do {
                std::cout << "Last name: ";
                std::getline(std::cin >> std::ws, last_name);
                if (std::cin.eof()) return;
                if (last_name.empty()) {
                    std::cout << "Can't put an empty field.\n";
                    std::cin.clear();
                }
            } while (last_name.empty());

            do {
                std::cout << "Nickname: ";
                std::getline(std::cin >> std::ws, nickname);
                if (std::cin.eof()) return;
                if (nickname.empty()) {
                    std::cout << "Can't put an empty field.\n";
                    std::cin.clear();
                }
            } while (nickname.empty());

            bool valid_number;
            do {
                valid_number = true;
                std::cout << "Phone number: ";
                std::getline(std::cin >> std::ws, phone_number);
                if (std::cin.eof()) return;

                if (phone_number.empty()) {
                    std::cout << "Can't put an empty field.\n";
                    std::cin.clear();
                    valid_number = false;
                } else {
                    for (int i = 0; i < (int)phone_number.length(); i++) {
                        if (!isdigit(phone_number[i])) {
                            std::cout << "Error: phone number must contain only digits.\n";
                            valid_number = false;
                            break;
                        }
                    }
                }
            } while (!valid_number);

            do {
                std::cout << "Darkest secret: ";
                std::getline(std::cin >> std::ws, secret);
                if (std::cin.eof()) return;
                if (secret.empty()) {
                    std::cout << "Can't put an empty field.\n";
                    std::cin.clear();
                }
            } while (secret.empty());
        }

        void print_contacts(int index) const {
            std::cout << "|" << std::setw(10) << index
                    << "|" << std::setw(10) << truncate(first_name)
                    << "|" << std::setw(10) << truncate(last_name)
                    << "|" << std::setw(10) << truncate(nickname)
                    << "|\n";
        }

        void print_index() const {
            std::cout << "First name: " << first_name << std::endl;
            std::cout << "Last name: " << last_name << std::endl;
            std::cout << "Nickname: " << nickname << std::endl;
            std::cout << "Phone number: " << phone_number << std::endl;
            std::cout << "Darkest secret: " << secret << std::endl;
        }
};

class PhoneBook {
    private:
        Contacts contacts[8];
        int nbr;
        int next;

    public:
        PhoneBook() : nbr(0), next(0) {}

        void add_contact(void) {
            contacts[next].set_contact();
            next = (next + 1) % 8;
            if (nbr < 8)
                nbr++;
        }

        void search() const {
            if (nbr == 0) {
                std::cout << "No contacts yet." << std::endl;
                return;
            }

            std::cout << "|" << BLUE << std::setw(10) << "index" << RESET
                    << "|" << BLUE << std::setw(10) << "first name" << RESET
                    << "|" << BLUE << std::setw(10) << "last name" << RESET
                    << "|" << BLUE << std::setw(10) << "nickname" << RESET << "|\n";
            for (int i = 0; i < nbr; i++)
                contacts[i].print_contacts(i);

            std::string input;
            std::cout << "Enter index to view contact: ";
            std::getline(std::cin >> std::ws, input);
            if (std::cin.eof()) {
                std::cout << "\nEOF detected, exiting search..." << std::endl;
                return;
            }

            if (input.empty()) {
                std::cout << "Error: empty input." << std::endl;
                return;
            }
            if (input.length() != 1 || !isdigit(input[0])) {
                std::cout << "Error: index must be a single digit." << std::endl;
                return;
            }

            int index = atoi(input.c_str());
            if (index >= 0 && index < nbr)
                contacts[index].print_index();
            else
                std::cout << "Error: index must be between 0 and " << (nbr - 1) << " ." << std::endl;
        }
};

Commands get_enum(const std::string &command) {
    if (command == "EXIT")
        return EXIT;
    else if (command == "ADD")
        return ADD;
    else if (command == "SEARCH")
        return SEARCH;
    else
        return UNKNOWN;
}

int main(void) {
    PhoneBook pb;
    std::string command;
    bool last_is_unknown = false;

    while (1) {
        if (!last_is_unknown)
            std::cout << "Please put a command : ADD, SEARCH, EXIT" << std::endl;
        std::cout << "> ";
        std::getline(std::cin >> std::ws, command);

        if (std::cin.eof()) {
            std::cout << "\nEOF detected, exiting..." << std::endl;
            return 0;
        }

        if (command.empty()) {
            std::cout << "Error: command can't be empty" << std::endl;
            last_is_unknown = true;
            continue;
        }

        switch (get_enum(command)) {
            case UNKNOWN:
                std::cout << "Error: Please put an existing command (ADD, SEARCH, EXIT)" << std::endl;
                last_is_unknown = true;
                break;

            case EXIT:
                std::cout << "Bye bye..." << std::endl;
                return 0;

            case ADD:
                pb.add_contact();
                last_is_unknown = false;
                break;

            case SEARCH:
                pb.search();
                last_is_unknown = false;
                break;
        }
    }
    return 0;
}