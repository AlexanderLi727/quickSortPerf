#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP

#include<iostream>
#include<vector>
#include<algorithm>


int partition( std::vector<int>& vec, int low, int high )
{
	int pivot = vec[high];
	int i = low - 1; 

	for( int j = low; j <= high - 1; ++j )
	{
		if( vec[j] < pivot )
		{
			++i;
			std::swap( vec[i], vec[j] ); 
		}
	}
	std::swap( vec[i + 1], vec[high] ); 
	return i + 1; 
}

void quickSort( std::vector<int>& vec, int low, int high )
{
	if( low >= high )
		return; 
	int p = partition( vec, low, high );
	quickSort( vec, low, p - 1 ); 
	quickSort( vec, p + 1, high ); 

}
/*
 * First call partition function 
 *  10 80 30 90 40 50 70 : 70 is pivot, i = -1  
 *  1. 10 80 30 90 40 50 70 : i = 0, j = 0
 *  2. 10 80 30 90 40 50 70 : i = 0, j = 1
 *  3. 10 30 80 90 40 50 70 : i = 1, j = 2
 *  4. 10 30 80 90 40 50 70 : i = 1, j = 3
 *  5. 10 30 40 90 80 50 70 : i = 2, j = 4
 *  6. 10 30 40 50 80 90 70 : i = 3, j = 5
 *  At the End we swap 70 with i + 1: 
 *  10 30 40 50 70 90 80 
 *  and we return i + 1, i.e. p = 4
 *  now we do again 
 *  	quickSort: low = 0, high = 3
 *  	quickSort: low = 5, high = 6
 *
 *  	so, we do sorting of the left array and sorting of the right array 
 *  */


#endif 
