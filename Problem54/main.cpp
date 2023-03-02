#include <string>
#include <vector>
#include <sstream>
#include <fstream>


#include "Player.hpp"

int getCardValue(char value)
{

}

void read_input(std::string filename, std::vector<std::vector<int>>& values, std::vector<Player>& players)
{
    // reading the input file
    std::fstream newfile;
    newfile.open(filename, std::ios::in);
    std::string line;

    std::stringstream _stream;

    Player player;
    Player::Card card;

    std::string element = 0;

    while(getline(newfile, line))
    {
        _stream << line;
        int i = 0;
        while(_stream >> element)
        {
            card.value = getCardValue(element[0]);
            card.suit = getCardSuit(element[1]);
            player.AddCard(card);
        }
        _stream.str("");
        _stream.clear();
    }
}


int main()
{
    std::vector<Player> players;
    return 0;
}