#include <stdio.h>
#include <fstream>
#include <string>
using namespace std;
int
main() {
    int sum = 0;
    ifstream f("input.txt");
    if (f.is_open())
    {
        string l;
        while (getline(f, l))
        {
            // approach from left to right, then right to left
            // set a to the first int found * 10
            // set b to the last int found
            int a = -1;
            int b = -1;
            int i = 0;
            while (a == -1) {
                char c = l[i];
                if (c >= 48 && c <= 57) {
                    a = ((c - '0') * 10);
                }
                ++i;
            }
            i = l.size() - 1;
            while (b == -1) {
                char c = l[i];
                if (c >= 48 && c <= 57) {
                    b = (c - '0');
                }
                --i;
            }
            sum += (a + b);
        }
    }
    printf("sum: %d\n", sum);
    
    return 0;
}