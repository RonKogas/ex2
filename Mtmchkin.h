//
// Created by Daniel_Meents on 07/04/2022.
//

#ifndef EX2_GAME_H
#define EX2_GAME_H
#include "Card.h"
#include <iostream>
#include <string>
/*
 * GameStatus:
 * MidGame - The game is still active and the player continues to encounter cards.
 * Win - The player reached level 10.
 * Loss - The player's HP is 0.
*/
enum class GameStatus{Win, Loss, MidGame};

class Mtmchkin {
public:

    //the player
    Player m_player;
    
    //the index of the card that will be played next(initialized to 0)
    int m_nextCardIndex; 

    /*
     * C'tor of the game:
     *
     * @param playerName - The name of the player.
     * @param cardsArray - A ptr to the cards deck.
     * @param numOfCards - Num of cards in the deck.
     * @result
     *      An instance of Mtmchkin
    */
    Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards);


    /*
     * Play the next Card - according to the instruction in the exercise document
     *
     * @return
     *      void
    */
    void playNextCard();


    /*
     *  Check if the game ended:
     *
     *  @return
     *          True if the game ended
     *          False otherwise
     */
    bool isOver() const;


    /*
     *  Get the status of the game:
     *
     *  @return
     *          GameStatus - the current status of the running game
     */
    GameStatus getGameStatus() const;

    //TODO: complete the Mtmchkin class.

    /**
     * @brief Destroy the Mtmchkin object
     * 
     */
    ~Mtmchkin();

    /**
     * @brief Construct a new Mtmchkin object
     *        create copy of game
     * @param game 
     */
    Mtmchkin(const Mtmchkin& game);

    /**
     * @brief assighment operator
     * assign data of right operand to the left
     **/
    Mtmchkin& operator=(const Mtmchkin&);

private:
    //TODO: complete the Mtmchkin class.
    
    //the current game status 
    GameStatus m_status;
    
    //array of cards
    Card* m_cardsArray;
    
    //the amount of cards(array size)
    int m_size;


};


#endif //EX2_GAME_H
