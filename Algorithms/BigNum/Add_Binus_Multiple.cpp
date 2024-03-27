#include <bits/stdc++.h>
using namespace std;

// Convert char to int
int Int(char c) {
    return c - '0';
}

// Convert int to char
char Char(int x) {
    return x + '0';
}

//  Add two numbers
string Sum(string a, string b)
{
    string ans = "";
    while(a.length() < b.length()) a = "0" + a;
    while(b.length() < a.length()) b = "0" + b;
    int nho = 0;
    for(int i = a.length() - 1; i >= 0; --i) {
        int cur = a[i] - '0' + b[i] - '0' + nho;
        ans = to_string(cur % 10) + ans;
        nho = cur / 10;
    }
    if(nho) ans = to_string(nho) + ans;
    return ans;
}

// Subtract two numbers
string Binus(string a, string b) {
    string ans = "";
    string sign = "";
    if (a.length() < b.length() || (a.length() == b.length() && a < b)) {
        sign = "-";
        swap(a, b);
    }
    while(a.length() < b.length()) a = "0" + a;
    while(b.length() < a.length()) b = "0" + b;
    int nho = 0;
    
    for(int i = a.length() - 1; i >= 0; --i) {
        int digitA = Int(a[i]);
        int digitB = Int(b[i]) + nho;
        if (digitA < digitB) {
            digitA += 10;
            nho = 1;
        }
        else 
            nho = 0;
        int diff = digitA - digitB;
        ans = to_string(diff) + ans;
    }
    int i = 0;
    while(ans[i] == '0') i++;
    if(i == ans.length()) ans = "0";        
    else ans = ans.substr(i);
    return (sign + ans);
}

// Multiplication number with one
string Multiplication_OneNumber(string a, char b) {
    string ans = "";
    int nho = 0;
    for (int i = a.length() - 1; i >= 0; --i) {
        int cur = Int(a[i]) * Int(b) + nho;
        ans = to_string(cur % 10) + ans;
        nho = cur / 10;
    }
    if(nho) ans = to_string(nho) + ans;
    return ans;
}

// Multiplication two numbers
string Multiplication(string a, string b) {
    string ans = "0";
    for (int i = b.length() - 1; i >= 0; --i) {
        string temp = Multiplication_OneNumber(a, b[i]);
        for (int j = 0; j < b.length() - i - 1; ++j)
            temp += "0";
        // printf("%d * %s = %s\n", Int(b[i]), a.c_str(), temp.c_str());
        ans = Sum(ans, temp);
    }
    return ans;
}

int main()
{
    string a, b;
    cin >> a >> b;
    cout << Sum(a, b) << endl;
    cout << Binus(a, b) << endl;
    // cout << Multiplication_OneNumber(a, '2') << endl;
    cout << Multiplication(a, b) << endl;
    return 0;
}