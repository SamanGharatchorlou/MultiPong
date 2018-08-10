#include "GameTemplateState.h"

namespace srac
{
	GameTemplateState::GameTemplateState(GameDataRef gameData) : _gameData(gameData) {  }

	// initialise all game state variables (controlled by GameStateMachine)
	void GameTemplateState::enter()
	{

	}

	// process lower level state changes i.e. player, enemy
	void GameTemplateState::processStateChanges()
	{

	}

	// read game inputs
	void GameTemplateState::handleInput()
	{

	}

	// update all game objects
	void GameTemplateState::update(float dt)
	{

	}

	// draw all game objects
	void GameTemplateState::draw()
	{

	}

	// exit state, delete required objects (controlled by GameStateMachine)
	void GameTemplateState::exit()
	{

	}

}