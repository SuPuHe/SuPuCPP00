/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:20:21 by omizin            #+#    #+#             */
/*   Updated: 2025/09/01 15:34:00 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact() : first_name(""), last_name(""), number(0), secret("") {}

void Contact::setFirstName(const std::string &fn) { first_name = fn; }
void Contact::setLastName(const std::string &ln) { last_name = ln; }
void Contact::setNumber(int num) { number = num; }
void Contact::setSecret(const std::string &sec) { secret = sec; }

std::string Contact::getFirstName() const { return first_name; }
std::string Contact::getLastName() const { return last_name; }
int Contact::getNumber() const { return number; }
std::string Contact::getSecret() const { return secret; }
