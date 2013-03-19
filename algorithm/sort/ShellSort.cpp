/// ShellSort.cpp:
/// CopyRight (c) 2012 Vobile Inc.  All Rights Reserved.
/// Author: Allen  <huang_zhen@vobile.cn>
/// Created: 2012-11-21

#include <vector>

/**
 * Shellsort, using Shell's (poor) increments.
 */
template <typename Comparable>
void ShellSort( std::vector<Comparable> & a )
{
    for( int gap = a.size( ) / 2; gap > 0; gap /= 2 ) {
        for( int i = gap; i < a.size( ); i++ ) {
            Comparable tmp = a[ i ];
            int j = i;
    
            for( ; j >= gap && tmp < a[ j - gap ]; j -= gap )
                a[ j ] = a[ j - gap ];
            a[ j ] = tmp;
        }
    }
}
