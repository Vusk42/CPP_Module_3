/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 16:44:58 by marudlof          #+#    #+#             */
/*   Updated: 2026/09/08 15:48:01 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap: " << this->_name
		<< " :Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap: " << this->_name
		<< " :String assignment constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap: " << this->_name
		<< " :Copy constructor called" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap: " << this->_name
		<< " :Copy assignment operator called" << std::endl;
	if (this != &other)
		this->ClapTrap::operator=(other);
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap: " << this->_name
		<< " :Destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name
			<< " has no hit points left and cannot attack." << std::endl;
		return ;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name
			<< " has no energy points left and cannot attack." << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << "ScavTrap " << this->_name << " savagely bites " << target
		<< ", causing " << this->_attackDamage << " points of damage!"
		<< std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->_name
		<< " is now in Gate keeper mode." << std::endl;
}
