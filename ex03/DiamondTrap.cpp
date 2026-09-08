/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 17:06:35 by marudlof          #+#    #+#             */
/*   Updated: 2026/09/08 15:48:44 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(void) :
	ClapTrap("default_clap_name"),
	ScavTrap(),
	FragTrap(),
	_name("default")
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;
	std::cout << "DiamondTrap: " << this->_name
		<< " :Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) :
	ClapTrap(name + "_clap_name"),
	ScavTrap(name),
	FragTrap(name),
	_name(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;
	std::cout << "DiamondTrap: " << this->_name
		<< " :String assignment constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) :
	ClapTrap(other),
	ScavTrap(other),
	FragTrap(other),
	_name(other._name)
{
	std::cout << "DiamondTrap: " << this->_name
		<< " :Copy constructor called" << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "DiamondTrap: " << this->_name
		<< " :Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->ClapTrap::operator=(other);
		this->_name = other._name;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap: " << this->_name
		<< " :Destructor called" << std::endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	this->ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "I am DiamondTrap " << this->_name
		<< ", and my ClapTrap name is " << this->ClapTrap::getName() << "."
		<< std::endl;
}
