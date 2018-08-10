#include "Map.h"

namespace environment
{
	Map::Map(srac::GameDataRef _gameData)
	{
		// left, right, top, bot walls respectively
		boundaries.push_back(Wall(-10, 0, 10, _gameData->window.getSize().y));
		boundaries.push_back(Wall(_gameData->window.getSize().x, 0, 10, _gameData->window.getSize().y));
		boundaries.push_back(Wall(0, _gameData->window.getSize().y, _gameData->window.getSize().x, 10));
		boundaries.push_back(Wall(0, -10, _gameData->window.getSize().x, 10));
	}

	Wall& Map::getBoundary(int i)
	{
		if (i < boundaries.size())
		{
			return boundaries[i];
		}
	}

	std::vector<Wall>& Map::getBoundaries()
	{
		return boundaries;
	}

	int Map::getBoundaryCount()
	{
		return boundaries.size();
	}
}