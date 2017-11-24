#include "Ball.h"



Ball::Ball()
{
	position.x = 400.0f;
	position.y = 600.0f;
	velocity.x = 0.25f;
	velocity.y = -0.25f;
	ball.setRadius(5);
	ball.setFillColor(sf::Color::Red);
	ball.setPosition(position);
}


Ball::~Ball()
{
}

void Ball::update(double timeUpdate)
{
	position.x = position.x + velocity.x * (float)timeUpdate;
	position.y = position.y + velocity.y * (float)timeUpdate;
	if (position.x <= 0 || position.x >= 805)
	{
		velocity.x = velocity.x * -1;
	}
	if (position.y <= 0 || position.y >= 805)
	{
		velocity.y = velocity.y * -1;
	}
	if (position.y >= 605)
	{
		alive = false;
	}
	ball.setPosition(position);
}

sf::CircleShape Ball::getBody()
{
	return ball;
}

void Ball::setAlive(bool newAlive)
{
	alive = newAlive;
}

bool Ball::getAlive()
{
	return alive;
}

void Ball::setLaunch(bool newLaunch)
{
	ballLaunch = newLaunch;
}

bool Ball::getLaunch()
{
	return ballLaunch;
}
