
#ifndef DECK_H
#define DECK_H
#include<vector>
#include"Card.h"
#include "termcolor.hpp"

using namespace std;
using namespace termcolor;

class Deck
{
public:
    Deck();
    
    Card drawCard();
    bool validCard(Card aCard);
private:
    vector<Card> cardsExist;
};
#endif
