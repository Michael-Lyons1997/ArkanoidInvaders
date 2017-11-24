#include "Game.h"
#include <iostream>

static double const MS_PER_UPDATE = 10.0;

Game::Game()
	: m_window(sf::VideoMode(800, 800, 32), "Arkanoid Invaders", sf::Style::Default),
	player(m_keyhandler)
	{ 
		m_window.setVerticalSyncEnabled(true);
	}


Game::~Game()
{
}

void Game::run()
{
	sf::Clock clock;
	sf::Int32 lag = 0;

	while (m_window.isOpen())
	{
		sf::Time dt = clock.restart();

		lag += dt.asMilliseconds();

		processEvents();

		while (lag > MS_PER_UPDATE)
		{
			update(MS_PER_UPDATE);
			lag -= (sf::Int32)MS_PER_UPDATE;
		}
		update(MS_PER_UPDATE);

		render();
	}
}

void Game::update(double dt)
{
	if (player.launchBall())
	{
		newBall.setLaunch(true);
	}
	if (newBall.getLaunch())
	{
		newBall.update(dt);
	}
	player.update(dt);
	if (newBall.getBody().getGlobalBounds().intersects(player.getBody().getGlobalBounds()))
	{
		newBall.bounce();
	}
}

void Game::render()
{
	m_window.clear();
	m_window.draw(player.getBody());
	if (newBall.getAlive())
	{
		m_window.draw(newBall.getBody());
	}
	m_window.display();
}

void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}
		processGameEvents(event);
	}
}

void Game::processGameEvents(sf::Event& event)
{
	switch (event.type)
	{
	case sf::Event::KeyPressed:
		m_keyhandler.updateKey(event.key.code, true);
		break;
	case sf::Event::KeyReleased:
		m_keyhandler.updateKey(event.key.code, false);
		break;
	}
}
