#pragma once
#include "GameStateMachine.h"
#include "Collider.h"

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>

#define MAX_FRAMERATE 60

namespace srac
{
	// master game data object
	struct GameData
	{
		sf::RenderWindow window;
		GameStateMachine machine;
		Collider collider;
	};

	typedef std::shared_ptr<GameData> GameDataRef;

	// main game object
	class Game
	{
	private:
		GameDataRef _gameData = std::make_shared<GameData>();
		void run(float dt);

	public:
		Game(int windowWidth, int windowHeight, std::string title);
	};
}