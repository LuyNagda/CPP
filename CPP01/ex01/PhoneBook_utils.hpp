/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_utils.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:00:22 by lunagda           #+#    #+#             */
/*   Updated: 2024/02/01 13:10:21 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_UTILS_HPP

# define PHONEBOOK_UTILS_HPP

# include <iostream>
# include "Contact.hpp"

/* Returns a string with n spaces */
std::string	add_spaces(int n);

/* Ensures a string has at most 'max' chars, adding '.' when needed */
std::string	fix_width(std::string str, long unsigned max);

/* Prints existing contacts with a pretty format */
int			search_ui(Contact contacts[8]);

#endif