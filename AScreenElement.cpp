/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AScreenElement.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:35:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/03/29 16:35:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AScreenElement.hpp"

// ---------------------------- Coplien Form -------------------------------- //

AScreenElement::AScreenElement()
{
	x_ = 4;
	y_ = 4;
	minX_ = 4;
	minY_ = 4;
	maxX_ = 104;
	maxY_ = 25;
}

AScreenElement::~AScreenElement() {}

AScreenElement &AScreenElement::operator= (const AScreenElement &element)
{
	if (this != &element)
	{
		x_ = element.x_;
		y_ = element.y_;
		minX_ = element.minX_;
		minY_ = element.minY_;
		maxX_ = element.maxX_;
		maxY_ = element.maxY_;
	}
	return (*this);
}

AScreenElement::AScreenElement(const AScreenElement &element)
{
	if (this != &element)
		*this = element;
}

// -------------------------------------------------------------------------- //
// ----------------------------- Constructor -------------------------------- //

AScreenElement::AScreenElement(int x, int y)
{
	x_ = x;
	y_ = y;
	minX_ = 4;
	minY_ = 4;
	maxX_ = 140;
	maxY_ = 30;
}

// -------------------------------------------------------------------------- //
// -------------------------- Member function ------------------------------- //

int 	AScreenElement::getX() const { return (x_); }

int 	AScreenElement::getY() const { return (y_); }

int 	AScreenElement::getMaxX() const { return (maxX_); }

int 	AScreenElement::getMaxY() const { return (maxY_); }

int 	AScreenElement::getMinX() const { return (this->minX_); }

int 	AScreenElement::getMinY() const { return (this->minY_); }

bool	AScreenElement::collision(AScreenElement *elem)
{
	return (y_ == elem->y_ && x_ == elem->x_);
}

// -------------------------------------------------------------------------- //