// Java program to find mean and median of an unsorted array
import java.util.*;

Class CN
{
// Function for calculating mean
    public static double Mean(int a[], int n)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += a[i];
        return (double)sum / (double)n;
    }

// Function for calculating median
    public static double Median(int a[], int n)     
    {
    // First we sort the array
        Arrays.sort(a);
        if (n % 2 != 0)
            return (double)a[n / 2];        //for even
        return (double)(a[(n - 1) / 2] + a[n / 2]) / 2.0; //for odd
    }

// Driver code
    public static void main(String args[])
    {
        int a[] = { 2, 3, 4, 1, 7, 5, 8, 6 };
        int n = a.length;
    // Function call
        System.out.println("Mean: " + Mean(a, n));
        System.out.println("Median: " + Median(a, n));
    }
}