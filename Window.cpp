/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 17:31:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/04/12 14:01:42 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zconf.h>
#include <iostream>
#include "Window.hpp"
#include "Enemy.hpp"
#include "EnemyBullet.hpp"
#include "Asteroid.hpp"
#include "Health.hpp"
#include <iostream>

// ----------------------------- Coplien Form ------------------------------- //

Window::Window()
{
	init ();

	srand(time(NULL));
	height_ = 31;
	weight_ = 142;
	startXY_ = 3;
	score_ = 0;
	input_ = '\n';
	MAX_BUL_ = 100;
	MAX_ASTEROID_ = 100;
	MAX_ENEMY_ = 100;
	timeCount_ = 0;
	life_ = 3;
	minOutStr_ = "00";
	secOutStr_ = "00";
	timeMin_ = 0;
	timeSec_ = 0;
	pause_ = 0;
	for (int i = 0; i < MAX_BUL_; i++)
	{
		bullet[i] = NULL;
		enemyBullet[i] = NULL;
	}
	for (int i = 0; i < MAX_ENEMY_; i++)
		enemy[i] = NULL;
	for (int i = 0; i < MAX_ASTEROID_; i++)
		asteroid[i] = NULL;
	addHealth = NULL;
}

Window::~Window()
{
	delBullet ();
	delEnemy ();
	delAsteroids ();
	if (addHealth)
		delete addHealth;
	clear ();
	refresh();
}

Window &Window::operator= (const Window &element)
{
	if (this != &element)
	{
		height_ = element.height_;
		weight_ = element.weight_;
		startXY_ = element.startXY_;
		score_ = element.score_;
		input_ = element.input_;
		MAX_BUL_ = element.MAX_BUL_;
		MAX_ASTEROID_ = element.MAX_ASTEROID_;
		MAX_ENEMY_ = element.MAX_ENEMY_;
		timeCount_ = element.timeCount_;
		life_ = element.life_;
		minOutStr_ = element.minOutStr_;
		secOutStr_ = element.secOutStr_;
		timeMin_ = element.timeMin_;
		timeSec_ = element.timeSec_;
		pause_ = element.pause_;
		delBullet ();
		delEnemy ();
		delAsteroids ();
		copyBullet (element);
		copyEnemy (element);
		copyAsteroids (element);
	}
	return (*this);
}

void	Window::init()
{
	initscr();
	nodelay(stdscr, true);
	keypad(stdscr, true);
	noecho();
	curs_set(false);
	timeout(0);
}

void	Window::delBullet ()
{
	for (int i = 0; i < MAX_BUL_; i++)
	{
		if (bullet[i] != NULL)
		{
			delete bullet[i];
			bullet[i] = NULL;
		}
		if (enemyBullet[i] != NULL)
		{
			delete enemyBullet[i];
			enemyBullet[i] = NULL;
		}
	}
}

void 	Window::delEnemy ()
{
	for (int i = 0; i < MAX_ENEMY_; i++)
	{
		if (enemy[i] != NULL)
		{
			delete enemy[i];
			enemy[i] = NULL;
		}
	}
}

void 	Window::delAsteroids ()
{
	for (int i = 0; i < MAX_ASTEROID_; i++)
	{
		if (asteroid[i] != NULL)
		{
			delete asteroid[i];
			asteroid[i] = NULL;
		}
	}
}

void	Window::copyBullet (const Window &element)
{
	for (int i = 0; i < MAX_BUL_; i++)
	{
		if (element.bullet[i] != NULL)
		{
			bullet[i] = new Bullet;
			*(bullet[i]) = *(element.bullet[i]);
		}
		if (element.enemyBullet[i] != NULL)
		{
			enemyBullet[i] = new EnemyBullet;
			*(enemyBullet[i]) = *(element.enemyBullet[i]);
		}
	}
}

void 	Window::copyEnemy (const Window &element)
{
	for (int i = 0; i < MAX_ENEMY_; i++)
	{
		if (element.enemy[i] != NULL)
		{
			enemy[i] = new Enemy;
			*(enemy[i]) = *(element.enemy[i]);
		}
	}
}

