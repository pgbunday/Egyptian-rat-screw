#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct defining playing cards
typedef struct card_struct{
    char suite[9];
    char value[6];
} card_t;

typedef struct queue{
    struct card_t *deck;
    int head;
    int tail;
    int num_entries;
    int size;
} queue_t;

void init_queue(queue_t *q){
    q->deck = malloc(sizeof(card_t)*52);
    q->size = 52;
    q->head = 0;
    q->tail = 0;
    q->num_entries = 0;
}

bool enqueue(queue_t *q, card_t value){
    if (q->size == q->num_entries){
        return false;
    }
    q->deck[q->tail] = value;
    q->num_entries++;
    q->tail = (q->tail + 1) % q->size;
    
    return true;
}

card_t dequeue(queue_t q){
}

//change return type and input type to circular queue
card_t create_deck(void){
    char values[13][6] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    char suites[4][9] = {"Spades", "Clubs", "Hearts", "Diamonds"};
    for (int i = 0; i < 13; i++){
        for (int j = 0; j < 4; j++){
            //add cards to main deck queue
        }
    }
}

int main(void){
}