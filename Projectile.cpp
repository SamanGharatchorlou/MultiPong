#include "Projectile.h"

namespace moveables
{
	Projectile::Projectile(srac::GameDataRef gameData, sf::Vector2f position, sf::Vector2f size, sf::Color colour)
	{
		_gameData = gameData;

		_position = position;
		_size = size;
		_colour = colour;

		_direction = sf::Vector2f(-1, 0);

		ball.setPosition(_position);
		ball.setSize(_size);
		ball.setFillColor(_colour);
	}

	void Projectile::update(float dt) 
	{
		wallBounce();

		_movement = _direction * _speed * dt;
		_position += _movement;

		ball.setPosition(_position);
	}

	void Projectile::draw()
	{
		_gameData->window.draw(ball);
	}

	void Projectile::wallBounce()
	{
		if (_gameData->collider.isColliding(this, _movement))
		{
			_direction.x *= -1;
		}
	}

	void Projectile::batBounce()
	{
		_direction.x *= -1;
	}


	sf::Vector2f Projectile::getMovement()
	{
		return _movement;
	}
}