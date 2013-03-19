/// QuickSort.hpp:
/// CopyRight (c) 2012 Vobile Inc.  All Rights Reserved.
/// Author: Allen  <huang_zhen@vobile.cn>
/// Created: 2012-11-22

#ifndef  INCLUDED_QUICKSORT_HPP
#define  INCLUDED_QUICKSORT_HPP

#include <vector>

template <typename Comparable>
void QuickSort( std::vector<Comparable> & a );
/*
template <typename Comparable>
const Comparable & median3( std::vector<Comparable> & a, int left, int right );
*/
template <typename Comparable>
void QuickSort( std::vector<Comparable> & a, int left, int right );

template <typename Comparable>
void QUICKSORT( std::vector<Comparable> & R, int s1, int t1 );

#include"QuickSort.cpp"

#endif   // ----- #ifndef INCLUDED_QUICKSORT_HPP  -----

