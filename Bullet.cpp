/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:13:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/04/03 13:13:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bullet.hpp"
#include <ncurses.h>

// --------------------------------- Coplien Form --------------------------- //

Bullet::Bullet () : AScreenElement(0, 0) {}

Bullet::~Bullet() {}

Bullet &Bullet::operator= (const Bullet &element)
{
	if (this != &element)
		AScreenElement::operator= (element);
	return (*this);
}

Bullet::Bullet (const Bullet &element)
		: AScreenElement(element) {}

// --------------------------------------------------------------------------- //
// ----------------------------- Constructor --------------------------------- //

Bullet::Bullet(int x, int y) : AScreenElement(x + 1, y) {}

// --------------------------------------------------------------------------- //
// ------------------------------ Member Function ---------------------------- //

void 	Bullet::printElement() const
{
	attron(COLOR_PAIR(2));
	mvprintw(y_, x_, "=");
	attroff(COLOR_PAIR(2));
}

bool	Bullet::move()
{
	if (x_ < maxX_)
	{
		x_++;
		return (true);
	}
	else
		return (false);
}

bool	Bullet::collision(AScreenElement *elem)
{
	return (y_ == elem->getY() && x_ >= elem->getX());
}

// --------------------------------------------------------------------------- //