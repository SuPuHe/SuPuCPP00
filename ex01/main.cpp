/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:04:29 by omizin            #+#    #+#             */
/*   Updated: 2025/09/02 16:54:01 by omizin           ###   ########.fr       */
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

	phonebook->displayContacts();

	index_str = getUserInput("Enter index of contact: ");
	index = std::stoi(index_str);
	std::cout << index << std::endl;
}

int	main(void)
{
	PhoneBook phonebook;
	std::string command;

	while (1)
	{
		std::cout << "Wait for command" << std::endl;
		if (!(std::getline(std::cin, command)))
			return (1);
		if (command.compare("ADD") == 0)
			add_command(&phonebook);
		else if (command.compare("SEARCH") == 0)
		{
			search_command(&phonebook);
			std::cout << "It is SEARCH" << std::endl;
		}
		else if (command.compare("EXIT") == 0)
			break;
		else
			std::cout << "Command not found" << std::endl;
	}
	return (0);
}


// int main() {
//     PhoneBook phonebook;

//     // Create a few contacts
//     Contact c1;
//     c1.setFirstName("Alicejosdhiusdhuidhuid");
//     c1.setLastName("Smith");
//     c1.setNickname("Ali");
//     c1.setNumber(111111);
//     c1.setSecret("Loves pizza");

//     Contact c2;
//     c2.setFirstName("Bob");
//     c2.setLastName("Johnson");
//     c2.setNickname("Bobby");
//     c2.setNumber(222222);
//     c2.setSecret("Afraid of spiders");

//     Contact c3;
//     c3.setFirstName("Charlie");
//     c3.setLastName("Brown");
//     c3.setNickname("Chuck");
//     c3.setNumber(333333);
//     c3.setSecret("Has a pet turtle");

//     // Add contacts to the phonebook
//     phonebook.addContact(c1);
//     phonebook.addContact(c2);
//     phonebook.addContact(c3);

//     // Display all contacts
//     phonebook.displayContacts();

//     // Test overwriting: add 9 contacts
//     for (int i = 0; i < 9; i++) {
//         Contact temp;
//         temp.setFirstName("Test" + std::to_string(i));
//         temp.setLastName("User");
//         temp.setNickname("T" + std::to_string(i));
//         temp.setNumber(1000 + i);
//         temp.setSecret("Secret #" + std::to_string(i));
//         phonebook.addContact(temp);
//     }

//     std::cout << "\nAfter adding 9 contacts (should overwrite oldest):\n";
//     phonebook.displayContacts();

//     // Test getContact
//     std::cout << "\nContact at index 2:\n";
//     Contact fetched = phonebook.getContact(2);
//     std::cout << "First: " << fetched.getFirstName() << "\n"
//               << "Last: " << fetched.getLastName() << "\n"
//               << "Nick: " << fetched.getNickname() << "\n"
//               << "Number: " << fetched.getNumber() << "\n"
//               << "Secret: " << fetched.getSecret() << std::endl;

//     return 0;
// }
