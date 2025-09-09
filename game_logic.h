// header file for Egyptian Rat Screw game logic

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

void set_agent(agent_t *a, int level);

float random_rxn(agent_t *a);

int face_check(card_t *card);

void print_winner(queue_t *q, queue_t *p1, queue_t *p2);

#endif  // GAME_LOGIC_H
