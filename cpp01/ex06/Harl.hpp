/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:00:42 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/12/07 18:00:45 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <string>
# include <iostream>
#include <map>

class Harl {
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );

	public:
		void complain( std::string level );
};