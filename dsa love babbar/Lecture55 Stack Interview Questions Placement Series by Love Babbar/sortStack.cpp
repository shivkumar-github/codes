#include <iostream>
#include <stack>
using namespace std;
// https://www.geeksforgeeks.org/problems/sort-a-stack/1

/*The structure of the class is*/
class SortedStack
{
public:
	stack<int> s;
	void sort();
};

/* The below method sorts the stack s
you are required to complete the below method */

/*
METHOD : 1
Approach - Pop out two elements and add them in the sorted order, before adding them back to stack first do the same process for remaining stack using recursion(process should be done on every two elements in the stack) and then push them.

Do execute this process for n time ( of stack) and alternately change the pair which will be taken out (by pulling out an element when i iterator is odd in the main function) and if only 1 element is remaining at last keep as it is.
(in first(i==0) we swapped indices top,top-1 and top-2,top-3 and .. so on in second we pull out top so that we can swap between pairs top-1,top-2 and top-3,top-4)
*/
// void solve(stack<int>&st){
//     if(st.empty()){
//         return;
//     }
//     int el1 = st.top();
//     st.pop();
//     if(st.empty()){ // if stack has only one element left then leave as it is
//         st.push(el1);
//         return;
//     }
//     int el2 = st.top();
//     st.pop();
//     solve(st);
// 	// pushing them in order
//     if(el1>=el2){
//         st.push(el2);
//         st.push(el1);
//     }
//     else{
//         st.push(el1);
//         st.push(el2);
//     }
// }
// void SortedStack :: sort()
// {
// 	// for more view the image stack sort explanation
//    //Your code here
//    for(int i = 0; i < s.size();i++){
//         if(i%2){// change the swapping indices pairs
//             int el = s.top();
//             s.pop();
//             solve(s);
//             s.push(el);
//         }
//         else{
//             solve(s);
//         }
//    }// space complextity = O(n)
// //    time complexity = O(n*n)
// }

// METHOD : 2
// approach 2 placing each smallest element in every iteration
// void insertOneMini(stack<int> &st, int &mini, int itrs, int &minicnt)
// {
// 	if (itrs == 0)
// 	{
// 		while (minicnt--) // for duplicate elemnts
// 			st.push(mini);
// 		return;
// 	}
// 	int el = st.top();
// 	st.pop();
// 	if (el < mini) // if any element is smaller than min then adjust mincnt and change mini
// 	{
// 		mini = el;
// 		minicnt = 1;
// 	}
// 	else if (el == mini)
// 	{
// 		minicnt++; // if element is equal then increase minicnt
// 	}
// 	insertOneMini(st, mini, itrs - 1, minicnt); // perform operation
// 	if (el != mini)// if it is mini then it is already pushed
// 	{
// 		st.push(el);
// 	}
// }
// 
// void SortedStack ::sort()
// {
// 	// in this approach the elements which appear more than one times might be operated multiple times
// 	int size = s.size();
// 	// every time the minimum element is placed at it's position
// 	for (int i = 0; i < size; i++)
// 	{
// 		int mini = INT_MAX;
// 		int itrs = size - i;
// 		int minicnt = 0; // count for elements that appear more than one time
// 		insertOneMini(s, mini, itrs, minicnt);
// 	}
// }

// METHOD : 3 
/*
By using recursion - In this approach we take out each element till the stack is empty and when stack becomes empty we start pushing those elements again but while pushing them back we push them at their position in such that stack remains sorted (for this pushing we use function insertAtItsPos)
*/

void insertAtItsPos(stack<int>&st, int eltoins){
    if(st.empty()){// element needs to inserted at bottom (when the element is smallest in the stack)
        st.push(eltoins);
        return;
    }
    int el = st.top();
	// main base case
    if(el<=eltoins){ // else if further element is smaller then insert the element
        st.push(eltoins);
        return;
    }
    else{//(el>eltoins) 
        st.pop(); // take element out and insert in  remaining stack
        insertAtItsPos(st, eltoins);
        st.push(el);
    }
}

// same function using another stack
// void solve(stack<int>&st){
//     stack<int>st1;
//     while(!st.empty()){
//         st1.push(st.top());
//         st.pop();
//     }
//     while(!st1.empty()){
//         insertAtItsPos(st,st1.top());
//         st1.pop();
//     }
// }

// using recursion
void sort(stack<int>&st){
	// base case
    if(st.empty())// if stack is empty then return
        return;
	// take out the top element
    int el = st.top();
    st.pop();
	// sort the remaining stack
    sort(st);
	// push the element again in stack at its correct position
    insertAtItsPos(st,el);
}

void SortedStack ::sort()
{
	solve(s); // pass to solve function
}

int main()
{
	SortedStack st;
	st.s.push(41);
	st.s.push(3);
	st.s.push(32);
	st.s.push(2);
	st.s.push(11);
	st.sort();
	while (!st.s.empty())
	{
		cout << st.s.top() << " ";
		st.s.pop();
	}
	cout << endl;
}