// Standard headers
#include <stdio.h>

// Internal headers
#include "direction.h"
#include "position.h"
#include "spy.h"

// Main header
#include "attacker.h"

// Macros
#define UNUSED(x) (void)(x) // Auxiliary to avoid error of unused parameter

/*----------------------------------------------------------------------------*/
/*                              PUBLIC FUNCTIONS                              */
/*----------------------------------------------------------------------------*/

static position_t current_attacker_position;
static int dir_attacker = 0;
static int add = 1;

direction_t execute_attacker_strategy(
    position_t attacker_position, Spy defender_spy) {

	if(current_attacker_position.i == attacker_position.i && 
		current_attacker_position.j == attacker_position.j)
		dir_attacker = (dir_attacker + add) % 4;

	if(attacker_position.j == 4 && add == 1){
		position_t defender_position = get_spy_position(defender_spy);
		if(defender_position.i <= 4) {
			dir_attacker = 3;
			add = 3;
		}
	}

  	current_attacker_position = attacker_position;

	if(dir_attacker == 0) 
		return (direction_t) DIR_UP;
	else if(dir_attacker == 1) 
		return (direction_t) DIR_RIGHT;
	else if(dir_attacker == 2) 
		return (direction_t) DIR_DOWN;
	else 
		return (direction_t) DIR_LEFT;
}

/*----------------------------------------------------------------------------*/
