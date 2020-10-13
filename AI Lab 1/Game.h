#pragma once
#include"Globals.h"
#include"Player.h"
#include"Enemy.h"


class Game
{
public:
	Game();
	void run();

private:

	Player player;
	Enemy wanderer;
	Enemy seeker;
	sf::RenderWindow window;
	void processEvents();
	void update(sf::Time t_dt);
	void processGameEvents(sf::Event& event);
	void render();

};

