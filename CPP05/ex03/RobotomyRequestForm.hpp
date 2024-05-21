/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:33:13 by lunagda           #+#    #+#             */
/*   Updated: 2024/05/21 16:16:33 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP

# define ROBOTOMYREQUESTFORM_HPP
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class RobotomyRequestForm : public Form
{
	private:
		const std::string target;
		RobotomyRequestForm();
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
		~RobotomyRequestForm();
		void execute(Bureaucrat const &executor) const;
		std::string getTarget(void) const;
		static Form *makeForm(Form *form, std::string const name, std::string const target);
};

#endif