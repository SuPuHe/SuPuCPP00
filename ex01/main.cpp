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

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

std::string getUserInput(std::string message)
{
	std::string user_input = "";

	while (user_input.length() == 0)
	{
		std::cout << YELLOW << message << RESET;
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
	int			index = -1;

	phonebook->displayContacts();

	index_str = getUserInput("Enter index of contact: ");

	try
	{
		index = std::stoi(index_str);
	}
	catch (const std::out_of_range &)
	{
		std::cout << RED << "Number is too large, try again." << RESET << std::endl;
		return;
	}
	catch (const std::invalid_argument &)
	{
		std::cout << RED << "Invalid input, try again." << RESET << std::endl;
		return;
	}
	if (index < 0 || index > 7 || phonebook->getContact(index).getFirstName().empty())
	{
		std::cout << RED << "Invalid index or empy contact" << RESET << std::endl;
		return;
	}
	Contact temp = phonebook->getContact(index);
	std::cout << CYAN << "Contact details by index: " << RESET << index << std::endl;
	std::cout << MAGENTA << "First Name: " << RESET << temp.getFirstName() << std::endl;
	std::cout << MAGENTA << "Last Name: " << RESET << temp.getLastName() << std::endl;
	std::cout << MAGENTA << "Nickname: " << RESET << temp.getNickname() << std::endl;
	std::cout << MAGENTA << "Number: " << RESET << temp.getNumber() << std::endl;
	std::cout << MAGENTA << "Secret: " << RESET << temp.getSecret() << std::endl;
}

int	main(void)
{
	PhoneBook phonebook;
	std::string command;

	while (1)
	{
		std::cout << GREEN << "Wait for command (ADD, SEARCH, EXIT)" << RESET << std::endl;
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
