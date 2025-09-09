#include "game_logic.h"
#include "playing_cards.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//functions to make: check for sandwiches, 2 player & computer?
//card flipping, game loop, player slap, computer slap

void set_agent(agent_t *a, int level) {
    // if on easy difficulty (level 0)
    if (level == 0){
        a->error_rate = 0.40;
        a->miss_slap = 0.25;
        a->rxn_max = 0.5;
        a->rxn_min = 0.3;
    }
    // if on the normal difficulty (level 1)
    else if (level == 1) {
      a->error_rate = 0.30;
      a->miss_slap = 0.15;
      a->rxn_max = 0.325;
      a->rxn_min = 0.175;
    }
    // if on the hard difficulty (level 2)
    else if (level == 2) {
      a->error_rate = 0.10;
      a->miss_slap = 0.05;
      a->rxn_max = 0.2;
      a->rxn_min = 0.075;
    }
}

float random_rxn(agent_t *a) {
    // create a random number [0, 1]
    float scale = (float)rand() / (float)RAND_MAX;
    // return a random number [rxn_min, rxn_max]
    return a->rxn_min + scale * (a->rxn_max - a->rxn_min);
}

int face_check(card_t *card){
    if (strcmp(card->value, "Ace") == 0) {
        return 4;
    }
    else if (strcmp(card->value, "King") == 0) {
      return 3;
    }
    else if (strcmp(card->value, "Queen") == 0) {
      return 2;
    }
    else if (strcmp(card->value, "Jack") == 0) {
      return 1;
    }
    return 0;
}

// TODO add printing out player names
void print_winner(queue_t *q, queue_t *p1, queue_t *p2) {
    if (q->num_entries == 0 && p1->num_entries == 0) {
        printf("The winner is p2");
    }
    else if (q->num_entries == 0 && p2->num_entries == 0) {
        printf("The winner is p2");
    }
}

int main(void) {
    // create a new random seed
    srand(time(NULL));

    // testing random function
    // int level = 2;
    // agent_t t;
    // set_agent(&t, level);
    // float random_real = random_rxn(&t);
    // printf("Random real number between %.3f and %.3f: %f\n", t.rxn_min, t.rxn_max, random_real);
    // for (int i = 0; i < 10; i++) {
    //   float r = random_rxn(&t);
    //   printf("%f\n", r);
    // }
}