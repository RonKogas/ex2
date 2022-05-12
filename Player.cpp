#include "Player.h"
#include "utilities.h"

using std::string;

const int MAX_LEVEL = 10;

Player::Player(const string name, const int maxHP, const int force) :
    m_name(name),
    m_level(1),
    m_force((force > 0) ? force : DEFAULT_FORCE),
    m_maxHP((maxHP > 0) ? maxHP : DEFAULT_MAX_HP),
    m_HP((maxHP > 0) ? maxHP : DEFAULT_MAX_HP),
    m_coins(0)
{
}


void Player::printInfo() const 
{
    printPlayerInfo(m_name.c_str(), m_level, m_force, m_HP, m_coins);
}


Player& Player::levelUp() 
{
    if (m_level < MAX_LEVEL) {
        m_level += 1;
    }
    return *this;
}


int Player::getLevel() const 
{
    return m_level;
}


Player& Player::buff(const int forceToIncrease) 
{
    if(forceToIncrease > 0) {
        m_force += forceToIncrease;
    }
    return *this;
}


Player& Player::heal(const int HPToIncrease) 
{
    if(HPToIncrease > 0) {
        if(m_HP + HPToIncrease <= m_maxHP) {
            m_HP += HPToIncrease;
        } else {
            m_HP = m_maxHP;
        }
    }
    return *this;
}


Player& Player::damage(const int HPToDecrease) 
{
    if(HPToDecrease > 0) {
        if(m_HP - HPToDecrease >= 0) {
            m_HP -= HPToDecrease;
        } else {
            m_HP = 0;
        }
    }
    return *this;
}


bool Player::isKnockedOut() const 
{
    return !m_HP;
}


Player& Player::addCoins(const int coinsToAdd) 
{
    if (coinsToAdd > 0) {
        m_coins += coinsToAdd;
    }
    return *this;
}


bool Player::pay(const int coinsToPay) 
{
    if((coinsToPay >= 0) && (m_coins - coinsToPay >= 0)) {
        m_coins -= coinsToPay;
        return true;
    } else if (coinsToPay < 0){
        return true;
    } else {
        return false;
    }
}


int Player::getAttackStrength() const 
{
    return m_force + m_level;
}
