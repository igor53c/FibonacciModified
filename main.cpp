#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

const int MAX_LENGHT = 512;

string addString(string x, string y)
{
    string retValue;

    int rest = 0;
    int result = 0;

    for(int i = x.length() - 1; i >= 0 ; i--)
    {
        result = stoi(x.substr(i, 1)) + stoi(y.substr(i, 1)) + rest;

        if(result > 9)
        {
            rest = 1;
            result -= 10;
        }
        else
            rest = 0;

        retValue = to_string(result) + retValue;
    }

    retValue = string(MAX_LENGHT - retValue.length(), '0') + retValue;

    return retValue;
}

string mulString(string x, string y)
{
    string retValue(MAX_LENGHT, '0');
    int result = 0;
    int rest = 0;

    for(int i = y.length() - 1; i >= 0; i--)
    {
        string temp;

        if(y.substr(i, 1) != "0")
        {
            for(int j = x.length() - 1; j >= 0; j--)
            {
                result = stoi(x.substr(j, 1)) * stoi(y.substr(i, 1)) + rest;

                if(result > 9)
                {
                    rest = result / 10;
                    result -= 10 * rest;
                }
                else
                    rest = 0;

                temp = to_string(result) + temp;
            }

            temp = temp.erase(0, y.length() - 1 - i) + string(y.length() - 1 - i, '0');
            temp = string(MAX_LENGHT - temp.length(), '0') + temp;

            retValue = i == y.length() - 1 ? temp : addString(retValue, temp);
        }
    }

    return retValue;
}

string fibonacciModified(string t1, string t2, int n)
{
    t1 = string(MAX_LENGHT - t1.length(), '0') + t1;

    t2 = string(MAX_LENGHT - t2.length(), '0') + t2;

    string retValue = addString(t1, mulString(t2, t2));

    if(n > 3)
        retValue = fibonacciModified(t2, retValue, n - 1);

    return retValue;
}

int main()
{
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    string t1 = first_multiple_input[0];

    string t2 = first_multiple_input[1];

    int n = stoi(first_multiple_input[2]);

    string result = fibonacciModified(t1, t2, n);

    while(result[0] == '0')
        result.erase(0, 1);

    cout << result << endl;

    return EXIT_SUCCESS;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
            );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
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
