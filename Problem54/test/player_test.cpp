#include "gtest/gtest.h"
#include "Player.hpp"
#include "main.cpp"

TEST(TestHands, Pair)
{
    std::vector<Player> players;
    int player1_wins = 0;

    // read the inputs
    read_input("file1.txt", players);

    // get hand value of first player
    players[0].GetHandValue();
    players[1].GetHandValue();
    players[2].GetHandValue();
    players[3].GetHandValue();
    players[4].GetHandValue();
    players[5].GetHandValue();
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}