#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Ball.h"
#include "Paddle.h"
class Game
{
public:
	Game();
	~Game();
	void run();
protected:
	sf::RenderWindow m_window;
	void update(double dt);
	void render();
	void processEvents();
	void Game::processGameEvents(sf::Event& event);
	Ball newBall;
	Paddle player;
	KeyHandler m_keyhandler;
};

