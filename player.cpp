//
// Created by Austin~ on 4/16/2020.
//

#include "player.h"

Player::Player(){
    vector<Card> hand;
}

void Player::addCard(Card c) {
    myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2) {
    myBook.push_back(c1);
    myBook.push_back(c2);
    int place1=0;
    int place2=0;
    while (myHand.at(place1)!=c1){
        place1++;
    }
    myHand.erase(myHand.begin()+place1);
    while (myHand.at(place1)!=c1){
        place1++;
    }
    myHand.erase(myHand.begin()+place2);
}

int Player::getHandSize() const {
    return myHand.size();
}

int Player::getBookSize() const {
    return (myBook.size()/2);
}

string Player::showHand() const {
    int size = myHand.size();
    string s;
    for(int i=0;i<size;i++){
        s.append(myHand.at(i).toString());
        s.append(" ");
    }
    return s;
}

bool Player::checkHandForPair(Card &c1, Card &c2) {
    int size = myHand.size();
    for(int i=0;i<size;i++){
        for (int w=i+1;w<size;w++){
            if(myHand.at(i).getRank()==myHand.at(w).getRank()){
                c1=myHand.at(i);
                c2=myHand.at(w);
                return true;
            }
        }
    }
    return false;
}