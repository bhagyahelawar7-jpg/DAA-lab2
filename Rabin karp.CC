#include <iostream>
#include <string>
using namespace std;

void rabinKarp(string text, string pattern) {
    int d = 256;
    int q = 101;
    int m = pattern.length();
    int n = text.length();
    int p = 0, t = 0, h = 1;

    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    for (int i = 0; i <= n - m; i++) {
        if (p == t) {
            if (text.substr(i, m) == pattern)
                cout << "Pattern found at index " << i << endl;
        }

        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0)
                t += q;
        }
    }
}

int main() {
    string text = "GEEKS FOR GEEKS";
    string pattern = "GEEK";

    rabinKarp(text, pattern);
    return 0;
}