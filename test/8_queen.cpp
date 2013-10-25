/// 8_queen.cpp: 
/// CopyRight (c) 2013 Vobile Inc.  All Rights Reserved.
/// Author: Allen  <huang_zhen@vobile.cn>
/// Created: 2013-10-25

#include <stdio.h>

static int gEightQueen[8] = {0};  
static int gCount = 0;  
  
void print()  
{  
    int outer;  
    int inner;  
  
    for(outer = 0; outer <8; outer ++){  
        for(inner = 0; inner < gEightQueen[outer]; inner ++)  
            printf("* ");  
  
        printf("# ");  
  
        for(inner = gEightQueen[outer] + 1; inner < 8; inner ++)  
            printf("* ");  
  
        printf("\n");  
    }  
  
    printf("=====================================\n");  
}  

int check_pos_valid(int loop, int value)  
{  
    int index;  
    int data;  
  
    for(index = 0; index < loop; index ++){  
        data = gEightQueen[index];  
  
        if(value == data)  
            return 0;  
  
        if((index + data) == (loop + value))  
            return 0;  
  
        if((index - data) == (loop - value))  
            return 0;  
    }  
  
    return 1;  
} 

void eight_queen(int index)  
{  
    int loop;  
  
    for(loop = 0; loop < 8; loop++){  
        if(check_pos_valid(index, loop)){  
            gEightQueen[index] = loop;  
  
            if(7 == index){  
                gCount ++, print();  
                gEightQueen[index] = 0;  
                return;  
            }  
              
            eight_queen(index + 1);  
            gEightQueen[index] = 0;  
        }  
    }  
}


int main(int argc, char *argv[])
{
    int index = 0;
    eight_queen(index);

    return 0;
}
