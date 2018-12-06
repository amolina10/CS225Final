#include "Card.h"
#include "termcolor.hpp"

Card::Card(faces cardf, suits suite)
{
    if (cardf == faces::ace)
    {
        char use11;
        cout << green << "You have drawn an ACE, enter 'y', to use as an 11:  " << white;
        cin >> use11;
        
        // check for usage
        if (tolower(use11) == 'y')
        {
            value = 11;
            cface = cardf;
            csuit = suite;
            calcCardVal();
        }
        else { value = 1; }
    }
    else
    {
        cface = cardf;
        csuit = suite;
        calcCardVal();
    }
}

bool Card::operator==(Card anyCard)
{
    if ((cface == anyCard.getFace()) && (csuit == anyCard.getSuite()))
    {
        return true;
    }
    else { return false; }
}

void Card::calcCardVal()
{
    switch(cface)
    {
        case faces::one: { value = 1; break; }
        case faces::two: { value = 2; break; }
        case faces::three: { value = 3; break; }
        case faces::four: { value = 4; break; }
        case faces::five: { value = 5; break; }
        case faces::six: { value = 6; break; }
        case faces::seven: { value = 7; break; }
        case faces::eight: { value = 8; break; }
        case faces::nine: { value = 9; break; }
        case faces::ten: { value = 10; break; }
        case faces::jack: { value = 11; break; }
        case faces::queen: { value = 12; break; }
        case faces::king: { value = 13; break; }
    }
}

int Card::getCardValue() const
{
    return value;
}

suits Card::getSuite() const
{
    return csuit;
}

faces Card::getFace()
{
    return cface;
}

string Card::getCardName()
{
    string buildUp;
    switch (cface)
    {
        case faces::one: { buildUp += "1"; break; }
        case faces::two: { buildUp += "2"; break; }
        case faces::three: { buildUp += "3"; break; }
        case faces::four: { buildUp += "4"; break; }
        case faces::five: { buildUp += "5"; break; }
        case faces::six: { buildUp += "6"; break; }
        case faces::seven: { buildUp += "7"; break; }
        case faces::eight: { buildUp += "8"; break; }
        case faces::nine: { buildUp += "9"; break; }
        case faces::ten: { buildUp += "10"; break; }
        case faces::jack: { buildUp += "Jack"; break; }
        case faces::queen: { buildUp += "Queen"; break; }
        case faces::king: { buildUp += "King"; break; }
        case faces::ace: { buildUp += "Ace"; break; }
    }
    
    switch (csuit)
    {
        case suits::spades: { buildUp += " of spades"; break; }
        case suits::clubs: { buildUp += " of clubs"; break; }
        case suits::hearts: { buildUp += " of hearts"; break; }
        case suits::diamonds: { buildUp += " of diamonds"; break; }
    }
    
    return buildUp;
}
