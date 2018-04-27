#include <iostream>

using namespace std;

class Int
    {
  private :
        int x = 5 ;
        int y = 7 ;
  public :
    int sum ;
    void sumvalue (int x ,int y)
    {sum = x + y ;}
    void showsum (){
    cout << "the sum is :" << sum << endl ;}
    };

int main()
{
    Int sum1 ;
    sum1.showsum ();
    return 0;
}
