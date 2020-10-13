#pragma once
#include <time.h>       /* time */

#include "SFML/Graphics.hpp" 
#include <iostream>
#include <vector>
#include <time.h>
#include <math.h>

#define PI 3.14159265359

const int static SCREEN_WIDTH = 1000;
const int static SCREEN_HEIGHT = 550;
const sf::Vector2f static MAX_SPEED = { 15.0f,-15.0f };

static sf::Vector2f normalize(sf::Vector2f vector) {
	float lenght;
	sf::Vector2f vectorNorm;
	lenght = sqrt((vector.x * vector.x) + (vector.y * vector.y));
	vectorNorm = sf::Vector2f(vector.x / lenght, vector.y / lenght);
	return vectorNorm;
};
