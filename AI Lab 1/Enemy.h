#pragma once
#include"Globals.h"

class Enemy
{
private:
	sf::Sprite enemySprite;
	sf::Texture enemySpriteTexture;
	sf::Vector2f velocity;
	int speed = 5;
	float enemyAngle;

public:
	Enemy();
	void update();
	void setPosition(sf::Vector2f t_pos);
	sf::Vector2f getPosition();
	sf::Vector2f getSpriteOrigin();
	void randomVelocity();
	void render(sf::RenderWindow& t_window);
	void boundaryCheck();
};

