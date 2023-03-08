#include "Player.hpp"

Player::Player()
{

}

Player::~Player()
{

}

void Player::SetHand(const std::vector<Player::Card> &cards)
{
    this->hand = cards;
}

std::vector<Player::Card> Player::GetHand() 
{
    return this->hand;
}

void Player::AddCard(Player::Card card)
{
    hand.push_back(card);
}

void Player::RemoveHand()
{
    hand.clear();
}

void Player::GetHandValue()
{
    // check straight flush

    if(IsStraightFlush())
        return;
    if(IsFourOfAKind())
        return;
    else if(IsFullHouse())
        return;
    else if(IsFlush())
        return;
    else if(IsStraight())
        return;
    else if(IsThreeOfAKind())
        return;
    else if(IsTwoPairs())
        return;
    else if(IsPair())
        return;
    else // high card
    {
        if(hand.size() < 5)
            return;
        high_card = std::max({hand[0].value, hand[1].value, hand[2].value, hand[3].value, hand[4].value});
        return;
    }
}

void Player::SortHand()
{
    std::sort(hand.begin(), hand.end());
}

bool Player::IsPair()
{
    std::vector<Card> tmp = hand;
    int size = hand.size();
    if (size < 2)
        return false;
    for(int i = 0; i <= size-2; i++)
    {
        if (hand[i].value == hand[i+1].value)
        {
            hand_value = PAIR;
            high_card = hand[i].value;
            tmp.erase(tmp.begin()+i);
            tmp.erase(tmp.begin()+i);
            highest_card = std::max({tmp[0].value, tmp[1].value, tmp[2].value});
            return true;
        }
    }
    return false;
}

bool Player::IsTwoPairs()
{
    int size = hand.size();
    int offset = 0;
    if (size < 4)
        return false;

    for(int i = 0; i <= size-4; i++)
    {
        if (hand[i].value == hand[i+1].value)
        {
            for(int j = i+2; j <= size-2; j++)
            {
                if(hand[j].value == hand[j+1].value)
                {
                    hand_value = TWO_PAIRS;
                    high_card = std::max({hand[i].value, hand[j].value});
                    return true;
                }
            }
        }
    }
    return false;
}

bool Player::IsThreeOfAKind()
{
    int size = hand.size();
    if (size < 3)
        return false;
    for(int i = 0; i <= size-3; i++)
    {
        if (hand[i].value == hand[i+1].value && 
            hand[i].value == hand[i+2].value)
        {
            hand_value = THREE_OF_A_KIND;
            high_card = hand[i].value;
            return true;
        }
    }

    return false;
}

bool Player::IsStraight()
{
    int size = hand.size();
    if (size < 5)
        return false;
    // check for straight
    for(int i=0; i < hand.size()-1; i++)
    {
        if(hand[i].value+1 != hand[i+1].value)
            return false;
    }
    hand_value = STRAIGHT;
    high_card = std::max({hand[0].value, hand[1].value, hand[2].value, hand[3].value, hand[4].value});
    return true;
}

bool Player::IsFlush()
{
    int size = hand.size();
    if (size < 5)
        return false;
    for(int i = 0; i <= size-5; i++)
    {
        if (hand[i].suit == hand[i+1].suit && 
            hand[i].suit == hand[i+2].suit && 
            hand[i].suit == hand[i+3].suit &&
            hand[i].suit == hand[i+4].suit)
        {
            hand_value = FLUSH;
            high_card = std::max({hand[0].value, hand[1].value, hand[2].value, hand[3].value, hand[4].value});
            return true;
        }
    }

    return false;
}

bool Player::IsFullHouse()
{
    int size = hand.size();
    if (size < 5)
        return false;

    for(int i = 0; i <= size-5; i++)
    {
        if (hand[i].value == hand[i+1].value && 
            hand[i].value == hand[i+2].value && 
            hand[i+3].value == hand[i+4].value)
        {
            hand_value = FULL_HOUSE;
            high_card = hand[i].value;
            return true;
        }
        else if (hand[i].value == hand[i+1].value && 
            hand[i+2].value == hand[i+3].value && 
            hand[i+2].value == hand[i+4].value)
        {
            hand_value = FULL_HOUSE;
            high_card = hand[i+2].value;
            return true;
        }
    }

    return false;
}

bool Player::IsFourOfAKind()
{
    int size = hand.size();
    if (size < 4)
        return false;
    for(int i = 0; i <= size-4; i++)
    {
        if (hand[i].value == hand[i+1].value && 
            hand[i].value == hand[i+2].value && 
            hand[i].value == hand[i+3].value)
        {
            hand_value = FOUR_OF_A_KIND;
            high_card = hand[i].value;
            return true;
        }
    }
    
    return false;
}

bool Player::IsStraightFlush()
{
    if (hand.size() < 5)
        return false;
    if(IsStraight() && IsFlush())
    {
        hand_value = STRAIGHT_FLUSH;
        high_card = hand[5].value;
        return true;
    }
    return false;
}

bool Player::DetermineWinner(Player &player2)
{
    if(hand_value > player2.GetHandRank())
        return true;
    else if(hand_value == player2.GetHandRank())
    {
        if(high_card > player2.GetHighCard())
            return true;
        else if(high_card == player2.GetHighCard())
        {
            // if the one where we are deciding is the same
            if (highest_card > player2.GetHighestCard())
                return true;
        }
    }
    return false;
}

