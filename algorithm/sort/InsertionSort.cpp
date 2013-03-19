/// InsertionSort.cpp:
/// CopyRight (c) 2012 Vobile Inc.  All Rights Reserved.
/// Author: Allen  <huang_zhen@vobile.cn>
/// Created: 2012-11-21

//#include"InsertionSort.hpp"

#include <vector>

/**
 * Simple insertion sort.
 */
template <typename Comparable>
void InsertionSort( std::vector<Comparable> & a )
{
    int j;

    for( int p = 1; p < a.size( ); p++ )
    {
        Comparable tmp = a[ p ];
        for( j = p; j > 0 && tmp < a[ j - 1 ]; j-- )
            a[ j ] = a[ j - 1 ];
        a[ j ] = tmp;
    }
}


template <typename Comparable>
void InsertionSort( std::vector<Comparable> & a, int left, int right )
{
    int j;

    for( int p = left; p < right + 1; p++ )
    {
        Comparable tmp = a[ p ];
        for( j = p; j > 0 && tmp < a[ j - 1 ]; j-- )
            a[ j ] = a[ j - 1 ];
        a[ j ] = tmp;
    }
}
