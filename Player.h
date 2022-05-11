#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

#include <string>

const int DEFAULT_FORCE = 5;
const int DEFAULT_MAX_HP = 100;

class Player {
public:
    /**
     * C'tor of Player class.
     *
     * @param name - The name of the player.
     * @param maxHP - The max HP of the player.
     * @param force - initial points of force
     * @return
     *      A new instance of a player.
    */
    Player(const std::string name, const int maxHP = DEFAULT_MAX_HP, const int force = DEFAULT_FORCE);

    /**
     * Prints the player info.
     *
     * @return
     *      void.
    */
    void printInfo() const;

    /**
     * Increasing the player level.
     *
     * @return
     *      player reference.
    */
    Player& levelUp();

    /**
     * @return
     *      int - the player level.
    */
    int getLevel() const;

    /**
     * Increasing the player force.
     *
     * @param forceToIncrease - number of force points to increase.
     * @return
     *      player reference.
    */
    Player& buff(const int forceToIncrease);

    /**
     * Increasing the player HP.
     *
     * @param HPToIncrease - number of HP points to increase considering the maxHP value.
     * @return
     *      player reference.
    */
    Player& heal(const int HPToIncrease);

    /**
     * Decreasing the player HP.
     *
     * @param HPToIncrease - number of HP points to decrease (as long as the player HP value equals or greater than 0).
     * @return
     *      player reference.
    */
    Player& damage(const int HPToDecrease);

    /**
     * Checking if the player HP is 0.
     *
     * @return
     *      true is it's 0.
     *      false is it's not 0.
    */
    bool isKnockedOut() const;

    /**
     * Adding coins the player.
     *
     * @param coinsToAdd - number of coins to add.
     * @return
     *      player reference.
    */
    Player& addCoins(const int coinsToAdd);

    /**
     * Decreasing the player coins.
     *
     * @param coinsToAdd - number of coins to decrease.
     * @return
     *      true if the payment was done.
     *      false if the payment wasn't done, in this case there is no change in the coins value.
    */
    bool pay(const int coinsToPay);

    /**
     * Attack strength is defined to be (player force + player level)
     *
     * @return
     *      int - attack strength.
    */
    int getAttackStrength() const;

    /**
     * using the default copy C'tor, D'tor and assignment operator.
    */
    Player(const Player&) = default;
    ~Player() = default;
    Player& operator=(const Player& other) = default;

private:
    const std::string m_name;
    int m_level;
    int m_force;
    const int m_maxHP;
    int m_HP;
    int m_coins;
};

#endif //EX2_PLAYER_H
