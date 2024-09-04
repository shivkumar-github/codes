/*

*/

#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

// we need maps to create key value pairs
// hash tables perform insertion, deletion, and searching in constant time complexity O(n)

int main()
{
        // in unordered map elements are inserted in random order
        // in ordered map elements are printed in the order they were inserted

        // creation
        unordered_map<string, int> m;

        // insertion

        // 1
        pair<string, int> p = make_pair("babbar", 2);
        m.insert(p);

        // 2
        pair<string, int> pair2("love", 2);
        m.insert(pair2);

        // 3
        m["mera"] = 1;

        // updation will happen
        m["mera"] = 3;

        // searching
        cout << m["mera"] << endl;
        cout << m.at("babbar") << endl;
        // cout<< m.at("unknown_key") << endl;
        cout << m["unknown_key"] << endl;
        cout << m.at("unknown_key") << endl;

        // size
        cout << m.size() << endl;

        // count
        // absent - 0
        // present - count
        m.count("love");

        // erase
        m.erase("love");
        cout << m.size() << endl;

        for (auto i : m)
        {
                cout << i.first << i.second << endl;
        }

        unordered_map<string, int>::iterator it = m.begin();

        while (it != m.end())
        {
                cout << it->first << " " << it->second << endl;
                it++;
        }
        return 0;
}

/*
 maps -> why -> O(1) for insertion deletion and searching

bucket array - storage

Hash functions
1. hash code - converstion to int - uniform distribution
2. compression function - it brings the int from hash code in the range

Collisions : -
two different values get same key after processing through hash code & compression function
-> Open hashing - separate chaining
-> Closed addressing

-> Closed addressing  - next vacant position
Hi(a) = h(a) + fi(a)
i th attempt
        -> there are different types of probing
        -> linear probing
         f(i) = i
        -> quadratic probing
        f(i) = i^2


-> Complexity Analysis :-
        -> Insertion
        assumption n >> k which makes T.C. O(k)

        -> Traverse -> O(n) --> O(1)

        n - no of entries in map
        b - no of boxes avalaible

        load factor = n/b and we always keep it <0.7

         if n keeps increasing we also have to increase the number of boxes to decrease the load factor by using rehashing by increasing no of boxes



*/