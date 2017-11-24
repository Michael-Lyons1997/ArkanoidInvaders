#pragma once
#include <SFML/Graphics.hpp>
#include "KeyHandler.h"
class Paddle
{
public:
	Paddle(KeyHandler const & keyHandler);
	~Paddle();
	void update(double timeUpdate);
	sf::RectangleShape getBody();
	bool launchBall();
protected:
	sf::RectangleShape paddle;
	sf::Vector2f position;
	sf::Vector2f velocity;
	void move(double timeUpdate);
	KeyHandler const & m_keyhandler;
};

