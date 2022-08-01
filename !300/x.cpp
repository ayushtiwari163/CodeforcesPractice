#include<iostream>
using namespace std;
class Car{
    int groundclearence; 
    public:
    int length;
    Car(){
        groundclearence=180;            // Line 1
        length=3500;
    }
  void setValue(int w, int l){
    groundclearence=w;
    length=l;
  }
};
int main(){
  Car Safari;
  Safari.groundclearence = 200;         // Line 2        
  Safari.setValue(200,4660);          // Line 3 
  return 0;
}