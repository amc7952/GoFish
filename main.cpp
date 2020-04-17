// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);




int main( )
{
    int numCards = 7;

    Player p1("Joe");
    Player p2("Jane");
    Card c1;
    Card c2;

    Deck d;  //create a deck of cards
    d.shuffle();

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    cout << endl << "Cards are dealt" << endl << endl;

    while(p1.checkHandForPair(c1,c2)){
        cout << "Joe books the " << c1.toString() << " and " << c2.toString() << endl;
        p1.bookCards(c1,c2);
    }
    cout << p1.getName() <<" has Hand: " << p1.showHand() << endl << "       Books: " << p1.showBooks() << endl << endl;

    while(p2.checkHandForPair(c1,c2)){
        p2.bookCards(c1,c2);
        cout << "Jane books the " << c1.toString() << " and " << c2.toString() << endl;
    }
    cout << p2.getName() <<" has Hand: " << p2.showHand() << endl << "        Books: " << p2.showBooks() << endl << endl;

    //Runs game. Game ends when all 26 books have been booked.
    while((p1.getBookSize()+p2.getBookSize())<26){
        //Player 1s turn
        //Both players need a card for a card to be asked for. Otherwise automatic "Go Fish"
        if((p1.getHandSize()>0)&&(p2.getHandSize()>0)) {
            c1 = p1.chooseCardFromHand();
            cout << "Joe asks - Do you have a " << c1.rankString() << endl;
            cout << "Jane says - ";
            //Keep asking for more cards as long as player 2 had the card player 1 asked for.
            while (p2.sameRankInHand(c1)) {
                cout << "Yes. I have a " << c1.rankString() << endl;
                cout << "Joe takes the " << c1.toString() << endl;
                c1 = p2.findSameRank(c1);
                p2.removeCardFromHand(c1);
                p1.addCard(c1);
                if (p1.checkHandForPair(c1, c2)) {
                    cout << "Joe books the " << c1.toString() << " and " << c2.toString() << endl;
                    p1.bookCards(c1, c2);
                }
                if((p1.getHandSize()>0)&&(p2.getHandSize()>0)) {
                    c1 = p1.chooseCardFromHand();
                    cout << "Joe asks - Do you have a " << c1.rankString() << endl;
                    cout << "Jane says - ";
                }
                else if (p1.getHandSize()==0){
                    cout << "Joe can't ask for any cards (empty hand)" << endl;
                }
                else {
                    cout << "Jane has no cards to steal" << endl;
                }
            }

            cout << "Go Fish!" << endl;
        }
        if(d.size()>0) {
            c1 = d.dealCard();
            cout << "Joe draws the " << c1.toString() << endl;
            p1.addCard(c1);
        }
        else{cout << "No draw - deck is empty" << endl;}

        if(p1.checkHandForPair(c1,c2)){
            cout << "Joe books the " << c1.toString() << " and " << c2.toString() << endl;
            p1.bookCards(c1,c2);
        }

        cout << p1.getName() <<" has Hand: " << p1.showHand() << endl << "       Books: " << p1.showBooks() << endl << endl;

        //Player 2s turn
        //Both players need a card for a card to be asked for. Otherwise automatic "Go Fish"
        if((p1.getHandSize()>0)&&(p2.getHandSize()>0)) {
            c1 = p2.chooseCardFromHand();
            cout << "Jane asks - Do you have a " << c1.rankString() << endl;
            cout << "Joe says - ";
            //Keep asking for more cards as long as player 1 had the card player 2 asked for.
            while (p1.sameRankInHand(c1)) {
                cout << "Yes. I have a " << c1.rankString() << endl;
                cout << "Jane takes the " << c1.toString() << endl;
                c1 = p1.findSameRank(c1);
                p1.removeCardFromHand(c1);
                p2.addCard(c1);
                if (p2.checkHandForPair(c1, c2)) {
                    cout << "Jane books the " << c1.toString() << " and " << c2.toString() << endl;
                    p2.bookCards(c1, c2);
                }
                if((p1.getHandSize()>0)&&(p2.getHandSize()>0)) {
                    c1 = p2.chooseCardFromHand();
                    cout << "Jane asks - Do you have a " << c1.rankString() << endl;
                    cout << "Joe says - ";
                }
                else if (p2.getHandSize()==0){
                    cout << "Jane can't ask for any cards (empty hand)" << endl;
                }
                else {
                    cout << "Joe has no cards to steal" << endl;
                }
            }

            cout << "Go Fish!" << endl;
        }
        if(d.size()>0) {
            c1 = d.dealCard();
            cout << "Jane draws the " << c1.toString() << endl;
            p2.addCard(c1);
        }
        else{cout << "No draw - deck is empty" << endl;}

        if(p2.checkHandForPair(c1,c2)){
            cout << "Jane books the " << c1.toString() << " and " << c2.toString() << endl;
            p2.bookCards(c1,c2);
        }
        cout << p2.getName() <<" has Hand: " << p2.showHand() << endl << "       Books: " << p2.showBooks() << endl << endl;
    }

    cout << "Joe has " << p1.getBookSize() << " Books." << endl;
    cout << "Jane has " << p2.getBookSize() << " Books." << endl;
    if(p1.getBookSize()>p2.getBookSize()){
        cout << "Joe wins!\n";
    }
    else if (p1.getBookSize()==p2.getBookSize()){
        cout << "It's a tie!\n";
    }
    else {
        cout << "Jane Wins!\n";
    }

    return EXIT_SUCCESS;
}



void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}