  #include <bits/stdc++.h>
using namespace std;



//first recursive soltion tle mar gya 
//alag baat hai but still good work 

class Solution {
public:
     int solve(vector<vector<int>>& books,int index,int max_height,int width_consumed ,int shelfWidth,int height){
        int n=books.size();
        if(index==n) return height + max_height;
        //ya nahi lena hai 
        //level up karke daldo 
        int a=INT_MAX;
        if(index!=0) a=solve(books,index+1,books[index][1],books[index][0],shelfWidth, height + max_height);
        //lena hai 
        //check kro ki width limits ke andar and index plus
        int temp=max_height>books[index][1]?max_height:books[index][1];
        int b=INT_MAX;
        if(width_consumed+books[index][0]<=shelfWidth) b=solve(books,index+1,temp,width_consumed+books[index][0],shelfWidth, height );
        return min(a,b);
     }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
       int n=books.size();
       return solve(books,0,0,0,shelfWidth,0);
    }
};
int main(){
    return 0;
}