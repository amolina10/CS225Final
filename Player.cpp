
#include "Player.h"
#include "termcolor.hpp"
#include "Card.h"
#include "Card.cpp"
#include "Game.h"
#include <string>
#include <locale>
#include "Player.h"

using namespace std;
using namespace termcolor;

Player::Player(playerType pt, const Card c1, const Card c2)
{
    if (pt == playerType::dealer)
    {
        // update the pot of the dealer
        funds = 100000;
        //pname = "Tyrone";
        // greet the player
        //cout << magenta << pname << " is your dealer!" << endl;
        //cout << "He has $" << funds << endl;
        // add cards to the hand
        m_hand.addCard(c1);
        m_hand.addCard(c2);
        cout << "Dealer Hand:  " << m_hand << white << endl;
        cout<< "Dealer point total" << m_hand.getTotalVal() <<endl;
   
    }
    else
    {
        cout << blue << "Enter a player name:  " << white << endl;
        cin >> pname;
        // create the player
        cout << blue << "Welcome " << pname << endl;
        // update the pot of the dealer
        funds = 1000;
        cout << "You have $" << funds << endl;
        // add cards to the hand
        m_hand.addCard(c1);
        m_hand.addCard(c2);
        cout << "Your Hand:  " << m_hand << white << endl;
    }
}

void Player::incFunds(int monies)
{
    funds += monies;
}


int Player::getFundsVal()
{
    return funds;
}

void Player::decFunds(int monies) { funds -= monies; }

int Player::getPoints()
{
    return m_hand.getTotalVal();
}

void Player::addCard(Card someCard)
{
    m_hand.addCard(someCard);
}

playerType Player::getPlayer()
{
    return ptype;
}

ostream& operator<<(ostream& os, const Player& somePlayer)
{
    os << blue << "Your cards: " << somePlayer.m_hand << white << endl;
    return os;
}
