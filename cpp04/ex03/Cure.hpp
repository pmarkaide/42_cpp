/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:55:03 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/09 20:28:07 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICUREHPP
#define ICUREHPP
class Cure: public AMateria{
	private:
		std::string type_;

	public:
		Cure();
		~Cure();
		Cure(const Cure& other);
		Cure& operator=(const Cure& other);
		
		AMateria* clone() const override;
		void use(ICharacter& target) override;
};

#endif // CURE_HPP