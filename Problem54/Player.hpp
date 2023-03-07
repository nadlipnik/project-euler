#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <vector>
#include <algorithm>

#define CLUB 1
#define DIAMOND 2
#define HEART 3
#define SPADE 4

#define PAIR 1
#define TWO_PAIRS 2
#define THREE_OF_A_KIND 3
#define STRAIGHT 4
#define FLUSH 5
#define FULL_HOUSE 6
#define FOUR_OF_A_KIND 7
#define STRAIGHT_FLUSH 8

class Player
{
public:
    Player();
    ~Player();

    struct Card
    {
        int value;
        int suit;

        // used for sorting
        bool operator < (const Card & card) {return value < card.value;}
    };

    void SetHand(const std::vector<Card> &cards);
    //void SetHand();
    std::vector<Player::Card> GetHand();
    
    void AddCard(Card card);
    void RemoveHand();

    void GetHandValue();

    void SortHand();

    int hand_value = 0;
    int high_card = 0;

private:

    std::vector<Card> hand;

    
    bool IsPair();
    bool IsTwoPairs();
    bool IsThreeOfAKind();
    bool IsStraight();
    bool IsFlush();
    bool IsFullHouse();
    bool IsFourOfAKind();

};

#endif // __PLAYER_H__