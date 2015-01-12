#include <string>
#include <vector>
#include <iostream>
#include "string_ops.h"


/*
 * corner cases:
 *  empty input
 *  empty delimiter
 *  everything in input is a delimiter
 *  everything in input is NOT a delimiter
 */

void print_vec(const std::vector<std::string> & vec)
{
    std::cout << "result: ";
    for(auto elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

void test_tokenizer_find ()
{
    std::string input1 = "nor.mal;.inputnoth.Special";
    std::string delimiters = ".;";
    std::vector<std::string> result_vec = tokenizer_find(input1, delimiters);
    print_vec(result_vec);
    print_vec(tokenizer_find("", "some"));
    print_vec(tokenizer_find("something", ""));
    print_vec(tokenizer_find("some\%thing", ",.?"));
    print_vec(tokenizer_find("something", "thingsome"));

}

void test_tokenizer_C ()
{
    std::string input1 = "nor.mal;.inputnoth.Special";
    std::string delimiters = ".;";
    std::vector<std::string> result_vec = tokenizer_C(input1, delimiters);
    print_vec(result_vec);
    print_vec(tokenizer_C("", "some"));
    print_vec(tokenizer_C("something", ""));
    print_vec(tokenizer_C("some\%thing", ",.?"));
    print_vec(tokenizer_C("something", "thingsome"));

}

void test_tokenizer_ss ()
{
    print_vec(tokenizer_ss("some thing", ' '));
    print_vec(tokenizer_ss("!@#$some", 's'));
    print_vec(tokenizer_ss("", '\0'));
    print_vec(tokenizer_ss("", 'a'));
    print_vec(tokenizer_ss("something", '\0'));
    print_vec(tokenizer_ss("aaa", 'a'));
    print_vec(tokenizer_ss("bbb", 'a'));
}

int main()
{
    test_tokenizer_C();
    std::cout << std::endl;
    test_tokenizer_find();
    std::cout << std::endl;
    test_tokenizer_ss();
}
