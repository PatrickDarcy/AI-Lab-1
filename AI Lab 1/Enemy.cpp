#include "Enemy.h"

Enemy::Enemy(enemyType type) :
	typeOfEnemy{type}
{
	velocity = sf::Vector2f(0.0f, 0.0f);
	enemySprite.setPosition(500, 250);

	if (!enemySpriteTexture.loadFromFile("Enemy.png"))
	{
		std::cout << "problem loading Player Texture" << std::endl;
	}

	enemyAngle = (rand() % 360) - 90;
	enemySprite.setTexture(enemySpriteTexture);
	enemySprite.setScale(0.5f, 0.5f);
}

void Enemy::update(sf::Vector2f targetPos)
{
	switch (typeOfEnemy)
	{
	case enemyType::Wanderer:
		wandererVelocity();
		break;
	case enemyType::Seek:
		seekVelocity(targetPos);
		break;
	default:
		break;
	}
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

void Enemy::wandererVelocity()
{
	speed *= rand() % 1 - 1;
	velocity.x = speed * cos(enemyAngle * PI / 180);
	velocity.y = speed * sin(enemyAngle * PI / 180);
	enemySprite.rotate(enemyAngle);
	enemySprite.setPosition(enemySprite.getPosition() + velocity);
}

void Enemy::seekVelocity(sf::Vector2f targetPos)
{
	speed = 2;
	velocity = targetPos - enemySprite.getPosition();
	velocity = normalize(velocity);
	velocity = sf::Vector2f(velocity.x * speed, velocity.y * speed);
	enemySprite.setPosition(enemySprite.getPosition() + velocity);
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

enemyType Enemy::getEnemyType()
{
	return typeOfEnemy;
}
