#include "Enemy.h"

Enemy::Enemy()
{
	velocity = sf::Vector2f(0.0f, 0.0f);
	enemySprite.setPosition(500, 250);
	enemyAngle = 0.0f;

	if (!enemySpriteTexture.loadFromFile("Enemy.png"))
	{
		std::cout << "problem loading Player Texture" << std::endl;
	}

	enemySprite.setTexture(enemySpriteTexture);
	enemySprite.setScale(0.5f, 0.5f);
	randomVelocity();
}

void Enemy::update()
{
	enemySprite.setPosition(enemySprite.getPosition() + velocity);
	boundaryCheck();
}

void Enemy::setPosition(sf::Vector2f t_pos)
{
	enemySprite.setPosition(t_pos);
}

sf::Vector2f Enemy::getPosition()
{
	return enemySprite.getPosition();
}

sf::Vector2f Enemy::getSpriteOrigin()
{
	return enemySprite.getOrigin();
}

void Enemy::randomVelocity()
{
	speed *= rand() % 1 - 1;
	velocity.x = speed * cos(enemyAngle * PI / 180);
	velocity.y = speed * sin(enemyAngle * PI / 180);
}

void Enemy::render(sf::RenderWindow& t_window)
{
	t_window.draw(enemySprite);
}

void Enemy::boundaryCheck()
{
	if (enemySprite.getPosition().x < (0))  //+ spriteOriginX))
	{
		enemySprite.setPosition(sf::Vector2f((SCREEN_WIDTH - enemySprite.getOrigin().x), enemySprite.getPosition().y));
	}
	if (enemySprite.getPosition().x > (SCREEN_WIDTH))
	{
		enemySprite.setPosition(sf::Vector2f(0, enemySprite.getPosition().y));
	}
	if (enemySprite.getPosition().y < (0))
	{
		enemySprite.setPosition(sf::Vector2f(enemySprite.getPosition().x, SCREEN_HEIGHT));
	}
	if (enemySprite.getPosition().y > (SCREEN_HEIGHT))
	{
		enemySprite.setPosition(sf::Vector2f(enemySprite.getPosition().x, 0));
	}
}