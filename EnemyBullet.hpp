/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyEnemyBullet.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:54:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/04/03 17:54:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMYEnemyBullet_HPP
#define ENEMYEnemyBullet_HPP

#include "Bullet.hpp"

class EnemyBullet : public Bullet
{
public:
// ----------------------------- Coplien Form ------------------------------- //

	EnemyBullet ();
	~EnemyBullet ();
	EnemyBullet &operator= (const EnemyBullet &EnemyBullet);
	EnemyBullet (const EnemyBullet &EnemyBullet);

// -------------------------------------------------------------------------- //
// ------------------------------- Constructor ------------------------------ //

	EnemyBullet (int x, int y);

// -------------------------------------------------------------------------- //
// ----------------------------- Member Function ---------------------------- //

	void 	printElement () const;
	bool 	move ();

// --------------------------------------------------------------------------- //
};

#endif