#include <bits/stdc++.h>
using namespace std;

// Function to generate prime numbers using Sieve Of Atkin
void get_primes(vector<int> &primes)
{
    int x = primes.size();

    // Calculate all the prime numbers using following conditions
    for (int i = 1 ; i * i < x ; i++)
    {
            for (int j = 1 ; j * j < x; j++)
    
        {
                    int temp = (4 * i * i) + (j * j);
                    if (temp <= x && (temp % 12 == 1 || temp % 12 == 5))
        
            {
                            primes[temp] ^= 1;
                       
            }
                    temp = (3 * i * i) + (j * j);
                    if (temp <= x && temp % 12 == 7)
        
            {
                            primes[temp] ^= 1;
                       
            }
                    temp = (3 * i * i) - (j * j);
                    if (i > j && temp <= x && temp % 12 == 11)
        
            {
                            primes[temp] ^= 1;
                       
            }
               
        }
    }
    // 1 is neither prime nor composite
     primes[1] = 0;
    // 2 and 3 both are prime numbers
     primes[2] = 1;
     primes[3] = 1;
    // All multiples of squares are non-prime
    for (int i = 5 ; i * i < x ; i++)
    {
             if (primes[i] == 1)
     
        {
                     for (int j = i * i; j < x ; j += i * i)
         
            {
                             primes[j] = 0;
                        
            }
                
        }
    }
    return;
}

// Function to accumulate all primes and non-prime numbers on left and right side of the 'input' vector respectively
void get_Result(vector<int> &input, int n)
{
      // Generate all primes
   vector<int> primes(1000005, 0);
      get_primes(primes);

      // Vector to store all the prime numbers
   vector<int> main_primes;

      // Vector to store all the non-prime numbers
   vector<int> main_non_primes;

      // Store all the prime and non-prime elements from 'input' vector separately
   for (int i = 0 ; i < n ; i++)
  
    {
              if (primes[input[i]] == 1)
      
        {
                      main_primes.push_back(input[i]);
                 
        }
              else      
        {
                      main_non_primes.push_back(input[i]);
                 
        }
         
    }

      // Store all prime numbers on left side of the 'input' vector
   int i = 0;
      while (i < main_primes.size())
  
    {
              input[i] = main_primes[i];
              i++;
         
    }

      // Store all non-prime numbers on right side of the 'input' vector
   int j = 0;
      while (j < main_non_primes.size())
  
    {
              input[i] = main_non_primes[j];
              i++;
              j++;
         
    }
      return;
}

// Driver code
int main()
{
      vector<int> input = { 20, 13, 41, 5, 1, 2, 9, 19, 14 };
      int n = input.size();

      cout << "Input Array:- ";
      for (int i = 0 ; i < n ; i++)
  
    {
              cout << input[i] << ", ";
         
    }
      cout << endl;

      cout << "Array after segregation of primes and non-prime: ";
      get_Result(input, n);
      for (int i = 0 ; i < n ; i++)
  
    {
              cout << input[i] << ", ";
         
    }
      cout << endl;
      return 0;
}