#include <iostream>

int main(void){
    int x = 321;
    int r = 0;
    for (; x; x/=10){
        r = r * 10 + x % 10;
    }
    std::cout << r << std::endl;
    return 0;
}
