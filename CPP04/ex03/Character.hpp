/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:41:52 by lunagda           #+#    #+#             */
/*   Updated: 2024/05/14 14:07:49 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP

# define CHARACTER_HPP
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
	public:
		Character(std::string name);
		Character(const Character &copy);
		~Character();
		Character &operator=(const Character &copy);
		std::string const &getName() const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
		AMateria *getMateriaFromInventory(int idx);
	private:
		std::string const	_name;
		AMateria	*(_inventory[4]);
};

#endif
