// DicesProbability.cpp : Defines the entry point for the console application.
//

// 《剑指Offer——名企面试官精讲典型编程题》代码
// 著作权所有者：何海涛

#include <stdio.h>
#include <math.h>
#include <sys/types.h>

int g_maxValue = 6;
 
// ====================方法一====================
void Probability(int number, int* pProbabilities);
void Probability(int original, int current, int sum, int* pProbabilities);

void PrintProbability_Solution1(int number)
{
    if(number < 1)
        return;
 
    int maxSum = number * g_maxValue;
    int* pProbabilities = new int[maxSum - number + 1];
    for(int i = number; i <= maxSum; ++i)
        pProbabilities[i - number] = 0;
 
    Probability(number, pProbabilities);
 
    double sum = 0;
    int total = pow((double)g_maxValue, number);
    for(int i = number; i <= maxSum; ++i)
    {
        double ratio = (double)pProbabilities[i - number] / total;
        sum += ratio;
        printf("%d: %e\n", i, ratio);
       // printf("%d: %e, sum: %e, total:%d\n", i, ratio, sum, total);
    }
 
    delete[] pProbabilities;
}
 
void Probability(int number, int* pProbabilities)
{
    for(int i = 1; i <= g_maxValue; ++i)
        Probability(number, number, i, pProbabilities);
}
 
void Probability(int original, int current, int sum, 
                 int* pProbabilities)
{
    //printf("original:%d, current: %d, sum: %d\n", original, current, sum);
    if(current == 1)
    {
        pProbabilities[sum - original]++;
    }
    else
    {
        for(int i = 1; i <= g_maxValue; ++i)
        {
            Probability(original, current - 1, i + sum, pProbabilities);
        }
    }
} 

// ====================方法二====================
void PrintProbability_Solution2(int number)
{
    if(number < 1)
        return;

    int* pProbabilities[2];
    pProbabilities[0] = new int[g_maxValue * number + 1];
    pProbabilities[1] = new int[g_maxValue * number + 1];
    for(int i = 0; i < g_maxValue * number + 1; ++i)
    {
        pProbabilities[0][i] = 0;
        pProbabilities[1][i] = 0;
    }
 
    int flag = 0;
    for (int i = 1; i <= g_maxValue; ++i) 
        pProbabilities[flag][i] = 1; 
    
    for (int k = 2; k <= number; ++k) 
    {
        for(int i = 0; i < k; ++i)
            pProbabilities[1 - flag][i] = 0;

        for (int i = k; i <= g_maxValue * k; ++i) 
        {
            pProbabilities[1 - flag][i] = 0;
            for(int j = 1; j <= i && j <= g_maxValue; ++j) 
            {
                pProbabilities[1 - flag][i] += pProbabilities[flag][i - j];
                //printf("k:%d, i: %d, j: %d, flag: %d, p[%d][%d]: %d, p[%d][%d]: %d\n"
                //        , k, i, j, flag, 1 - flag, i, pProbabilities[1 - flag][i], flag, i - j, pProbabilities[flag][i - j]);
            }
        }
 
        flag = 1 - flag;
    }
 
    double total = pow((double)g_maxValue, number);
    for(int i = number; i <= g_maxValue * number; ++i)
    {
        double ratio = (double)pProbabilities[flag][i] / total;
        printf("%d: %e\n", i, ratio);
    }
 
    delete[] pProbabilities[0];
    delete[] pProbabilities[1];
}

// ====================测试代码====================
void Test(int n)
{
    printf("Test for %d begins:\n", n);
    
    printf("Test for solution1\n");
    PrintProbability_Solution1(n);

    printf("Test for solution2\n");
    PrintProbability_Solution2(n);

    printf("\n");
}

int main(int argc, char* argv[])
{
    int total = pow(4, 2);
    int64_t minint = (int64_t)( ~((unsigned long long)-1) / 2);
    int64_t maxint = (int64_t)(((unsigned long long)-1 ) / 2);
    printf("total: %d, minint: %lld, maxint: %lld\n", total, minint, maxint);
    
    /*Test(1);
    Test(2);
    Test(3);
    Test(4);*/
    
    //Test(11);

    Test(0);

    return 0;
}

