/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 17:07:29 by marudlof          #+#    #+#             */
/*   Updated: 2026/09/07 17:07:30 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string	_name;

	public:
		DiamondTrap(void);
		DiamondTrap(const std::string& name);
		DiamondTrap(const DiamondTrap& other);
		DiamondTrap&	operator=(const DiamondTrap& other);
		~DiamondTrap(void);

		void	attack(const std::string& target);
		void	whoAmI(void);
};

#endif
