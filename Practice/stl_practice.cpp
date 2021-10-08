#include<iostream>
#include<set>
using namespace std;

void printStatus(set<int>& s) {
    for(int i : s) cout<<i<<" ";
    cout<<endl;
}

int main() {
    set<int> intSet;

    intSet.insert(1);
    intSet.insert(3);
    intSet.insert(5);
    intSet.insert(4);
    intSet.insert(2);

    intSet.insert(2);

    /// current status: { 1, 2, 3, 4, 5 }
    printStatus(intSet);

//    cout<<"Normal itarator"<<endl;
//    /// begin() -> returns iterator to first element
//    cout<<"First Element: "<<*intSet.begin()<<endl;
//    /// end() -> returns iterator to the next position of last element
//    cout<<"Last element: "<<*(--intSet.end())<<endl;
////
//    cout<<"Reverse iterator"<<endl;
//    /// rbegin()
//    cout<<"Last element: "<<*intSet.rbegin()<<endl;
//    /// rend()
//    cout<<"First Element: "<<*(--intSet.rend())<<endl;

//    cout<<"Other common member functions"<<endl;
//    /// size() -> returns size of set
//    cout<<"Current Size: "<<intSet.size()<<endl;
//    /// max_size() -> returns maximum capacity
//    cout<<"Max size: "<<intSet.max_size()<<endl;
//    /// empty() -> returns if the set is empty
//    cout<<"isEmpty: "<<intSet.empty()<<endl;

    intSet.erase(intSet.find(3));
    printStatus(intSet);
    cout<<"Lower Bound: "<<*intSet.lower_bound(3)<<endl;
    cout<<"Upper Bound: "<<*intSet.upper_bound(3)<<endl;
//
    cout<<"Count: "<<intSet.count(4)<<endl;
    cout<<"Count: "<<intSet.count(3)<<endl;

    intSet.clear();
    cout<<"After clear isEmpty: "<<intSet.empty()<<endl;
}
