/// defines.hpp:
/// CopyRight (c) 2012 Vobile Inc.  All Rights Reserved.
/// Author: Allen  <huang_zhen@vobile.cn>
/// Created: 2012-11-21

#ifndef  INCLUDED_DEFINES_HPP
#define  INCLUDED_DEFINES_HPP

//#include <unistd.h>
#include <stddef.h>

template <typename Comparable>
struct TreeNode
{
    Comparable   element;
    TreeNode *firstChild;
    TreeNode *nextSibling;
};

template <typename Comparable>
struct BinaryNode
{
    Comparable element;
    BinaryNode *left;
    BinaryNode *right;
    BinaryNode( const Comparable & theElement, BinaryNode *lt, BinaryNode *rt )
        : element( theElement ), left( lt ), right( rt ) { }
};

template <typename Comparable>
struct AvlNode
{
    Comparable element;
    AvlNode   *left;
    AvlNode   *right;
    int       height;

    AvlNode( const Comparable & theElement, AvlNode *lt,
                                            AvlNode *rt, int h = 0 )
      : element( theElement ), left( lt ), right( rt ), height( h ) { }
};

/*
template <typename Comparable>
struct LeftistNode
{
    Comparable   element;
    LeftistNode *left;
    LeftistNode *right;
    int          npl;

    LeftistNode( const Comparable & theElement, LeftistNode *lt = NULL,
                    LeftistNode *rt = NULL, int np = 0 )
      : element( theElement ), left( lt ), right( rt ), npl( np ) { }
};
*/

template< typename Comparable >
struct LeftistNode
{
    Comparable element;
    LeftistNode *left;
    LeftistNode *right;
    int npl;
    LeftistNode(const Comparable & theElement, LeftistNode* lt = NULL,
                LeftistNode * rt = NULL,int np = 0)
                :element(theElement), left(lt), right(rt), npl(np){}
};

/*
template <typename Comparable>
struct BinomialNode
{
    Comparable    element;
    BinomialNode *leftChild;
    BinomialNode *nextSibling;

    BinomialNode( const Comparable & theElement,
                    BinomialNode *lt, BinomialNode *rt )
      : element( theElement ), leftChild( lt ), nextSibling( rt ) { }
};
*/

#endif   // ----- #ifndef INCLUDED_DEFINES_HPP  -----

