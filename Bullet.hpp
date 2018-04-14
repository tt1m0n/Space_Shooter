/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:13:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/04/03 13:13:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_HPP
#define BULLET_HPP

#include "AScreenElement.hpp"

class Bullet : public AScreenElement
{
public:
// ----------------------------- Coplien Form ------------------------------- //

	Bullet ();
	virtual ~Bullet();
	Bullet &operator= (const Bullet &bullet);
	Bullet (const Bullet &Bullet);

// -------------------------------------------------------------------------- //
// ------------------------------- Constructor ------------------------------ //

Bullet (int x, int y);

// -------------------------------------------------------------------------- //	
// ----------------------------- Member Function ---------------------------- //

	virtual void 	printElement () const;
	virtual bool 	move ();
	bool	collision (AScreenElement *element);

// -------------------------------------------------------------------------- //		

};

#endif