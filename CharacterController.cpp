#include "CharacterController.h"

#include <iostream>

namespace gamespace
{
	CharacterController::CharacterController(srac::GameDataRef gameData, moveables::Projectile* ball, moveables::PlayerBat* player) :
		_gameData(gameData)
	{	
		_charData->_player = player;
		_charData->_ball = ball;
	}

	void CharacterController::handleInput()
	{
		_charData->_ball->handleInput();
		_charData->_player->handleInput();
	}

	void CharacterController::update(float dt)
	{
		// bat ball collisions
		if (_gameData->collider.collision(_charData->_player, _charData->_ball, _charData->_ball->getMovement()))
		{
			_charData->_ball->batBounce();
		}

		_charData->_ball->update(dt);
		_charData->_player->update(dt);
	}

	void CharacterController::draw()
	{
		_charData->_ball->draw();
		_charData->_player->draw();
	}
}