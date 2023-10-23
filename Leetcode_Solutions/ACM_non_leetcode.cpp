#include <iostream>
#include <cstring>

using namespace std;

bool check(char A, char C, char M){
    if (A == 'A' && C == 'C' && M == 'M'){
        return true;
    }
    return false;
}

void AcmCheck(string s){
    int len = s.length();
    if (len%3 != 0){
        cout << "NO" << endl;
        return;
    }
    int ptr = 0;
    int unmatch_ptr = -1;
    while (ptr < len){
        if (ptr+2 < len && check(s[ptr], s[ptr+1], s[ptr+2])){
            ptr = ptr + 3;
        }
        else if (unmatch_ptr >= 0 && ptr+1 < len && check(s[unmatch_ptr], s[ptr], s[ptr+1])){
            unmatch_ptr--;
            ptr = ptr+2;
        }
        else if (unmatch_ptr >= 1 && check(s[unmatch_ptr-1], s[unmatch_ptr], s[ptr])){
            unmatch_ptr = unmatch_ptr - 2;
            ptr++;
        }
        else{
            unmatch_ptr++;
            ptr++;
        }
    }
    // cout << unmatch_ptr << endl;
    if (unmatch_ptr >= 0){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
    }
    return;
}


int main(){
    string test[] = {"ACM","AMC","A","AACMCM","AAAACMCMCMCM","ACMACMAC","ACMACMACMACCM","ACACMACMACMM","ACM"};
    for (int i = 0; i < sizeof(test)/sizeof(test[0]); i++){
        AcmCheck(test[i]);
    }
    return 0;
}