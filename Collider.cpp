#include "Collider.h"
#include <iostream>

namespace srac
{
	void Collider::addBoxCollider(int x, int y, int width, int height)
	{
		_boxColliders.push_back(BoxCollider(x, y, width, height));
	}

	void Collider::addBoxCollider(BoxCollider boxCollider)
	{
		_boxColliders.push_back(boxCollider);
	}

	// returns true if collider collides with any box
	bool Collider::checkCollisions(BoxCollider collider)
	{
		for (int i = 0; i < _boxColliders.size(); i++)
		{
			if (collider.intersects(_boxColliders[i]))
				return true;
		}

		return false;
	}

	// returns all collision boxes being collided with
	std::vector<BoxCollider> Collider::getBoxesCollidedWith(BoxCollider collider)
	{
		std::vector<BoxCollider> boxesCollidedWith;

		for (int i = 0; i < _boxColliders.size(); i++)
		{
			if (collider.intersects(_boxColliders[i]))
				boxesCollidedWith.push_back(_boxColliders[i]);
		}

		return boxesCollidedWith;
	}


	bool Collider::isGrounded(moveables::Entity* entity)
	{
		// player collider and box of object colliding with
		BoxCollider entityCollider = getBoxCollider(entity);
		std::vector<BoxCollider> collisionBoxes = getBoxesCollidedWith(entityCollider);

		for (int i = 0; i < collisionBoxes.size(); i++)
		{
			// add small movement buffer to check
			if (entity->getPosition().y >= collisionBoxes[i].top)
			{
				entity->setPosition(sf::Vector2f(entity->getPosition().x, collisionBoxes[i].top));
				return true;
			}
		}

		return false;
	}


	bool Collider::isColliding(moveables::Entity* entity, sf::Vector2f movement)
	{
		return checkCollisions(getBoxCollider(entity,movement));
	}

	bool Collider::collision(moveables::Entity* entity1, moveables::Entity* entity2)
	{
		BoxCollider entityCollider1 = getBoxCollider(entity1);
		BoxCollider entityCollider2 = getBoxCollider(entity2);

		if (entityCollider1.intersects(entityCollider2))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Collider::collision(moveables::Entity* entity1, moveables::Entity* entity2, sf::Vector2f e2Movement)
	{
		BoxCollider entityCollider1 = getBoxCollider(entity1);
		BoxCollider entityCollider2 = getBoxCollider(entity2, e2Movement);

		if (entityCollider1.intersects(entityCollider2))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	BoxCollider Collider::getBoxCollider(moveables::Entity* entity)
	{
		// top left point of character (NOT of texture/sprite!) + movement
		sf::Vector2i position = toVec2i(entity->getPosition());
		sf::Vector2i size = toVec2i(entity->getSize());

		return BoxCollider(position, size);
	}

	BoxCollider Collider::getBoxCollider(moveables::Entity* entity, sf::Vector2f movement)
	{
		// top left point of character (NOT of texture/sprite!) + movement
		sf::Vector2i position = toVec2i(entity->getPosition().x + movement.x, entity->getPosition().y + movement.y);
		sf::Vector2i size = toVec2i(entity->getSize());

		return BoxCollider(position, size);
	}


	// util
	sf::Vector2i Collider::toVec2i(sf::Vector2f floatVector)
	{
		return sf::Vector2i(floatVector.x + 0.5f, floatVector.y + 0.5f);
	}

	sf::Vector2i Collider::toVec2i(float x, float y)
	{
		return sf::Vector2i(x + 0.5f, y + 0.5f);
	}
}
