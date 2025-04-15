/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:15:47 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/04/15 17:30:23 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint>
#include "Data.hpp"

class Serializer {
private:
	Serializer() = delete;
	~Serializer() = default;
	Serializer(const Serializer&) = delete;
	Serializer& operator=(const Serializer&) = delete;
		
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif // SERIALIZER_HPP