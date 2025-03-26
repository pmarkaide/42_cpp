/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 11:50:06 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/03/26 12:07:11 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	INTERN_HPP
 #define 	INTERN_HPP

#include "AForm.hpp"

class Intern{
	public:
		AForm* makeForm(std::string form, std::string target);
};


#endif // 	INTERN_HPP