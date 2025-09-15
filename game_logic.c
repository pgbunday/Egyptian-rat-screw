#include "game_logic.h"
#include "playing_cards.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//functions to make: 2 player & computer?
//game loop

// initialize the agent based on the level the player chose
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

// return a boolean to determine if the computer makes an error based on its error threshold
bool random_error(float threshold) {
  // create a random number [0, 1]
  float random = (float)rand() / (float)RAND_MAX;
  // if the error is within the limits then return true
  if (random <= threshold) {
    return true;
  }
  return false;
}

// return a float representing the milliseconds it takes the computer to respond to a slap
float random_rxn_time(agent_t *a) {
    // create a random number [0, 1]
    float scale = (float)rand() / (float)RAND_MAX;
    // return a random number [rxn_min, rxn_max]
    return a->rxn_min + scale * (a->rxn_max - a->rxn_min);
}

// check whether or not one of four special cards was played
// returns the number of turns the opponent has to respond
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

// check if a sandwich is present
bool sandwich_check(queue_t *q) {
  if (q->num_entries <= 1) {
    return false;
  }
  if (q->num_entries >= 2) {
    if (strcmp(q->deck[q->head].value, q->deck[(q->head + 1) % q->size].value) == 0) {
      return true;
    }
  }
  if (q->num_entries >= 3) {
    if (strcmp(q->deck[q->head].value, q->deck[(q->head + 2) % q->size].value) == 0) {
      return true;
    }
  }
  return false;
}

// flip a card onto the main pile
void card_flip(queue_t *q, queue_t *p) {
  if (p->num_entries > 0) {
    card_t temp = dequeue(p);
    enqueue(q, temp);
  }
}

// pick up deck
void deck_pick_up(queue_t *q, queue_t *p) {
  card_t temp;
  for (int i = 0; i < q->num_entries; i++) {
    temp = dequeue(q);
    enqueue(p, temp);
  }
}

// slap function
bool slap(queue_t *q, queue_t *p) {
  bool good_slap = sandwich_check(q);
  if (good_slap) {
    deck_pick_up(q, p);
    return true;
  }
  // penalty for a misslap is to put down one card
  // figure out how to deal with slapping when you are out of cards
  else {
    if (p->num_entries > 0) {
      card_t temp = dequeue(p);
      enqueue(q, temp);
      return true;
    }
  }
  return false;
}

// TODO add printing out player names
// print the winner of the game
void print_winner(queue_t *q, queue_t *p1, queue_t *p2) {
    if (q->num_entries == 0 && p1->num_entries == 0) {
        printf("The winner is p2");
    }
    else if (q->num_entries == 0 && p2->num_entries == 0) {
        printf("The winner is p2");
    }
}

// check whether or not someone has won and the game should end
bool check_game_status(queue_t *q, queue_t *p1, queue_t *p2) {
  // checking if the game was initialized correctly
  if (q->num_entries == 0 && p1->num_entries == 0 && p2->num_entries == 0){
    return false;
  } 
  // checking if someone won
  else if ((q->num_entries == 0 && p1->num_entries == 0) || (q->num_entries == 0 && p2->num_entries == 0)) {
    return false;
  }
  // if both players still have cards continue the game
  else if (p1->num_entries != 0 && p2->num_entries != 0) {
    return true;
  }
  // check if that is all cases that need to be considered
  return true;
}

// game loop for a computer vs. a person
void comp_v_player(queue_t *q, queue_t *p1, queue_t *p2) {
  bool game_status = check_game_status(q, p1, p2);
  while (game_status) {
    
    // keep going until the game ends
    game_status = check_game_status(q, p1, p2);
  }
}

int main(void) {
    // create a new random seed
    // srand(time(NULL));

    // testing random function
    // int level = 2;
    // agent_t t;
    // set_agent(&t, level);
    // float random_real = random_rxn_time(&t);
    // printf("Random real number between %.3f and %.3f: %f\n", t.rxn_min, t.rxn_max, random_real);
    // for (int i = 0; i < 10; i++) {
    //   float r = random_rxn_time(&t);
    //   printf("%f\n", r);
    // }
}