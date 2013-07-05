/// black_white.cpp: test
/// CopyRight (c) 2013 Vobile Inc.  All Rights Reserved.
/// Author: Allen  <huang_zhen@vobile.cn>
/// Created: 2013-07-02

#include <iostream>
#include <algorithm>    // std::find
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
            cout << "use operator==" << endl;
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
        // init
        for(int i = 0; i < SIZE; ++i) {
            for(int j = 0; j < SIZE; ++j) {
                m_list[i][j] = list[i][j];
            }
        }
        m_points.clear();

        // check
        bool su;
        if (list[x][y] == e_white) {
            su = check_points( x, y);
        }
        else {
            cout << "error point, x:" << x << ", y:" << y << ", is not white point." << endl;
            su = false;
        }
        
        // dump points
        std::vector<point>::const_iterator it;
        cout << "checked points: " << endl;
        for( it = m_points.begin(); it != m_points.end(); ++it ){
            cout << "x: " << it->x << ",\ty: " << it->y << endl;
        }

        return su;
    }

private:
    bool is_in_checked_points(int x, int y) 
    {
        std::vector<point>::const_iterator it;
        it = find( m_points.begin(), m_points.end(), point(x, y) );
        if ( it != m_points.end() ) {
            return true;
        }
        //for( it = m_points.begin(); it != m_points.end(); ++it ){
        //    if(x == it->x && y == it->y){
        //        return true;
        //    }
        //}
        return false;
    }

    bool check_points(int x, int y)
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
            m_points.push_back( point(x, y) );

            bool left, right, up, down;
            left = right = up = down = true;
            int i = 0;
            // left
            i = x - 1;
            if (!is_in_checked_points(i, y)) {
                left = check_points(i, y);
            }
            // right
            i = x + 1;
            if (!is_in_checked_points(i, y)) {
                right = check_points(i, y);
            }
            // up
            i = y - 1;
            if (!is_in_checked_points(x, i)) {
                up = check_points(x, i);
            }
            // down
            i = y + 1;
            if (!is_in_checked_points(x, i)) {
                down = check_points(x, i);
            }

            return left && right && up && down;
        }
    }

private:
    int m_list[SIZE][SIZE];
    std::vector<point> m_points;
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

    cout << "input list:" << endl;
    for (int i = 0; i < SIZE; ++i) {
        for(int j = 0; j < SIZE; ++j) {
            cout << list[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
