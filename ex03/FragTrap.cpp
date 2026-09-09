/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 17:04:33 by marudlof          #+#    #+#             */
/*   Updated: 2026/09/09 15:39:47 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void) : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap: " << this->_name
		<< ": Default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap: " << this->_name
		<< ": String assignment constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap: " << this->_name
		<< ": Copy constructor called" << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap: " << this->_name
		<< ": Copy assignment operator called" << std::endl;
	if (this != &other)
		this->ClapTrap::operator=(other);
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap: " << this->_name
		<< ": Destructor called" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name
		<< " high fives, guys!" << std::endl;
}
