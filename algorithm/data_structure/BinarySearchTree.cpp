/// BinarySearchTree.cpp:
/// CopyRight (c) 2012 xxx Inc.  All Rights Reserved.
/// Author: Allen  <huang_zhen@xxx.cn>
/// Created: 2012-11-20

//#include"BinarySearchTree.hpp"

#include <iostream>

////////////  public functions  //////////////////
/**
 * constructor for the tree
 */
template <typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree( ): root(NULL)
{
}

template <typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree( const BinarySearchTree & rhs)
{
    if( this != &rhs )
    {
        root = clone( rhs.root );
    }
}

/**
 * Destructor for the tree
 */
template <typename Comparable>
BinarySearchTree<Comparable>::~BinarySearchTree( )
{
    makeEmpty( );
}

template <typename Comparable>
const Comparable & BinarySearchTree<Comparable>::findMin( ) const
{
    return findMin( root );
}

template <typename Comparable>
const Comparable & BinarySearchTree<Comparable>::findMax( ) const
{
    return findMax( root );
}

/**
 * Returns true if x is found in the tree.
 */
template <typename Comparable>
bool BinarySearchTree<Comparable>::contains( const Comparable & x ) const
{
    return contains( x, root );
}

template <typename Comparable>
bool BinarySearchTree<Comparable>::isEmpty( ) const
{
    if( root == NULL )
        return true;
    return false;
}

template <typename Comparable>
void BinarySearchTree<Comparable>::printTree( ) const
{
    std::cout << "This is BinarySearchTree printing:" << std::endl;
    printTree( root );
    std::cout << std::endl;
}

template <typename Comparable>
void BinarySearchTree<Comparable>::makeEmpty( )
{
    makeEmpty( root );
}

/**
* Insert x into the tree; duplicates are ignored.
*/
template <typename Comparable>
void BinarySearchTree<Comparable>::insert( const Comparable & x )
{
    insert( x, root );
}

/**
 * Remove x from the tree. Nothing is done if x is not found.
 */

template <typename Comparable>
void BinarySearchTree<Comparable>::remove( const Comparable & x )
{
    remove( x, root );
}

/**
 * Deep copy.
 */
template <typename Comparable>
const BinarySearchTree<Comparable> & BinarySearchTree<Comparable>::operator=( const BinarySearchTree & rhs )
{
    if( this != &rhs )
    {
        makeEmpty( );
        root = clone( rhs.root );
    }
    return *this;
}

////////////  private functions  //////////////////
/**
 * Internal method to insert into a subtree.
 * x is the item to insert.
 * t is the node that roots the subtree.
 * Set the new root of the subtree.
 */
template <typename Comparable>
void BinarySearchTree<Comparable>::insert( const Comparable & x, BinaryNode<Comparable> * & t ) const
{
    if( t == NULL )
        t = new BinaryNode<Comparable>( x, NULL, NULL );
    else if( x < t->element )
        insert( x, t->left );
    else if( t->element < x )
        insert( x, t->right );
    else
        std::cout << "Duplicate element: " << x << ", will be ignored." << std::endl;
        ;  // Duplicate; do nothing
}

/**
 * Internal method to remove from a subtree.
 * x is the item to remove.
 * t is the node that roots the subtree.
 * Set the new root of the subtree.
 */
template <typename Comparable>
void BinarySearchTree<Comparable>::remove( const Comparable & x, BinaryNode<Comparable> * & t ) const
{
    if( t == NULL )
        return;   // Item not found; do nothing
    if( x < t->element )
        remove( x, t->left );
    else if( t->element < x )
        remove( x, t->right );
    else if( t->left != NULL && t->right != NULL ) // Two children
    {
        t->element = findMin( t->right )->element;
        remove( t->element, t->right );
    }
    else
    {
        BinaryNode<Comparable> *oldNode = t;
        t = ( t->left != NULL ) ? t->left : t->right;
        delete oldNode;
    }
}

/**
 * Internal method to find the smallest item in a subtree t.
 * Return node containing the smallest item.
 */
template <typename Comparable>
BinaryNode<Comparable> * BinarySearchTree<Comparable>::findMin( BinaryNode<Comparable> *t ) const
{
    if( t == NULL )
        return NULL;
    if( t->left == NULL )
        return t;
    return findMin( t->left );
}


/**
 * Internal method to find the largest item in a subtree t.
 * Return node containing the largest item.
 */
template <typename Comparable>
BinaryNode<Comparable> * BinarySearchTree<Comparable>::findMax( BinaryNode<Comparable> *t ) const
{
    if( t != NULL )
        while( t->right != NULL )
            t = t->right;
    return t;
}

/**
 * Internal method to test if an item is in a subtree.
 * x is item to search for.
 * t is the node that roots the subtree.
 */
template <typename Comparable>
bool BinarySearchTree<Comparable>::contains( const Comparable & x, BinaryNode<Comparable> *t ) const
{
    if( t == NULL )
        return false;
    else if( x < t->element )
        return contains( x, t->left );
    else if( t->element < x )
        return contains( x, t->right );
    else
        return true;    // Match
}

/**
 * Internal method to make subtree empty.
 */
template <typename Comparable>
void BinarySearchTree<Comparable>::makeEmpty( BinaryNode<Comparable> * & t )
{
    if( t != NULL )
    {
        makeEmpty( t->left );
        makeEmpty( t->right );
        delete t;
    }
    t = NULL;
}

template <typename Comparable>
void BinarySearchTree<Comparable>::printTree( BinaryNode<Comparable> *t ) const
{
    if( t != NULL )
    {
        std::cout << t->element << "\t";
        printTree( t->left);
        printTree( t->right);
    }
}


/**
 * Internal method to clone subtree.
 */
template <typename Comparable>
BinaryNode<Comparable> * BinarySearchTree<Comparable>::clone( BinaryNode<Comparable> *t ) const
{
    if( t == NULL )
        return NULL;
    return new BinaryNode<Comparable>( t->element, clone( t->left ), clone( t->right ) );
}
