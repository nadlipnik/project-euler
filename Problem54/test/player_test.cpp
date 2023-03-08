#include <stdio.h>

#include "gtest/gtest.h"
#include "Player.hpp"
#include "main.cpp"


TEST(TestHands, Pair)
{
    std::vector<Player> players;
    int player1_wins = 0;

    // read the inputs
    read_input("file2.txt", players);


    // get hand value of first player
    for(int i = 0; i < players.size(); i++)
    {
        players[i].GetHandValue();
    }
    // game 1
    EXPECT_EQ(players[0].GetHandRank(), PAIR);
    EXPECT_EQ(players[0].GetHighCard(), 5);

    EXPECT_EQ(players[1].GetHandRank(), PAIR);
    EXPECT_EQ(players[1].GetHighCard(), 8);

    EXPECT_EQ(players[0].DetermineWinner(players[1]), false);

    // game 2
    EXPECT_EQ(players[2].GetHandRank(), 0);
    EXPECT_EQ(players[2].GetHighCard(), 14);

    EXPECT_EQ(players[3].GetHandRank(), 0);
    EXPECT_EQ(players[3].GetHighCard(), 12);

    EXPECT_EQ(players[2].DetermineWinner(players[3]), true);
    // game 3
    EXPECT_EQ(players[4].GetHandRank(), THREE_OF_A_KIND);
    EXPECT_EQ(players[4].GetHighCard(), 14);

    EXPECT_EQ(players[5].GetHandRank(), FLUSH);
    EXPECT_EQ(players[5].GetHighCard(), 12);

    EXPECT_EQ(players[4].DetermineWinner(players[5]), false);
    // game 4
    EXPECT_EQ(players[6].GetHandRank(), PAIR);
    EXPECT_EQ(players[6].GetHighCard(), 12);

    EXPECT_EQ(players[7].GetHandRank(), PAIR);
    EXPECT_EQ(players[7].GetHighCard(), 12);

    EXPECT_EQ(players[6].DetermineWinner(players[7]), true);
    // game 5
    EXPECT_EQ(players[8].GetHandRank(), FULL_HOUSE);
    EXPECT_EQ(players[8].GetHighCard(), 4);

    EXPECT_EQ(players[9].GetHandRank(), FULL_HOUSE);
    EXPECT_EQ(players[9].GetHighCard(), 3);

    EXPECT_EQ(players[8].DetermineWinner(players[9]), true);
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}