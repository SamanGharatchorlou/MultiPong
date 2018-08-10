#pragma once
#include "GameState.h"
#include "Game.h"

namespace srac
{
	class GameTemplateState: public GameState
	{
	private:
		GameDataRef _gameData;

	public:
		GameTemplateState(GameDataRef gameData);

		void enter();
		void processStateChanges();
		void handleInput();
		void update(float dt);
		void draw();
		void exit();
	};
}
