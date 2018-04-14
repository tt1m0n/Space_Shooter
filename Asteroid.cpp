/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asteroid.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 16:52:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/04/08 16:52:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <cstdlib>
#include <sys/time.h>
#include "Asteroid.hpp"


// -------------------------------- Coplien Form ---------------------------- //

Asteroid::Asteroid() : AScreenElement (0, 0)
{
	srand(time(NULL));
}

Asteroid::~Asteroid() {}

Asteroid &Asteroid::operator= (const Asteroid &element)
{
	if (this != &element)
		AScreenElement::operator= (element);
	return (*this);
}

Asteroid::Asteroid (const Asteroid &element)
		: AScreenElement(element) {}

// -------------------------------------------------------------------------- //
// -------------------------------- Constructor ----------------------------- //

Asteroid::Asteroid(int x, int y) : AScreenElement(x, y) {}

// -------------------------------------------------------------------------- //
// ------------------------------ Member Function --------------------------- //

void 	Asteroid::printElement() const
{
	attron(COLOR_PAIR(9));
	mvprintw(this->y_, this->x_, ".");
	attroff(COLOR_PAIR(9));
}

bool	Asteroid::move()
{
	if (this->x_ > this->minX_)
	{
		this->x_--;
		return (true);
	}
	return (false);
}

// ------------------------------------------------------------------------- //
