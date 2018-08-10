#pragma once
#include "Game.h"
#include "GameState.h"
#include "Collider.h"
#include "CharacterController.h"
#include "Map.h"

#include "PlayerBat.h"
#include "Projectile.h"

#include <SFML/Graphics.hpp>

namespace srac
{
	class GamePlayState : public GameState
	{
	private:
		GameDataRef _gameData;

		gamespace::CharacterController* charController;

		moveables::PlayerBat* player;
		moveables::Projectile* ball;

		environment::Map* map;

		Collider collider;

	public:
		GamePlayState(GameDataRef gameData);

		void enter();
		void processStateChanges();
		void handleInput();
		void update(float dt);
		void draw();
		void exit();
	};
}
