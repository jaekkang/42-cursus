/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 09:25:15 by jaekkang          #+#    #+#             */
/*   Updated: 2023/05/02 09:49:14 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

int main(int ac, char **av)
{	
	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < ac; i++)
			for (int j = 0; av[i][j] != '\0'; j++)
				std::cout.put(toupper(av[i][j]));
	}
	std::cout.put('\n');
}