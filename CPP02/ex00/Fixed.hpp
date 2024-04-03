/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luynagda <luynagda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 11:02:42 by luynagda          #+#    #+#             */
/*   Updated: 2024/03/17 11:08:48 by luynagda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
	private:
		int	_value;
		static const int _bits;
	public:
		//Constructors
		Fixed(void);
		Fixed(const Fixed &copy);

		//Destructor
		~Fixed(void);

		//Overloading operators
		Fixed &operator = (const Fixed &copy);
		
		int	getRawBits(void) const;
		void setRawBits(int const raw);
};
