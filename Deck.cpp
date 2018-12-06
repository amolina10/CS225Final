#include"Deck.h"

Deck::Deck()
{
    // putting 4 cards in the deck
    cardsExist.push_back(drawCard());
    cardsExist.push_back(drawCard());
    cardsExist.push_back(drawCard());
    cardsExist.push_back(drawCard());
}

Card Deck::drawCard()
{
    // generate random number for face value
    faces f = static_cast<faces>(rand() % ((14 - 1) + 1) + 1);
    suits s = static_cast<suits>(rand() % ((3 - 1) + 1) + 1);
    Card n_card(f , s);
    
    if (cardsExist.size() != 0)
    {
        // check if the card already exists in the deck.  if not add to deck
        while (!validCard(n_card))
        {
            Card n_card{ static_cast<faces>(rand() % 13), static_cast<suits>(rand() % 4) };
        }
    }
    
    // generate random number for face value
    cardsExist.push_back(n_card);
    // return this card
    return n_card;
}

bool Deck::validCard(Card someCard)
{
    for (Card element : cardsExist)
    {
        if (element == someCard)
        {
            return false;
        }
    }
    return true;
}
