#include "Paddle.h"


Paddle::Paddle(KeyHandler const & keyHandler):
	m_keyhandler(keyHandler)
{
	position.x = 375.0f;
	position.y = 610.0f;
	velocity.x = 0.2f;
	velocity.y = 0.2f;
	paddle.setSize(sf::Vector2f(50.0f, 10.0f));
	paddle.setFillColor(sf::Color::Blue);
	paddle.setPosition(position);
}


Paddle::~Paddle()
{
}

void Paddle::update(double timeUpdate)
{
	launchBall();
	move(timeUpdate);
	paddle.setPosition(position);
}

sf::RectangleShape Paddle::getBody()
{
	return paddle;
}

void Paddle::move(double timeUpdate)
{
	if (m_keyhandler.isPressed(sf::Keyboard::Right))
	{
		position.x = position.x + velocity.x * (float)timeUpdate;
	}
	else if(m_keyhandler.isPressed(sf::Keyboard::Left))
	{
		position.x = position.x - velocity.x * (float)timeUpdate;
	}
	if (position.x > 800)
	{
		position.x = -50.0f;
	}
	if (position.x < -50)
	{
		position.x = 800.0f;
	}
}

bool Paddle::launchBall()
{
	if (m_keyhandler.isPressed(sf::Keyboard::Space))
	{
		return true;
	}
	else
	{
		return false;
	}
}
