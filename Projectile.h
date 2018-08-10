#pragma once
#include "Entity.h"
#include "Game.h"
#include <vector>

namespace moveables
{
	class Projectile : public Entity
	{
	private:
		sf::RectangleShape ball;

		srac::GameDataRef _gameData;

		sf::Vector2f _direction;
		float _speed = 250.0f;

		void wallBounce();

	public:
		Projectile(srac::GameDataRef gameData, sf::Vector2f position, sf::Vector2f size, sf::Color colour);

		void handleInput() { };
		void update(float dt);
		void draw();

		void batBounce();

		sf::Vector2f getMovement();
	};
}