void	Window::copyAsteroids (const Window &element)
{
	for (int i = 0; i < MAX_ASTEROID_; i++)
	{
		if (element.asteroid[i] != NULL)
		{
			asteroid[i] = new Asteroid;
			*(asteroid[i]) = *(element.asteroid[i]);
		}
	}
}

Window::Window (const Window &) {}

// --------------------------------------------------------------------------- //
// ----------------------------- Public Member Function ---------------------- //

void	Window::play()
{
	time_t start;

	time(&start);
	while ((input_ = getch()) != 27)
	{
		if (input_ == 'p')
			changePauseFlag ();
		if (pause_ == 0)
		{
			if (!gameCycle ())
				return ;
		}
		timer(start);
		timeCount_++;
		if (timeCount_ % 10000 == 0) {
			printScreen(8);
		}
	}
}

// ------------------------------------------------------------------------------ //
// ---------------------------------- Game Cycle -------------------------------- //

void	Window::changePauseFlag()
{
	if (pause_ != 0)
		pause_ = 0;
	else
		pause_ = 1;
}

bool	Window::gameCycle()
{
	if (input_ == KEY_UP || input_ == KEY_DOWN ||
		input_ == KEY_RIGHT || input_ == KEY_LEFT)
	{
		myShip_.move(input_);
		printScreen(8);
	}
	else if (input_ == ' ')
	{
		shoot(myShip_.getX(), myShip_.getY());
		printScreen(8);
	}
	else if (timeCount_ % 10000 == 0)
	{
		createEnemy();
		createAsteroids ();
		createAddHealth ();
		moveAllElements();
		if (checkCollision())
			usleep(250000);
		if (life_ == 0)
		{
			clear ();
			printGameOver ();
			refresh ();
			usleep(2000000);
			return (false);
		}
		printScreen(8);
	}
	return (true);
}

// -------------------------------------------------------------------------- //
// ---------------------------- Print Functios ------------------------------ //

void	Window::printScreen(int color_border) const
{
	clear();
	printBorder(color_border);
	myShip_.printElement();
	printInfo();
	printBullets();
	printEnemies();
	printAsteroids();
	printAddHealth ();
}

void	Window::printBorder(int color) const
{
	attron (COLOR_PAIR(color));
	for (int i = startXY_; i <= weight_; i++)
		mvprintw(startXY_, i, "-");
	for (int i = startXY_; i <= weight_; i++)
		mvprintw(height_, i, "-");
	for (int i = startXY_; i < height_; i++)
		mvprintw(i, startXY_, "|");
	for (int i = startXY_; i < height_; i++)
		mvprintw(i, weight_, "|");
	attroff (COLOR_PAIR(color));
}

void	Window::printInfo() const
{
	mvprintw (2, 4, "SCORE");
	mvprintw (2, 135, "LIFE");
	mvprintw (2, 66, "TIME");
	attron (COLOR_PAIR(2));
	mvprintw (2, 11, "%d", score_);
	mvprintw (2, 71, "%s:%s", minOutStr_.c_str(), secOutStr_.c_str());
	mvprintw (2, 141, "%d", life_);
	attroff (COLOR_PAIR(2));
}

void	Window::printBullets() const
{
	for (int i = 0; i < MAX_BUL_; i++)
	{
		if (bullet[i])
			bullet[i]->printElement();
		if (enemyBullet[i])
			enemyBullet[i]->printElement();
	}
}

void	Window::printEnemies() const
{
	for (int i = 0; i < MAX_ENEMY_; i++)
	{
		if (enemy[i])
			enemy[i]->printElement();
	}
}

void	Window::printAsteroids() const
{
	for (int i = 0; i < MAX_ASTEROID_; i++)
	{
		if (asteroid[i])
			asteroid[i]->printElement();
	}
}

void	Window::printAddHealth() const
{
	if (addHealth != NULL)
		addHealth->printElement();
}

// -------------------------------------------------------------------------- //
// ----------------------------- Create Functions --------------------------- //

