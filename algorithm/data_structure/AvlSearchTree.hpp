/// AvlSearchTree.hpp:
/// CopyRight (c) 2012 xxx Inc.  All Rights Reserved.
/// Author: Allen  <huang_zhen@xxx.cn>
/// Created: 2012-11-21

#ifndef  INCLUDED_AVLSEARCHTREE_HPP
#define  INCLUDED_AVLSEARCHTREE_HPP

#include "defines.hpp"

template <typename Comparable>
class AvlSearchTree
{
public:
    AvlSearchTree( );
    AvlSearchTree( const AvlSearchTree & rhs );
    ~AvlSearchTree( );

    const Comparable & findMin( ) const;
    const Comparable & findMax( ) const;
    bool contains( const Comparable & x ) const;
    bool isEmpty( ) const;
    void printTree( ) const;

    void makeEmpty( );
    void insert( const Comparable & x );
    void remove( const Comparable & x );
    const AvlSearchTree & operator=( const AvlSearchTree & rhs );

private:
    AvlNode<Comparable> *root;

    void insert( const Comparable & x, AvlNode<Comparable> * & t ) const;
    void remove( const Comparable & x, AvlNode<Comparable> * & t ) const;
    AvlNode<Comparable> * findMin( AvlNode<Comparable> *t ) const;
    AvlNode<Comparable> * findMax( AvlNode<Comparable> *t ) const;
    bool contains( const Comparable & x, AvlNode<Comparable> *t ) const;
    void makeEmpty( AvlNode<Comparable> * & t );
    void printTree( AvlNode<Comparable> *t ) const;
    AvlNode<Comparable> * clone( AvlNode<Comparable> *t ) const;

    int  height( AvlNode<Comparable> *t ) const;
    int  max( int k1, int k2 ) const; //max hight
    void rotateWithLeftChild( AvlNode<Comparable> * & k2 ) const;
    void rotateWithRightChild( AvlNode<Comparable> * & k2 ) const;
    void doubleWithLeftChild( AvlNode<Comparable> * & k3 ) const;
    void doubleWithRightChild( AvlNode<Comparable> * & k3 ) const;
};

#include "AvlSearchTree.cpp"

#endif   // ----- #ifndef INCLUDED_AVLSEARCHTREE_HPP  -----

