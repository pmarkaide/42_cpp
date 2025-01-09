/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:52:53 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/09 20:17:21 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Character.hpp"

Character::Character() : name_(""), count_(0)
{
	for (int i = 0; i < 4; i++)
		materia_[i] = nullptr;
}

Character::Character(const std::string& name) : name_(name), count_(0)
{
	for (int i = 0; i < 4; i++)
		materia_[i] = nullptr;
}

Character::Character(const Character& other) : name_(other.name_), count_(other.count_)
{
	for (int i = 0; i < 4; i++)
	{
		if (other.materia_[i])
			materia_[i] = other.materia_[i]->clone();
		else
			materia_[i] = nullptr;
	}
}

Character& Character::operator=(const Character& other)
{
	if (this == &other)
		return *this;
	name_ = other.name_;
	count_ = other.count_;
	for (int i = 0; i < 4; i++)
	{
		if (materia_[i])
			delete materia_[i];
		if (other.materia_[i])
			materia_[i] = other.materia_[i]->clone();
		else
			materia_[i] = nullptr;
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (materia_[i])
			delete materia_[i];
	}
}

std::string const & Character::getName() const{
	return name_;
}

void Character::equip(AMateria* materia)
{
	if (count_ < 4 && materia)
	{
		for (int i = 0; i < 4; i++)
		{
			if (!materia_[i])
			{
				materia_[i] = materia;
				count_++;
				break;
			}
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && materia_[idx])
	{
		materia_[idx] = nullptr;
		count_--;
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && materia_[idx])
		materia_[idx]->use(target);
}
