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

    point(): x(0), y(0) { }
    point(int i, int j): x(i), y(j) { }

    bool operator==(point p) {
        if(p.x == x && p.y == y){
            cout << "operator==, point x: " << p.x << ", y:" << p.y << endl;
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
        m_x = x;
        m_y = y;
        for(int i = 0; i < SIZE; ++i) {
            for(int j = 0; j < SIZE; ++j) {
                m_list[i][j] = list[i][j];
            }
        }

        if (list[x][y] == e_white) {
            m_white_points.push_back( point(x, y) );
        }
        else {
            cout << "error point, x:" << x << ", y:" << y << ", is not white point." << endl;
        }

        get_white_points(x, y);
        std::vector<point>::const_iterator it = m_white_points.begin();
        for( ; it != m_white_points.end(); ++it ){
            cout << "point x: " << it->x << ", y:" << it->y << endl;
        }
    
        return true;
    }
private:
    bool check_and_add_point( int x, int y ) 
    {
        point tmp(x, y);
        std::vector<point>::const_iterator it = m_white_points.begin();
        for( ; it != m_white_points.end(); ++it ){
            if (tmp == (*it)){
            //if ((*it) == tmp){
                break;
            }
        }
        if( it == m_white_points.end() && m_list[x][y] == e_white) {
            m_white_points.push_back( tmp );
            return true;
        }
        else {
            return false;
        }
    }

    void get_white_points(
              int x
            , int y)
    {
   
        int i;
        for( i = x - 1; i >=0; --i ){
            if (!check_and_add_point(i, y)) {
                break;
            }    
        }
        for( i = x + 1; i < SIZE; ++i ){
            if (!check_and_add_point(i, y)) {
                break;
            }    
        }
        for( i = y - 1; i >=0; --i ){
            if (!check_and_add_point(x, i)) {
                break;
            }    
        }
        for( i = y + 1; i < SIZE; ++i ){
            if (!check_and_add_point(x, i)) {
                break;
            }    
        }
    }

private:
    int m_x;
    int m_y;
    int m_list[SIZE][SIZE];

    std::vector<point> m_white_points;
};



int main(int argc, char *argv[])
{
    int list[SIZE][SIZE] = {
          {0, 0, 0, 0, 0, 0}
        , {0, 1, -1, -1, 0, 0}
        , {0, -1, 1, 1, -1, 0}
        , {0, -1, -1, -1, 0, 0}
        , {0, 1, -1, 0, 0, 0}
        , {0, 0, 0, 0, 0, 0}
    };

    check_point ch;
    if ( ch.check_surrounded(list, 2, 2) ){
        cout << "2,2 was surrounded." << endl;
    }
    else {
        cout << "2,2 was not surrounded." << endl;
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
