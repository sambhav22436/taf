#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void classify_digits(const string &s, vector<int> &odd_digits, vector<int> &even_digits) {
    for (char c : s) {
        int digit = c - '0';
        if (digit & 1)
            odd_digits.push_back(digit);
        else
            even_digits.push_back(digit);
    }
}

string merge_digits(const vector<int> &odd_digits, const vector<int> &even_digits) {
    size_t odd_index = 0, even_index = 0;
    string result = "";

    while (odd_index < odd_digits.size() && even_index < even_digits.size()) {
        if (odd_digits[odd_index] < even_digits[even_index])
            result += (char)(odd_digits[odd_index++] + '0');
        else
            result += (char)(even_digits[even_index++] + '0');
    }

    while (odd_index < odd_digits.size())
        result += (char)(odd_digits[odd_index++] + '0');

    while (even_index < even_digits.size())
        result += (char)(even_digits[even_index++] + '0');

    result.erase(0, result.find_first_not_of('0'));

    return result;
}

string format_result(const string &original, const string &merged) {
    string leading_zeros(original.size() - merged.size(), '0');
    return leading_zeros + merged;
}

void process_test_case(int test_case) {
    string input_string;
    cin >> input_string;

    vector<int> odd_digits;
    vector<int> even_digits;

    classify_digits(input_string, odd_digits, even_digits);
    string merged_digits = merge_digits(odd_digits, even_digits);
    string final_result = format_result(input_string, merged_digits);

    cout << final_result << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        process_test_case(i);
    }

    return 0;
}