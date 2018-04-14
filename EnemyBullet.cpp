/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyEnemyBullet.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:54:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/04/03 17:54:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "EnemyBullet.hpp"

// --------------------------------- Coplien Form --------------------------- //

EnemyBullet::EnemyBullet () : Bullet(0, 0) {}

EnemyBullet::~EnemyBullet() {}

EnemyBullet &EnemyBullet::operator= (const EnemyBullet &element)
{
	if (this != &element)
		AScreenElement::operator= (element);
	return (*this);
}

EnemyBullet::EnemyBullet (const EnemyBullet &element)
		: Bullet(element) {}

// -------------------------------------------------------------------------- //
// ------------------------------- Constructor ------------------------------ //

EnemyBullet::EnemyBullet(int x, int y) : Bullet(x, y) {}

// -------------------------------------------------------------------------- //
// ----------------------------- Member Function ---------------------------- //

void 	EnemyBullet::printElement() const
{
	attron(COLOR_PAIR(7));
	mvprintw(y_, x_, "<");
	attroff(COLOR_PAIR(7));
}

bool	EnemyBullet::move()
{
	if (x_ > minX_)
	{
		x_--;
		return (true);
	}
	return (false);
}

// --------------------------------------------------------------------------- //