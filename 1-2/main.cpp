#include <stdio.h>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

pair<int,int> parseNum(const string &myString,
                       const int &index)
{
    pair<int, int> rv;
    switch (myString[index])
    {
    case 'o':
        if (myString[index + 1] == 'n' && myString[index + 2] == 'e' && ((index + 2) < myString.size()))
        {
            rv.first = 1;
            rv.second = 3;
        }
        break;
    case 't':
        if (myString[index + 1] == 'w' && myString[index + 2] == 'o' && ((index + 2) < myString.size()))
        {
            rv.first = 2;
            rv.second = 3;
        }
        else if (myString[index + 1] == 'h' && myString[index + 2] == 'r' && myString[index + 3] == 'e' && myString[index + 4] == 'e' && ((index + 4) < myString.size()))
        {
            rv.first = 3;
            rv.second = 5;
        }
        break;
    case 'f':
        if (myString[index + 1] == 'o' && myString[index + 2] == 'u' && myString[index + 3] == 'r' && ((index + 3) < myString.size()))
        {
            rv.first = 4;
            rv.second = 4;
        }
        else if (myString[index + 1] == 'i' && myString[index + 2] == 'v' && myString[index + 3] == 'e' && ((index + 3) < myString.size()))
        {
            rv.first = 5;
            rv.second = 4;
        }
        break;
    case 's':
        if (myString[index + 1] == 'i' && myString[index + 2] == 'x' && ((index + 2) < myString.size()))
        {
            rv.first = 6;
            rv.second = 3;
        }
        else if (myString[index + 1] == 'e' && myString[index + 2] == 'v' && myString[index + 3] == 'e' && myString[index + 4] == 'n' && ((index + 4) < myString.size()))
        {
            rv.first = 7;
            rv.second = 5;
        }
        break;
    case 'e':
        if (myString[index + 1] == 'i' && myString[index + 2] == 'g' && myString[index + 3] == 'h' && myString[index + 4] == 't' && ((index + 4) < myString.size()))
        {
            rv.first = 8;
            rv.second = 5;
        }
        break;
    case 'n':
        if (myString[index + 1] == 'i' && myString[index + 2] == 'n' && myString[index + 3] == 'e' && ((index + 3) < myString.size()))
        {
            rv.first = 9;
            rv.second = 4;
        }
        break;
    }

    return rv;
}

int main()
{
    int sum = 0;
    ifstream f("input.txt");
    if (f.is_open())
    {
        string l;
        while (getline(f, l))
        {
            // parse string left to right
            // if a number is found, push it to a vector
            // once all of the string is parsed, add (a * 10) + (b)
            vector<int> numbers;

            int i = 0;
            while (i < l.size()) {
                char c = l[i];
                if (c >= 48 && c <= 57) {
                    numbers.push_back(c - '0');
                    ++i;
                } else {
                    pair<int, int> parsednum = parseNum(l, i);
                    if (parsednum.first) {
                        numbers.push_back(parsednum.first);
                        i += (parsednum.second - 1);
                    } else {
                        ++i;
                    }
                }
            }
            sum += ((numbers.front() * 10) + numbers.back());
            
        }
    }
    printf("sum: %d\n", sum);

    return 0;
}