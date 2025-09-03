/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:04:29 by omizin            #+#    #+#             */
/*   Updated: 2025/09/03 16:08:34 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "contact.hpp"
#include "phonebook.hpp"

std::string getUserInput(std::string message)
{
	std::string user_input = "";

	while (user_input.length() == 0)
	{
		std::cout << message;
		if (!(std::getline(std::cin, user_input)))
			exit(0);
	}
	return (user_input);
}

void	add_command(PhoneBook *phonebook)
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string number;
	std::string secret;

	first_name = getUserInput("Enter first name: ");
	last_name = getUserInput("Enter last name: ");
	nickname = getUserInput("Enter nickname: ");
	number = getUserInput("Enter number: ");
	secret = getUserInput("Enter secret: ");

	Contact temp;
	temp.setFirstName(first_name);
	temp.setLastName(last_name);
	temp.setNickname(nickname);
	temp.setNumber(number);
	temp.setSecret(secret);
	phonebook->addContact(temp);
}

void	search_command(PhoneBook *phonebook)
{
	std::string	index_str;
	int			index;

	index_str = getUserInput("Enter index of contact: ");
	for (size_t i = 0; i < index_str.size(); i++)
	{
		if (!(std::isdigit(index_str[i])))
		{
			std::cout << "Only digits allowed" << std::endl;
			return search_command(phonebook);
		}
	}
	try
	{
		index = std::stoi(index_str);
	}
	catch (const std::out_of_range &)
	{
		std::cout << "Number is too large, try again." << std::endl;
		return search_command(phonebook);
	}
	catch (const std::invalid_argument &)
	{
		std::cout << "Invalid input, try again." << std::endl;
		return search_command(phonebook);
	}
	if (!(index >= 0 && index <= 7))
		std::cout << "Index beyond range. Display all contacts" << std::endl;
	phonebook->displayContacts(index);
}

int	main(void)
{
	PhoneBook phonebook;
	std::string command;

	while (1)
	{
		std::cout << "Wait for command (ADD, SEARCH, EXIT)" << std::endl;
		if (!(std::getline(std::cin, command)))
			return (1);
		if (command.compare("ADD") == 0)
			add_command(&phonebook);
		else if (command.compare("SEARCH") == 0)
			search_command(&phonebook);
		else if (command.compare("EXIT") == 0)
			break;
	}
	return (0);
}
