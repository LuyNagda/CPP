/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 11:02:42 by luynagda          #+#    #+#             */
/*   Updated: 2024/04/05 12:22:34 by lunagda          ###   ########.fr       */
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
		Fixed(const int value);
		Fixed(const float value);

		//Destructor
		~Fixed(void);

		//Overloading operators
		Fixed &operator = (const Fixed &copy);
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream &operator << (std::ostream &out, const Fixed &copy);