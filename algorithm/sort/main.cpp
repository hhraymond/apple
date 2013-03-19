/// main.cpp:
/// CopyRight (c) 2012 Vobile Inc.  All Rights Reserved.
/// Author: Allen  <huang_zhen@vobile.cn>
/// Created: 2012-11-22

#include"InsertionSort.hpp"
#include"ShellSort.hpp"
#include"QuickSort.hpp"
#include"MergeSort.hpp"
#include"HeapSort.hpp"
#include"BubbleSort.hpp"

#include <iostream>
#include <vector>

void data_prepare( std::vector<int> & data )
{
    //int integer[] = {10,9, 15, 14, 4, 2, 8, 20};
    //int integer[] = {10,9, 15, 14, 4, 2, 8, 20, 11, 43, 29, 7, 20, 28, 38, 39};
    int integer[] = {10,9, 15, 14, 4, 2, 8, 20, 11, 43, 29, 7};

    int count = sizeof(integer) / sizeof(int);
    std::cout << "data count: " << count << "\tinit as: " << std::endl;
    for( int i = 0; i < count; ++i )
    {
        data.push_back(integer[i]);
        std::cout << integer[i] << "\t" ;
    }
    std::cout << std::endl;
}

void print_data( const std::vector<int> &data )
{
    std::cout << "data after sort: " << std::endl;
    for( int j = 0; j < data.size(); ++j )
    {
        std::cout << data[j] << "\t";
    }
    std::cout << "\n" << std::endl;
}

void InsertionSortTest()
{
    std::cout << "this is InsertionSort..." << std::endl;
    std::vector<int> data;
    data_prepare(data);

    InsertionSort( data );

    print_data( data );
}

void BubbleSortTest()
{
    std::cout << "this is BubbleSort..." << std::endl;
    std::vector<int> data;
    data_prepare(data);

    BubbleSort( data );

    print_data( data );
}

void ShellSortTest()
{
    std::cout << "this is ShellSort..." << std::endl;
    std::vector<int> data;
    data_prepare(data);

    ShellSort( data );

    print_data( data );
}

void QuickSortTest()
{
    std::cout << "this is QuickSort..." << std::endl;
    std::vector<int> data;
    data_prepare(data);

    QuickSort( data );

    print_data( data );
}

void MergeSortTest()
{
    std::cout << "this is MergeSort..." << std::endl;
    std::vector<int> data;
    data_prepare(data);

    MergeSort( data );

    print_data( data );
}

void HeapSortTest()
{
    std::cout << "this is HeapSort..." << std::endl;
    std::vector<int> data;
    data_prepare(data);

    HeapSort( data );

    print_data( data );
}

enum aaa{
    e_task01  = 1,
    e_task02  = 2
};

//*********** main  ************//
int main(int argc, char *argv[])
{
    char a = '9';
    int i = (int) a;
    int j = (int) (a - '0');
    std::cout << "i:" << i << std::endl;
    std::cout << "j:" << j << std::endl;

    InsertionSortTest();

    BubbleSortTest();

    ShellSortTest();

    QuickSortTest();

    MergeSortTest();

    HeapSortTest();

    return 0;
}
