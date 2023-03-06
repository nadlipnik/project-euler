#include <string>
#include <vector>
#include <sstream>
#include <fstream>


#include "Player.hpp"

int getCardValue(char value)
{
    switch(value)
    {
        case 'T': return 10;
        case 'J': return 11;
        case 'Q': return 12;
        case 'K': return 13;
        case 'A': return 14;
        default:
        {
            return ((int) value - 0x30);
        }
    }
}

int getCardSuit(char suit)
{
    switch (suit)
    {
        case 'C':
            return CLUB;
        case 'D':
            return DIAMOND;
        case 'H':
            return HEART;
        case 'S':
            return SPADE;
        default:
            return -1;
    }
}

void read_input(std::string filename, std::vector<Player>& players)
{
    // reading the input file
    std::fstream newfile;
    newfile.open(filename, std::ios::in);
    std::string line;

    std::stringstream _stream;

    Player player;
    Player::Card card;

    std::string element;

    while(getline(newfile, line))
    {
        _stream << line;
        int i = 0;
        int j = 0;
        while(_stream >> element)
        {
            card.value = getCardValue(element[0]);
            card.suit = getCardSuit(element[1]);
            player.AddCard(card);
            i++;
            if (i == 5)
            {
                i = 0;
                player.SortHand();
                players.push_back(player);
                player.RemoveHand();
                //players[j].SetHand(player.GetHand());
                //j++;
            }
        }
        _stream.str("");
        _stream.clear();
    }
}


int main()
{
    std::vector<Player> players;
    int player1_wins = 0;

    read_input("file1.txt", players);
    return 0;
}