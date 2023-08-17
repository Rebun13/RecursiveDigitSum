#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING n
 *  2. INTEGER k
 */

int superDigitAlt(string n, int k) {
    string kn = "";
    for(int i = 0; i < k; i++) {
        kn += n;
    }
    while(kn.size() > 1) {
        long res = 0;
        for(int i = 0; i < kn.size(); i++) {
            res += kn[i] - '0';
        }
        kn = to_string(res);
    }
    return stoi(kn);
}

int superDigit(string n, int k) {
    while(n.size() > 1) {
        long res = 0;
        for(int i = 0; i < n.size(); i++) {
            res += n[i] - '0';
        }
        n = to_string(res  * k);
        k = 1;
    }
    return stoi(n);
}

int main()
{
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    string n = first_multiple_input[0];

    int k = stoi(first_multiple_input[1]);

    int result = superDigit(n, k);

    cout << result << endl;

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), [](unsigned char c) { return !ispunct(c); })
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), [](unsigned char c) { return !ispunct(c); }).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
