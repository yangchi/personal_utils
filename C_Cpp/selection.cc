#include "selection.h"
#include <cstdlib>
#include <ctime>

void swap(viiter first, viiter second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

viiter
partition(std::vector<int> & input, viiter begin, viiter end, viiter pivot_iter) {
    if (begin == end) {
        return end;
    }

    if (pivot_iter >= end || pivot_iter < begin) {
        return end;
    }

    int pivot_value = *pivot_iter;
    swap(end - 1, pivot_iter);
    auto write_iter = begin;
    for(auto iter = begin; iter != end - 1; iter++) {
        if (*iter < pivot_value) {
            swap(iter, write_iter);
            write_iter++;
        }
    }

    swap(end - 1, write_iter);
    return write_iter;
}

viiter
quickselect(std::vector<int> & input, size_t k, viiter begin, viiter end) {
    if (begin == end || end - begin < k) {
        return end;
    }

    viiter pivot = begin;
    std::srand(std::time(NULL));
    pivot = begin + std::rand() % (end - begin);

    pivot = partition(input, begin, end, pivot);
    if (pivot - begin == k - 1) {
        return pivot;
    } else if (pivot - begin < k - 1) {
        return quickselect(input, k -  1 - (pivot - begin), pivot + 1, end);
    } else {
        return quickselect(input, k, begin, pivot);
    }
}

viiter 
quickselect(std::vector<int> & input, size_t k) {
    if (input.size() < k) {
        return input.end();
    }

    return quickselect(input, k, input.begin(), input.end());
}


