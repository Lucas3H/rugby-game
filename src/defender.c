// Standard headers
#include <stdio.h>

// Internal headers
#include "direction.h"
#include "position.h"
#include "spy.h"

// Main header
#include "defender.h"

// Macros
#define UNUSED(x) (void)(x) // Auxiliary to avoid error of unused parameter

/*----------------------------------------------------------------------------*/
/*                              PUBLIC FUNCTIONS                              */
/*----------------------------------------------------------------------------*/

static int rounds = 0;
static size_t final_row;

direction_t execute_defender_strategy(
    position_t defender_position, Spy attacker_spy) {
  	// TODO: unused parameters, remove these lines later

	rounds++;
	if(rounds < 5){
		if(rounds%2 == 0) 
			return (direction_t) DIR_UP;
		else 
			return (direction_t) DIR_DOWN;
	}
	if(rounds == 5){
		position_t attacker_position = get_spy_position(attacker_spy);
		if(attacker_position.i <= 4) 
			final_row = 3;
		else
			final_row = 7;
	}

	if(final_row <= defender_position.i)
		return (direction_t) DIR_UP;
	else
		return (direction_t) DIR_DOWN;
}

/*----------------------------------------------------------------------------*/
