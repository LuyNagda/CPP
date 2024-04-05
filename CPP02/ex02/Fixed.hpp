/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 11:02:42 by luynagda          #+#    #+#             */
/*   Updated: 2024/04/05 13:00:08 by lunagda          ###   ########.fr       */
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
		Fixed	&operator = (const Fixed &copy);
		bool	operator > (const Fixed &copy) const;
		bool	operator < (const Fixed &copy) const;
		bool	operator >= (const Fixed &copy) const;
		bool	operator <= (const Fixed &copy) const;
		bool	operator == (const Fixed &copy) const;
		bool	operator != (const Fixed &copy) const;

		Fixed	operator + (const Fixed &copy) const;
		Fixed	operator - (const Fixed &copy) const;
		Fixed	operator / (const Fixed &copy) const;
		Fixed	operator * (const Fixed &copy) const;

		Fixed	&operator ++ (void);
		Fixed	operator ++ (int);
		Fixed	&operator -- (void);
		Fixed	operator -- (int);

		static Fixed		&min(Fixed &a, Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream &operator << (std::ostream &out, const Fixed &copy);