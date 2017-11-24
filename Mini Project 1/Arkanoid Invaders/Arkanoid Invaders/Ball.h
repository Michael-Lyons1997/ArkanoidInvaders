#pragma once
#include <SFML/Graphics.hpp>
#include "Paddle.h"
class Ball
{
public:
	Ball();
	~Ball(); 
	void update(double timeUpdate);
	sf::CircleShape getBody();
	void setAlive(bool newAlive);
	bool getAlive();
	void setLaunch(bool newLaunch);
	bool getLaunch();
	void bounce();
private:
	sf::CircleShape ball;
	sf::Vector2f position;
	sf::Vector2f velocity;
	bool ballLaunch;
	bool alive = true;
};

