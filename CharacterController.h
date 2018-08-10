#pragma once
#include "Game.h"
#include "Map.h"
#include "Projectile.h"
#include "PlayerBat.h"

namespace gamespace
{
	struct CharacterData
	{
		moveables::Projectile* _ball;
		moveables::PlayerBat* _player;
	};

	typedef std::shared_ptr<CharacterData> CharDataRef;

	class CharacterController
	{
	private:
		srac::GameDataRef _gameData;
		CharDataRef _charData = std::make_shared<CharacterData>();

	public:
		CharacterController(srac::GameDataRef _gameData, moveables::Projectile* ball, moveables::PlayerBat* player);
		
		void handleInput();
		void update(float dt);
		void draw();
	};
}
