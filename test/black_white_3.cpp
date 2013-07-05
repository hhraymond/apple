/// black_white.cpp: test
/// CopyRight (c) 2013 Vobile Inc.  All Rights Reserved.
/// Author: Allen  <huang_zhen@vobile.cn>
/// Created: 2013-07-02

#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 6;

enum
{
    e_black = -1,
    e_blank = 0,
    e_white = 1,
};

struct point
{
    int x;
    int y;

    bool is_checked;

    point(): x(0), y(0), is_checked(false) { }
    point(int i, int j): x(i), y(j) { }

    bool operator==(point p) {
        if(p.x == x && p.y == y){
            cout << "1," << endl;
            return true;
        }
        else {
            return false;
        }
    }
};

class check_point
{
public:
    check_point() {}
    ~check_point() {}

    
    bool check_surrounded(
            int list[SIZE][SIZE]
            , int x
            , int y)
    {
        for(int i = 0; i < SIZE; ++i) {
            for(int j = 0; j < SIZE; ++j) {
                m_list[i][j] = list[i][j];
            }
        }

        if (list[x][y] == e_white) {
            return check_points( x, y, -1, -1);
        }
        else {
            cout << "error point, x:" << x << ", y:" << y << ", is not white point." << endl;
            return false;
        }
    }

private:
    bool check_points(int x, int y, int last_x, int last_y)
    {
        if (x < 0 || x >= SIZE) {
            return true;
        }

        if (y < 0 || y >= SIZE) {
            return true;
        }

        if (m_list[x][y] == e_black) {
            return true;
        }
        else if (m_list[x][y] == e_blank) {
            return false;
        }
        else if (m_list[x][y] == e_white) {
            bool left, right, up, down;
            left = right = up = down = true;
            int i = 0;
            // left
            i = x - 1;
            if ( i != last_x) {
                left = check_points(i, y, x, y);
            }
            // right
            i = x + 1;
            if ( i != last_x) {
                right = check_points(i, y, x, y);
            }
            // up
            i = y - 1;
            if ( i != last_y) {
                up = check_points(x, i, x, y);
            }
            // down
            i = y + 1;
            if ( i != last_y) {
                down = check_points(x, i, x, y);
            }

            return left && right && up && down;
        }
    }

private:
    int m_list[SIZE][SIZE];
    std::vector<point> m_checked_points;
};



int main(int argc, char *argv[])
{
    int list[SIZE][SIZE] = {
          {0, 0, 0, 0, 0, 0}
        , {0, 1, -1, -1, 0, 0}
        , {0, -1, 1, 1, -1, 0}
        , {0, -1, 1, 1, -1, 0}
        , {0, 1, -1, -1, 0, 0}
        , {0, 0, 0, 0, 0, 0}
    };

    check_point ch;
    if ( ch.check_surrounded(list, 2, 2) ){
        cout << "2,2 was surrounded." << endl;
    }
    else {
        cout << "2,2 was not surrounded." << endl;
    }

    if ( ch.check_surrounded(list, 1, 1) ){
        cout << "1,1 was surrounded." << endl;
    }
    else {
        cout << "1,1 was not surrounded." << endl;
    }

    point pt(e_black, e_white);
    cout << pt.x << "\t" << pt.y << endl;
    
    for (int i = 0; i < SIZE; ++i) {
        for(int j = 0; j < SIZE; ++j) {
            cout << list[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
