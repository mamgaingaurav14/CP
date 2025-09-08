#include <bits/stdc++.h>
using namespace std;

//  double averageWaitingTime(vector<vector<int>>& customers) {

//isme yeh bhi sochna tha ki chef wait krega agar
//cutumer late ata hai to aur customer wait krega 
//agar vo jaldi ata hai to 
    
       double averageWaitingTime(vector<vector<int>>& customers) {
        double current_time=customers[0][0];
        double total_time=0;
        double total_customers=customers.size();
        for(vector<int> custumber:customers){
         double av1=0;
        if(current_time>=custumber[0]){
           av1=current_time-custumber[0];
        } 
        else{
           current_time=custumber[0];
        }
         av1+=custumber[1];
         current_time+=custumber[1];
         total_time+=av1;
    }
    double ans=total_time/total_customers;
    return ans;
    }
    
int main(){

}