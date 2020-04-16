//
// Created by Austin~ on 4/15/2020.
//
#include "card.h"


Card::Card(){
    myRank = 1;
    mySuit = spades;
}

Card::Card(int rank, Suit S){
    myRank = rank;
    mySuit = S;
}

string Card::toString() const{
    string s;
    string suit;
    s = rankString();
    suit = suitString(mySuit);
    s.append(suit);
    return s;
}

bool Card::sameSuitAs(const Card& c) const{
    return (mySuit == c.mySuit);
}

int  Card::getRank() const{
    return myRank;
}

string Card::suitString(Suit s) const{
    string suit;
    if(mySuit==Suit::spades){suit = 's';}
    if(mySuit==Suit::hearts){suit = 'h';}
    if(mySuit==Suit::diamonds){suit = 'd';}
    if(mySuit==Suit::clubs){suit = 'c';}
    return suit;
}

string Card::rankString() const{
    string s;
    if((1<myRank)&&(myRank<11)){
        stringstream ss;
        ss<<myRank;
        ss>>s;
    }
    else{
        if(myRank==11){s="J";}
        if(myRank==12){s="Q";}
        if(myRank==13){s="K";}
        if(myRank==1){s="A";}
    }
    return s;
}

bool Card::operator == (const Card& rhs) const{
    return ((mySuit == rhs.mySuit)&&(myRank == rhs.myRank));
}

bool Card::operator != (const Card& rhs) const{
    return !((mySuit == rhs.mySuit)&&(myRank == rhs.myRank));
}
