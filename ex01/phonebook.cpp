/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:33:07 by omizin            #+#    #+#             */
/*   Updated: 2025/09/01 15:37:00 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iostream>

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
