//header file for Egyptian Rat Screw game logic

#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H



typedef struct {
    //rxn_min and rxn_max represent the bounds on the time it will take the computer to react to a slap
    float rxn_min, rxn_max;
    //probability that the computer will make an error and not slap when it should
    float error_rate;
    //probability that the computer will miss slap
    float miss_slap;
} agent_t;

float random_rxn(int level);

float random_in_bounds(float min, float max);

#endif  //GAME_LOGIC_H
