#include <bits/stdc++.h>
using namespace std;
  int getSum(int a,int b){

    return 1;
  }

  //right answer acccording to dry run
   //undertstading the dry run here is the key for intuition
    int getSum(int a, int b) {
        while(b){
            int carry=(a&b)<<1;
            a=(a^b);
            b=carry;
        }
        return a;
    }
  double int_to_binary(int a){
        double answer=0;
        double power=1;
        while(a){
            double rem=a%2;
            answer+=rem*power;
            a/=2;
            power*=10;
        }
        return answer;
    }
//bits manipluation sikhna pdenga for this

    double int_to_binary(int a){
        double answer=0;
        double power=1;
        while(a){
            int rem=a%2;
            answer+=rem*power;
            a/=2;
            power*=10;
        }
        return answer;
    }
    int getSum(int a, int b) {
        int ans=0;
        int carry=0;
        while(b){
            ans=a^b;
            carry=a&b;
            carry=carry<<1;
            a=ans;
            b=carry;
        }
        return a;
    }
int main(){
    cout<<int_to_binary(10)<<endl;
    cout<<int_to_binary(500)<<endl;
    cout<<int_to_binary(15)<<endl;
}
