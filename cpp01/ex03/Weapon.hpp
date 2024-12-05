/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:17:45 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/12/05 16:58:50 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <string>

class Weapon {
	private:
		std::string type_;
	
	public:
		Weapon(const std::string& type);
		const std::string& getType() const;
		void setType(const std::string& newType);
};