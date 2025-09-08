#include <bits/stdc++.h>
using namespace std;
#define lil long long int 

bool perfect_no(lil x){
       x++;
       lil prod=1;
       for(lil i=0;i<18;i++){
           if(x/prod==0) break;
           prod*=2;
      }
      lil rem=x%(prod/2);
      if(rem==0) return true;
      return false;
   }