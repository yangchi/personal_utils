#include <cstring>
#include <sstream>

#include "string_ops.h"

std::vector<std::string> tokenizer_C (std::string input, std::string delimiters)
{
    if (input.empty()) {
        return std::vector<std::string>();
    }
    if (delimiters.empty()) {
        return std::vector<std::string>({input});
    }

    std::vector<std::string> result;
    char *input_c = new char[input.size()];
    char *delimiters_c = new char[delimiters.size()];

    strncpy(input_c, input.c_str(), input.size());
    strncpy(delimiters_c, delimiters.c_str(), delimiters.size());

    char *token = strtok(input_c, delimiters_c);
    while(token) {
        result.push_back(token);
        token = strtok(NULL, delimiters_c);
    }

    return result;
}

std::vector<std::string> tokenizer_find (std::string input, std::string delimiters)
{
    if (input.empty()) {
        return std::vector<std::string>();
    }

    if (delimiters.empty()) {
        return std::vector<std::string>({input});
    }

    std::vector<std::string> result;
    size_t first_non_delimiter_index = input.find_first_not_of(delimiters, 0);
    if (first_non_delimiter_index == std::string::npos) {
        /* everything is a delimiter */
        return result;
    }

    size_t next_delimiter_index = input.find_first_of(delimiters, first_non_delimiter_index);
    while (next_delimiter_index != std::string::npos) {
        result.push_back(input.substr(first_non_delimiter_index, next_delimiter_index - first_non_delimiter_index));
        first_non_delimiter_index = input.find_first_not_of(delimiters, next_delimiter_index);
        if (first_non_delimiter_index == std::string::npos) {
            break;
        }
        next_delimiter_index = input.find_first_of(delimiters, first_non_delimiter_index);
    }

    result.push_back(input.substr(first_non_delimiter_index));

    return result;
}

std::vector<std::string> tokenizer_ss (std::string input, char delimiter)
{
    std::istringstream ss(input);
    std::string temp;
    std::vector<std::string> result;
    while (std::getline(ss, temp, delimiter)) {
        if (!temp.empty()) {
            result.push_back(temp);
        }
    }
    return result;
}
