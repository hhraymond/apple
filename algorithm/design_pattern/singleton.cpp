/// singleton.cpp: 
/// CopyRight (c) 2013 Vobile Inc.  All Rights Reserved.
/// Author: Allen  <huang_zhen@vobile.cn>
/// Created: 2013-04-17

#include<iostream>

using namespace std;

class Singleton
{
public:
    static Singleton* getInstance();

private:
    Singleton() 
    {
        cout<<"constructor\n";
        // do something 
    };
    ~Singleton()
    {
        cout<<"destructor\n";
        //do something
    }
};

Singleton* Singleton::getInstance()
{
    static Singleton instance;
    return &instance;
}

int main()
{
    cout<<"begin main\n";
    Singleton* instance = Singleton::getInstance();
    cout<<"end main\n";
}
