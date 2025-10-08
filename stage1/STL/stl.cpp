#include <bits/stdc++.h>
using namespace std;

/* 
STL (vector, map, set, unordered_map, pair, tuple, algorithms) 

Ví dụ: dùng vector, map, unordered_map, set, pair, tuple và algorithm
*/

int main() {
    // vectorr 
    vector<int> v = {3, 2, 5, 3 ,6};
    sort(v.begin(), v.end()); // sort ascending
    cout << "sorted vector: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    sort(v.rbegin(), v.rend()); // sort descending
    cout << "sorted vector (desc): ";   
    for (int x : v) cout << x << " ";
    cout << endl;

    // custom sort (descending)
    sort(v.begin(), v.end(), greater<int>());
    cout << "sorted vector (desc custom): ";
    for (int x : v) cout << x << " ";
    cout << endl;

    // map (ordered map)
    map<string, int> freq;
    vector<string> words = {"apple", "banana", "apple", "orange", "banana", "apple"};
    for (auto &w : words) freq[w]++;
    cout << "word frequencies (map):" << endl;
    for (auto &p : freq) {
        cout << p.first << " -> " << p.second << endl;
    };

    //unordered_map (hash map) - faster for large data
    unordered_map<string, int> ufreq;
    for (auto &w : words) ufreq[w]++;
    cout << "word frequencies (unordered_map):" << endl;
    cout << "unordered_map size: " << ufreq.size() << endl; 
    for (auto &p : ufreq) {
        cout << p.first << " -> " << p.second << endl;
    }

    // set 
    set<int> s = {5, 3, 8, 5, 2, 3};
    cout << "set elements (unique & sorted): ";
    for (int x : s) cout << x << " ";
    cout << endl;

    //pair and tuple 
    pair<int, string> p = {1, "one"};
    cout << "pair: " << p.first << " - " << p.second << endl;
    tuple<int, string, double> t = {2, "two", 2.5};
    cout << "tuple: " << get<0>(t) << " - " << get<1>(t) << " - " << get<2>(t) << endl;

    //find, accumulate, transform
    auto it = find(v.begin(), v.end(), 5); // from <algorithm>
    cout << *it << endl;
    cout << "find 5 in vector: " << (it != v.end() ? "found" : "not found") << endl;
    
    // accumulate: sum of elements
    int sum = accumulate(v.begin(), v.end(), 0); // from <numeric>
    cout << "sum of vector elements: " << sum << endl;

    // transform: square each element
    vector<int> sq(v.size());
    transform(v.begin(), v.end(), sq.begin(), [](int x){return x * x;});
    cout << "squared elements: ";
    for (int x:sq) cout << x << " ";
    cout << endl;
}

