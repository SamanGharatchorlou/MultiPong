#include "GameStateMachine.h"
#include <iostream>

namespace srac
{
	void GameStateMachine::addState(stateRef state)
	{
		_isAdding = true;
		_isRemoving = false;
		_isReplacing = false;
		_newState = std::move(state);
	}

	void GameStateMachine::removeState()
	{
		_isRemoving = true;
		_isAdding = false;
		_isReplacing = false;

		if (_states.size() == 0)
			std::cout << "no states!" << std::endl;
	}

	void GameStateMachine::replaceState(stateRef state)
	{
		_isReplacing = true;
		_isAdding = false;
		_isRemoving = false;
		_newState = std::move(state);
	}

	void GameStateMachine::processStateChanges()
	{
		// add new state
		if (_isAdding)
		{
			_states.push(std::move(_newState));
			_states.top()->enter();

			_isAdding = false;
		}
		// remove top state
		else if (_isRemoving)
		{
			if (_states.size() > 1)
			{
				_states.top()->exit();
				_states.pop();

				_states.top()->resume();
			}

			_isRemoving = false;
		}
		// replace top state
		else if (_isReplacing)
		{
			if (_states.size() > 0)
			{
				_states.top()->exit();
				_states.pop();

				_states.push(std::move(_newState));
				_states.top()->enter();

				_isReplacing = false;
			}
		}
	}

	void GameStateMachine::clearStates()
	{
		while (_states.size() > 1)
		{
			_states.pop();
		}
	}

	stateRef& GameStateMachine::getActiveState()
	{
		if (_states.size() > 0)
			return _states.top();
		else
			std::cout << "no state" << std::endl;
	}

	int GameStateMachine::getStateCount()
	{
		return _states.size();
	}

}