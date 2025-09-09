// Header file for playing cards
#include <stdbool.h>

#ifndef PLAYING_CARDS_H
#define PLAYING_CARDS_H

// struct defining playing cards
typedef struct {
  char suit[9];
  char value[6];
} card_t;

// struct defining queue to hold cards
typedef struct {
  card_t *deck;
  int head;
  int tail;
  int num_entries;
  int size;
} queue_t;

// initializing queue with space for the entire deck
void init_queue(queue_t *q);

// deallocating cards in the deck
void clear_queue(queue_t *q);

// adding cards to the deck
bool enqueue(queue_t *q, card_t card);

// removing cards from the top of the deck
card_t dequeue(queue_t *q);

// create a deck out of a circular queue
void create_deck(queue_t *q);

// shuffle the deck
void shuffle_deck(queue_t *q);

// print out cards left in the deck
void print_cards(queue_t *q);

// print out the last three cards played
void print_last_three(queue_t *q);

#endif //PLAYING_CARDS_H