void 	Window::createEnemy()
{
	if (timeCount_ % 19 != 0)
		return ;
	for (int i = 0; i < MAX_ENEMY_; i++)
	{
		if (enemy[i] == NULL)
		{
			int randomY = (rand() % (height_ - (startXY_ + 3))) + startXY_ + 2;
			enemy[i] = new Enemy(myShip_.getMaxX(), randomY);
			return;
		}
	}
}

void	Window::createAddHealth()
{
	if (timeCount_ % 10000000 == 0 && timeCount_ != 0)
	{
		if (addHealth == NULL) {
			int randomY = (rand() % (height_ - (startXY_ + 1))) + startXY_ + 1;
			addHealth = new Health(myShip_.getMaxX(), randomY);
		}
	}
}

void 	Window::createAsteroids()
{
	if (timeCount_ % 19 != 0)
		return ;
	for (int i = 0; i < MAX_ASTEROID_; i++)
	{
		if (asteroid[i] == NULL)
		{
			int randomY = (rand() % (height_ - (startXY_ + 1))) + startXY_ + 1;
			asteroid[i] = new Asteroid(myShip_.getMaxX(), randomY);
			return;
		}
	}
}

void	Window::createEnemyBullet()
{
	for (int i = 0; i < MAX_BUL_; i++)
		if (enemy[i])
		{
			if (rand() % 400 == 1)
				shootEnemy(enemy[i]->getX() - 2, enemy[i]->getY());
		}
}

// ---------------------------------------------------------------------------- //
// ------------------------------ Move Functions ------------------------------ //

void	Window::moveAllElements()
{
	moveMyBullets ();
	createEnemyBullet ();
	if (timeCount_ % 10000 == 0)
		moveAsteroids();
	if (timeCount_ % 70000 == 0)
		moveEnemies();
	if (timeCount_ % 20000 == 0)
	{
		moveEnemyBullets();
		moveAddHealth ();
	}
}

void	Window::moveAddHealth()
{
	if (addHealth != NULL && !addHealth->move())
	{
		delete addHealth;
		addHealth = NULL;
	}
}

void	Window::moveMyBullets ()
{
	for (int i = 0; i < MAX_BUL_; i++)
	{
		if (bullet[i] && !bullet[i]->move())
		{
			delete bullet[i];
			bullet[i] = NULL;
		}
	}
}

void	Window::shootEnemy(int x, int y)
{
	if (x == myShip_.getMaxX())
		return ;
	for (int i = 0; i < MAX_BUL_; i++)
	{
		if (enemyBullet[i] == NULL)
		{
			enemyBullet[i] = new EnemyBullet(x, y);
			return ;
		}
	}
}

void	Window::moveEnemies()
{
	for (int i = 0; i < MAX_ENEMY_; i++)
	{
		if (enemy[i] && !enemy[i]->move()) {
			delete enemy[i];
			enemy[i] = NULL;
		}
	}
}

void	Window::moveAsteroids()
{
	for (int i = 0; i < MAX_ASTEROID_; i++)
	{
		if (asteroid[i] && !asteroid[i]->move()) {
			delete asteroid[i];
			asteroid[i] = NULL;
		}
	}
}

void	Window::moveEnemyBullets()
{
	for (int i = 0; i < MAX_BUL_; i++) {
		if (enemyBullet[i] && !enemyBullet[i]->move()) {
			delete enemyBullet[i];
			enemyBullet[i] = NULL;
		}
	}
}

void	Window::shoot(int x, int y)
{
	if (x == myShip_.getMaxX())
		return ;
	for (int i = 0; i < MAX_BUL_; i++)
	{
		if (bullet[i] == NULL)
		{
			bullet[i] = new Bullet(x + 1, y);
			return ;
		}
	}
}

// --------------------------------------------------------------------------- //
// --------------------------- Colision Functions ---------------------------- //

bool	Window::checkCollision()
{
	checkMyBulletCol();
	return (checkMyShipCol());
}

