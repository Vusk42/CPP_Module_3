/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 17:05:36 by marudlof          #+#    #+#             */
/*   Updated: 2026/09/16 17:13:49 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "=== ClapTrap ===" << std::endl;
	ClapTrap	bob("Bob");
	bob.attack("the training dummy");

	std::cout << std::endl << "=== ScavTrap ===" << std::endl;
	{
		ScavTrap	serena("Serena");
		serena.attack("Bob");
		serena.guardGate();
	}

	std::cout << std::endl << "=== FragTrap construction chaining ==="
		<< std::endl;
	{
		FragTrap	frag("Frag");

		std::cout << frag.getName() << ": hp=" << frag.getHitPoints()
			<< " ep=" << frag.getEnergyPoints()
			<< " ad=" << frag.getAttackDamage() << std::endl;

		std::cout << std::endl << "=== FragTrap in action ===" << std::endl;
		frag.attack("Bob");
		frag.highFivesGuys();
		frag.takeDamage(35);
		frag.beRepaired(20);
		std::cout << frag.getName() << ": hp=" << frag.getHitPoints()
			<< " ep=" << frag.getEnergyPoints()
			<< " ad=" << frag.getAttackDamage() << std::endl;

		std::cout << std::endl << "=== Copy and assignment ===" << std::endl;
		FragTrap	clone(frag);
		FragTrap	other("Spare");
		other = frag;

		std::cout << std::endl << "=== FragTrap destruction chaining ==="
			<< std::endl;
	}

	std::cout << std::endl << "=== End of main ===" << std::endl;
	return (0);
}
