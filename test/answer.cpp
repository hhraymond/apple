1
1.1 test1 错在：str1以"\0"结尾，在strcpy拷贝过程中，目标字符串长度需要11个字节，而string只有10个字节，造成程序越界的问题，程序出现未知的错误。

1.2 test2 错在：str1无"\0"结尾，str1的长度未知，导致strcpy函数不知道str1在哪里结尾，拷贝过程中拷贝的内容可能远远超过10个字节，造成程序越界的问题，程序出现未知的错误。

1.3 test3 错在：strlen函数计算长度时，未计入"\0"字符。故strlen(str1) = 10时，会造成test1中一样的问题: 在strcpy拷贝过程中，目标字符串长度需要11个字节，而string只有10个字节，造成程序越界的问题，程序出现未知的错误。

2. 程序：
void sb_sort(int e[], int n) 
{
    int j, p, h, t;
    
    for (j = n -1; j >= 0; j--) {
        for (p = 0; p < j; p++) {
            if (e[p] < e[p+1]) {
                h      = e[p];
                e[p]   = e[p+1];
                e[p+1] = h;
            }
        }
    }

    return ;
}

3. 程序：
char *strcpy(char *strDest, char *strSrc)
{
    // assert(strDest != NULL && strSrc != NULL);
    if (strDest == NULL || strSrc == NULL) {
        return NULL;
    }

    char *tmp = strDest;
    while( ((*strDest++) = (*strSrc++)) != '\0'  ) {
    }

    return tmp;
}

4. 程序：
// String.h
class String
{
public:
    String(const char *str = NULL);
    String(const String &other);
    ~String(void);
    String& operate =(const String &other);
private:
    char *m_data;
};

// String.cpp
#include "String.h"

String::String(const char *str)
{
    // if NULL, also need 1 char
    if (str == NULL) {
        m_data = new char [1];
        m_data = "\0";
    }
    else {
        int len = strlen(str);
        m_data = new char [len + 1];
        strcpy(m_data, str);
    }
}

String::String(const String &other) 
{
    int len = strlen(other.m_data);
    m_data = new char [len + 1];
    strcpy(m_data, other.m_data);
}

String::~String(void)
{
    delete [] m_data;
}

String& String::operate =(const String &other)
{
    //if (other == *this) {
    if ( &other == this) {
        return *this;
    } 
    
    delete [] m_data;
    
    int len = strlen(other.m_data);
    m_data = new char [len + 1];
    strcpy(m_data, other.m_data);

    return *this;
}
