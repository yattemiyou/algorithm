#include <iostream>
#include <string>
#include <memory>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        return 1;
    }

    int n = stoi(argv[1]);

    // 終端文字のために＋１
    unique_ptr<char[]> flags(new char[n + 1]());

    // １は素数ではないため
    flags[0] = '-';

    int count = 0;

    for (int i = 2; i <= n; i++)
    {
        if (flags[i - 1] == '-')
        {
            continue;
        }

        flags[i - 1] = '*';
        count++;

        for (int j = i * 2; j <= n; j += i)
        {
            flags[j - 1] = '-';
        }
    }

    cout << n << "までの素数の数：" << count << endl;
    cout << flags.get() << endl;

    return 0;
}
