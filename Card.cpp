Card::Card(CardType type, const CardStats& stats) :
m_effect(type), m_stats(stats)
{}

void Card::applyEncounter(Player& player) const
{
    if(m_effect==CardType::Battle)
    {
        int attackStrength=player.getAttackStrength();
        if(m_stats.force>attackStrength)
        {
            player.damage(m_stats.hpLoss);
            printBattleResults(false);
        }
        else
        {
            player.levelUp();
            player.addCoins(m_stats.loot);
            printBattleResults(true);
        }
    }
    else if(m_effect==CardType::Buff)
    {
        if(player.pay(m_stats.cost))
        {
            player.buff(m_stats.buff);
        }
    }
    else if(m_effect==cardType::Heal)
    {
        if(player.pay(m_stats.cost))
        {
            player.heal(m_stats.heal);
        }
    }
    else    //Treasure card
    {
        player.addCoins(m_stats.loot);
    }
}

void Card::printInfo() const
{
    if(m_effect==CardType::Battle)
    {
        printBattleCardInfo(m_stats);
    }
    else if(m_effect==CardType::Heal)
    {
        printHealCardInfo(m_stats);
    }
    else if(m_effect==CardType::Buff)
    {
        printBuffCardInfo(m_stats);
    }
    else
    {
        printTreasureCardInfo(m_stats);
    }

}