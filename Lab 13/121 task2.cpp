#include <iostream>

int i=0;
float f=0.5f;

namespace my_namespace {
    int i=56;
    float f = 5.6625f;

    void my_func() {
        std::cout<<"\nInside my_namespace\n"<<i<<std::endl<<f<<std::endl;
    }

}

int main() {
    my_namespace::my_func();
    std::cout<<"\nOutside my_namespace\n"<<i<<std::endl<<f<<std::endl;
}
