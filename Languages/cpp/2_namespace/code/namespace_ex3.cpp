#include <iostream>
using namespace std;
namespace AAA{
        int n=1;
        namespace BBB{
                int n=2;
                namespace CCC{
                        int n=3;
                }
        }
}

int main(void){
        int val=200;

        cout<<"AAA : "<<AAA::n<<endl;
        cout<<"BBB : "<<AAA::BBB::n<<endl;
        cout<<"CCC : "<<AAA::BBB::CCC::n<<endl;

        namespace All=AAA::BBB::CCC;
        namespace All2=AAA::BBB;

        cout<<"All  : "<<All::n<<endl;
        cout<<"All2 : "<<All2::n<<endl;
}
