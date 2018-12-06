

#ifndef PLAYER_H
#define PLAYER_H

#include"Hand.h"
#include "Card.h"


enum class playerType {dealer=0, player=1};

class Player
{
private:
    int funds;
    string pname;
protected:
    Hand m_hand;
    playerType ptype;
    
public:
    // default constructor for player creation
    Player() {};
    Player(const playerType pt, const Card c1, const Card c2);
    playerType getPlayer();
    friend ostream& operator<<(ostream& os, const Player& someHand);
    void incFunds(int monies);
    void decFunds(int monies);
    int getFundsVal();
    int getPoints();
    void addCard(Card);
};
#endif
