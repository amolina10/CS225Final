

#ifndef CARD_H
#define CARD_H
#include <vector>
#include <string>
#include "termcolor.hpp"

using namespace std;
using namespace termcolor;

// this enum aliasing may not work
enum class faces  { one=1, two=2, three=3, four=4, five=5, six=6, seven=7, eight=8, nine=9, ten=10, jack=11, queen=12, king=13, ace=14};
enum class suits {hearts, diamonds, spades, clubs};

class Card
{
private:
    faces cface;
    suits csuit;
    int value;
    
public:
    Card();
    Card(faces face, suits suit);
    bool operator ==(Card anyCard);
    void calcCardVal();
    int getCardValue() const;
    suits getSuite() const;
    faces getFace();
    string getCardName();
};
#endif // CARD_H

