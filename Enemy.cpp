/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:18:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/04/03 16:18:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "Enemy.hpp"

// ----------------------------- Coplien Form ------------------------------- //

Enemy::Enemy() : AScreenElement (0, 0) {}

Enemy::~Enemy() {}

Enemy &Enemy::operator= (const Enemy &element)
{
	if (this != &element)
		AScreenElement::operator= (element);
	return (*this);
}

Enemy::Enemy (const Enemy &element)
		: AScreenElement(element) {}

// -------------------------------------------------------------------------- //
// ------------------------------- Constructor ------------------------------ //

Enemy::Enemy(int x, int y) : AScreenElement(x, y) {}

// -------------------------------------------------------------------------- //
// ----------------------------- Member Function ---------------------------- //

void 	Enemy::printElement() const
{
	attron(COLOR_PAIR(3));
	mvprintw(this->y_, this->x_, "O");
	attroff(COLOR_PAIR(3));
}

bool	Enemy::move()
{
	if (this->x_ > this->minX_)
	{
		this->x_--;
		return (true);
	}
	return (false);
}

// --------------------------------------------------------------------------- //
