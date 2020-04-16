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
    removeCardFromHand(c1);
    removeCardFromHand(c2);
}

Card Player::chooseCardFromHand() const {
    int size = myHand.size();
    int num1 = (rand() % size);
    return (myHand.at(num1));
}

Card Player::removeCardFromHand(Card c) {
    int place = 0;
    Card p;
    while (myHand.at(place)!=c){
        place++;
    }
    myHand.erase(myHand.begin()+place);
    return c;
}

Card Player::findSameRank(Card c) const {
    int place = 0;
    while (myHand.at(place).getRank()!=c.getRank()){
        place++;
    }
    return myHand.at(place);

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

string Player::showBooks() const {
    int size = myBook.size();
    if(size==0){
        cout << "no books";
    }
    string s;
    for(int i=0;i<size;i+=2){
        s.append(myBook.at(i).toString());
        s.append(myBook.at(i+1).toString());
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

bool Player::sameRankInHand(Card c) const {
    int size = myHand.size();
    for(int i=0;i<size;i++){
        if(c.getRank()==myHand.at(i).getRank()){
            return true;
        }
    }
    return false;
}