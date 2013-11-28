/// 8_queen.cpp: 
/// CopyRight (c) 2013 Vobile Inc.  All Rights Reserved.
/// Author: Allen  <huang_zhen@vobile.cn>
/// Created: 2013-10-25

#include <stdio.h>
#include <stdlib.h>
//#include <math.h>

static int gEightQueen[8] = {0};  
static int gCount = 0;
int gTest = 0;
  
void print()  
{  
    for(int row = 0; row <8; row ++){  
        for(int col = 0; col < gEightQueen[row]; col ++)  
            printf("* ");  
  
        printf("# ");  
  
        for(int col = gEightQueen[row] + 1; col < 8; col ++)  
            printf("* ");  
  
        printf("\n");  
    }  
  
    printf("%d, =====================================\n", gCount);  
}  

int check_pos_valid(int row, int col)  
{  
    int data;  
    for(int i = 0; i < row; i++){  
        data = gEightQueen[i];  
        // same column    // square: length == width 
        if(col == data || abs(i - row) == abs(col - data) )  
            return false;  
  
        //if((i + data) == (row + col))  
        //    return false;  
  
        //if((i - data) == (row - col))  
        //    return false;  
    }  
  
    return true;
} 

void eight_queen(int row)  
{  
    for(int col = 0; col < 8; col++){  
        if(check_pos_valid(row, col)){  
            gEightQueen[row] = col;  
  
            if(7 == row){  
                gCount ++;
                print();  
                //gEightQueen[row] = 0;  
                return;  
            }  
              
            eight_queen(row + 1);  
            //gEightQueen[row] = 0;
            //print();
            //printf("xx%dxx.\n", gTest++);
        }  
    }  
}

int main(int argc, char *argv[])
{
    int row = 0; // row
    eight_queen(row);

    return 0;
}
