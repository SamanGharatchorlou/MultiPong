#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Game.h"

#define SPEED 300.0f

namespace moveables
{
	class PlayerBat : public Entity
	{
	private:
		sf::RectangleShape _bat;

		srac::GameDataRef _gameData;

		float _speed = SPEED;

		void moveUp();
		void moveDown();
		void moveLeft();
		void moveRight();

	public:
		PlayerBat(srac::GameDataRef gameData, sf::Vector2f position, sf::Vector2f size, sf::Color colour);

		void handleInput();
		void update(float dt);
		void draw();
	};
}