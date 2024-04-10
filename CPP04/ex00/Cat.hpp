/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:38:52 by lunagda           #+#    #+#             */
/*   Updated: 2024/04/10 16:52:59 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
	# define CAT_HPP
	#include "Animal.hpp"

	class Cat : public Animal
	{
		public:
			Cat();
			Cat(const Cat &copy);
			Cat &operator=(const Cat &copy);
			~Cat();
			void makeSound() const;
	};
#endif
