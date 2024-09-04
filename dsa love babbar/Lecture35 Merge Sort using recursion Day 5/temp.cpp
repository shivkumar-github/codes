#include <iostream>
#include <vector>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
        int findGreatest(vector<int> arr)
        {
                int g = arr[0];
                for (int i = 0; i < arr.size(); i++)
                {
                        if (g < arr[i])
                        {
                                g = arr[i];
                        }
                }
                return g;
        }

        int distributeCandies(int n, vector<int> &arr)
        {
                int g = findGreatest(arr);
                int ans = g * n;
                for (int i = 2; i <= 2; i++)
                {
                        int temp = 0;
                        for (int j = 0; j < n; j++)
                        {
                                if (arr[j] % i != 0)
                                {
                                        temp += (i - (arr[j] % i));
                                        cout << temp << endl;
                                }
                        }
                        if (temp < ans)
                        {
                                ans = temp;
                                cout << ans << endl;
                        }
                }
                return ans;
        }
};

int main()
{
        vector<int> arr = {2, 3, 4, 5, 6};
        Solution s;
        s.distributeCandies(arr.size(), arr);

        return 0;
}