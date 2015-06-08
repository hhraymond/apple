/// BinarySearchTree.hpp:
/// CopyRight (c) 2012 xxx Inc.  All Rights Reserved.
/// Author: Allen  <huang_zhen@xxx.cn>
/// Created: 2012-11-20

#ifndef  INCLUDED_BINARYSEARCHTREE_HPP
#define  INCLUDED_BINARYSEARCHTREE_HPP

#include "defines.hpp"

template <typename Comparable>
class BinarySearchTree
{
public:
    BinarySearchTree( );
    BinarySearchTree( const BinarySearchTree & rhs );
    ~BinarySearchTree( );

    const Comparable & findMin( ) const;
    const Comparable & findMax( ) const;
    bool contains( const Comparable & x ) const;
    bool isEmpty( ) const;
    void printTree( ) const;

    void makeEmpty( );
    void insert( const Comparable & x );
    void remove( const Comparable & x );
    const BinarySearchTree & operator=( const BinarySearchTree & rhs );

private:
    BinaryNode<Comparable> *root;

    void insert( const Comparable & x, BinaryNode<Comparable> * & t ) const;
    void remove( const Comparable & x, BinaryNode<Comparable> * & t ) const;
    BinaryNode<Comparable> * findMin( BinaryNode<Comparable> *t ) const;
    BinaryNode<Comparable> * findMax( BinaryNode<Comparable> *t ) const;
    bool contains( const Comparable & x, BinaryNode<Comparable> *t ) const;
    void makeEmpty( BinaryNode<Comparable> * & t );
    void printTree( BinaryNode<Comparable> *t ) const;
    BinaryNode<Comparable> * clone( BinaryNode<Comparable> *t ) const;
};


#include "BinarySearchTree.cpp"

#endif   // ----- #ifndef INCLUDED_BINARYSEARCHTREE_HPP  -----

