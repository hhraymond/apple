/// BinomialQueue.hpp:
/// CopyRight (c) 2012 xxx Inc.  All Rights Reserved.
/// Author: Allen  <huang_zhen@xxx.cn>
/// Created: 2012-11-21

#ifndef  INCLUDED_BINOMIALQUEUE_HPP
#define  INCLUDED_BINOMIALQUEUE_HPP

#include "defines.hpp"

#include <vector>
#include <stdexcept>
#include <iostream>

using namespace std;

template<typename Comparable>
class BinomialQueue
{
public:
    BinomialQueue( ): currentSize( 0 ){ }
    BinomialQueue( const Comparable& item): currentSize( 0 )
    {
        theTrees.push_back( new BinomialNode(item,NULL,NULL) );
        ++currentSize;
    }
    BinomialQueue(const BinomialQueue& rhs)
    {
        makeEmpty(  );
        merge( rhs );
    }

    ~BinomialQueue( )
    {
        makeEmpty(  );
    }

    bool isEmpty( ) const
    {
        return theTrees.size( ) == 0;
    }

    void printQueue( ) const
    {
        std::cout << "This is BinomialQueue printing: size " << currentSize << std::endl;
        for( size_t i = 0; i < theTrees.size( ); ++i)
        {
            printQueue( theTrees[i] );
        }
        cout << endl;
    }

    const Comparable& findMin( ) const
    {
        int minIndex=findMinIndex( );
        return theTrees[ minIndex ]->element;
    }

    void insert( const Comparable& x )
    {
        BinomialQueue rhs( x );
        merge( rhs );
    }


    void deleteMin( )
    {
        Comparable minItem;
        deleteMin( minItem );
    }

    void deleteMin( Comparable & minItem )
    {
        if( isEmpty( ) )
            throw runtime_error("Cannot call pop_back on empty");
        int minIndex = findMinIndex( );
        minItem = theTrees[ minIndex ]->element;

        BinomialNode *oldRoot = theTrees[ minIndex ];
        BinomialNode *deletedTree = oldRoot->leftChild;
        delete oldRoot;

        // construct H'', new trees created by delete minItem
        BinomialQueue deletedQueue;
        deletedQueue.theTrees.resize( minIndex + 1 );
        deletedQueue.currentSize = ( 1 << minIndex ) - 1;
        for( int j = minIndex - 1; j >= 0; j-- )
        {
            deletedQueue.theTrees[ j ] = deletedTree;
            deletedTree = deletedTree->nextSibling;
            deletedQueue.theTrees[ j ]->nextSibling = NULL;
        }
        
        // construct H', old trees
        theTrees[ minIndex ] = NULL;
        currentSize -= deletedQueue.currentSize + 1; // currentSize =  currentSize - ( deletedQueue.currentSize + 1 );
        
        merge( deletedQueue );
    }

    void makeEmpty()
    {
        for( size_t i = 0; i != theTrees.size(); ++i )
            makeEmpty( theTrees[ i ] );
        theTrees.clear( );
        theTrees.resize( 0 );
        currentSize = 0;
    }

    void merge( BinomialQueue& rhs )
    {
        if( this == &rhs ) // Avoid aliasing problems
            return;
        
        currentSize += rhs.currentSize;
        
        if( currentSize > capacity() )
        {
            int oldNumTrees = theTrees.size();
            int newNumTrees = max( theTrees.size(), rhs.theTrees.size() ) + 1;
            theTrees.resize( newNumTrees );
            for(int i = oldNumTrees; i < newNumTrees; i++ )
                theTrees[i] = NULL;
        }

        BinomialNode* carry = NULL;
        for(size_t i = 0, j = 1; j <= currentSize; i++, j *= 2)
        {
            BinomialNode *t1 = theTrees[i];
            BinomialNode *t2 = ( i < rhs.theTrees.size() ) ? rhs.theTrees[i] : NULL;

            int whichCase = ( t1 == NULL ) ? 0 : 1;
            whichCase += ( t2 == NULL ) ? 0 : 2;
            whichCase += ( carry == NULL ) ? 0 : 4;

            switch( whichCase )
            {
             case 0: // No tree
             case 1: // Only this
                break;
             case 2: // Only rhs
                theTrees[i] = t2;
                rhs.theTrees[i] = NULL;
                break;
             case 4: // Only carry
                theTrees[i] = carry;
                carry = NULL;
                break;
             case 3: // this and rhs
                carry = combineTrees(t1, t2);
                theTrees[i] = rhs.theTrees[i] = NULL;
                break;
             case 5: // this and carry
                carry = combineTrees(t1, carry);
                theTrees[i] = NULL;
                break;
             case 6: // rhs and carry
                carry = combineTrees(t2, carry);
                rhs.theTrees[i] = NULL;
                break;
             case 7: // all three
                theTrees[i] = carry;
                carry = combineTrees(t1, t2);
                rhs.theTrees[i] = NULL;
                break;
            }
        }
        for(size_t k = 0; k < rhs.theTrees.size(); k++)
            rhs.theTrees[k] = NULL;
        rhs.currentSize = 0;
    }

