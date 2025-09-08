#include <bits/stdc++.h>
using namespace std;

//best time to buy and sell stocks

//method 1 
//brutal brute force
//exceeds time limit by margin but tle anyways
    int maximum(vector<int>& arr,int j){
      int ans=INT_MIN;
      for(int i=j;i<arr.size();i++){
        if(ans<arr[i]) ans=arr[i];
      }
      return ans;
    }
    //i need the highest element after this element
    int maxProfit(vector<int>& prices) {
      int maxi=0;
      for(int i=0;i<prices.size()-1;i++){
       int this_time=maximum(prices,i+1)-prices[i];
        if(maxi<this_time) maxi=this_time;
      }
      return maxi;
    }

//method 2
//again good attempt but failed since
/*
copy.erase(remove(copy.begin(), copy.end(), value_to_remove), copy.end());
in this statment the item will be removed all copied 
if mulitple copies exist
*/
   int maxProfit(vector<int>& prices) {
        vector<int> copy=prices;
        sort(copy.begin(),copy.end());
        int maxi=0;
        for(int i=0;i<prices.size()-1;i++){
            if(copy.back()!=prices[i]){
              int diff=copy.back()-prices[i];
            if(maxi<diff) maxi=diff;
            }
    copy.erase(remove(copy.begin(), copy.end(), prices[i]), copy.end());
        }
        return maxi;
    }
//Method 3
//this algo also known as kadane algo
int maxProfit(vector<int>& prices) {
        int n=prices.size();
         int maxi=0;
         int min_price=prices[0];
        for(int i=1;i<n;i++){
               maxi=max((prices[i]-min_price),maxi);
               min_price=min(prices[i],min_price);
            
        }
        return maxi;
    }

//METHOD 4
/*
exactly ulta kardiya method 3 ko but method sexc hai
aap isme min track karte chal rhe ho a
nd jis price pr ho usi ko maximum maan rhe ho 
     //nice approACH*/
  int maxProfit(vector<int>& prices) {
        int maxi=0;
        int n=prices.size()-1;
        int max_price=prices[n];
        for(int i=n;i>=0;i--){
            maxi=max((max_price -prices[i]),maxi);
            max_price=max(prices[i],max_price);
        }
    }
int main(){

}
