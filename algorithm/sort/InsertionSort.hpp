/// InsertionSort.hpp:
/// CopyRight (c) 2012 xxx Inc.  All Rights Reserved.
/// Author: Allen  <huang_zhen@xxx.cn>
/// Created: 2012-11-22

#ifndef  INCLUDED_INSERTIONSORT_HPP
#define  INCLUDED_INSERTIONSORT_HPP

#include<vector>

template <typename Comparable>
void InsertionSort( std::vector<Comparable> & a );

template <typename Comparable>
void InsertionSort( std::vector<Comparable> & a, int left, int right );

#include "InsertionSort.cpp"
#endif   // ----- #ifndef INCLUDED_INSERTIONSORT_HPP  -----

