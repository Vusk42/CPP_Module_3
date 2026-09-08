/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 17:07:37 by marudlof          #+#    #+#             */
/*   Updated: 2026/09/08 16:02:18 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "=== ClapTrap ===" << std::endl;
	{
		ClapTrap	bob("Bob");
		bob.attack("the training dummy");
	}

	std::cout << std::endl << "=== ScavTrap ===" << std::endl;
	{
		ScavTrap	serena("Serena");
		serena.attack("Bob");
		serena.guardGate();
	}

	std::cout << std::endl << "=== FragTrap ===" << std::endl;
	{
		FragTrap	frag("Frag");
		frag.attack("Bob");
		frag.highFivesGuys();
	}

	std::cout << std::endl << "=== DiamondTrap construction ===" << std::endl;
	{
		DiamondTrap	gemma("Gemma");

		std::cout << std::endl << "=== Who am I? ===" << std::endl;
		gemma.whoAmI();

		std::cout << std::endl << "=== Abilities from both parents ==="
			<< std::endl;
		gemma.attack("Bob");
		gemma.guardGate();
		gemma.highFivesGuys();

		std::cout << std::endl << "=== Stats: hp/ad from FragTrap, ep from "
			"ScavTrap ===" << std::endl;
		std::cout << "ClapTrap name: " << gemma.getName() << std::endl;
		std::cout << "hp=" << gemma.getHitPoints()
			<< " ep=" << gemma.getEnergyPoints()
			<< " ad=" << gemma.getAttackDamage() << std::endl;

		std::cout << std::endl << "=== Inherited ClapTrap actions ==="
			<< std::endl;
		gemma.takeDamage(45);
		gemma.beRepaired(10);

		std::cout << std::endl << "=== Copy and assignment ===" << std::endl;
		DiamondTrap	clone(gemma);
		clone.whoAmI();
		DiamondTrap	spare("Spare");
		spare = gemma;
		spare.whoAmI();

		std::cout << std::endl << "=== DiamondTrap destruction ===" << std::endl;
	}

	std::cout << std::endl << "=== Deleting through a ClapTrap pointer ==="
		<< std::endl;
	{
		ClapTrap	*ptr = new DiamondTrap("Heap");
		ptr->takeDamage(10);
		delete ptr;
	}
}
