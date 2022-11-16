/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} 
		virtual ~TicTacToeBoardTest(){} 
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(TicTacToeBoardTest, check_space_positive)
{
	// This should fail as the board is out of bounds
	TicTacToeBoard myboard;
	Piece actual = myboard.placePiece(4,10);
    ASSERT_EQ(actual, Invalid);
}

TEST(TicTacToeBoardTest, check_space_negative)
{
	// This should fail as the board is out of bounds
	TicTacToeBoard myboard;
	Piece actual = myboard.placePiece(3,-30);
    ASSERT_EQ(actual, Invalid);
}

TEST(TicTacToeBoardTest, check_turn_1_and_2)
{
	// This should pass as the first turn is X then changes to O
	TicTacToeBoard myboard;
	Piece actual;
	myboard.toggleTurn();
	actual = myboard.toggleTurn();
    ASSERT_EQ(actual, X);
}

TEST(TicTacToeBoardTest, get_space_positive)
{
	// This should fail as the board is out of bounds
	TicTacToeBoard myboard;
	Piece actual = myboard.getPiece(4,10);
    ASSERT_EQ(actual, Invalid);
}

TEST(TicTacToeBoardTest, get_space_negative)
{
	// This should fail as the board is out of bounds
	TicTacToeBoard myboard;
	Piece actual = myboard.getPiece(3,-30);
    ASSERT_EQ(actual, Invalid);
}

// TEST(TicTacToeBoardTest, test_diagnal_winner)
// {
// 	// This should fail as the board is out of bounds
// 	TicTacToeBoard myboard;
// 	Piece actual;
// 	myboard.placePiece(0,2);
// 	myboard.placePiece(1,1);
// 	myboard.placePiece(2,0);
// 	actual = myboard.getWinner();
//     ASSERT_EQ(actual, X);
// }

TEST(TicTacToeBoardTest, test_down_winner)
{
	// This should fail as the board is out of bounds
	TicTacToeBoard myboard;
	Piece actual;
	myboard.placePiece(0,0);
	myboard.placePiece(0,1);
	myboard.placePiece(0,2);
	actual = myboard.getWinner();
    ASSERT_EQ(actual, X);
}