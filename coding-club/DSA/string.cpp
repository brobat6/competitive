#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < n; i++)

int main()
{
    ios_base::sync_with_stdio(false);
    string s;
    while (cin >> s)
    {
        int n = s.length();
        char arr[n];
        forn(i, n) arr[i] = s[i];
        stack<string> start;
        string middle;
        queue<string> end;
        // Find MIDDLE
        forn(i, n)
        {
            if (arr[i] != '[' && arr[i] != ']')
                middle += arr[i];
            else
                break;
        }
        // Find START
        int i = 0;
        while (i < n)
        {
            if (arr[i] == '[')
            {
                string temp;
                i++;
                while (i < n && arr[i] != ']' && arr[i] != '[')
                {
                    temp += arr[i];
                    i++;
                }
                start.push(temp);
            }
            else
            {
                i++;
            }
        }
        // Find END
        i = 0;
        while (i < n)
        {
            if (arr[i] == ']')
            {
                string temp;
                i++;
                while (i < n && arr[i] != '[' && arr[i] != ']')
                {
                    temp += arr[i];
                    i++;
                }
                end.push(temp);
            }
            else
            {
                i++;
            }
        }
        while (!start.empty())
        {
            cout << start.top();
            start.pop();
        }
        cout << middle;
        while (!end.empty())
        {
            cout << end.front();
            end.pop();
        }
        cout << endl;
    }
}