#pragma once
#include <SFML/Graphics.hpp>

namespace moveables
{
	class Entity
	{
	protected:
		sf::Vector2f _position;
		sf::Vector2f _size;
		sf::Color _colour;

		sf::Vector2f _movement;

	public:
		virtual void handleInput() = 0;
		virtual void update(float dt) = 0;
		virtual void draw() = 0;

		sf::Vector2f getPosition();
		void setPosition(sf::Vector2f position);

		sf::Vector2f getSize();
	};
}