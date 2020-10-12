#pragma once
#include"Globals.h"
class Player
{
private:
	sf::Sprite playerSprite;
	sf::Texture playerSpriteTexture;
	sf::Vector2f velocity;
	const int speed = 5;
	int playerDirection;
	const int rotationSpeed = 3;
	float playerAngle;

public:
	Player();
	void update();
	void setPosition(sf::Vector2f t_newPos);
	sf::Vector2f getPosition();
	void increaseVelocity();
	void decreaseVelocity();
	void rotateRight();
	void rotateLeft();
	void render(sf::RenderWindow& t_window);
	void boundaryCheck();
	void applySpeed();
};