    const BinomialQueue& operator=(const BinomialQueue& rhs)
    {
        if( this != &rhs )
        {
            makeEmpty();
            theTrees.resize(rhs.theTrees.size());
            for(int i = 0;i < rhs.theTrees.size(); ++i)
                theTrees[i] = clone(rhs.theTrees[i]);
        }
        return *this;
    }

private:
    struct BinomialNode
    {
      Comparable element;
      BinomialNode* leftChild;
      BinomialNode* nextSibling;
      BinomialNode( const Comparable& theElement,
                BinomialNode* lt, BinomialNode* rt )
          : element(theElement), leftChild(lt), nextSibling( rt ) { }
    };

    size_t currentSize;

    vector<BinomialNode*> theTrees;

    void printQueue( BinomialNode *t ) const
    {
        if( t != NULL )
        {
            cout << t->element << "\t";
            printQueue( t->leftChild );
            printQueue( t->nextSibling );
        }
    }

    size_t findMinIndex( ) const
    {
        size_t i;
        size_t minIndex;
        // get first not null tree place, where used in theTrees[ minIndex ]->element
        for( i = 0; theTrees[i] == NULL; i++)
         ;
        // get minIndex
        for( minIndex = i; i < theTrees.size(); i++)
        {
            if( theTrees[i] != NULL &&
                theTrees[i]->element < theTrees[ minIndex ]->element )
            minIndex = i;
        }
        return minIndex;
    }
    
    size_t capacity()const
    {
        return ( 1<< theTrees.size() ) - 1;
    }
    
    BinomialNode* combineTrees(BinomialNode* t1,BinomialNode* t2)
    {
        if(t2->element < t1->element)
            return combineTrees(t2, t1);
        t2->nextSibling = t1->leftChild;
        t1->leftChild = t2;
        return t1;
    }
    
    void makeEmpty( BinomialNode * & t )
    {
        if( t != NULL )
        {
            makeEmpty( t->leftChild );
            makeEmpty( t->nextSibling );
            delete t;
        }
        t = NULL;
    }
    
    BinomialNode* clone( BinomialNode* t ) const
    {
        if( t == NULL )
            return NULL;
        return new BinomialNode( t->element, clone(t->leftChild), clone(t->nextSibling) );
    }
};

/*
template <typename Comparable>
class BinomialQueue
{
public:
    BinomialQueue( );
    BinomialQueue( const Comparable & item );
    BinomialQueue( const BinomialQueue & rhs );
    ~BinomialQueue( );

    bool isEmpty( ) const;
    const Comparable & findMin( ) const;

    void insert( const Comparable & x );
    void deleteMin( );
    void deleteMin( Comparable & minItem );

    void makeEmpty( );
    void merge( BinomialQueue & rhs );

    const BinomialQueue & operator= ( const BinomialQueue & rhs );

private:

    enum { DEFAULT_TREES = 1 };

    int currentSize;                  // Number of items in priority queue
    vector<BinomialNode<Comparable> *> theTrees;  // An array of tree roots

    int findMinIndex( ) const;
    int capacity( ) const;
    BinomialNode<Comparable> * combineTrees( BinomialNode<Comparable> *t1, BinomialNode<Comparable> *t2 );
    void makeEmpty( BinomialNode<Comparable> * & t );
    BinomialNode<Comparable> * clone( BinomialNode<Comparable> *t ) const;
};

*/

#endif   // ----- #ifndef INCLUDED_BINOMIALQUEUE_HPP  -----

