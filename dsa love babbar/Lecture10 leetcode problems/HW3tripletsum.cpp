/*
Array of N integers
task is to find a tripplet which adds upto a given number K
An array is said to have such a triplet when there exists three indices i, j, k such that
arr[i] + arr[j] + arr[k] = K

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_ans(vector<vector<int>> &answer)
{
    for (int i = 0; i < answer.size(); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            vector<int> &temp = answer[i];
            cout << temp[j] << " ";
        }
        cout << endl;
    }
}

// to inlcude only unique pairs
bool check_if_already(vector<vector<int>> &main, vector<int> &temp)
{
    for (int t = 0; t < main.size(); t++)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    vector<int> temparory = main[t];
                    if (temparory[i] == temp[0] && temparory[j] == temp[1] && temparory[k] == temp[2])
                    {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

void find_triplets(int *arr, int n, int K)
{
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            for (int k = j+1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == K)
                {
                    vector<int> temp;
                    temp.push_back(arr[i]);
                    temp.push_back(arr[j]);
                    temp.push_back(arr[k]);
                    if (check_if_already(ans, temp) == 0)
                    {
                        ans.push_back(temp);
                    }
                }
            }
        }
    }
    print_ans(ans);
}

// // better approach by using sorting and two pointer approach
// void find_triplets(vector<int> arr, int K)
// {
//     int n = arr.size();
//     vector<vector<int>> ans;
//     sort(arr.begin(), arr.end());

//     for (int i = 0; i < n - 2; i++)
//     {
//         // to avoid printing duplicates
//         if (arr[i] == arr[i - 1])
//             continue;

//         int start = i + 1;
//         int end = n - 1;

//         while (start < end) // mind that it is two pointers approach and not the binary search hence time complexity for this while loop is O(n)
//         {
//             int sum = arr[i] + arr[start] + arr[end];
//             if (sum == K)
//             {
//                 ans.push_back({arr[i], arr[start], arr[end]});

//                 // to avoid printing duplicates
//                 while (start <= end && arr[start] == arr[start + 1])
//                     start++;
//                 while (start <= end && arr[end] == arr[end - 1])
//                     end--;

//                 start++;
//                 end--;
//             }
//             else if (sum < K)
//                 start++;
//             else
//                 end--;
//         }
//     }
//     print_ans(ans);
// }

int main()
{
    int array[9] = {0, 1, 0, 2, 2, 2, 3, 4};
    // vector<int> array = {0, 1, 0, 2, 2, 2, 3, 4};

    find_triplets(array, 8, 7);
    return 0;
}