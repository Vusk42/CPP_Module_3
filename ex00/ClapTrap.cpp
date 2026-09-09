/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 16:37:47 by marudlof          #+#    #+#             */
/*   Updated: 2026/09/09 15:36:08 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void) :
	_name("default"),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0)
{
	std::cout << "ClapTrap: " << this->_name
		<< ": Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) :
	_name(name),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0)
{
	std::cout << "ClapTrap: " << this->_name
		<< ": String assignment constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) :
	_name(other._name),
	_hitPoints(other._hitPoints),
	_energyPoints(other._energyPoints),
	_attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap: " << this->_name
		<< ": Copy constructor called" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap: " << this->_name
		<< ": Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap: " << this->_name
		<< ": Destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name
			<< " has no hit points left and cannot attack." << std::endl;
		return ;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name
			<< " has no energy points left and cannot attack." << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target
		<< ", causing " << this->_attackDamage << " points of damage!"
		<< std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name
			<< " is already out of hit points." << std::endl;
		return ;
	}
	if (amount >= this->_hitPoints)
	{
		this->_hitPoints = 0;
		std::cout << "ClapTrap " << this->_name << " takes " << amount
			<< " points of damage and collapses!" << std::endl;
		return ;
	}
	this->_hitPoints -= amount;
	std::cout << "ClapTrap " << this->_name << " takes " << amount
		<< " points of damage! " << this->_hitPoints << " hit points left."
		<< std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name
			<< " has no hit points left and cannot repair itself." << std::endl;
		return ;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name
			<< " has no energy points left and cannot repair itself."
			<< std::endl;
		return ;
	}
	this->_energyPoints--;
	this->_hitPoints += amount;
	std::cout << "ClapTrap " << this->_name << " repairs itself for " << amount
		<< " hit points! " << this->_hitPoints << " hit points now."
		<< std::endl;
}

const std::string&	ClapTrap::getName(void) const
{
	return (this->_name);
}

unsigned int	ClapTrap::getHitPoints(void) const
{
	return (this->_hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints(void) const
{
	return (this->_energyPoints);
}

unsigned int	ClapTrap::getAttackDamage(void) const
{
	return (this->_attackDamage);
}
