/// InsertionSort.hpp:
/// CopyRight (c) 2012 Vobile Inc.  All Rights Reserved.
/// Author: Allen  <huang_zhen@vobile.cn>
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

