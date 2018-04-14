/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Health.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 20:26:37 by omakovsk          #+#    #+#             */
/*   Updated: 2018/04/08 20:26:40 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "Health.hpp"

// ----------------------------- Coplien Form ------------------------------- //

Health::Health() : AScreenElement (0, 0) {}

Health::~Health() {}

Health &Health::operator= (const Health &element)
{
	if (this != &element)
		AScreenElement::operator= (element);
	return (*this);
}

Health::Health (const Health &element)
		: AScreenElement(element) {}

// -------------------------------------------------------------------------- //
// ------------------------------- Constructor ------------------------------ //

Health::Health(int x, int y) : AScreenElement(x, y) {}		

// -------------------------------------------------------------------------- //
// ----------------------------- Member Function ---------------------------- //

void 	Health::printElement() const
{
	attron(COLOR_PAIR(2));
	mvprintw(this->y_, this->x_, "+1");
	attroff(COLOR_PAIR(2));
}

bool	Health::move()
{
	if (this->x_ > this->minX_)
	{
		this->x_--;
		return (true);
	}
	return (false);
}

// --------------------------------------------------------------------------- //
