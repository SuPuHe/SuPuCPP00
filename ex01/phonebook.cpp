/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:33:07 by omizin            #+#    #+#             */
/*   Updated: 2025/09/03 16:32:54 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iostream>
#include <cstring>
#include <iomanip>

PhoneBook::PhoneBook() : next_index(0) {};

void PhoneBook::addContact(const Contact &c)
{
	contacts[next_index] = c;
	next_index = (next_index + 1) % 8;
}

Contact PhoneBook::getContact(int index) const
{
	if (index >= 0 && index < 8)
		return (contacts[index]);
	return (Contact());
}

static std::string formatField(const std::string &str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (std::string(10 - str.length(), ' ') + str);
}

void PhoneBook::displayContacts() const
{
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;

	for (int i = 0; i < 8; i++)
	{
		if (contacts[i].getFirstName().empty())
			continue;

		std::cout << "|"
				<< std::setw(10) << i << "|"
				<< formatField(contacts[i].getFirstName()) << "|"
				<< formatField(contacts[i].getLastName()) << "|"
				<< formatField(contacts[i].getNickname()) << "|"
				<< std::endl;
		std::cout << "---------------------------------------------" << std::endl;
	}
}
