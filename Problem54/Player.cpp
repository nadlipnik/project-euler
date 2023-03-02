#include "Player.hpp"

Player::Player()
{

}

Player::~Player()
{

}

void Player::SetHand(std::vector<Player::Card> cards)
{

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
