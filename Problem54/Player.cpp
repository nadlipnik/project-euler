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

int Player::GetHandValue()
{
    int value = 0;
    // check straight flush

    // check for four of a kind
    if(IsFourOfAKind())
    {
        value = FOUR_OF_A_KIND;
    }

    // check for straight
    if(IsStraight())
    {
        value = STRAIGHT;
    }


    return 0;
}

void Player::SortHand()
{
    std::sort(hand.begin(), hand.end());
}

bool Player::IsPair()
{
    int size = hand.size();
    if (size < 2)
        return false;
    for(int i = 0; i <= size-2; i++)
    {
        if (hand[i].value == hand[i+1].value)
            return true;
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
            for(int j = i+2; j <= size-2; i++)
            {
                if(hand[j].value == hand[j+1].value)
                    return true;
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
            return true;
    }
    
    return false;
}

bool Player::IsStraight()
{
    // check for straight
    for(int i=0; i < hand.size()-1; i++)
    {
        if(hand[i].value+1 != hand[i+1].value)
            return false;
    }
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
            return true;
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
            return true;
        if (hand[i].value == hand[i+1].value && 
            hand[i+2].value == hand[i+3].value && 
            hand[i+2].value == hand[i+4].value)
            return true;
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
            return true;
    }
    
    return false;
}

