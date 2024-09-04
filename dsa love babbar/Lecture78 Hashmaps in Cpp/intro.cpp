/*
hashmaps are data structures
    ->> time complexity of insertion and deletion and search is O(1)
    ->> we can not implement hashmaps using linked list as for linked list time complexity of insertion deletion is O(n) similarly for BST time complecities are O(log n) they can't be used
    ->> so we will use hash tables where time complextities are O(1)
    ->> each key corresponds to 1 value

    ->> for unordered map time complexity = O(1) constant time  ->> order is not preserved
    ->> for map time complexity = O(log n) ->> order is preserved in map
*/

#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{

        // creation
        unordered_map<string, int> m;

        // insertion

        // 1
        pair<string, int> p = make_pair("babbar", 3);
        m.insert(p);

        // 2
        pair<string, int> pair2("love", 2);
        m.insert(pair2);

        // 3
        m["mera"] = 1;
        // what will happen ->> pehli bar insert karte ho to creation hoti hai uske baad mein sirf updation hoga
        // har ek key ke corresponding ek hi entry hogi
        m["mera"] = 2;

        // search
        cout << m["mera"] << endl;
        cout << m.at("babbar") << endl;

        // cout<< m.at("unknownKey") << endl; // ye error dega kyunki nayi value nahi bana sakta
        cout << m["unknownKey"] << endl;    // ye nayi entry banata hai with value 0
        cout << m.at("unknownKey") << endl; // now it will print 0 as new entry is created by previous line

        // size
        cout << m.size() << endl;

        // to check presence
        // absent -> 0 and present -> 1
        cout << m.count("bro") << endl;
        cout << m.count("babbar") << endl;

        // erase
        m.erase("love");
        cout << m.size() << endl;

        for (auto i : m)
        {
                cout << i.first << " " << i.second << endl;
        }

        // iterator
        unordered_map<string, int>::iterator it = m.begin();

        while (it != m.end())
        {
                cout << it->first << " " << it->second << endl;
                it++;
        }

        return 0;
}