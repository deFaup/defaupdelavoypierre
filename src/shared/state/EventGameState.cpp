// includes
#include "define.hpp"
#include "EventGameState.h"

using namespace std;
using namespace state;

// set all atributes to false (parent's one included)
EventGameState::EventGameState()
{
	events[GameState_newMap] = false;
	events[GameState_playerChanged] = false;
	events[GameState_charactersChanged] = false;
	events[GameState_stateID_Changed] = false;
}

bool EventGameState::hasChanged() 
{
	bool changed_copy = false;// (changed);
	return changed_copy;
}

