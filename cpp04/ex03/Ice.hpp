/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:54:01 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/09 15:35:33 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP
class Ice: public AMateria{
	private:
		std::string type_;

	public:
		Ice();
		~Ice();
		Ice(const Ice& other);
		Ice& operator=(const Ice& other);
		
		AMateria* clone() const override;
		void use(ICharacter& target) override;
};

#endif // ICE_HPP