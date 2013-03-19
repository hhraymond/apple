/// AvlSearchTree.cpp:
/// CopyRight (c) 2012 Vobile Inc.  All Rights Reserved.
/// Author: Allen  <huang_zhen@vobile.cn>
/// Created: 2012-11-21

//#include"AvlSearchTree.hpp"

#include <iostream>

////////////  public functions  //////////////////
/**
 * constructor for the tree
 */
template <typename Comparable>
AvlSearchTree<Comparable>::AvlSearchTree( ): root(NULL)
{
}

template <typename Comparable>
AvlSearchTree<Comparable>::AvlSearchTree( const AvlSearchTree & rhs)
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
AvlSearchTree<Comparable>::~AvlSearchTree( )
{
    makeEmpty( );
}

template <typename Comparable>
const Comparable & AvlSearchTree<Comparable>::findMin( ) const
{
    return findMin( root );
}

template <typename Comparable>
const Comparable & AvlSearchTree<Comparable>::findMax( ) const
{
    return findMax( root );
}

/**
 * Returns true if x is found in the tree.
 */
template <typename Comparable>
bool AvlSearchTree<Comparable>::contains( const Comparable & x ) const
{
    return contains( x, root );
}

template <typename Comparable>
bool AvlSearchTree<Comparable>::isEmpty( ) const
{
    if( root == NULL )
        return true;
    return false;
}

template <typename Comparable>
void AvlSearchTree<Comparable>::printTree( ) const
{
    std::cout << "This is AvlSearchTree printing:" << std::endl;
    printTree( root );
    std::cout << std::endl;
}

template <typename Comparable>
void AvlSearchTree<Comparable>::makeEmpty( )
{
    makeEmpty( root );
}

/**
* Insert x into the tree; duplicates are ignored.
*/
template <typename Comparable>
void AvlSearchTree<Comparable>::insert( const Comparable & x )
{
    insert( x, root );
}

/**
 * Remove x from the tree. Nothing is done if x is not found.
 */

template <typename Comparable>
void AvlSearchTree<Comparable>::remove( const Comparable & x )
{
    remove( x, root );
}

/**
 * Deep copy.
 */
template <typename Comparable>
const AvlSearchTree<Comparable> & AvlSearchTree<Comparable>::operator=( const AvlSearchTree & rhs )
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
void AvlSearchTree<Comparable>::insert( const Comparable & x, AvlNode<Comparable> * & t ) const
{
    if( t == NULL )
        t = new AvlNode<Comparable>( x, NULL, NULL );
    else if( x < t->element )
    {
        insert( x, t->left );
        if( height( t->left ) - height( t->right ) == 2 )
        {
            if( x < t->left->element )
                rotateWithLeftChild( t );
            else
                doubleWithLeftChild( t );

        }
    }
    else if( t->element < x )
    {
        insert( x, t->right );
        if( height( t->right ) - height( t->left ) == 2 )
        {
            if( t->right->element < x )
                rotateWithRightChild( t );
            else
                doubleWithRightChild( t );
        }
    }
    else
        ;  // Duplicate; do nothing
    t->height = max( height( t->left ), height( t->right ) ) + 1;
}

/**
 * Internal method to remove from a subtree.
 * x is the item to remove.
 * t is the node that roots the subtree.
 * Set the new root of the subtree.
 */
template <typename Comparable>
void AvlSearchTree<Comparable>::remove( const Comparable & x, AvlNode<Comparable> * & t ) const
{
    if( t == NULL )
        return;   // Item not found; do nothing
    if( x < t->element )
    {
        remove( x, t->left );
        t->height = max( height( t->left ), height( t->right ) ) + 1;
    }
    else if( t->element < x )
    {
        remove( x, t->right );
        t->height = max( height( t->left ), height( t->right ) ) + 1;
    }
    else if( t->left != NULL && t->right != NULL ) // Two children
    {
        t->element = findMin( t->right )->element;
        remove( t->element, t->right );
        t->height = max( height( t->left ), height( t->right ) ) + 1;
    }
    else
    {
        AvlNode<Comparable> *oldNode = t;
        t = ( t->left != NULL ) ? t->left : t->right;
        delete oldNode;
    }
}

/**
 * Internal method to find the smallest item in a subtree t.
 * Return node containing the smallest item.
 */
template <typename Comparable>
AvlNode<Comparable> * AvlSearchTree<Comparable>::findMin( AvlNode<Comparable> *t ) const
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
AvlNode<Comparable> * AvlSearchTree<Comparable>::findMax( AvlNode<Comparable> *t ) const
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
bool AvlSearchTree<Comparable>::contains( const Comparable & x, AvlNode<Comparable> *t ) const
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
void AvlSearchTree<Comparable>::makeEmpty( AvlNode<Comparable> * & t )
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
void AvlSearchTree<Comparable>::printTree( AvlNode<Comparable> *t ) const
{
    if( t != NULL )
    {
        std::cout << t->element << ":" << t->height << "\t";
        printTree( t->left);
        printTree( t->right);
    }
}


/**
 * Internal method to clone subtree.
 */
template <typename Comparable>
AvlNode<Comparable> * AvlSearchTree<Comparable>::clone( AvlNode<Comparable> *t ) const
{
    if( t == NULL )
        return NULL;
    return new AvlNode<Comparable>( t->element, clone( t->left ), clone( t->right ) );
}

/**
 * Return the height of node t or -1 if NULL.
 */
template <typename Comparable>
int AvlSearchTree<Comparable>::height( AvlNode<Comparable> *t ) const
{
    return t == NULL ? -1 : t->height;
}

/**
 * Return the max height of node k1 and k2.
 */
template <typename Comparable>
int AvlSearchTree<Comparable>::max( int k1, int k2 ) const
{
    return k1 > k2 ? k1 : k2;
}

/**
 * Rotate binary tree node with left child.
 * For AVL trees, this is a single rotation for case 1.
 * Update heights, then set new root.
 */
template <typename Comparable>
void AvlSearchTree<Comparable>::rotateWithLeftChild( AvlNode<Comparable> * & k2 ) const
{
    AvlNode<Comparable> *k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max( height( k2->left ), height( k2->right ) ) + 1;
    k1->height = max( height( k1->left ), k2->height ) + 1;
    k2 = k1;
}

/**
 * Rotate binary tree node with right child.
 * For AVL trees, this is a single rotation for case 2.
 * Update heights, then set new root.
 */
template <typename Comparable>
void AvlSearchTree<Comparable>::rotateWithRightChild( AvlNode<Comparable> * & k2 ) const
{
    AvlNode<Comparable> *k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    k2->height = max( height( k2->left ), height( k2->right ) ) + 1;
    k1->height = max( height( k1->right ), k2->height ) + 1;
    k2 = k1;
}
/**
 * Double rotate binary tree node: first left child
 * with its right child; then node k3 with new left child.
 * For AVL trees, this is a double rotation for case 2.
 * Update heights, then set new root.
 */
template <typename Comparable>
void AvlSearchTree<Comparable>::doubleWithLeftChild( AvlNode<Comparable> * & k3 ) const
{
    rotateWithRightChild( k3->left );
    rotateWithLeftChild( k3 );
}

/**
 * Double rotate binary tree node: first right child
 * with its left child; then node k3 with new right child.
 * For AVL trees, this is a double rotation for case 1.
 * Update heights, then set new root.
 */
template <typename Comparable>
void AvlSearchTree<Comparable>::doubleWithRightChild( AvlNode<Comparable> * & k3 ) const
{
    rotateWithLeftChild( k3->right );
    rotateWithRightChild( k3 );
}
