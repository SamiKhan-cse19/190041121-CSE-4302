#include<iostream>
using namespace std;

int main() {
    std::pair<int,int> p(50, 50);

    uint64_t val = 0x4163554941410000;
    for (int j = 8; j > 0; j--) {
			for (int i = 8; i > 0; i--) {
				bool color = val & (1LL << (8 * (j - 1) + i -1));
				if (color) cout<<1;
				else cout<<" ";
			}
			cout<<endl;
		}
}

