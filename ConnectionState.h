#pragma once
#include "GameState.h"
#include "Game.h"

#include <SFML/Network.hpp>
#include <iostream>

namespace srac
{
	class ConnectionState : public GameState
	{
	private:
		GameDataRef _gameData;

	public:
		ConnectionState(GameDataRef gameData);

		void enter();
		void processStateChanges();
		void handleInput();
		void update(float dt);
		void draw();
		void exit();
	};
}
