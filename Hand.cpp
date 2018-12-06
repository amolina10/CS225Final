
#include "Hand.h"

void Hand::init(Card card1, Card card2)
{
    
    thisHand.push_back(card1);
    thisHand.push_back(card2);
}

void Hand::addCard(Card card)
{
    //cout << white << "Took out: " << magenta << card.getCardName() << white << endl;
    thisHand.push_back(card);
    hVal += card.getCardValue();
}

int Hand::getTotalVal()
{
    return hVal;
}

int Hand::getNumOfCards()
{
    return thisHand.size();
}

ostream & operator<<(ostream & os, const Hand & someHand)
{
    os << yellow;
    for (Card element : someHand.thisHand)
    {
        cout << endl;
        os << element.getCardName();
    }
    os << white;
    return os;
}
