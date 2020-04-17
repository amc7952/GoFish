// FILE:  player.h
// written by Roger Priebe
// 1/22/08 (revised 9/2/08)
// This class represents a player in a card game that takes "tricks"
// The "Books" represent a container for holding tricks

#ifndef _PLAYER_H
#define _PLAYER_H

#include <iostream>
#include <string>
#include <vector>


#include "card.h"
using namespace std;


class Player
{
public:
    Player();

    Player(string name) {
        myName = name;
    }

    string getName() const {
        return myName;
    }

    void addCard(Card c);  //adds a card to the hand

    //books two cards. Does not check if those two cards should be paired.
    // Removes the cards from hand Pre-condition: Chosen cards actually exist in hand.
    void bookCards(Card c1, Card c2);

    //OPTIONAL
    // comment out if you decide to not use it
    //this function will check a players hand for a pair.
    //If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

    //bool checkHandForBook(Card &c1, Card &c2);

    //OPTIONAL
    // comment out if you decide to not use it
    //Does the player have a card with the same rank as c in her hand?
    //bool rankInHand(Card c) const;

    //Randomly selects a card from the hand. Pre-condition: At least 1 card is in hand.
    Card chooseCardFromHand() const;


    //returns card in hand that is the same rank as given card. Pre-condition: At least 1 card is in hand.
    Card findSameRank(Card c) const;

    //Does the player have the card c in her hand?
    //bool cardInHand(Card c) const;

    //Remove the card c from the hand and return it to the caller
    Card removeCardFromHand(Card c);

    string showHand() const;
    string showBooks() const;

    int getHandSize() const;
    int getBookSize() const;

    //OPTIONAL
    // comment out if you decide to not use it
    //this function will check a players hand for a pair.
    //If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

    bool checkHandForPair(Card &c1, Card &c2);

    //OPTIONAL
    // comment out if you decide to not use it
    //Does the player have a card with the same rank as c in her hand?
    //e.g. will return true if the player has a 7d and the parameter is 7c

    bool sameRankInHand(Card c) const;


private:
    vector <Card> myHand;

    vector <Card> myBook;

    string myName;

};


#endif