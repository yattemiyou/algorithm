#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    while (true)
    {
        cout << "> " << ends;

        string line;
        getline(cin, line);

        stringstream ss(line);
        string command;

        ss >> command;

        if (command == "quit")
        {
            break;
        }
    }

    return 0;
}
