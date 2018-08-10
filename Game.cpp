#include "Game.h"
#include "ConnectionState.h"

#include <iostream>

namespace srac
{
	Game::Game(int windowWidth, int windowHeight, std::string title)
	{
		_gameData->window.create(sf::VideoMode(windowWidth, windowHeight), title, sf::Style::Close | sf::Style::Titlebar);
		
		_gameData->window.setFramerateLimit(MAX_FRAMERATE);
		float dt = 1.0f / MAX_FRAMERATE;

		_gameData->machine.addState(stateRef(new ConnectionState(_gameData)));

		run(dt);
	}

	void Game::run(float dt)
	{
		while (_gameData->window.isOpen())
		{
			// process any high level game state changes
			_gameData->machine.processStateChanges();

			// process all changes within the state
			_gameData->machine.getActiveState()->handleInput();
			_gameData->machine.getActiveState()->update(dt);
			_gameData->machine.getActiveState()->draw();
		}
	}
}
