#include "PlayerBat.h"
#include <iostream>

namespace moveables
{
	PlayerBat::PlayerBat(srac::GameDataRef gameData, sf::Vector2f position, sf::Vector2f size, sf::Color colour)
	{
		_gameData = gameData;

		_position = position;
		_size = size;
		_colour = colour;

		_bat.setPosition(_position);
		_bat.setSize(_size);
		_bat.setFillColor(_colour);
	}

	void PlayerBat::moveUp()
	{
		_movement.y -= _speed;
	}

	void PlayerBat::moveDown()
	{
		_movement.y += _speed;
	}

	void PlayerBat::moveRight()
	{
		_movement.x += _speed;
	}

	void PlayerBat::moveLeft()
	{
		_movement.x -= _speed;
	}

	void PlayerBat::handleInput()
	{
		// reset movement vector
		_movement *= 0.0f;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			moveUp();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			moveDown();
		}
	}

	void PlayerBat::update(float dt)
	{
		_position += _movement * dt;

		_bat.setPosition(_position);
	}

	void PlayerBat::draw()
	{
		_gameData->window.draw(_bat);
	}
}