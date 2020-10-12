#include "Player.h"

Player::Player()
{
	velocity = sf::Vector2f(0.0f,0.0f);
	playerSprite.setPosition(500, 225);
	playerAngle = -90;

	if (!playerSpriteTexture.loadFromFile("player.png"))
	{
		std::cout << "problem loading Player Texture" << std::endl;
	}

	playerSprite.setOrigin(120, 160);
	playerSprite.setTexture(playerSpriteTexture);
	playerSprite.setScale(0.5f, 0.5f);
}

void Player::update()
{
	playerSprite.setPosition(playerSprite.getPosition() + velocity);
	boundaryCheck();
}

void Player::setPosition(sf::Vector2f t_newPos)
{
	playerSprite.setPosition(t_newPos);
}

sf::Vector2f Player::getPosition()
{
	return playerSprite.getPosition();
}

void Player::increaseVelocity()
{
	if (velocity.x <= MAX_SPEED.x && velocity.y >= MAX_SPEED.y) {
		velocity.x = speed * cos(playerAngle * PI / 180);
		velocity.y = speed * sin(playerAngle * PI / 180);
	}
}

void Player::rotateRight()
{
	playerSprite.rotate(rotationSpeed);
	playerAngle += rotationSpeed;
}

void Player::rotateLeft()
{
	playerSprite.rotate(-rotationSpeed);
	playerAngle -= rotationSpeed;
}

void Player::render(sf::RenderWindow & t_window)
{
	t_window.draw(playerSprite);
}

void Player::boundaryCheck()
{
	if (playerSprite.getPosition().x < (0))  //+ spriteOriginX))
	{
		playerSprite.setPosition(sf::Vector2f((SCREEN_WIDTH - playerSprite.getOrigin().x), playerSprite.getPosition().y));
	}
	if (playerSprite.getPosition().x > (SCREEN_WIDTH))
	{
		playerSprite.setPosition(sf::Vector2f(0, playerSprite.getPosition().y));
	}
	if (playerSprite.getPosition().y < (0))
	{
		playerSprite.setPosition(sf::Vector2f(playerSprite.getPosition().x, SCREEN_HEIGHT));
	}
	if (playerSprite.getPosition().y > (SCREEN_HEIGHT))
	{
		playerSprite.setPosition(sf::Vector2f(playerSprite.getPosition().x, 0));
	}
}



