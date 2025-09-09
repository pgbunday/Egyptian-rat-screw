#include "game_logic.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//functions to make: randomize reaction time, check for sandwiches, face card slaps, 2 player & computer?
//card flipping, game loop, player slap, computer slap, print winner

float random_rxn(int level) {
    //if on easy difficulty
    if (level == 1){
        float max = 0.5;
        float min = 0.2;
    }
    return 0.0;
}

float random_in_bounds(float min, float max) {
    // create a random number [0, 1]
    float scale = (float)rand() / (float)RAND_MAX;
    // return a random number [min, max]
    return min + scale * (max - min);
}

int main(void) {
    // create a new random seed
    srand(time(NULL));

    // testing random function
    // float max = 0.5;
    // float min = 0.3;
    // float random_real = random_in_bounds(min, max);
    // printf("Random real number between %.2f and %.2f: %f\n", min, max, random_real);
    // for (int i = 0; i < 10; i++) {
    //   float r = random_in_bounds(min, max);
    //   printf("%f\n", r);
    // }
}