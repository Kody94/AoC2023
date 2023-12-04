#include <stdio.h>
#include <fstream>
#include <string>
using namespace std;
const int MAX_BLUE = 14;
const int MAX_GREEN = 13;
const int MAX_RED = 12;
int main()
{
    int sum = 0;
    ifstream f("input.txt");
    if (f.is_open())
    {
        string line;
        while (getline(f, line))
        {
            bool bLegalCount = true;
            // get game ID
            int gameId = line[5] - '0';

            // split string by ;
            string input = line.substr(line.find(":") + 2, line.size() - 1);
            string outerDelimiter = ";";
            size_t outerPos = 0;
            string outerToken;
            while ((outerPos = input.find(outerDelimiter)) != string::npos && bLegalCount) {
                outerToken = input.substr(0, outerPos);
                printf("outerToken: %s\n", outerToken.c_str());
                input.erase(0, outerPos + outerDelimiter.length());

            }
            // for each group, parse red, blue, green
            // if each color less than or equal to max, add game id to sum
        }
    }
    printf("sum: %d\n", sum);

    return 0;
}