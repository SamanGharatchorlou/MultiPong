#pragma once
#include "GameState.h"

#include <memory>
#include <stack>
#include <vector>

namespace srac
{
	typedef std::unique_ptr<GameState> stateRef;

	class GameStateMachine
	{
	private:
		stateRef _newState;
		std::stack<stateRef> _states;

		bool _isAdding, _isRemoving, _isReplacing;

	public:
		void addState(stateRef state);
		void removeState();
		void replaceState(stateRef state);

		void processStateChanges();
		void clearStates();

		int getStateCount();

		stateRef& getActiveState();
	};
}