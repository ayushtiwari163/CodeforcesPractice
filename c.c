#include <stdio.h>
int fact(int num)
{
    int mul = 1;
    for (int i = 1; i <= num; i++)
    {
        mul = mul * i;
    }
    return mul;
}
int findSumofFactorials(int n)
{
    int sum = 0;
    while (n > 0)
    {
        // find each digit
        int temp = n % 10;
        // add factorial of each digit to the variable sum
        sum += fact(temp);
        n = n / 10;
    }
    return sum;
}
int main()
{
    int n = 145;

    // Find the sum of factorial of each digit
    int sum = findSumofFactorials(n);

    /* If the sum is equal to the original number,
    then the number is a strong number */
    if (sum == n)
        printf("%d is a Strong Number!", n);

    /* If the sum is not equal to the original number,
    then the number is not a strong number */
    else
        printf("%d is not a Strong Number!", n);

    return 0;
}
