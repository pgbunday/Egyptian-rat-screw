// header file for Egyptian Rat Screw game logic
#include <stdbool.h>

#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

typedef struct {
    // rxn_min and rxn_max represent the bounds on the time it will take the computer to react to a slap
    float rxn_min, rxn_max;
    // probability that the computer will make an error and not slap when it should
    float error_rate;
    // probability that the computer will miss slap
    float miss_slap;
    // computer name
    char name[40];
} agent_t;

typedef struct {
    // player name
    char name[40];
} player_t;

// initialize the agent based on the level the player chose
void set_agent(agent_t *a, int level);

// return a boolean to determine if the computer makes an error based on its error threshold
bool random_error(float threshold);

// return a float representing the milliseconds it takes the computer to respond to a slap
float random_rxn_time(agent_t *a);

// check whether or not one of four special cards was played
// returns the number of turns the opponent has to respond
int face_check(card_t *card);

// check if a sandwich is present
bool sandwich_check(queue_t *q);

// print the winner of the game
void print_winner(queue_t *q, queue_t *p1, queue_t *p2);

#endif  // GAME_LOGIC_H
