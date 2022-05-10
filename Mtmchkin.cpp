Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards) :
m_player(new Player(playerName)),
m_array(new Card[numOfCards]), 
m_size(numOfCards),
m_status(GameStats::MidGame), 
m_nextCardIndex(0)
{
    for(int i=0; i<numOfCards; ++i)
    {
        m_array[i] = cardsArray[i];
    }
}

void Mtmchkin::playNextCard()
{
    if(m_status==GameStatus::MidGame)
    {
        Card nextCard=array[m_nextCardIndex];
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

GameStatus Mtmckin::getGameStatus() const
{
    return m_status;
}

Mtmchkin::~Mtmchkin()
{
    delete[] m_array;
    delete m_player;
}

Mtmchkin::Mtmchkin(const Mtmchkin& game)
m_player(new Player(game.m_player)),
m_array(new Card[game.m_size]), 
m_size(game.m_size),
m_status(game.m_status), 
m_nextCardIndex(game.m_nextCardIndex)
{
    for(int i=0; i<m_size; ++i)
    {
        m_array[i] = game.m_array[i];
    }
}

Mtmchkin& operator=(const Mtmchkin& gmae)
{
    if(this==&game)
    {
        return *this;
    }
    delete[] m_array;
    delete m_player
    m_player = new Player(game.m_player);
    m_array = new Card[game.m_size];
    m_size = game.m_size;
    m_status = game.m_status;
    m_nextCardIndex = game.m_nextCardIndex;
    for(int i=0; i<m_size; ++i)
    {
        m_array[i] = game.m_array[i];
    }
}

