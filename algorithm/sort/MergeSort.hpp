/// MergeSort.hpp:
/// CopyRight (c) 2012 Vobile Inc.  All Rights Reserved.
/// Author: Allen  <huang_zhen@vobile.cn>
/// Created: 2012-11-22

#ifndef  INCLUDED_MERGESORT_HPP
#define  INCLUDED_MERGESORT_HPP

#include <vector>

template <typename Comparable>
void MergeSort( std::vector<Comparable> & a );

template <typename Comparable>
void MergeSort( std::vector<Comparable> & a,
                std::vector<Comparable> & tmpArray, int left, int right);


template <typename Comparable>
void merge( std::vector<Comparable> & a, std::vector<Comparable> & tmpArray,
        int leftPos, int rightPos, int rightEnd );

#include "MergeSort.cpp"

#endif   // ----- #ifndef INCLUDED_MERGESORT_HPP  -----

