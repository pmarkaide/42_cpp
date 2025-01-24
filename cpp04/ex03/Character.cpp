/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:52:53 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/24 13:14:51 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Character.hpp"

Character::Character() : name_(""), floor_(nullptr), count_(0)
{
	for (int i = 0; i < 4; i++)
		materia_[i] = nullptr;
	std::cout << "Character default constructor called" << std::endl;
}

Character::Character(const std::string& name) : name_(name), floor_(nullptr), count_(0)
{
	for (int i = 0; i < 4; i++)
		materia_[i] = nullptr;
	std::cout << "Character constructor called" << std::endl;
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

    t_floor* current = other.floor_;
    t_floor** head = &floor_;
    while (current)
    {
        *head = new t_floor(*current);
        (*head)->next = nullptr;
        head = &((*head)->next);
        current = current->next;
    }
	std::cout << "Character copy constructor called" << std::endl;
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
	
	t_floor* current = floor_;
	while (current)
	{
		t_floor* tmp = current;
		current = current->next;
		delete tmp;
	}
	floor_ = nullptr;

	t_floor* other_current = other.floor_;
    t_floor** head = &floor_;
    while (other_current)
    {
        *head = new t_floor(*other_current);
        (*head)->next = nullptr;
        head = &((*head)->next);
        other_current = other_current->next;
    }

	std::cout << "Character copy assignment operator called" << std::endl;
	return *this;
}

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << "going to CRASH" << std::endl;
		
		if (materia_[i] && !materia_[i]->getFloor()){
			delete materia_[i];
			materia_[i] = nullptr;
		}
	}

	while (floor_) {
    t_floor* tmp = floor_;
    floor_ = floor_->next;
    if (tmp->materia_) {
        delete tmp->materia_;
        tmp->materia_ = nullptr;
    }
    delete tmp;
	}
}

std::string const & Character::getName() const{
	return name_;
}

void Character::equip(AMateria* materia)
{
	if(!materia){
		std::cout << "Nothing to equip!" << std::endl;
		return;
	}

	if(materia->getOwned() == true){
		std::cout << "This materia has been equiped already!" << std::endl;
		return;
	}

	if (count_ < 4 && materia)
	{
		for (int i = 0; i < 4; i++)
		{
			if (!materia_[i])
			{
				materia_[i] = materia;
				std::cout << "Equipped " << materia->getType() << " in slot " << i << std::endl;
				materia->setOwned(true);
				count_++;
				break;
			}
		}
	}
	else
		std::cout << "Inventory is full. Unequip something to add a new Materia" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && materia_[idx])
	{
		std::cout << "Throwing " + materia_[idx]->getType() + " to the floor" << std::endl;
		materia_[idx]->setFloor(true);
		t_floor* new_node = new t_floor();
		new_node->materia_ = materia_[idx];
		new_node->next = floor_;
		floor_ = new_node;
		materia_[idx] = nullptr;
		count_--;
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && materia_[idx])
		materia_[idx]->use(target);
}
