/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:03:04 by lunagda           #+#    #+#             */
/*   Updated: 2024/05/22 11:35:45 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern;

typedef Form* (Intern::*CF)(const std::string&) const;

class Intern
{
	private:
		static const std::string	names[3];
		static const CF				forms[3];
		Form *ShrubberyCreation(const std::string &target) const;
		Form *RobotomyRequest(const std::string &target) const;
		Form *PresidentialPardon(const std::string &target) const;
	public:
		Intern();
		Intern(Intern const & obj);
		~Intern();
		Intern & operator=(Intern const & obj);
		Form *makeForm(std::string const name, std::string const target);
		
		class FormNotFoundException : public std::exception
		{
			virtual const char * what() const throw();
		};
};

#endif
