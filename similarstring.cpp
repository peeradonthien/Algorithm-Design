#include <iostream>
#include <vector>
using namespace std;
bool divide(int start1 , int start2 ,int len,string word1,string word2){
    if(len == 1){
        return word1[start1] == word2[start2];
    }
    if(len == 2){//ab ba    ab ab
        if(word1[start1]==word2[start2] && word1[start1+1]==word2[start2+1]) return true;
        if(word1[start1]==word2[start2+1] && word1[start1+1]==word2[start2]) return true;
        return false;
    }
    int m = len/2;
    if(divide(start1,start2,m,word1,word2) && divide(start1+m,start2+m,m,word1,word2)) return true;
    if(divide(start1+m,start2,m,word1,word2) && divide(start1,start2+m,m,word1,word2)) return true;
    return false;
}
int main(){
    string word1,word2;
    cin >> word1 >> word2;
    if(divide(0,0,word1.size(),word1,word2)){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
}