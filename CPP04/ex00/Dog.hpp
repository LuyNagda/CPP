/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:43:26 by lunagda           #+#    #+#             */
/*   Updated: 2024/04/10 16:52:57 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
	# define DOG_HPP
	#include "Animal.hpp"

	class Dog : public Animal
	{
		public:
			Dog();
			Dog(const Dog &copy);
			Dog &operator=(const Dog &copy);
			~Dog();
			void makeSound() const;
	};
#endif
