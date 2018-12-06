#include "Game.h"
#include <string>
#include <locale>
#include "Player.h"

Game::Game()
{
    doubleDown = false;
    Stand = false;
    playerBet = 0;
    pot = 0;
}

void Game::playGame()
{
    // get bets
    bet();
    // push off first deal
    /*****************************************how do i know if i havent added points*/
    
    if (pushed())
    {
        cout<< "tie bet returned" << endl;
        // return bets to players
        p1.incFunds(playerBet);
        dl.incFunds(playerBet);
        
    }
    // dealer busts off the deal
    else if (busted(dl))
    {
        // standard winnings are 2.5x
        p1.incFunds(playerBet * 2.5);
        // give winnings to player and ask to deal again
        cout << green << " Dealer Busted on Deal, You Win 2.5x bet!" << endl
        << "Your Pot is now = " << p1.getFundsVal() << white << endl;;
    }
    // player busted on deal
    else if(busted(p1))
    {
        p1.decFunds(playerBet);
        // give winnings to dealer and ask to deal again
        cout << green << " Player Busted on Deal, You lose!" << endl
        << "Your Pot is now = " << p1.getFundsVal() << white << endl;;
    }
    // play the game
    else
    {
        char choice;
        cout << red << "Would you like to double down? Enter 'y' for yes:  " << endl;
        cin >> choice;

        if (tolower(choice) == 'y') {
            pot += playerBet;
            p1.decFunds(playerBet);
            doubleDown = true;
            cout << p1.getFundsVal() << endl;
        }
        
        // player hit or stay?
        if(p1.getPoints() <21 ){
            cout << red << "hit or stay? Enter h to hit:  " << endl;
            cin >> choice;
            if (tolower(choice) == 'h')
            {
                hit(p1, thisDeck.drawCard(), choice);
            }
        }
        else
            cout<< "player hit over 21" <<endl;
        
        
         cout << "dealers turn" << endl;
            dealerOps();
        }
        // dealers turn to hit or stay
        //dealerOps();
        if (pushed())
        {
            cout << red << "Push, monies returned to players" << white << endl;
            pot = 0;
            p1.incFunds(playerBet);
            dl.incFunds(playerBet);
        }
        else if (dl.getPoints() > p1.getPoints())
        {
            cout << grey << "YOU LOST!" << white << endl;
        }
        else
        {
            cout << green << "YOU WON!" << white << endl;
        }
    
}

bool Game::pushed()
{
    if ((p1.getPoints() == 21) && (dl.getPoints() == 21))
    {
        cout << red << " Push!" << white << endl;
        return true;
    }
    else return false;
}

bool Game::busted(Player whoEver)
{
    if (whoEver.getPoints() > 21){
        return true;
    }
    else { return false; }
}

void Game::bet()
{
    cout << red << "Enter an amount you would like to bet:  " << endl;
    cin >> playerBet;
    
    if (playerBet <= p1.getFundsVal())
    {
        p1.decFunds(playerBet);
        pot += 2 * playerBet;
        dl.decFunds(playerBet);
        cout << red << "Your funds are now:  " << p1.getFundsVal() << endl
        << "House Funds are now:  " << dl.getFundsVal() << white << endl;
    }
}

void Game::dealerOps()
{
    //hit if dealer has less than 17 points
    while (dl.getPoints() < 17) {
        hit(dl, thisDeck.drawCard(), 'h');
        }
}

void Game::hit(Player anyPlayer, Card someCard, char choice) {

    if (anyPlayer.getPlayer() == playerType::dealer)
    {
        //p1.decFunds(playerBet);
       // cout << red << p1.getFundsVal() << white << endl;
        anyPlayer.addCard(someCard);
        anyPlayer.getPoints();
    }
    else {
        while (tolower(choice) == 'h')
        {
                cout << red << "Enter h to hit again:  " << white;
                cin >> choice;
                p1.decFunds(playerBet);
                cout << red << p1.getFundsVal() << white << endl;
                anyPlayer.addCard(someCard);
        }
    }
}
