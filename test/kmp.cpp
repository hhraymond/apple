/// kmp.cpp: 
/// CopyRight (c) 2013 Vobile Inc.  All Rights Reserved.
/// Author: Allen  <huang_zhen@vobile.cn>
/// Created: 2013-11-10

#include <string>
#include <iostream>

using namespace std;

int* getNext(const string& ps)
{
    const char* p = ps.c_str();
    int* next = new int[ps.length()];

    next[0] = -1;
    int j = 0;
    int k = -1;

    while (j < ps.length() - 1) {
        if (k == -1 || p[j] == p[k]) {
            if (p[++j] == p[++k]) { // 当两个字符相等时要跳过
                next[j] = next[k];
            } else {
                next[j] = k;
            }
        } else {
            k = next[k];
        }
    }
    cout << "next[" << j << "]: " << next[j] << endl;
    return next;
} 

int KMP(const string& ts, const string& ps) 
{
    const char* t = ts.c_str();
    const char* p = ps.c_str();

    int i = 0; // 主串的位置
    int j = 0; // 模式串的位置
    int* next = getNext(ps);
    int size = ps.length();
    cout << "next[] size:" << size << ", element: ";
    for(int m = 0; m < size; ++m) {
        cout << next[m] << '\t';
    }
    cout << endl;

    while (i < ts.length() && j < ps.length()) {
        if (j == -1 || t[i] == p[j]) { // 当j为-1时，要移动的是i，当然j也要归0
            i++;
            j++;
        } else {
            // i不需要回溯了
            // i = i - j + 1;
            j = next[j]; // j回到指定位置
        }
    }
    if (j == ps.length()) {
        return i - j;
    } else {
        return -1;
    }
}


int main(int argc, char *argv[])
{
    string ts = "1234abcdefgaaa"; 
    string ps = "ababab"; 
    cout << "ts: " << ts.c_str() << "\n" << "ps: " << ps.c_str() << endl;
    int i = KMP(ts, ps);
    cout << "pos: " << i << endl;

    return 0;
}
