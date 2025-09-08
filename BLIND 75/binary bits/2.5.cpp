#include <bits/stdc++.h>
using namespace std;
//learnin how to convery int to bits first 
string toBinary(uint32_t number) {
    // Use bitset to convert the integer to a binary string of 32 bits
    bitset<32> converter(number);
    return converter.to_string();
}

//lerning how to convert string to number then
int binaryToNumber(const string& binaryString) {
    // Use bitset to convert the binary string to a bitset of 32 bits
    bitset<32> binary(binaryString);
    // Convert the bitset to an unsigned long and then to an int
    return static_cast<int>(binary.to_ulong());
}

//learing how to reverese a string 
   string revereseString(string given){
        int i=0;
        int j=given.size()-1;
        while(i<j){
            swap(given[i++],given[j--]);
        }
        return given;
    }
int main() {
    uint32_t number = 964176192;
    string binaryString = toBinary(number);
    cout << "The 32-bit binary representation of " << number << " is " << binaryString << std::endl;
    cout<<binaryToNumber(binaryString)<<endl;

    cout<<revereseString("12345");
    return 0;
}


//answer used 
//intituition is using understanding converting bits 
//to string and string to bits
uint32_t BinarytoNumber(string &binaryString){
        bitset<32> converter(binaryString);
        return static_cast<uint32_t> (converter.to_ulong());
    }
    string NotoBinary(uint32_t number){
        bitset<32> converter(number);
        return converter.to_string();
    }
    string revereseString(string given){
        int i=0;
        int j=given.size()-1;
        while(i<j){
            swap(given[i++],given[j--]);
        }
        return given;
    }
    uint32_t reverseBits(uint32_t n) {
        string given=NotoBinary(n);
        string reverse=revereseString(given);
        return BinarytoNumber(reverse);
    }


//method2 correct from solution
//directky using bitset object 
 uint32_t reverseBits(uint32_t n) {
        bitset<32> given(n);
        int i=0;
        int j=given.size()-1;
        while(i<j){
            int temp=given[i];
            given[i++]=given[j];
            given[j--]=temp;
            // will not work hereswap(given[i++],given[j--]);
        } 
        return given.to_ulong();
    }
    //swap doesnt work for bitset object

   // binary.to_ulong(); learn these 2 functions 
   // binary.to_string();

   //method 3 using bit manipulation intuitive 
//keep on taking the last bit and adding it to 0 number 
//then right shifting and left shifting accordingly 
      uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0;
        for(int i=0;i<32;i++){
            if(n&1) ans=(ans|1);
           if(i!=31) ans<<=1;
            n>>=1;
        }
        //if(n&1) ans=(ans|1);
        return ans;
    }