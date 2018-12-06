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
 
    bet();// get bets
    
    if ((p1.getPoints() == 21) && (dl.getPoints() == 21))
    {
        cout<< "tie, bet returned" << endl;
        // return bets to players
        p1.incFunds(playerBet);
        dl.incFunds(playerBet);
    }
    // play the game
    else
    {
        char choice;
        cout << red << "Would you like to double down? Enter 'y' for yes:  " << endl;
        cin >> choice;

        if (tolower(choice) == 'y') { //yes double down
            //check if enough founds
            if((p1.getFundsVal()- playerBet) >= p1.getFundsVal()){ 
                p1.decFunds(playerBet);
                cout << "New Funds:" p1.getFundsVal() << endl;
                hit(p1, thisDeck.drawCard(), choice);
            }
            else{
                choice == 'n'; //manually go to not doubling down
                break;
            }
        }
        
        if(tolower(choice) == 'n'){ //no dont double down
            cout << red << "hit(h) or stay(s)? :  " << endl;
            cin >> choice;
            while (tolower(choice) == 'h') //player hits
            {
               hit(p1, thisDeck.drawCard(), choice);
               if(!(busted(p1)))
               {
                    cout << red << "Enter h to hit again:  " << white;
                    cin >> choice;
               }
               else //busted
               {
                   cout << cyan << "You busted" << endl;
                   p1.decFunds(playerBet);
                   dl.incFunds(playerBet);
                   break;
               }
            }  
            cout << "dealers turn" << endl;         // dealers turn to hit or stay
                hit(dl, thisDeck.drawCard(), choice);
        }      

        if (pushed())
        {
            cout << red << "Push, monies returned to players" << white << endl;
            p1.incFunds(playerBet);
            dl.incFunds(playerBet);
        }
       if ((dl.getPoints() > p1.getPoints()) && (dl.getPoints() <21)))
        {
            cout << grey << "YOU LOST!" << white << endl;
        }
       if ((p1.getPoints() > dl.getPoints()) && (p1.getPoints() <21)))
        {
            cout << green << "YOU WON!" << white << endl;
            p1.incFunds(playerBet*2);
            "Your Pot is now = " << p1.getFundsVal() << white << endl;;
        }
}

bool Game::pushed()
{
    if (p1.getPoints() == dl.getPoints())
    {
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
        dl.decFunds(playerBet);
        cout << red << "Your funds are now:  " << p1.getFundsVal() << endl
        << "House Funds are now:  " << dl.getFundsVal() << white << endl;
    }
}

void Game::hit(Player anyPlayer, Card someCard, char choice) {
    if (anyPlayer.getPlayer() == playerType::dealer)
    {
        //manually hit if dealer has less than 17 points
        while (dl.getPoints() < 17) {
            dl.addCard(someCard);
            if(!busted(dl))
            {
                
            }
            else
            {
                cout<< "Dealer bust" <<endl;
                p1.incFunds(playerBet*2);
                cout<< cyan<< "New Player Funds:" << p1.getFundsVal() << endl;
                break;
            }
        }
    }
    else {
           p1.addCard(someCard);
        //cout << cyan << "Player drew: " << p1<< white << endl;
        cout<< cyan<< "New Player Total:" << p1.getPoints() << endl;
    }
}
