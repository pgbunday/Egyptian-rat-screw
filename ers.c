#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//struct defining playing cards
typedef struct card_struct{
    char suite[9];
    char value[6];
} card_t;

typedef struct queue{
    card_t *deck;
    int head;
    int tail;
    int num_entries;
    int size;
} queue_t;

const card_t BLANK = {"None", "None"};

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
    q->tail = (q->tail + 1) % q->size;
    q->num_entries++;
    return true;
}

card_t dequeue(queue_t *q){
    if (q->num_entries == 0){
        return BLANK;
    }
    card_t temp = q->deck[q->head];
    q->head = (q->head + 1) % q->size;
    q->num_entries--;
    return temp;
}

//change return type and input type to circular queue
queue_t create_deck(queue_t q){
    char values[13][6] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    char suites[4][9] = {"Spades", "Clubs", "Hearts", "Diamonds"};
    for (int i = 0; i < 13; i++){
        for (int j = 0; j < 4; j++){
            card_t new_card;
            strcpy(new_card.value, values[i]);
            strcpy(new_card.suite, suites[j]);
            enqueue(&q, new_card);
        }
    }
    return q;
}

queue_t shuffle_deck(queue_t q){
    srand(time(NULL));
    for (int i = 0; i < 52; i++){
        int rand_index = rand() % 52;
        card_t temp = q.deck[i];
        q.deck[i] = q.deck[rand_index];
        q.deck[rand_index] = temp;
    }
    return q;
}

int main(void){
}