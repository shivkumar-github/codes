int totalPages(vector<int> &arr)
{
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }
    return sum;
}

bool isPossible(vector<int> &arr, int students, int mid)
{
    int studentCount = 1;
    int possiblemaxPages = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (possiblemaxPages + arr[i] <= mid)
        {
            possiblemaxPages += arr[i];
        }
        else
        {
            studentCount++;
            if (studentCount > students || arr[i] > mid)
            {                                            
                return false;
            }
            possiblemaxPages = arr[i]; 
        }
    }
    return true;
}

int findPages(vector<int>& arr, int n, int m) {
    if(m > n)
        return -1;
    int ans = -1;
    int start = 0;
    int end = totalPages(arr);
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isPossible(arr, m, mid) == 1) 
        {
            ans = mid;
            end = mid - 1;
        }
        else
        { 
            start = mid + 1;
        }
    }
    return ans;
}

int main(){
	int n = 19;
	int m = 3;
	vector<int> arr = {2 9 12 18 22 39 42 47 56 59 66 73 80 80 82 86 88 91 99}
	return 0;
}