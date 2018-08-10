#pragma once
#pragma once

// abstract class to be inherited by all game state objects
namespace srac
{
	struct GameState
	{
		// pure virtual functions - require override
		virtual void enter() = 0;
		virtual void processStateChanges() = 0;
		virtual void handleInput() = 0;
		virtual void update(float dt) = 0;
		virtual void draw() = 0;
		virtual void exit() = 0;

		// virtual functions - optional
		virtual void pause() {  }
		virtual void resume() {  }
	};


}