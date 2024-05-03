/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:54:27 by lunagda           #+#    #+#             */
/*   Updated: 2024/04/10 17:04:13 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
	# define WRONGANIMAL_HPP
	#include <iostream>

	class WrongAnimal
	{
		protected:
			std::string _type;
		public:
			WrongAnimal();
			WrongAnimal(const WrongAnimal &copy);
			WrongAnimal(std::string type);
			virtual ~WrongAnimal();
			WrongAnimal &operator=(const WrongAnimal &copy);
			std::string getType() const;
			virtual void makeSound() const;
	};
#endif
