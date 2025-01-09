/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:35:04 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/08 15:48:23 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BRAIN_HPP
 #define BRAIN_HPP

# include <iostream>

class Brain {
	private:
		std::string ideas_[100];
	
	public:
		Brain();
		Brain(const Brain &other);
		Brain &operator=(const Brain &other);
		~Brain();

		void setIdea(int index, const std::string& idea);
		const std::string& getIdea(int index) const;
};
#endif // BRAIN_HPP