bool	Window::checkMyBulletCol()
{
	for (int i = 0; i < MAX_BUL_; i++)
		if (bullet[i])
		{
			for (int j = 0; j < MAX_ENEMY_; j++)
				if (enemy[j] && bullet[i]->collision(enemy[j]))
				{
					delete bullet[i];
					delete enemy[j];
					bullet[i] = NULL;
					enemy[j] = NULL;
					score_ += 5;
					return (true);
				}
		}
	return (false);
}

bool	Window::checkMyShipCol()
{
	return (myShipEnemyCol() || myShipBulletCol() || myShipHealthCol ());
}

bool	Window::myShipEnemyCol()
{
	for (int i = 0; i < MAX_ENEMY_; i++)
		if (enemy[i] && myShip_.collision(enemy[i]))
		{
			life_ = life_ - 1;
			delete enemy[i];
			enemy[i] = NULL;
			return (true);
		}
	return (false);
}

bool	Window::myShipHealthCol()
{
	if (addHealth != NULL && myShip_.collision(addHealth))
	{
		life_ = life_ + 1;
		delete addHealth;
		addHealth = NULL;
		return (true);
	}
	return (false);
}

bool	Window::myShipBulletCol()
{
	for (int i = 0; i < MAX_BUL_; i++)
		if (enemyBullet[i] && myShip_.collision(enemyBullet[i]))
		{
			life_ = life_ - 1;
			delete enemyBullet[i];
			enemyBullet[i] = NULL;
			return (true);
		}
	return (false);
}

// ---------------------------------------------------------------------------- //

void	Window::timer(time_t &start)
{
	time_t end;

	time(&end);

	if (end - start > 59)
	{
		time(&start);
		timeMin_++;
		if (timeMin_ < 10)
			minOutStr_ = "0" + std::to_string(timeMin_);
		else
			minOutStr_ = std::to_string(timeMin_);
	}
	if ((timeSec_ = end - start) < 10)
		secOutStr_= "0" + std::to_string(end-start);
	else
		secOutStr_= std::to_string(end-start);
}

// ------------------------------- Print Game Over ---------------------------- //

void 	Window::printGameOver() const
{
	printBorder(6);
	attron (COLOR_PAIR(7));
	mvprintw(8, 32,  "000000000000000000         00000000          00000       000000   000000000000000000");
	mvprintw(9, 32,  "00000                    000000000000        000000     0000000   000000000000000000");
	mvprintw(10, 32, "00000                  00000      00000      0000000   00000000   000000");
	mvprintw(11, 32, "00000   0000000000    0000          0000     00000000 000000000   0000000000000000");
	mvprintw(12, 32, "00000   0000000000    00      00      00     0000  00000  00000   0000000000000000");
	mvprintw(13, 32, "00000        00000    00   00000000   00     0000  00000  00000   000000");
	mvprintw(14, 32, "000000000000000000    00              00     0000  00000  00000   000000000000000000");
	mvprintw(15, 32, "000000000000000000    00              00     0000  00000  00000   000000000000000000");
	mvprintw(16, 32, "                       00            00                                             ");
	mvprintw(17, 32, "                    00000            00000                                          ");
	mvprintw(18, 32, "                       00            00                                ");
	mvprintw(19, 32, "000000000000000000                          000000000000000000    0000000000000000");
	mvprintw(20, 32, "000000000000000000    00              00    000000000000000000    000000     000000");
	mvprintw(21, 32, "00000       000000    00    000000    00    000000                000000      00000");
	mvprintw(22, 32, "00000       000000    00      00      00    0000000000000000      000000    0000000 ");
	mvprintw(23, 32, "00000       000000    0000          0000    0000000000000000      000000000000000");
	mvprintw(24, 32, "00000       000000    00000        00000    000000                000000   00000");
	mvprintw(25, 32, "000000000000000000     00000      00000     000000000000000000    00000    000000");
	mvprintw(26, 32, "000000000000000000        00000000000       000000000000000000    000000      00000");
	mvprintw(27, 32, "  00000000000000            0000000           000000000000000     00000        00000");
	attroff (COLOR_PAIR(7));
	refresh ();
}

// ---------------------------------------------------------------------------- //
