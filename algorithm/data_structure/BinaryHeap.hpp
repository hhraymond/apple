/// BinaryHeap.hpp:
/// CopyRight (c) 2012 xxx Inc.  All Rights Reserved.
/// Author: Allen  <huang_zhen@xxx.cn>
/// Created: 2012-11-21

#ifndef  INCLUDED_BINARYHEAP_HPP
#define  INCLUDED_BINARYHEAP_HPP

#include <vector>

template <typename Comparable>
class BinaryHeap
{
public:
    explicit BinaryHeap( int capacity = 100 );
    explicit BinaryHeap( const std::vector<Comparable> & items );
    ~BinaryHeap();

    bool isEmpty( ) const;
    void printHeap( )const;
    const Comparable & findMin( ) const;

    void insert( const Comparable & x );
    void deleteMin( );
    void deleteMin( Comparable & minItem );
    void makeEmpty( );

private:
    int                currentSize;  // Number of elements in heap
    std::vector<Comparable> array;        // The heap array

    void buildHeap( );
    void percolateDown( int hole );
};

#include "BinaryHeap.cpp"

#endif   // ----- #ifndef INCLUDED_BINARYHEAP_HPP  -----

