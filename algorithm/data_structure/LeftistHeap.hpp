/// LeftistHeap.hpp:
/// CopyRight (c) 2012 xxx Inc.  All Rights Reserved.
/// Author: Allen  <huang_zhen@xxx.cn>
/// Created: 2012-11-21

#ifndef  INCLUDED_LEFTISTHEAP_HPP
#define  INCLUDED_LEFTISTHEAP_HPP


#include "defines.hpp"

template< typename Comparable >
class LeftistHeap
{
public:
    LeftistHeap( );
    LeftistHeap( const LeftistHeap & rhs );
    LeftistHeap( const Comparable args[],const int n );
    ~LeftistHeap( );

    bool isEmpty( ) const;
    const Comparable findMin() const;
    void printTree( ) const;

    void Insert( const Comparable &x );
    void deleteMin( );
    void deleteMin( Comparable & minItem );
    void makeEmpty( );
    void merge( LeftistHeap &rhs );

private:
    LeftistNode<Comparable> *root;

    LeftistNode<Comparable> * mergetree( LeftistNode<Comparable> *h1, LeftistNode<Comparable> *h2);
    LeftistNode<Comparable> * merge( LeftistNode<Comparable> *h1, LeftistNode<Comparable> *h2);

    void swapChildren( LeftistNode<Comparable> *t );
    void Free( LeftistNode<Comparable> *p );
    void printTree( LeftistNode<Comparable> *t ) const;

};

/*
template <typename Comparable>
class LeftistHeap
{
public:
    LeftistHeap( );
    LeftistHeap( const LeftistHeap & rhs );
    ~LeftistHeap( );

    bool isEmpty( ) const;
    const Comparable & findMin( ) const;

    void insert( const Comparable & x );
    void deleteMin( );
    void deleteMin( Comparable & minItem );
    void makeEmpty( );
    void merge( LeftistHeap & rhs );

    const LeftistHeap & operator=( const LeftistHeap & rhs );

private:
    LeftistNode *root;

    LeftistNode * merge( LeftistNode *h1, LeftistNode *h2 );
    LeftistNode * merge1( LeftistNode *h1, LeftistNode *h2 );

    void swapChildren( LeftistNode *t );
    void reclaimMemory( LeftistNode *t );
    LeftistNode * clone( LeftistNode *t ) const;
};
*/

#include "LeftistHeap.cpp"

#endif   // ----- #ifndef INCLUDED_LEFTISTHEAP_HPP  -----

