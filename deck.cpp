//
// Created by Austin~ on 4/15/2020.
//

#include "deck.h"

Deck::Deck(){
    myIndex=51;
    for(int i=0;i<13;i++) {
        myCards[i] = Card(i+1, Card::spades);
        myCards[i+13] = Card(i+1, Card::hearts);
        myCards[i+26] = Card(i+1, Card::diamonds);
        myCards[i+39] = Card(i+1, Card::clubs);
    }
    unsigned int currentTime = (unsigned) time(0);
    srand(currentTime);
}

void Deck::shuffle(){
    //Randomly selects two nodes, swaps their data. Repeats this process five times the number of songs.
    for(int i=0;i<5*SIZE;i++) {
        int num1 = (rand() % SIZE);
        int num2 = (rand() % SIZE);
        Card temp = myCards[num1];
        myCards[num1] = myCards[num2];
        myCards[num2] = temp;
    }
}

Card Deck::dealCard() {
    Card card = myCards[myIndex];
    myIndex--;
    return card;
}

int Deck::size() const{
    return myIndex+1;
}