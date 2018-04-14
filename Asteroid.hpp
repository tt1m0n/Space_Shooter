/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asteroid.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 16:52:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/04/08 16:52:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ASTEROID_HPP
#define ASTEROID_HPP

#include "AScreenElement.hpp"

class Asteroid : public AScreenElement {
public:
// ----------------------------- Coplien Form ------------------------------- //

	Asteroid ();
	~Asteroid ();
	Asteroid (const Asteroid &ship);
	Asteroid &operator= (const Asteroid &ship);

// -------------------------------------------------------------------------- //
// ------------------------------- Constructor ------------------------------ //

	Asteroid (int x, int y);

// -------------------------------------------------------------------------- //
// ----------------------------- Member Function ---------------------------- //

	void			printElement() const;
	virtual bool	move ();

// -------------------------------------------------------------------------- //	
};

#endif
