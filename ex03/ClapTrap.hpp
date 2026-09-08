/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 16:45:20 by marudlof          #+#    #+#             */
/*   Updated: 2026/09/07 17:03:36 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap
{
	protected:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;

	public:
		ClapTrap(void);
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& other);
		ClapTrap&	operator=(const ClapTrap& other);
		virtual ~ClapTrap(void);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		const std::string&	getName(void) const;
		unsigned int		getHitPoints(void) const;
		unsigned int		getEnergyPoints(void) const;
		unsigned int		getAttackDamage(void) const;
};

#endif
