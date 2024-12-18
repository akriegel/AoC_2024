/* Day 1 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <tuple>
#include <list>

using namespace std;
using Ints = list<int>;
using IntsRef = list<int>&;
using TupInts = tuple<Ints, Ints>;

// Initialize a tuple containing two empty lists of ints
TupInts tups_new() {
    Ints list0;
    Ints list1;
    return make_tuple(list0, list1);
}

int find_ind(int n, Ints xs) {
    int idx = 0;
    for (auto it = xs.begin(); it != xs.end(); it++) {
        if (n < *it) {
            return idx;
        }
        idx++;
    }
    return idx;
}

// Insert two ints into a TupInts such that the lists are sorted
TupInts tups_insert(TupInts tups, int n, int m) {
    IntsRef list0 = get<0>(tups);
    IntsRef list1 = get<1>(tups);
    int i = find_ind(n, list0);
    int j = find_ind(m, list1);
    list0.insert(next(list0.begin(), i), n);
    list1.insert(next(list1.begin(), j), m);
    return tups;
}

int count_diffs(TupInts tups) {
    IntsRef list0 = get<0>(tups);
    IntsRef list1 = get<1>(tups);
    auto idx0 = list0.begin();
    auto idx1 = list1.begin();
    int result = 0;
    while(idx0 != list0.end()) {
        result += abs(*idx0 - *idx1);
        idx0 = next(idx0);
        idx1 = next(idx1);
    }
    return result;
}

int similarity_score(TupInts tups) {
    IntsRef list0 = get<0>(tups);
    IntsRef list1 = get<1>(tups);
    auto idx0 = list0.begin();
    auto idx1 = list1.begin();
    int n, ns, ms;
    int result = 0;
    while(idx0 != list0.end()) {
        n = *idx0;
        ms = 0;
        while(idx1 != list1.end() && *idx1 < n) {
            idx1 = next(idx1);
        }
        while(idx1 != list1.end() && *idx1 == n) {
            ms++;
            idx1 = next(idx1);
        }
        ns = 0;
        while (idx0 != list0.end() && *idx0 == n) {
            ns++;
            idx0 = next(idx0);
        }
        result += (n * ns * ms);
    }
    return result;
}

int main() {
    ifstream file("input.txt");
    string line;

    TupInts tups = tups_new();
    int n, m;
    while (getline(file, line)) {
        stringstream ss(line);
        ss >> n >> m;
        tups = tups_insert(tups, n, m);
    }

    int diff = count_diffs(tups);
    int sim = similarity_score(tups);

    printf("Difference = %d\nSimilarity = %d\n", diff, sim);
    file.close();

    return 0;
}