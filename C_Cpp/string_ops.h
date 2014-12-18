#include <vector>
#include <string>

/*
 * A string tokenizer backed by C std lib strtok function
 */
std::vector<std::string> tokenizer_C(std::string input, std::string delimiters);

/*
 * A string tokenizer backed by string member methods find()
 */
std::vector<std::string> tokenizer_find (std::string input, std::string delimiters);

/*
 * A string tokenizer backed by stringstream class
 */
std::vector<std::string> tokenizer_ss (std::string input, char delimiter);

