#include "playing_cards.h"
#include <stdio.h>

//figure out if there are memory leaks?

int main(void){
    //testing out main deck creation and shuffling
    queue_t main_deck;
    init_queue(&main_deck);
    create_deck(&main_deck);
    printf("Printing initialized deck:\n");
    print_cards(&main_deck);
    printf("Length of deck: %i\n", main_deck.num_entries);
    shuffle_deck(&main_deck);
    printf("\n\nPrinting shuffled deck:\n");
    print_cards(&main_deck);
    printf("Length of deck: %i\n", main_deck.num_entries);
    queue_t computer_deck;
    queue_t player_deck;
    init_queue(&computer_deck);
    init_queue(&player_deck);
    create_player_decks(&main_deck, &computer_deck, &player_deck, 26);
    printf("\n\nPrinting the computer's deck:\n");
    print_cards(&computer_deck);
    printf("Length of computer's deck: %i\n", computer_deck.num_entries);
    printf("\n\nPrinting the player's deck:\n");
    print_cards(&player_deck);
    printf("Length of player's deck: %i\n", player_deck.num_entries);
    printf("\n\nPrinting main deck:\n");
    print_cards(&main_deck);
    printf("Length of deck: %i\n", main_deck.num_entries);
    printf("\nadding cards back to the main deck\n\n");
    add_back_to_deck(&computer_deck, &main_deck);
    printf("Printing the computer's deck:\n");
    print_cards(&computer_deck);
    printf("Length of computer's deck: %i\n", computer_deck.num_entries);
    printf("\n\nPrinting main deck:\n");
    print_cards(&main_deck);
    printf("Length of deck: %i\n", main_deck.num_entries);

    //testing out printing the top three cards of a deck
    queue_t small_deck;
    init_queue(&small_deck);
    card_t king = {"Spades", "King"};
    card_t queen = {"Diamonds", "Queen"};
    card_t jack = {"Hearts", "Jack"};
    card_t ace = {"Clubs", "Ace"};
    enqueue(&small_deck, king);
    enqueue(&small_deck, queen);
    enqueue(&small_deck, jack);
    enqueue(&small_deck, ace);
    printf("\n\nFirst check and deck head: %i\n", small_deck.head);
    print_last_three(&small_deck);
    dequeue(&small_deck);
    printf("\nSecond check and deck head: %i\n", small_deck.head);
    print_last_three(&small_deck);
    dequeue(&small_deck);
    printf("\nThird check and deck head: %i\n", small_deck.head);
    print_last_three(&small_deck);
    dequeue(&small_deck);
    printf("\nFourth check and deck head: %i\n", small_deck.head);
    print_last_three(&small_deck);

    //free memory
    // clear_queue(&main_deck);
    // clear_queue(&computer_deck);
    // clear_queue(&player_deck);
    // clear_queue(&small_deck);
}