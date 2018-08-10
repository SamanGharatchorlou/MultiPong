#include "ConnectionState.h"
#include "GamePlayState.h"

namespace srac
{
	ConnectionState::ConnectionState(GameDataRef gameData) : _gameData(gameData) {  }

	// initialise all game state variables (controlled by GameStateMachine)
	void ConnectionState::enter()
	{
		// network
		sf::IpAddress address = "10.205.175.38";
		unsigned short serverPort = 1234;
		unsigned short clientPort;
		sf::UdpSocket socket;
		std::string mode;

		// enter mode server / client
		std::cout << "Enter mode: 'server' or 'client': ";
		std::cin >> mode;


		// client/server bindings
		if (mode == "client")
		{
			sf::Packet sendPackage;

			// client bind
			socket.bind(0);
			clientPort = socket.getLocalPort();
			sendPackage << clientPort;

			std::cout << "client binded to port: " << clientPort << std::endl;
			std::cout << "the server is on port: " << serverPort;

			socket.send(sendPackage, address, serverPort);
		}
		else if (mode == "server")
		{
			sf::Packet recevivePacket;

			// server bind
			socket.bind(serverPort);
			std::cout << "server binded to port: " << socket.getLocalPort() << std::endl;

			socket.receive(recevivePacket, address, serverPort);

			if (recevivePacket >> clientPort)
			{
				std::cout << "the client is on port: " << clientPort;
			}
		}


		socket.setBlocking(false);
	}

	// process lower level state changes i.e. player, enemy
	void ConnectionState::processStateChanges()
	{

	}

	// read game inputs
	void ConnectionState::handleInput()
	{
		sf::Event event;

		while (_gameData->window.pollEvent(event))
		{
			// X is pressed (top right)
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				_gameData->window.close();
			}
		}
	}

	// update all game objects
	void ConnectionState::update(float dt)
	{
		_gameData->machine.replaceState(stateRef(new GamePlayState(_gameData)));
	}

	// draw all game objects
	void ConnectionState::draw()
	{

	}

	// exit state, delete required objects (controlled by GameStateMachine)
	void ConnectionState::exit()
	{

	}

}