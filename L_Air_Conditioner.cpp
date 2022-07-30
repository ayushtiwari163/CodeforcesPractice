// C++ program to Add two numbers represented by Stacks
#include <bits/stdc++.h>
using namespace std;


// Function to calculate the sum of two numbers. Answer will be stored in stack
stack<int> addStack(stack<int> N1, stack<int> N2)
{
  stack<int> res;
  int sum = 0, rem = 0;


  while (!N1.empty() and !N2.empty()) {

    // Calculate the sum of the top elements of both the stacks
    sum = (rem + N1.top() + N2.top());
   // Push the sum into the stack
   res.push(sum % 10);
   // Store the carry
   rem = sum / 10;
   // Pop the top elements
   N1.pop();
   N2.pop();
  }


  // If N1 is not empty
  while (!N1.empty()) {
    sum = (rem + N1.top());
    res.push(sum % 10);
    rem = sum / 10;
    N1.pop();
  }
  // If N2 is not empty
  while (!N2.empty()) {
    sum = (rem + N2.top());
    res.push(sum % 10);
    rem = sum / 10;
    N2.pop();
  }

  // If carry remains
  while (rem > 0) {
    res.push(rem);
     rem /= 10;
  }


    // Reverse the stack.so that most significant digit is at the bottom of the stack
   while (!res.empty()) {
     N1.push(res.top());
      res.pop();
   }
   res = N1;
  return res;
}


// Function to display the resultant stack
void display(stack<int>& res)
{
   int N = res.size();
    string s = "";
   while (!res.empty()) {
   s = to_string(res.top()) + s;
   res.pop();
}

  cout << s << endl;
}



int main()
{
   stack<int> N1;
   N1.push(5);
   N1.push(8);
   N1.push(7);
   N1.push(4);


   stack<int> N2;
   N2.push(2);
   N2.push(1);
   N2.push(3);
   stack<int> res = addStack(N1, N2);
   display(res);
   return 0;
}