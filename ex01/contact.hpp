/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:15:55 by omizin            #+#    #+#             */
/*   Updated: 2025/09/01 15:19:41 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		int			number;
		std::string secret;

	public:
		Contact();

		void setFirstName(const std::string &fn);
		void setLastName(const std::string &ln);
		void setNumber(int num);
		void setSecret(const std::string &sec);

		std::string getFirstName() const;
		std::string getLastName() const;
		int getNumber() const;
		std::string getSecret() const;
};

#endif
