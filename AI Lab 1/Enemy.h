#pragma once
#include"Globals.h"
#include<math.h>

enum class enemyType 
{
	Wanderer,
	Seek,
	Arrive
};

class Enemy
{
private:
	sf::Sprite enemySprite;
	sf::Texture enemySpriteTexture;
	sf::Vector2f velocity;
	int speed = 5;
	float enemyAngle;
	enemyType typeOfEnemy;
	const sf::Vector2f MAX_SPEED = sf::Vector2f(2,2);

public:
	Enemy(enemyType type);
	void update(sf::Vector2f targetPos);
	void setPosition(sf::Vector2f t_pos);
	sf::Vector2f getPosition();
	sf::Vector2f getSpriteOrigin();
	void wandererVelocity();
	void seekVelocity(sf::Vector2f targetPos);
	void render(sf::RenderWindow& t_window);
	void boundaryCheck();
	enemyType getEnemyType();
};

