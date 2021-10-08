#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

//bool cmp(const int &a, const int &b){
//    return a<b;
//}

int main() {
    int arr[25];
    set<int> st;
    vector<int> v(50);
    int j=0;

    for(int i=1; i<=50; i++) {
        if(i%2==0) {
            arr[j++] = i;
        }
        else
            st.insert(i);
    }


    merge(st.begin(), st.end(), arr, arr+j, v.begin());
    for(auto a: v) cout<<a<<" ";

    return 0;
}
