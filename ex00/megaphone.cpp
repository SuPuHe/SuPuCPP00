/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:04:36 by omizin            #+#    #+#             */
/*   Updated: 2025/09/01 15:04:46 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		{
			for (int i = 1; i < argc; i++)
			{
				std::string word = argv[i];
				for (char &c : word)
					c = std::toupper(c);
				std::cout << word;
			}
			std::cout << std::endl;
		}
	return (0);
}
