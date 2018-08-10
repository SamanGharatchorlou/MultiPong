#include "Entity.h"

namespace moveables
{
	sf::Vector2f Entity::getPosition()
	{
		return _position;
	}

	void Entity::setPosition(sf::Vector2f position)
	{
		_position = position;
	}

	sf::Vector2f Entity::getSize()
	{
		return _size;
	}
}