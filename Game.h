
#ifndef GAME_H
#define GAME_H

#include "Deck.h"
#include "Player.h"

class Game
{
public:
    Game();
    void playGame();
    bool pushed();
    bool busted(const Player);
    void bet();
    void dealerOps();
    
    void hit(Player, Card, char);
    
private:
    Deck thisDeck{};
    Player dl{ playerType::dealer, thisDeck.drawCard(), thisDeck.drawCard() }, p1{ playerType::player, thisDeck.drawCard(), thisDeck.drawCard() };
    int pot;
    int playerBet;
    bool doubleDown;
    bool Stand;
    
};
#endif
