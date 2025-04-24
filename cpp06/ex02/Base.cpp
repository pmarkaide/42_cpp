/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:34:13 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/04/24 12:50:08 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {
}

Base* generate(void) {
		
	int random = rand() % 3;
		
	switch (random) {
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			return NULL;
	}
}


// dynamic_cast return null if the cast cannot be done
// it safer, as we don't need to catch a throw
void identify(Base* p) {
	if (dynamic_cast<A*>(p) != nullptr) {
		std::cout << "A" << std::endl;
	} else if (dynamic_cast<B*>(p) != nullptr) {
		std::cout << "B" << std::endl;
	} else if (dynamic_cast<C*>(p) != nullptr) {
		std::cout << "C" << std::endl;
	} else {
		std::cout << "Unknown type" << std::endl;
	}
}

// We can't use pointers directly, so we use try/catch with dynamic_cast
// When dynamic_cast fails with references, it throws a std::bad_cast exception
void identify(Base& p) {

	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	} catch (std::bad_cast&) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	} catch (std::bad_cast&) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	} catch (std::bad_cast&) {}

	std::cout << "Unknown type" << std::endl;
}