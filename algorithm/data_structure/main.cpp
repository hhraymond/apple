/// main.cpp:
/// CopyRight (c) 2012 Vobile Inc.  All Rights Reserved.
/// Author: Allen  <huang_zhen@vobile.cn>
/// Created: 2012-11-22

#include "defines.hpp"
#include "BinarySearchTree.hpp"
#include "AvlSearchTree.hpp"
#include "BinaryHeap.hpp"
#include "LeftistHeap.hpp"
#include "BinomialQueue.hpp"

#include <stdlib.h>
#include <iostream>
#include <vector>

void BinTreeTest()
{
    int da[]={6, 2, 8, 1, 4, 3, 5, 10, 4};

    int m = 0;
    std::cout << da [m] << std::endl;
    std::cout << da [m++] << std::endl;
    std::cout << da [m++] << std::endl;
    std::cout << da [1] << std::endl;

    BinarySearchTree<int> binTree;
    for(size_t i=0; i<sizeof(da)/sizeof(int); ++i)
    {
        std::cout << "intsert element: " << da[i] << std::endl;
        binTree.insert(da[i]);
        binTree.printTree();
    }

    std::cout << "remove element 2" << std::endl;
    binTree.remove(2);
    binTree.printTree();
    BinarySearchTree<int> binTree2(binTree);
    std::cout << "binTree2 :" << std::endl;
    binTree2.printTree();
}

void AvlTreeTest()
{
    int da[]={6, 2, 8, 1, 4, 3, 5, 10, 4};

    AvlSearchTree<int> avlTree;
    for(size_t i=0; i<sizeof(da)/sizeof(int); ++i)
    {
        std::cout << "intsert element: " << da[i] << std::endl;
        avlTree.insert(da[i]);
        avlTree.printTree();
    }

    std::cout << "remove element 5" << std::endl;
    avlTree.remove(5);
    avlTree.printTree();
    std::cout << "remove element 1" << std::endl;
    avlTree.remove(1);
    avlTree.printTree();
    std::cout << "remove element 3" << std::endl;
    avlTree.remove(3);
    avlTree.printTree();
    avlTree.makeEmpty();

}

void BinHeapTest()
{

    int da[12]={15,5,3,12,10,13,6,7,16,20,18,23};
    BinaryHeap<int> binHeap;
    for(int i=0;i<12;i++)
    {
        binHeap.insert(da[i]);
        binHeap.printHeap();
    }
    int a = 0;
    binHeap.deleteMin( a );
    std::cout << "delete Min: " << a << std::endl;
    binHeap.printHeap();
    binHeap.deleteMin( a );
    std::cout << "delete Min: " << a << std::endl;
    binHeap.printHeap();

}

void LeftistHeapTest()
{
    int da[12]={15,5,3,12,10,13,6,7,16,20,18,23};
    LeftistHeap<int> leftist( da, 12 );
    leftist.printTree();

}

void BinomialQueueTest()
{
    //BinaryNode<int>  aa;
    //aa = avlTree.findMax();
    //std::cout << aa << std::endl;
    BinomialQueue<int> bq1;
    BinomialQueue<int> bq2;
    int a[] = {2, 3, 1, 7, 9, 33, 2, 5, 7, 2, 5, 6, 6, 45, -5};
    int b[] = {6, 2, 4, 9, 56, 23, 12, 55, 7, 23, 2, -9, 0, 1, 13};
    for( int i = 0; i != 15; ++i )
    {
        bq1.insert( a[i] );
        bq1.printQueue( );
    }
    std::cout<<bq1.findMin()<<std::endl;
    for( int j = 0; j!=15; ++j )
    {
        bq2.insert(b[j]);
        bq2.printQueue( );
    }
    std::cout << bq2.findMin() << std::endl;
    bq1.merge( bq2 );
    std::cout << bq1.findMin() << std::endl;
    bq1.printQueue( );

    bq1.deleteMin( );
    std::cout << bq1.findMin() <<std::endl;
    bq1.printQueue( );
    //system("pause");

    //pause();

}

//*********** main  ************//
int main(int argc, char *argv[])
{

    //BinTreeTest();
    //AvlTreeTest();
    //BinHeapTest();
    LeftistHeapTest();
    BinomialQueueTest();

    int i = 20;
    int j = 6;
    i -= j + 1;

    std::cout << i << std::endl; 

    std::vector<int> vec;
    vec.push_back(1);
    std::cout << vec.size() << std::endl;
    
    vec.push_back(1);
    std::cout << vec.size() << vec[0] << vec[1] << std::endl;
  
    //std::string str = NULL;
    /*
    if ( str.empty() ){
        std::cout << "null" << std::endl;
    }*/
    //std::string str1 = str;

    return 0;
}
