/// LeftistHeap.cpp:
/// CopyRight (c) 2012 Vobile Inc.  All Rights Reserved.
/// Author: Allen  <huang_zhen@vobile.cn>
/// Created: 2012-11-21

#include <stdlib.h>
#include <iostream>

template< typename Comparable >
LeftistHeap< Comparable > ::LeftistHeap(): root( NULL )
{
}

template< typename Comparable >
LeftistHeap< Comparable > ::LeftistHeap( const LeftistHeap<Comparable> & rhs )
{
    root = NULL;
    root = merge(root,rhs.root);
}

template< typename Comparable >
LeftistHeap< Comparable > ::LeftistHeap(const Comparable args[],const int n)
{
    int i;
    root = NULL;
    for( i = 0; i < n; ++i )
    {
        Insert(args[i]);
    }
}

template< typename Comparable >
LeftistHeap< Comparable > ::~LeftistHeap()
{
    Free(root);
}

template< typename Comparable >
void LeftistHeap< Comparable >::merge(LeftistHeap & rhs)
{
    if(this == &rhs)        //avoid aliasing problems
    {
        return;
    }
    root = merge(root,rhs.root);
    rhs.root = NULL;
}


/**
 * Internal method to merge two roots.
*/
template< typename Comparable >
LeftistNode< Comparable > * LeftistHeap< Comparable >::merge( LeftistNode< Comparable > *h1
        ,LeftistNode< Comparable > *h2 )
{
    if( h1 == NULL )
        return h2;
    if( h2 == NULL )
        return h1;
    if( h1->element < h2->element )
        return mergetree( h1, h2 );
    else
        return mergetree( h2, h1 );
}


/**
 * Internal method to merge two roots.
 * Assumes trees are not empty,and h1's root contains smallest item
*/
template< typename Comparable >
LeftistNode< Comparable > * LeftistHeap< Comparable >::mergetree( LeftistNode< Comparable > *h1,
        LeftistNode< Comparable > *h2 )
{
    if(h1->left == NULL)
        h1->left = h2;
    else
    {
        h1->right = merge( h1->right, h2 );
        if( h1->left->npl < h1->right->npl )
            swapChildren( h1 );
        h1->npl = h1->right->npl + 1;
    }
    return h1;
}

/**
* Insert x,duplicates allowed
*/
template < typename Comparable >
void LeftistHeap< Comparable >::Insert(const Comparable &x)
{
    root = merge(new LeftistNode< Comparable >(x),root);
}

/**
* Remove the minimum item.
* Comparablehrows underflowException if empty
*/
template < typename Comparable >
void LeftistHeap< Comparable > ::deleteMin( Comparable & minItem )
{
    if(isEmpty())
    {
        std::cerr<<"Error! Comparable heap is empty!";
        exit(1);
    }
    minItem = root->element;

    LeftistNode<Comparable> *oldRoot = root;
    root = merge(root->left,root->right);
    delete oldRoot;
}

/**
* Remove the minimum item.
* Comparablehrows underflowException if empty
*/
template < typename Comparable >
void LeftistHeap< Comparable > ::deleteMin()
{
    if(isEmpty())
    {
        std::cerr<<"Error! Comparable heap is empty!";
        exit(1);
    }
    LeftistNode<Comparable> *oldRoot = root;
    root = merge(root->left,root->right);
    delete oldRoot;
}


template< typename Comparable >
bool LeftistHeap< Comparable >::isEmpty() const
{
    return root == NULL;
}

template< typename Comparable>
void LeftistHeap< Comparable >::swapChildren(LeftistNode< Comparable> *t)
{
    LeftistNode< Comparable > *left = t->left;
    t->left = t->right;
    t->right = left;
}

template< typename Comparable >
void LeftistHeap< Comparable >::makeEmpty()
{
    Free(root);
}

template< typename Comparable >
void LeftistHeap< Comparable >::Free(LeftistNode< Comparable > *p)
{
    if(p == NULL)
        return;
    LeftistNode< Comparable > *tmp = p;
    Free(p->left);
    Free(p->right);
    delete tmp;
}

template< typename Comparable >
const Comparable LeftistHeap< Comparable >::findMin() const
{
    if(isEmpty())
    {
        std::cerr<<"Error! Comparablehe heap is empty!";
        exit(1);
    }
    return root->element;
}

template <typename Comparable>
void LeftistHeap<Comparable>::printTree( ) const
{
    std::cout << "This is LeftistHeap printing:" << std::endl;
    printTree( root );
    std::cout << std::endl;
}

template <typename Comparable>
void LeftistHeap<Comparable>::printTree( LeftistNode<Comparable> *t ) const
{
    if( t != NULL )
    {
        std::cout << t->element << ":" << t->npl << "\t";
        printTree( t->left);
        printTree( t->right);
    }
}
//
///**
// * Merge rhs into the priority queue.
// * rhs becomes empty. rhs must be different from this.
// */
//void merge( LeftistHeap & rhs )
//{
//    if( this == &rhs )    // Avoid aliasing problems
//        return;
//
//    root = merge( root, rhs.root );
//    rhs.root = NULL;
//}
//
///**
// * Internal method to merge two roots.
// * Deals with deviant cases and calls recursive merge1.
// */
//LeftistNode * merge( LeftistNode *h1, LeftistNode *h2 )
//{
//    if( h1 == NULL )
//        return h2;
//    if( h2 == NULL )
//        return h1;
//    if( h1->element < h2->element )
//        return merge1( h1, h2 );
//    else
//        return merge1( h2, h1 );
//}
//
///**
// * Internal method to merge two roots.
// * Assumes trees are not empty, and h1's root contains smallest item.
// */
//LeftistNode * merge1( LeftistNode *h1, LeftistNode *h2 )
//{
//    if( h1->left == NULL )   // Single node
//        h1->left = h2;       // Other fields in h1 already accurate
//    else
//    {
//        h1->right = merge( h1->right, h2 );
//        if( h1->left->npl < h1->right->npl )
//            swapChildren( h1 );
//        h1->npl = h1->right->npl + 1;
//    }
//    return h1;
//}
//
///**
// * Inserts x; duplicates allowed.
// */
//void insert( const Comparable & x )
//{
//    root = merge( new LeftistNode( x ), root );
//}
//
///**
// * Remove the minimum item.
// * Comparablehrows UnderflowException if empty.
// */
//void deleteMin( )
//{
//    if( isEmpty( ) )
//        throw UnderflowException( );
//
//    LeftistNode *oldRoot = root;
//    root = merge( root->left, root->right );
//    delete oldRoot;
//}
//
///**
// * Remove the minimum item and place it in minItem.
// * Comparablehrows UnderflowException if empty.
// */
//void deleteMin( Comparable & minItem )
//{
//    minItem = findMin( );
//    deleteMin( );
//}
