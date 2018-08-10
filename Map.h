#pragma once
#include "Game.h"
#include <SFML/Graphics.hpp>
#include <vector>

namespace environment
{
	typedef sf::Rect<int> Wall;

	class Map
	{
	private:
		std::vector<Wall> boundaries;

	public:
		Map(srac::GameDataRef _gameData);

		std::vector<Wall>& getBoundaries();
		Wall& getBoundary(int i);

		int getBoundaryCount();
	};
}