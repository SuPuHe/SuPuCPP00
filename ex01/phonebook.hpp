/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:06:06 by omizin            #+#    #+#             */
/*   Updated: 2025/09/03 16:28:58 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <string>
#include "contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int		next_index;

	public:
		PhoneBook();

		void addContact(const Contact &c);
		Contact getContact(int index) const;
		void displayContacts() const;
};

#endif
