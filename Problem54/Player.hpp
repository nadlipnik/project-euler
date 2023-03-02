#include <vector>

#define CLUB 1
#define DIAMOND 2
#define HEART 3
#define SPADE 4

class Player
{
public:
    Player();
    ~Player();

    struct Card
    {
        int value;
        int suit;
    };

    void SetHand(std::vector<Card> cards);
    std::vector<Player::Card> GetHand();
    
    void AddCard(Card card);
    void RemoveHand();

private:

    std::vector<Card> hand;

};