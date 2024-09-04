/*

*/

#include <iostream>
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

// assumption, word will be in CAPS
class Trie
{
public:
        TrieNode *root;

        Trie()
        {
                root = new TrieNode('\0'); // inserting null character initially
        }

        void insertUtil(TrieNode *root, string word) // TODO: why not &
        {
                // base case
                if (!word.length()) // word.length() == 0
                {
                        root->isTerminal = true;
                        return;
                }

                int index = word[0] - 'A';
                TrieNode *child;
                // absent
                if(!root->children[index])
                {
                        root->children[index] = new TrieNode(word[0]);
                }

                // recursion
                insertUtil(root->children[index], word.substr(1)); // extract a portion of a string by specifying a starting position and the length of the substring.
                // the copy of children[index] will be passed to next recursive call and changes will be made to the object pointed by the copy pointer i.e. orignal object  and copy of pointer will be deleted then
        } // time complexity - O(length of word)

        void insertWord(string word)
        {
                insertUtil(root, word);
        }

        bool searchUtil(TrieNode *root, string word)
        {

                // base case
                if (word.length() == 0)
                {
                        return root->isTerminal;
                }

                int index = word[0] - 'A';
                TrieNode *child;
                // present
                if (root->children[index])
                {
                        child = root->children[index];
                }
                // absent
                else
                {
                        return false;
                }
                // recursion
                return searchUtil(child, word.substr(1));
        } // time complexity - O(length of word)
        bool searchWord(string word)
        {
                return searchUtil(root, word);
        }
        bool isEmpty()
        {
                for (int i = 0; i < 26; i++)
                        if (root->children[i])
                                return false;
                return true;
        }
        void removeWordByIsTerminal(string word)
        {
                TrieNode *temp = root;
                while (word.length() != 0)
                {
                        int index = word[0] - 'A';
                        temp = temp->children[index];
                        word = word.substr(1);
                }
                temp->isTerminal = false;
        }
        void removeWordCompletely(string word)
        {
                int index = word[0] - 'A';
                root->children[index] = NULL;
        }
};

int main()
{
        Trie *t = new Trie();
        t->insertWord("ABCD");
        t->insertWord("TIME");
        // t->insertWord("DO");
        cout << t->searchWord("ABCD") << endl;
        cout << t->searchWord("TIM") << endl;
        cout << t->searchWord("DO") << endl;
        cout << t->searchWord("TIME") << endl;
        // t->removeWord("TIME");
        cout << t->searchWord("TIME") << endl;
        
        return 0;
}
