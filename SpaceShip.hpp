/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpaceShip.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 17:00:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/03/29 17:00:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPACESHIP_HPP
#define SPACESHIP_HPP

#include "AScreenElement.hpp"

class SpaceShip : public AScreenElement
{
public:
// ----------------------------- Coplien Form ------------------------------- //

	SpaceShip ();
	~SpaceShip ();
	SpaceShip (const SpaceShip &ship);
	SpaceShip &operator= (const SpaceShip &ship);

// -------------------------------------------------------------------------- //
// ----------------------------- Member Function ---------------------------- //

	void	printElement () const;
	bool	move ();
	bool	move (int input);
	bool	collision (AScreenElement *elem);

// --------------------------------------------------------------------------- //		
};

#endif
