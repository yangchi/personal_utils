#include <string>
#include <vector>
#include <iostream>

using namespace std;

/**
 * table[i] represents max length of proper prefix and proper postfix in pattern[0, ..., i - 1] that match.
 */
void buildTable(const string & pattern, vector<int> & table) {
    if (table.size() < 2) {
        return; //I actually don't know what to do
    }

    table[0] = -1; table[1] = 0;
    int index = 2, candidate = 0;
    while (index < pattern.size()) {
        if (pattern[index - 1] == pattern[candidate]) {
            table[index++] = ++candidate;
        } else if (candidate > 0) {
            candidate = table[candidate];
        } else {
            table[index++] = 0;
        }
    }
}

int KMP(const string & text, const string & pattern) {
    vector<int> lookback(pattern.size(), -1);
    buildTable(pattern, lookback);

    int match_start_ind = 0, pat_ind = 0;
    while (match_start_ind + pat_ind < text.size()) {
        if (pattern[pat_ind] == text[match_start_ind + pat_ind]) {
            if (pat_ind == pattern.size() - 1) {
                return match_start_ind;
            }
            pat_ind++;
        } else {
            if (lookback[pat_ind] > -1) {
                match_start_ind += pat_ind - lookback[pat_ind];
                pat_ind = lookback[pat_ind];
            } else {
                pat_ind = 0; match_start_ind++;
            }
        }
    }

    return -1;
}

int main() {
    cout << KMP("ABC ABCDAB ABCDABCDABDE", "ABCDABD") << endl;
}
