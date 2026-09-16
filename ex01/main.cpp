/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 16:44:48 by marudlof          #+#    #+#             */
/*   Updated: 2026/09/16 17:12:06 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "=== A plain ClapTrap ===" << std::endl;
	ClapTrap	bob("Bob");
	bob.attack("the training dummy");

	std::cout << std::endl << "=== Construction chaining ===" << std::endl;
	{
		ScavTrap	serena("Serena");

		std::cout << std::endl << "=== Inherited stats ===" << std::endl;
		std::cout << serena.getName() << ": hp=" << serena.getHitPoints()
			<< " ep=" << serena.getEnergyPoints()
			<< " ad=" << serena.getAttackDamage() << std::endl;

		std::cout << std::endl << "=== ScavTrap in action ===" << std::endl;
		serena.attack("Bob");
		serena.guardGate();
		serena.takeDamage(40);
		serena.beRepaired(15);

		std::cout << std::endl << "=== Inherited stats (after actions) ===" << std::endl;
		std::cout << serena.getName() << ": hp=" << serena.getHitPoints()
			<< " ep=" << serena.getEnergyPoints()
			<< " ad=" << serena.getAttackDamage() << std::endl;

		std::cout << std::endl << "=== Copy and assignment ===" << std::endl;
		ScavTrap	clone(serena);
		ScavTrap	other("Kevin");
		other = serena;

		std::cout << std::endl << "=== Destruction chaining (reverse order) ==="
			<< std::endl;
	}

	std::cout << std::endl << "=== End of main ===" << std::endl;
	return (0);
}
