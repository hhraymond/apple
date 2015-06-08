/// QuickSort.cpp:
/// CopyRight (c) 2012 xxx Inc.  All Rights Reserved.
/// Author: Allen  <huang_zhen@xxx.cn>
/// Created: 2012-11-21

#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

//#include"InsertionSort.hpp"

/**
 * Quicksort algorithm (driver).
 */
template <typename Comparable>
void QuickSort( vector<Comparable> & a )
{
    //QuickSort( a, 0, a.size( ) - 1 );
    QUICKSORT( a, 0, a.size() - 1);
}

/**
 * Return median of left, center, and right.
 * Order these and hide the pivot.
 */
template <typename Comparable>
const Comparable & median3( vector<Comparable> & a, int left, int right )
{
    int center = ( left + right ) / 2;
    if( a[ center ] < a[ left ] )
        swap( a[ left ], a[ center ] );
    if( a[ right ] < a[ left ] )
        swap( a[ left ], a[ right ] );
    if( a[ right ] < a[ center ] )
        swap( a[ center ], a[ right ] );

        // Place pivot at position right - 1
    swap( a[ center ], a[ right - 1 ] );
    return a[ right - 1 ];
}

/**
 * Internal QuickSort method that makes recursive calls.
 * Uses median-of-three partitioning and a cutoff of 10.
 * a is an array of Comparable items.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 */
template <typename Comparable>
void QuickSort( std::vector<Comparable> & a, int left, int right )
{
    cout << "sort data: " << endl;
    for( int m = left; m < right + 1; ++ m )
    {
        cout << a[m] << "\t";
    }
    cout << endl;

    if( left + 10 <= right )
    {
        Comparable pivot = median3( a, left, right );

        // Begin partitioning
        int i = left, j = right - 1;
        for( ; ; )
        {
            while( a[ ++i ] < pivot ) { }
            while( pivot < a[ --j ] ) { }
            if( i < j )
                swap( a[ i ], a[ j ] );
            else
                break;
        }

        swap( a[ i ], a[ right - 1 ] );  // Restore pivot
        // dump data
        cout << "sort data: " << endl;
        for( int m = left; m <= right; ++m )
        {
            cout << a[m] << "\t";
        }
        cout << endl;

        QuickSort( a, left, i - 1 );     // Sort small elements
        QuickSort( a, i + 1, right );    // Sort large elements
    }
    else  // Do an insertion sort on the subarray
        InsertionSort( a, left, right );
}


///////////////////////////////////////////////////////////////
// method 2  for simple //
template <typename Comparable>
int PARTITION( vector<Comparable> & R, int l, int h )
{
    int i, j;
    i = l; j = h;
	Comparable tmp = R[i];
    do {
        while( R[j] >= tmp && i<j ) j--;
        if ( i < j ) R[i++] = R[j];
        while( R[i] <= tmp && i<j ) i++;
        if ( i < j ) R[j--] = R[i];
    }while (i != j);
    R[i] = tmp;
    //do {
    //    // dump data
    //    cout << "sort data: " << endl;
    //    for( int m = l; m <= h; ++ m )
    //    {
    //        cout << R[m] << "\t";
    //    }
    //    cout << endl;
	//	
    //    // sort logic
    //    while( R[i] <= tmp && i <= j )
    //        ++i;
	//	while( R[j] >= tmp && i <= j ) 
    //        --j;
    //    if (i < j) 
    //        swap(R[i], R[j]);
    //    else 
    //        break;
	//}while (i != j);
	//swap(tmp, R[i]);
	
    // dump data
    cout << "sort data: " << endl;
    for( int m = l; m <= h; ++ m )
    {
        cout << R[m] << "\t";
    }
    cout << endl;
    return i;
}

template <typename Comparable>
void QUICKSORT( vector<Comparable> & R, int s1, int t1 )
{
	int i;
	if ( s1 < t1 )
	{
		i = PARTITION(R, s1, t1);
		QUICKSORT( R, s1, i-1 );
		QUICKSORT( R, i+1, t1 );
	}
}

