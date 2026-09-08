/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 16:42:38 by marudlof          #+#    #+#             */
/*   Updated: 2026/09/07 16:42:46 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "=== Construction ===" << std::endl;
	ClapTrap	bob("Bob");
	ClapTrap	rusty("Rusty");

	std::cout << std::endl << "=== Basic actions ===" << std::endl;
	bob.attack("Rusty");
	rusty.takeDamage(4);
	rusty.beRepaired(2);

	std::cout << std::endl << "=== Draining every energy point ===" << std::endl;
	for (int i = 0; i < 10; i++)
		bob.attack("Rusty");
	bob.beRepaired(5);

	std::cout << std::endl << "=== Taking a lethal hit ===" << std::endl;
	rusty.takeDamage(100);
	rusty.takeDamage(1);
	rusty.beRepaired(10);

	std::cout << std::endl << "=== Orthodox Canonical Form ===" << std::endl;
	ClapTrap	copy(bob);
	ClapTrap	assigned;
	assigned = bob;
	std::cout << "copy: " << copy.getName() << " hp=" << copy.getHitPoints()
		<< " ep=" << copy.getEnergyPoints()
		<< " ad=" << copy.getAttackDamage() << std::endl;
	std::cout << "assigned: " << assigned.getName()
		<< " hp=" << assigned.getHitPoints()
		<< " ep=" << assigned.getEnergyPoints()
		<< " ad=" << assigned.getAttackDamage() << std::endl;

	std::cout << std::endl << "=== Destruction ===" << std::endl;
	return (0);
}
