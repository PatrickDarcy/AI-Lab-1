#include "Game.h"

static int const WIDTH = 1000;
static int const HEIGHT = 550;

Game::Game() :
	window{sf::VideoMode{WIDTH,HEIGHT,32}, "Lab 1"}
{
	srand(time(NULL));
}

void Game::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps
    while (window.isOpen())
    {
        processEvents(); // as many as possible
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > timePerFrame)
        {
            timeSinceLastUpdate -= timePerFrame;
            processEvents(); // at least 60 fps
            update(timePerFrame); //60 fps
        }
        render(); // as many as possible
    }
}

void Game::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
	    if (event.type == sf::Event::Closed)
	        {
		    window.close();
	    }
	        processGameEvents(event);
    }
}
void Game::processGameEvents(sf::Event& event)
{
	// check if the event is a a mouse button release
	if (sf::Event::KeyPressed == event.type)
	{
		switch (event.key.code)
		{
		case sf::Keyboard::Escape:
			window.close();
			break;
		case sf::Keyboard::Up:
			player.increaseVelocity();
			break;
		case sf::Keyboard::Right:
			player.rotateRight();
			break;
		case sf::Keyboard::Left:
			player.rotateLeft();
			break;
		default:
			break;
		}
	}
}

void Game::update(sf::Time t_dt)
{
	player.update();
	enemy.update();
}

void Game::render()
{
    window.clear();
	player.render(window);
	enemy.render(window);
    window.display();
}