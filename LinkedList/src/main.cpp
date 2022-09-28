#include <iostream>
#include <sstream>

#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList list;

    while (true)
    {
        string command;
        int index;
        int value;

        cout << "> " << ends;

        string line;
        getline(cin, line);

        stringstream ss(line);

        ss >> command;

        if (command == "quit")
        {
            break;
        }
        else if (command == "add")
        {
            ss >> value;
            list.add(value);
            list.printForwardOrder();
        }
        else if (command == "insert")
        {
            ss >> index;
            ss >> value;
            list.insert(index, value);
            list.printForwardOrder();
        }
        else if (command == "remove")
        {
            ss >> index;
            list.remove(index);
            list.printForwardOrder();
        }
        else if (command == "sort")
        {
            list.sort();
            list.printForwardOrder();
        }
        else if (command == "clear")
        {
            list.clear();
        }
        else if (command == "printf")
        {
            list.printForwardOrder();
        }
        else if (command == "printr")
        {
            list.printReverseOrder();
        }
    }

    return 0;
}
