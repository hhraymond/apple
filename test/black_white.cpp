/// black_white.cpp: test
/// CopyRight (c) 2013 xxx Inc.  All Rights Reserved.
/// Author: Allen  <huang_zhen@xxx.cn>
/// Created: 2013-07-02

#include <iostream>

using namespace std;

struct point
{
    int x;
    int y;

    point(): x(0), y(0) { }
    point(int i, int j): x(i), y(j) { }
};


bool check_surrounded(int **list, int x, int y)
{
    point pt(x, y);

    return true;
}


int main(int argc, char *argv[])
{
    int list[6][6] = {
          {0, 0, 0, 0, 0, 0}
        , {0, 1, -1, -1, 0, 0}
        , {0, -1, 1, 1, -1, 0}
        , {0, -1, -1, -1, 0, 0}
        , {0, 1, -1, 0, 0, 0}
        , {0, 0, 0, 0, 0, 0}
    };
    
    point pt(1, 2);
    cout << pt.x << "\t" << pt.y << endl;
    
    for (int i = 0; i < 6; ++i) {
        for(int j = 0; j < 6; ++j) {
            cout << list[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}
