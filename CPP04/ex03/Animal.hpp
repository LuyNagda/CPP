/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luynagda <luynagda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:22:40 by lunagda           #+#    #+#             */
/*   Updated: 2024/04/15 19:41:19 by luynagda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
	# define ANIMAL_HPP
	#include <iostream>

	class Animal
	{
		protected:
			std::string _type;
		public:
			Animal();
			Animal(const Animal &copy);
			Animal(std::string type);
			virtual ~Animal();
			Animal &operator=(const Animal &copy);
			std::string getType() const;
			virtual void makeSound() const = 0;
	};
#endif
