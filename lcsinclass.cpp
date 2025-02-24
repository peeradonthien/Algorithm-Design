#include <iostream>
#include <vector>
using namespace std;

vector<char> LCS(vector<char> a , vector<char> b){
    if(a.size() == 0 || b.size() == 0){
        return vector<char>();
    }
    if(a[a.size()-1] == b[b.size()-1]){
        vector<char> result = LCS(vector<char>(a.begin(),a.end()-1) , vector<char>(b.begin(),b.end()-1));
        result.push_back(a[a.size()-1]);
        return result;
    }
    vector<char> r1,r2;
    r1 = LCS(vector<char>(a.begin(),a.end()-1),vector<char>(b.begin(),b.end()));
    r2 = LCS(vector<char>(a.begin(),a.end()),vector<char>(b.begin(),b.end()-1));
    if(r1.size() > r2.size()) return r1;
    else return r2;
} 
int main(){
    
}

