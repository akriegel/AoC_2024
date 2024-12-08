/* Day 02 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include "day02.hpp"

using namespace std;

int main() {
    ifstream file("input.txt");
    string line;

    int result1 = 0;
    int result2 = 0;
    list<int> ns;
    int lineCount = 0;

    while (getline(file, line)) {
        cout << "Processing line " << ++lineCount << ": " << line << endl;
        ns = parseInput(line);
        cout << "List size: " << ns.size() << endl;

        if (part1(ns)) {
            result1++;
        }
        if (part2(ns)) {
            result2++;
        }
    }

    printf("Part 1 = %d\nPart 2 = %d\n", result1, result2);
    file.close();

    return 0;
}