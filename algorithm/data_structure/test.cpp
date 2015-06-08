/// test.cpp:
/// CopyRight (c) 2012 xxx Inc.  All Rights Reserved.
/// Author: Allen  <huang_zhen@xxx.cn>
/// Created: 2012-11-24

#include <iostream>

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
class BinarySearchTree
{
public:
    BinarySearchTree( );
    ~BinarySearchTree( );

private:
    BinaryNode* findMin( );
    BinaryNode *root;
};

/**
 * constructor for the tree
 */
template <typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree( )
{
    BinaryNode();
}

/**
 * Destructor for the tree
 */
template <typename Comparable>
BinarySearchTree<Comparable>::~BinarySearchTree( )
{
}

template <typename Comparable>
BinaryNode * BinarySearchTree<Comparable>::findMin( )
{
    return root;
}


//*********** main  ************//
int main(int argc, char *argv[])
{

    BinarySearchTree<int> aa;

    return 0;
}
