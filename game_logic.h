//header file for Egyptian Rat Screw game logic

#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

typedef struct {
    //rxn_time represents the time it will take the computer to react to a slap
    float rxn_time;
    //probability that the computer will make an error and not slap when it should
    float error_rate;
    //probability that the computer will miss slap
    float miss_slap;
} agent_t;

#endif  //GAME_LOGIC_H
