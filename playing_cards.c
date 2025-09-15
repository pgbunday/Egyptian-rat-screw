#include "game_logic.h"
#include "playing_cards.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/*
This file contains details to create cards, a deck (as a circular queue),
add cards to different decks, and print out the whole deck or
just the top three cards
*/


// constant to return during dequeue if the deck is empty
const card_t BLANK = {"None", "None"};

// initializing queue with space for the entire deck
void init_queue(queue_t *q) {
  q->deck = malloc(sizeof(card_t) * 52);
  q->size = 52;
  q->head = 0;
  q->tail = 0;
  q->num_entries = 0;
}

// deallocating cards in the deck
void clear_queue(queue_t *q) {
    // if (q->num_entries != 0) {
    //     for (int i = q->head; i < (q->num_entries + q->head) % q->size; i++) {
    //         free(&q->deck[i]);
    //     }
    // }
    free(q);
}

// adding cards to the deck
bool enqueue(queue_t *q, card_t card) {
  if (q->size == q->num_entries) {
    return false;
  }
  q->deck[q->tail] = card;
  // wrap around details
  q->tail = (q->tail + 1) % q->size;
  q->num_entries++;
  return true;
}

// removing cards from the top of the deck
card_t dequeue(queue_t *q) {
  if (q->num_entries == 0) {
    return BLANK;
  }
  card_t temp = q->deck[q->head];
  // wrap around details
  q->head = (q->head + 1) % q->size;
  q->num_entries--;
  return temp;
}

// create a deck out of a circular queue
void create_deck(queue_t *q) {
  char values[13][6] = {"Ace", "2", "3",  "4",    "5",     "6",   "7", "8",   "9", "10", "Jack", "Queen", "King"};
  char suits[4][9] = {"Spades", "Clubs", "Hearts", "Diamonds"};
  for (int i = 0; i < 13; i++) {
    for (int j = 0; j < 4; j++) {
      card_t new_card;
      strcpy(new_card.value, values[i]);
      strcpy(new_card.suit, suits[j]);
      enqueue(q, new_card);
    }
  }
}

// create the players' decks out of circular queues
void create_player_decks(queue_t *q, queue_t *p1, queue_t *p2, int p1_size) {
    for (int i = 0; i < p1_size; i++) {
        card_t temp = dequeue(q);
        enqueue(p1, temp);
    }
    for (int i = 0; i < (52 - p1_size); i++) {
        card_t temp = dequeue(q);
        enqueue(p2, temp);
    }
}

// add cards from the main deck to the player's deck
void add_back_to_deck(queue_t *q, queue_t *p) {
    int count = q->num_entries;
    for (int i = 0; i < count; i++) {
        card_t temp = dequeue(q);
        enqueue(p, temp);
    }
}

// shuffle the deck
void shuffle_deck(queue_t *q) {
  // create a new random seed each time
  srand(time(NULL));
  // outer loop to run more times if wanted
  for (int reps = 0; reps < 2; reps++) {
    for (int i = 0; i < 52; i++) {
      int rand_index = rand() % 52;
      card_t temp = q->deck[i];
      q->deck[i] = q->deck[rand_index];
      q->deck[rand_index] = temp;
    }
  }
}

// print out cards left in the deck
void print_cards(queue_t *q) {
  for (int i = 0; i < q->num_entries; i++) {
    printf("%s of %s\n", q->deck[i].value, q->deck[i].suit);
  }
}

// print out the last three cards played
void print_last_three(queue_t *q) {
  if (q->num_entries < 1) {
    printf("Game over!");
    return;
  }

  int count;

  if (q->num_entries < 3) {
    count = q->num_entries;
  }
  else {
    count = 3;
  }

  for (int i = 0; i < count; i++) {
    int index = (q->head + i) % q->size;
    card_t card = q->deck[index];
    printf("%d: %s of %s\n", index, card.value, card.suit);
  }
}