/// BinaryHeap.cpp:
/// CopyRight (c) 2012 Vobile Inc.  All Rights Reserved.
/// Author: Allen  <huang_zhen@vobile.cn>
/// Created: 2012-11-21

#include <iostream>

////////////  public functions  //////////////////
/**
 * constructor for the Heap
 */
template <typename Comparable>
BinaryHeap<Comparable>::BinaryHeap( int capacity ): currentSize( 0 )
{
        array.resize( capacity );
}

/**
 * constuctor of Binary heap
 */
template <typename Comparable>
BinaryHeap<Comparable>::BinaryHeap( const std::vector<Comparable> & items )
  : array( items.size( ) + 10 ), currentSize( items.size( ) )
{
    for( int i = 0; i < items.size( ); i++ )
        array[ i + 1 ] = items[ i ];
    buildHeap( );
}

/**
 * Destructor for the Heap
 */
template <typename Comparable>
BinaryHeap<Comparable>::~BinaryHeap( )
{
}

template <typename Comparable>
bool BinaryHeap<Comparable>::isEmpty( ) const
{
    return currentSize == 0;
}

template <typename Comparable>
void BinaryHeap<Comparable>::printHeap( ) const
{
    std::cout << "This is BinaryHeap printing: " << std::endl;
    for( int i = 1; i <= currentSize; ++i)
    {
        std::cout << array[i] << "\t" ;
    }
    std::cout << std::endl;
}

template <typename Comparable>
const Comparable & BinaryHeap<Comparable>::findMin( ) const
{
    // TO DO
    if( isEmpty( ) )
        //throw UnderflowException( );
    return array[1];
}
/**
 * Insert item x, allowing duplicates.
 */
template <typename Comparable>
void BinaryHeap<Comparable>::insert( const Comparable & x )
{
    if( currentSize == static_cast<int>( array.size( ) ) - 1 )
        array.resize( array.size( ) * 2 );

    // Percolate up
    int hole = ++currentSize;
    for( ; hole > 1 && x < array[ hole / 2 ]; hole /= 2 )
    {
        array[ hole ] = array[ hole / 2 ];
    }
    array[ hole ] = x;
}


/**
 * Remove the minimum item.
 * Throws UnderflowException if empty.
 */
template <typename Comparable>
void BinaryHeap<Comparable>::deleteMin( )
{
    std::cout << "just delete min item" << std::endl;
    if( isEmpty( ) )
    {
        //throw UnderflowException( );
    }
    array[ 1 ] = array[ currentSize-- ];
    percolateDown( 1 );
}

/**
 * Remove the minimum item and place it in minItem.
 * Throws UnderflowException if empty.
 */
template <typename Comparable>
void BinaryHeap<Comparable>::deleteMin( Comparable & minItem )
{
    std::cout << "delete min item and get the value" << std::endl;
    if( isEmpty( ) )
    {
        //throw UnderflowException( );
    }
    minItem = array[ 1 ];
    array[ 1 ] = array[ currentSize-- ];
    percolateDown( 1 );
}

////////////  private functions  //////////////////

/**
 * Establish heap order property from an arbitrary
 * arrangement of items. Runs in linear time.
 */
template <typename Comparable>
void BinaryHeap<Comparable>::buildHeap( )
{
    for( int i = currentSize / 2; i > 0; i-- )
        percolateDown( i );
}

/**
 * Internal method to percolate down in the heap.
 * hole is the index at which the percolate begins.
 */
template <typename Comparable>
void BinaryHeap<Comparable>::percolateDown( int hole )
{
    int child;
    Comparable tmp = array[ hole ];

    for( ; hole * 2 <= currentSize; hole = child )
    {
        child = hole * 2;
        if( child != currentSize && array[ child + 1 ] < array[ child ] )
            child++;
        if( array[ child ] < tmp )
            array[ hole ] = array[ child ];
        else
            break;
    }
    array[ hole ] = tmp;
}

