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

void clear_queue(queue_t *q){
    for (int i = q->head; i < (q->num_entries + q->head) % q->size; i++){
        free(&q->deck[i]);
    }
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
void create_deck(queue_t *q){
    char values[13][6] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    char suites[4][9] = {"Spades", "Clubs", "Hearts", "Diamonds"};
    for (int i = 0; i < 13; i++){
        for (int j = 0; j < 4; j++){
            card_t new_card;
            strcpy(new_card.value, values[i]);
            strcpy(new_card.suite, suites[j]);
            enqueue(q, new_card);
        }
    }
}

void shuffle_deck(queue_t *q){
    srand(time(NULL));
    for (int i = 0; i < 52; i++){
        int rand_index = rand() % 52;
        card_t temp = q->deck[i];
        q->deck[i] = q->deck[rand_index];
        q->deck[rand_index] = temp;
    }
}

void print_cards(queue_t *q){
    for (int i = 0; i < q->num_entries; i++){
        printf("%s of %s", q->deck[i].value, q->deck[i].suite);
    }
}

int main(void){
    queue_t main_deck;
    init_queue(&main_deck);
    create_deck(&main_deck);
    print_cards(&main_deck);
    shuffle_deck(&main_deck);
    print_cards(&main_deck);

    clear_queue(&main_deck);
    free(&main_deck);
}