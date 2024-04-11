/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:55:26 by lunagda           #+#    #+#             */
/*   Updated: 2024/04/10 16:58:47 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP

	# define WRONGCAT_HPP
	#include "WrongAnimal.hpp"

	class WrongCat : public WrongAnimal
	{
		public:
			WrongCat();
			WrongCat(const WrongCat &copy);
			WrongCat &operator=(const WrongCat &copy);
			~WrongCat();
			void makeSound() const;
	};
#endif
