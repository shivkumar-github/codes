// https://leetcode.com/problems/copy-list-with-random-pointer/submissions/
#include <unordered_map>
#include <iostream>

using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

void insertAtEnd(Node *&head, int data)
{
    Node *nNode = new Node(data);
    if (!head)
        head = nNode;
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = nNode;
}

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head) // if head is NULL (if head->next is null then that case is automatically hanlded by code)
            return head;
        unordered_map<Node *, int> nodeso; // map to store node and corresponding index of that node in old ll so that we can use to set random pointers later in new ll
        unordered_map<int, Node *> nodesn; // map to store index and corresponding node at that index (same to set random pointers)

        Node *hdt = head;               // temp for head
        Node *nhd = new Node(hdt->val); // new head
        Node *nhdt = nhd;               // temp for new head
        nodeso.insert({hdt, 0});
        nodesn.insert({0, nhdt}); // inserting both in respective map
        // update hdt only as we need old nhdt to add new node in new ll
        hdt = hdt->next;
        int pos = 1; // to keep track of position of nodes
        while (hdt)
        {
            nodeso.insert({hdt, pos});
            Node *nNode = new Node(hdt->val); // create new copy node
            nhdt->next = nNode;               // adjust pointer
            nhdt = nhdt->next;                // move further
            nodesn.insert({pos, nhdt});       // after moving to newly created node add it's pos and node to map for new ll
            pos++;                            // update pos
            hdt = hdt->next;                  // updation
        }
        // linked list is constructed now we have to set random pointers
        hdt = head;
        nhdt = nhd;
        while (hdt)
        {
            if (hdt->random)
            { // if random pointer exists
                int index = nodeso[hdt->random];
                nhdt->random = nodesn[index]; // findin random pointer through index of node in old ll
            }
            // updation
            hdt = hdt->next;
            nhdt = nhdt->next;
        }
        // return ans
        return nhd;
    } // time complexity = O(n)
    // space complexity = O(n)
    // we can also do same method by storing mp<orignal node, dupicate node> and when pointing random pointer in new ll we will do
    // clonenode->random = mapping[orignal node->random];

    // approach 2 by using single map (pointing old nodes to new nodes)
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return head;
        unordered_map<Node *, Node *> oldnew;
        Node *hdt = head->next;
        Node *nhd = new Node(head->val);
        oldnew.insert({head, nhd});
        Node *nhdt = nhd;
        while (nhdt && hdt)
        {
            Node *nNode = new Node(hdt->val);
            nhdt->next = nNode;
            nhdt = nhdt->next;
            oldnew.insert({hdt, nhdt});
            hdt = hdt->next;
        }

        // linked list is constructed now have to point random pointers
        hdt = head;
        nhdt = nhd;
        while (hdt)
        {
            nhdt->random = oldnew[hdt->random];
            nhdt = nhdt->next;
            hdt = hdt->next;
        }
        return nhd;
    }

    // approach 3 in constant space
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return head;

        Node *hdt = head->next;               // temp for head
        Node *nhd = new Node(head->val); // new head
        Node *nhdt = nhd;               // temp for new head
        while (hdt)
        {
            Node *nNode = new Node(hdt->val); // create new copy node
            nhdt->next = nNode;               // adjust pointer
            nhdt = nhdt->next;                // move further
            hdt = hdt->next;                  // updation
        }
        // step1 : linked list is constructed now we have to set random pointers
        hdt = head;
        nhdt = nhd;
        Node *n1, *n2;
        while (nhdt && hdt)
        {
            n1 = hdt->next;
            hdt->next = nhdt;
            hdt = n1;
            
            n2 = nhdt->next;
            nhdt->next = n1;
            nhdt = n2;
        }
        // step 2 : zig zag linkage is created
        hdt = head;
        nhdt = nhd;
        while (hdt && nhdt)
        {
            if(!hdt->random)
                nhdt->random = NULL;
            else
                nhdt->random = hdt->random->next;
            hdt = hdt->next->next;
            if(nhdt->next)// for last case
            nhdt = nhdt->next->next;
        }
        // step 3: readjusting next pointers
        hdt = head;
        nhdt = nhd;
        while (hdt && nhdt)
        {
            hdt->next = nhdt->next;
            if(nhdt->next)
                nhdt->next = nhdt->next->next;
            hdt = hdt->next;
            nhdt = nhdt->next;
        }
        // now the next pointers are restored
        return nhd;
    } // constant space and O(n) time complexity
};

int main()
{
    Node *head = NULL;
    insertAtEnd(head, )
}