/// find.cpp: 
/// CopyRight (c) 2013 xxx Inc.  All Rights Reserved.
/// Author: Allen  <huang_zhen@xxx.cn>
/// Created: 2013-07-04

// find example
#include <iostream>     // std::cout
#include <algorithm>    // std::find
#include <vector>       // std::vector

struct buddy
{
    int a[1];
    int b;
};

int main () {
  int myints[] = { 10, 20, 30 ,40 };
  int * p;

  buddy bud[3];
  buddy *self = bud;
  (bud[0]).a[0] = 10;
  (bud[1]).a[0] = 22;
  (bud[2]).a[0] = 12;
  std::cout << self->a[0] << std::endl;
  std::cout << self->a[1] << std::endl;
  std::cout << self->a[2] << std::endl;

  // pointer to array element:
  p = std::find (myints,myints+4,30);
  ++p;
  std::cout << "The element following 30 is " << *p << '\n';

  std::vector<int> myvector (myints,myints+4);
  std::vector<int>::iterator it;

  // iterator to vector element:
  it = find (myvector.begin(), myvector.end(), 30);
  ++it;
  std::cout << "The element following 30 is " << *it << '\n';

  return 0;
}
