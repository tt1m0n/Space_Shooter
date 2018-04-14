/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpaceShip.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 17:00:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/03/29 17:00:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "SpaceShip.hpp"

// ----------------------------- Coplien Form -------------------------------

SpaceShip::SpaceShip() : AScreenElement(8, 17){}

SpaceShip::~SpaceShip() {}

SpaceShip &SpaceShip::operator= (const SpaceShip &element)
{
	if (this != &element)
		AScreenElement::operator= (element);
	return (*this);
}

SpaceShip::SpaceShip (const SpaceShip &element)
		  : AScreenElement(element) {}

// -------------------------------------------------------------------------- //
// ----------------------------- Member Function ---------------------------- //

void 	SpaceShip::printElement() const
{
	attron(COLOR_PAIR(9));
	mvprintw(this->y_ - 1, this->x_, "\\");
	mvprintw(this->y_, this->x_, "<>");
	mvprintw(this->y_ + 1, this->x_, "/");
	attroff(COLOR_PAIR(9));
}

bool	SpaceShip::move ()
{
	return (true); // TODO it is bad
}

bool	SpaceShip::move(int input)
{
	if (input == KEY_UP && y_ - 1 > minY_)
		y_--;
	else if (input == KEY_DOWN && y_ + 1 < maxY_)
		y_++;
	else if (input == KEY_LEFT && x_> minX_)
		x_--;
	else if (input == KEY_RIGHT && x_ < maxX_)
		x_++;
	return (true);
}

bool	SpaceShip::collision(AScreenElement *elem)
{
	return ((y_ == elem->getY() && x_ + 1 == elem->getX()) ||
            (y_ - 1 == elem->getY() && x_ + 1 == elem->getX()) ||
            (y_ + 1 == elem->getY() && x_ + 1 == elem->getX()));
}

// --------------------------------------------------------------------------- //	