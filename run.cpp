#include <bits/stdc++.h>
using namespace std;
bool zhushi, inchar, inlongzhushi;
char path[255];
long long length, siz;
char check[] = {' ', '\n', ')', '(', '{', '}', ':', '=', '|', '<', '>', '^', '*', '/', '+', '-', '&', ',', '?', '!', '%', ';'};
inline bool in(char x)
{
    for (int i = 0; i < strlen(check); i++)
        if (check[i] == x)
            return true;
    return false;
}
inline bool getys(string tip)
{
    char get;
    cout << tip << "(Y/n):";
    cin >> get;
    if (get == 'Y' || get == 'y')
        return true;
    else if (get == 'N' || get == 'n')
        return false;
    else
    {
        cout << "wrong input,please try again\n";
        return getys(tip);
    }
}
int main()
{
    register char be, now, nt;
    cout << "Welcome to use auto-full by pigeonteam\nhttps://github.com/ymj3/\nThis is version 2.2\nclick here to learn more(暂无)\nAdd support for\"\"\n";
    if (!getys("Would you like to use ./in.cpp as stdin"))
    {
        cout << "Please press in the location:";
        cin >> path;
    }
    else
    {
        stringstream ss;
        ss << "./in.cpp";
        ss >> path;
    }
    cout << "press 0 to get the min file\nPlease press in the max size of zhe file(KB):";
    cin >> siz;
    siz <<= 10;
    freopen(path, "r", stdin);
    freopen("./output.cpp", "w", stdout);
    char h;
    length = 3;
    int line = 0;
    string read;
    while (getline(cin, read))
    {
        zhushi = false;
        int i = read.length();
        h = read[0];
        for (int j = 0; j < i; j++)
        {
            if (j < i - 1)
                nt = read[j + 1];
            else
                nt = 0;
            now = read[j];
            if (now == '\"' && be != '\\')
                inchar = !inchar;
            if (!inchar && !inlongzhushi)
            {
                if (now == '\\' && nt == 0)
                {
                    be == '\\';
                    break;
                }
                if (now == '/' && nt == '/')
                {
                    zhushi = true;
                    break;
                }
                if (now == '/' && nt == '*')
                {
                    inlongzhushi = true;
                    break;
                }
                if ((in(be) || in(nt)) && now == ' ')
                    ;
                else
                {
                    length++;
                    putchar(now);
                }
            }
            else if (inchar)
            {
                length++;
                putchar(now);
            }
            else
            {
                if (now == '/' && be == '*')
                    inlongzhushi = false;
            }
            be = now;
        }
        now = '\n';
        if (h != '#' && (in(be) || zhushi || inlongzhushi))
            ;
        else
        {
            putchar(now);
            length += 2;
        }
        be = now;
    }
    if (length >= siz - 2)
        return 0;
    long long x;
    srand(time(0));
    x = rand() % 127;
    putchar('/');
    putchar('/');
    while (length <= siz)
    {
        if (x < 32)
            x += 33;
        putchar(x);
        x = ((((x * 998244353 + rand()) % 1000000007 + (long long)clock())) % 19198103 + (long long)clock()) % 127;
        length++;
    }
    return 0;
}
