#include "Mtmchkin.h"
#include "Card.h"
#include "Player.h"
#include "utilities.h"

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards) :
m_player(Player(playerName)),
m_nextCardIndex(0),
m_status(GameStatus::MidGame), 
m_cardsArray(new Card[numOfCards]), 
m_size(numOfCards)
{
    for(int i=0; i<numOfCards; ++i)
    {
        m_cardsArray[i] = cardsArray[i];
    }
}

void Mtmchkin::playNextCard()
{
    if(m_status==GameStatus::MidGame)
    {
        Card nextCard=m_cardsArray[m_nextCardIndex];
        nextCard.printInfo();
        nextCard.applyEncounter(m_player);
        if(m_player.getLevel()>=10)
        {
            m_status=GameStatus::Win;
        }
        else if(m_player.isKnockedOut())
        {
            m_status=GameStatus::Loss;
        }
        m_player.printInfo();
        m_nextCardIndex = (m_nextCardIndex+1) % m_size;
    }
}

bool Mtmchkin::isOver() const
{
    if(getGameStatus()==GameStatus::MidGame)
    {
        return false;
    }
    return true;
}

GameStatus Mtmchkin::getGameStatus() const
{
    return m_status;
}

Mtmchkin::~Mtmchkin()
{
    delete[] m_cardsArray;
    //delete &m_player;
}


Mtmchkin::Mtmchkin(const Mtmchkin& game) :
m_player(Player(game.m_player)),
m_nextCardIndex(game.m_nextCardIndex),
m_status(game.m_status),
m_cardsArray(new Card[game.m_size]), 
m_size(game.m_size)
{
    for(int i=0; i<m_size; ++i)
    {
        m_cardsArray[i] = game.m_cardsArray[i];
    }
}

Mtmchkin& Mtmchkin::operator=(const Mtmchkin& game)
{
    if(this==&game)
    {
        return *this;
    }
    delete[] m_cardsArray;
    m_player = Player(game.m_player);
    m_cardsArray = new Card[game.m_size];
    m_size = game.m_size;
    m_status = game.m_status;
    m_nextCardIndex = game.m_nextCardIndex;
    for(int i=0; i<m_size; ++i)
    {
        m_cardsArray[i] = game.m_cardsArray[i];
    }
    return *this;
}

