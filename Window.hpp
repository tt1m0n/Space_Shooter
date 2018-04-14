/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 17:31:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/04/12 14:01:08 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <ncurses.h>
#include <string>
#include "SpaceShip.hpp"
#include "Bullet.hpp"

class Window {
public:
// ----------------------------- Coplien Form ------------------------------- //

	Window ();
	~Window ();
	Window &operator= (const Window &win);

// -------------------------------------------------------------------------- //
// ------------------------------- Main Function ---------------------------- //

	void 	play ();
	
// --------------------------------------------------------------------------- //

private:
	Window (const Window &);

	int 			height_;
	int				weight_;
	int 			startXY_;
	int				score_;
	int 			input_;
	unsigned long 	timeCount_;
	int 			life_;
	int 			MAX_BUL_;
	int				MAX_ENEMY_;
	int 			MAX_ASTEROID_;
	int 			timeMin_;
	int 			timeSec_;
	int				pause_;
	std::string		minOutStr_;
	std::string		secOutStr_;
	AScreenElement	*bullet[100];
	AScreenElement	*enemy[100];
	AScreenElement	*enemyBullet[100];
	AScreenElement	*asteroid[100];
	AScreenElement	*addHealth;
	SpaceShip		myShip_;

// ------------------------------------ Game Cycle -------------------------------------------- //

	void			changePauseFlag ();
	bool			gameCycle ();

// -------------------------------------------------------------------------------------------- //

// ----------------------------------- Del Functions ----------------------------------------- //

	void 			delBullet ();
	void 			delEnemy ();
	void			delAsteroids ();

// ------------------------------------------------------------------------------------------- //

// ----------------------------------- Copy Functions ---------------------------------------- //

	void 			copyBullet (const Window &element);
	void 			copyEnemy (const Window &element);
	void			copyAsteroids (const Window &element);

// ------------------------------------------------------------------------------------------- //

// ---------------------------------- Create Functions --------------------------------------- //

	void			init ();
	void 			createEnemy();
	void			createAddHealth ();
	void			createEnemyBullet ();
	void 			createAsteroids ();

// ------------------------------------------------------------------------------------------- //

// ----------------------------------- Print Functions --------------------------------------- //

	void			printScreen (int color_border) const;
	void			printInfo () const;
	void			printBullets () const;
	void			printEnemies () const;
	void			printAddHealth () const;
	void			printAsteroids () const;
	void			printBorder (int color) const;
	void 			printGameOver () const;

// ------------------------------------------------------------------------------------------- //

// ---------------------------------- Collision Functions ------------------------------------ //

	bool			checkCollision ();
	bool			checkMyBulletCol ();
	bool			checkMyShipCol ();
	bool			myShipBulletCol ();
	bool			myShipEnemyCol ();
	bool			myShipHealthCol ();

// ------------------------------------------------------------------------------------------ //

// ------------------------------------ Move Functions -------------------------------------- //

	void			moveAllElements ();
	void			moveMyBullets ();
	void			moveEnemies ();
	void			moveEnemyBullets ();
	void			moveAsteroids ();
	void			moveAddHealth ();
	void			shoot(int x, int y);
	void 			shootEnemy(int x, int y);

// ------------------------------------------------------------------------------------------ //

// ---------------------------------------- Other ------------------------------------------- //

	void			timer(time_t &start);

// ------------------------------------------------------------------------------------------ //
};

#endif
