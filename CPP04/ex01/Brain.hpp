/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:26:50 by lunagda           #+#    #+#             */
/*   Updated: 2024/04/11 12:34:57 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP

	# define BRAIN_HPP
	#include <iostream>
	class Brain
	{
		public:
			Brain();
			Brain(const Brain &copy);
			Brain &operator=(const Brain &copy);
			~Brain();
			std::string ideas[100];
	};
	
#endif
