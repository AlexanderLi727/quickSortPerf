#include <limits.h>
#include <gtest/gtest.h>
#include "quickSort.hpp"

TEST( quickSortTest, firstTest )
{
	std::vector<int> testVect{ 23, 40, 321, 65, 21, 22, 0, 450, 4, 3, 2, 1, 22 };
	quickSort( testVect, 0, testVect.size() - 1 ); 
	int prev = testVect[0];
	for( int i = 1; i < testVect.size(); ++i )
	{
		ASSERT_LE( prev, testVect[i] ); 
		prev = testVect[i];
	}

}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest( &argc, argv );
  return RUN_ALL_TESTS();
}

