#include <iostream>
const double epsilon = 0.0000000001;

int summ(int a, int b)
{
    return a + b;
}
double fabs(double num)
{
    if ((num-epsilon)>0)  return num; 
    else return -num;
}
void print(char S, int N)
{
    for (int i = 0; i < N; i++)
    {
        std::cout << S;
    }
}
bool isCharachter(char c)
{
    if (c >= 65 && c <= 122) return true;
    else return false;
}
bool isCapitalLetter(char c)
{
    if (isCharachter(c) == 1)
    {
        if (c >= 65 && c <= 90) return true;
        else return false;
    }
    
}
char toLower(char c)
{
    if (isCharachter(c) == 1) 
    {
        if (c >= 65 && c <= 90)  return c + 32;
        else  return c;
    }
}

char toUpper(char c)
{
    if (isCharachter(c) == 1)
    {
        if (c >= 97 && c <= 122)  return c - 32;
        else  return c;
    }
}

int Length(int num)
{
    int c = 0;
    do
    {
        c++;
        num /= 10;
    } while (num!=0);
    return c;

}

int KtaCifra(int n, int k)
{
    int temp = 0;

  int nesh = Length(n) - k;

    for (int i = 0; i < nesh; i++)
    {
        
      n /= 10;
    }
    temp = n % 10;
    return temp;
}

bool isTochen(int num)
{
   
    for (int i = 2; i <= num/2; i++)
    {
        if (num / i == i && num %i==0) return true;
        else continue;
    }
    return false;
}

int ObshtKratno(int a,int b , int c)
{

}
int main()
{
    int a = 6, b = 7;
    
    std::cout << fabs(-4.5)<<std::endl;
    std::cout << summ(a,b)<<std::endl;
    print('*', 5); std::cout << std::endl;

    std::cout << isCapitalLetter('L') << std::endl;
    std::cout << toLower('A') << std::endl;
    std::cout << toUpper('A') << std::endl;
   // std::cout << Length(12345) << std::endl;
    std::cout << KtaCifra(78952,2) << std::endl;
 // std::cout << sortedNumber(12345);//54321
    std::cout << isTochen(17)<<  std::endl;

}

