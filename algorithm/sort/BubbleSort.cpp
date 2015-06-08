/// BubbleSort.cpp:
/// CopyRight (c) 2012 xxx Inc.  All Rights Reserved.
/// Author: Allen  <huang_zhen@xxx.cn>
/// Created: 2012-11-21

#include<vector>

/**
 * BubbleSort.
 */
template <typename Comparable>
void BubbleSort( std::vector<Comparable> & a )
{
    int size = a.size();
    int tmp = 0;
    
    for( int i = 0; i < size + 1; ++i )
    {
        for( int j = 0; j < size - i - 1; ++j )
        {
            if(a[j] > a[j + 1])
            {
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
    /*
    int n = size;
    int j, p, h, t;
    for(h = n - 1; h > 0; h= p) {
        for(p = j = 0; j < h; j++){
            if(a[j] > a[j+1]) {
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
                p = j;
            }
        }
    }
    */
}
