#include "gtest/gtest.h"
#include "Player.hpp"
#include "main.c"

TEST(TestHands, Pair)
{
    std::vector<Player> players;
    int player1_wins = 0;

    // read the inputs
    read_input("file1.txt", players);

    // get hand value of first player
    
}

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}