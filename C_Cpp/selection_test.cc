#include <vector>
#include <iostream>
#include "selection.h"

void print_vec(const std::vector<int> & vec) {
    for (auto elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> test_input = {1, 5, 3, 4, 6, 7 ,9, 12};
    std::cout << *quickselect(test_input, 3) << std::endl;
    print_vec(test_input);
}
