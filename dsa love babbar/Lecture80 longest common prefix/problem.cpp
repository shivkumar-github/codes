/*

*/

#include <iostream>
#include <vector>
using namespace std;

class TrieNode
{
public:
        char data;
        TrieNode *children[26];
        bool isTerminal;
        TrieNode(char ch)
        {
                data = ch;
                for (int i = 0; i < 26; i++)
                {
                        children[i] = NULL;
                }
                isTerminal = false;
        }
};

class Trie
{
public:
        TrieNode *root;
        Trie()
        {
                root = new TrieNode('\0');
        }
        void insertUtil(TrieNode *root, string word)
        {
                if (!word.length())
                        return;
                int index = word[0] - 'a'; // assuming upper case letters
                if (!root->children[index])
                {
                        root->children[index] = new TrieNode(word[0]);
                }
                insertUtil(root->children[index], word.substr(1));
        }
        void insert(string word)
        {
                insertUtil(root, word);
        }
};

class Solution
{
public:
        // approach 1 without using trie
        //     string longestCommonPrefix(vector<string>& strs) {
        //         int len = strs.size();
        //         string ans = "";
        //         bool inAll = true;
        //         // complaring with the first word
        //         for(int i = 0; i < strs[0].length();i++)
        //         {
        //             char ch = strs[0][i];
        //             for( int j = 1 ; j < len ; j++){
        //                 if(ch != strs[j][i] || i > strs[j].length()){
        //                     inAll = false;
        //                     break;
        //                 }
        //             }
        //             if(inAll){
        //                 ans.push_back(ch);
        //             }
        //             else {
        //                 break;
        //             }
        //         }
        //         return ans;
        //     }
        //     // time complexity = O(m*n) where m is length of first word and n is no of words
        //     // space complexity = O(1)

        string longestCommonPrefix(vector<string> &strs)
        {
                // approach first insert the words in the trie and till child count for node is 1 it is common prefix
                Trie *t = new Trie(); // DOUBT: why to dynamically access memory
                for (int i = 0; i < strs.size(); i++)
                {
                        t->insert(strs[i]);
                }
                string ans = "";
                bool isSinglechild = true;
                TrieNode *temp = t->root;
                while (isSinglechild)
                {
                        TrieNode *child;
                        int cnt = 0;
                        for (int i = 0; i < 26; i++)
                        {
                                if (temp->children[i])
                                {
                                        child = temp->children[i];
                                        cnt++;
                                }
                        }
                        ans.push_back(temp->data);
                        if (cnt != 1)
                        {
                                isSinglechild = false;
                                break;
                        }
                        else
                        {
                                temp = child;
                        }
                }
                return ans;
        }
        // time complexity O(m*n)
        // space complexity O(m*n)  not efficient
};

int main()
{
        vector<string> strs = {"shivkumar", "shivling", "shivanjali", "shubhada"};
        Solution s;
        string ans = s.longestCommonPrefix(strs);
        cout << ans << endl;

        return 0;
}