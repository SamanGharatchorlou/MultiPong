#include "GamePlayState.h"

namespace srac
{
	GamePlayState::GamePlayState(GameDataRef gameData) : _gameData(gameData) {  }

	// initialise all game state variables (controlled by GameStateMachine)
	void GamePlayState::enter()
	{
		player = new moveables::PlayerBat(
			_gameData,
			sf::Vector2f(100.0f, _gameData->window.getSize().y / 2),
			sf::Vector2f(10.0f, 100.0f),
			sf::Color::White
		);

		ball = new moveables::Projectile(
			_gameData,
			sf::Vector2f(_gameData->window.getSize().y / 2, _gameData->window.getSize().y / 2),
			sf::Vector2f(10.0f, 10.0f),
			sf::Color::Green
		);

		// setup character controller
		charController = new gamespace::CharacterController(_gameData, ball, player);

		// set map boundaries
		map = new environment::Map(_gameData);

		for (int i = 0; i < map->getBoundaryCount(); i++)
		{
			collider.addBoxCollider(map->getBoundary(i));
		}

		_gameData->collider = collider;
	}

	// process lower level state changes i.e. player, enemy
	void GamePlayState::processStateChanges()
	{

	}

	// read game inputs
	void GamePlayState::handleInput()
	{
		sf::Event event;

		while (_gameData->window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				_gameData->window.close();
			}
		}

		charController->handleInput();
	}

	// update all game objects
	void GamePlayState::update(float dt)
	{
		// TODO
		/*
		make new connection class
		replace section in connection state with that class use
		send data packets with class here

		how to get the data from packets to objects?

		*/








		charController->update(dt);
	}

	// draw all game objects
	void GamePlayState::draw()
	{
		_gameData->window.clear();

		charController->draw();

		_gameData->window.display();
	}

	// exit state, delete required objects (controlled by GameStateMachine)
	void GamePlayState::exit()
	{

	}

}