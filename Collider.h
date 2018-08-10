#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "Entity.h"

namespace srac
{
	typedef sf::Rect<int> BoxCollider;

	class Collider
	{
	private:
		std::vector<BoxCollider> _boxColliders;

		bool checkCollisions(BoxCollider collider);

		std::vector<BoxCollider> getBoxesCollidedWith(BoxCollider collider);
		
		sf::Vector2i toVec2i(sf::Vector2f floatVector);
		sf::Vector2i toVec2i(float x, float y);

		BoxCollider getBoxCollider(moveables::Entity* entity);
		BoxCollider getBoxCollider(moveables::Entity* entity, sf::Vector2f movement);

	public:
		void addBoxCollider(int x, int y, int width, int height);
		void addBoxCollider(BoxCollider boxCollider);

		bool isColliding(moveables::Entity* entity, sf::Vector2f movement);
		bool isGrounded(moveables::Entity* entity);

		bool collision(moveables::Entity* entity1, moveables::Entity* entity2);
		bool collision(moveables::Entity* entity1, moveables::Entity* entity2, sf::Vector2f e2Movement);
	};
}