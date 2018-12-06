
#ifndef HAND_H
#define HAND_H
#include"Card.h"

class Hand
{
public:
    
    void init(Card, Card);
    friend ostream& operator<<(ostream& os, const Hand& someHand);
    
    void addCard(Card);
    
    int getNumOfCards();
    int getTotalVal();
    
private:
    vector<Card> thisHand;
    int hVal;
};
#endif // HAND_H
