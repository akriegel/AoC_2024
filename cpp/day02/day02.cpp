#include <list>
#include <sstream>
#include <string>
using namespace std;
using Ints = list<int>;

Ints parseInput(string line) {
    stringstream ss(line);
    Ints input;
    int n;
    while (ss >> n) {
        input.push_back(n);
    }
    return input;
}

bool part1(Ints ns) {
    if (ns.size() < 2) {
        return true;
    }
    auto idx = ns.begin();
    int n0 = *idx++;
    int n1 = *idx;
    int diff;
    int minDiff = 1;
    int maxDiff = 3;
    int incr = (n1 - n0) > 0 ? 1 : -1;
    for (; idx != ns.end(); idx++) {
        diff = incr * (*idx - *prev(idx));
        if (minDiff <= diff && diff <= maxDiff) {
            continue;
        }
        return false;
    }
    return true;
}

Ints removeElement(Ints list, int position) {
    list.erase(next(list.begin(), position));
    return list;
}

bool part2(Ints ns) {
    for (auto idx = ns.begin(); idx != ns.end(); idx++) {
        if (part1(removeElement(ns, distance(ns.begin(), idx)))) {
            return true;
        }
    }
    return false;
}