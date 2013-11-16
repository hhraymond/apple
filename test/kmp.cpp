/// kmp.cpp: 
/// CopyRight (c) 2013 Vobile Inc.  All Rights Reserved.
/// Author: Allen  <huang_zhen@vobile.cn>
/// Created: 2013-11-10

#include <string>
#include <iostream>

using namespace std;

int* getNext(const string& ps)
//int* getNext(char const* ptrn, int plen, int* nextval)    
{ 
    const char* ptrn = ps.c_str();
    int* nextval = new int[ps.length()];   
    
    int i = 0;  //注，此处与下文的代码实现二不同的是，i是从0开始的（代码实现二i从1开始）     
    nextval[i] = -1;    
    int j = -1;    
    while( i < ps.length() - 1 )    
    {    
        if( j == -1 || ptrn[i] == ptrn[j] )   //循环的if部分    
        {    
            ++i;    
            ++j;    
            //修正的地方就发生下面这4行    
            if( ptrn[i] != ptrn[j] ) //++i，++j之后，再次判断ptrn[i]与ptrn[j]的关系    
                nextval[i] = j;      //之前的错误解法就在于整个判断只有这一句。    
            else    
                nextval[i] = nextval[j];    
        }    
        else                                 //循环的else部分    
            j = nextval[j];    
    }

    int size = ps.length();
    cout << "next[] size:" << size << ", element: ";
    for(int m = 0; m < size; ++m) {
        cout << nextval[m] << '\t';
    }
    cout << endl;
    return nextval; 
}

int* getNext2(const string& ps)
{
    const char* p = ps.c_str();
    int* next = new int[ps.length()];

    next[0] = -1;
    int j = 0;
    int k = -1;

    //while (j < ps.length() - 1) {
    //    if (k == -1 || p[j] == p[k]) {
    //        ++j;
    //        ++k;
    //        next[j] = k;
    //    } else {
    //        k = next[k];
    //    }
    //}
 
    while (j < ps.length() - 1) {
        if (k == -1 || p[j] == p[k]) {
            ++j;
            ++k;
            if (p[j] == p[k]) { // 当两个字符相等时要跳过
                next[j] = next[k];
            } else {
                next[j] = k;
            }
            cout << "j:" << j << ", k:" << k << ", next[" << j << "]: " <<  next[j] << ", next[" << k << "]: " << next[k] << endl;
        } else {
            k = next[k];
            cout << "k:" << k << ", next[" << k << "]: " << next[k] << endl;
        }
    }
    
    int size = ps.length();
    cout << "next[] size:" << size << ", element: ";
    for(int m = 0; m < size; ++m) {
        cout << next[m] << '\t';
    }
    cout << endl;
    
    return next;
} 

int KMP(const string& ts, const string& ps) 
{
    const char* t = ts.c_str();
    const char* p = ps.c_str();

    int i = 0; // 主串的位置
    int j = 0; // 模式串的位置
    int* next = getNext2(ps);

    int ts_len = (int)ts.length();
    int ps_len = (int)ps.length();
    cout << "ts.length: " << ts_len << ", ps.length: " << ps_len << endl;
    while (i < ts_len && j < ps_len) {
        if (j == -1 || t[i] == p[j]) { // 当j为-1时，要移动的是i，当然j也要归0
            ++i;
            ++j;
            cout << "i:" << i << ", j:" << j << ", t: " << t[i] << ", p: " << p[j] << endl;
        }
        else {
            // i不需要回溯了
            // i = i - j + 1;
            cout << "i:" << i << ", j:" << j << ", next[" << j << "]: " << next[j] << endl;
            j = next[j]; // j回到指定位置
        }
    }
    cout << "i:" << i << ", j:" << j << endl;
    cout << "ts.length: " << ts.length() << ", ps.length: " << ps.length() << endl;
    if (j >= ps.length()) {
        return i - j;
    } else {
        return -1;
    }
}

int main(int argc, char *argv[])
{
    string ts = "ABACBCDHIABABACDEABABCBBA"; 
    //string ps = "ABACDEABABC"; 
    string ps = "ABAB"; 
    cout << "ts: " << ts.c_str() << "\n" << "ps: " << ps.c_str() << endl;
    int i = KMP(ts, ps);
    cout << "pos: " << i << endl;

    return 0;
}
