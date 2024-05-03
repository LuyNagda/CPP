/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:43:26 by lunagda           #+#    #+#             */
/*   Updated: 2024/04/13 15:22:09 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
	# define DOG_HPP
	#include "Animal.hpp"
	#include "Brain.hpp"
	class Dog : public Animal
	{
		private:
			Brain *_brain;
		public:
			Dog();
			Dog(const Dog &copy);
			Dog &operator=(const Dog &copy);
			~Dog();
			void makeSound() const;
	};
#endif
