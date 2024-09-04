// https://www.geeksforgeeks.org/problems/circular-tour-1587115620/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
class Solution
{
public:
    // METHOD: 1 Find possible candidate and then check if the candidate can be answer or not by traversing from 0 to that cadidate with taking remaining balance to check if the candidate is answer or not
    int tour(petrolPump p[], int n)
    {
        queue<int> q;
        int balance = 0;
        for (int i = 0; i < n; i++)
        {
            int netpetrol = p[i].petrol + balance; // total petrol at this station after refuling
            if (netpetrol >= p[i].distance)
            { // if distance is coverable then push in stack and adjust the remaining petrol
                q.push(i);
                balance = netpetrol - p[i].distance;
            }
            else
            { // else empty the q as no answer in q is possible
                while (!q.empty())
                    q.pop();
                balance = 0;
            }
        }
        if (q.empty())
            return -1; // if q is empty now then there is no possible candidate
        int candidate = q.front();
        for (int i = 0; i < candidate; i++)
        {
            int netpetrol = p[i].petrol + balance; // total petrol at this station after refuling
            if (netpetrol < p[i].distance)
                return -1; // if netpetrol is less then the candidate is not our answer
            else
                balance = netpetrol - p[i].distance; // else adjust the balance
        }
        return candidate;
    }
};

// METHOD: 2 Without using queue In O(n) tc and constant extra space'
// this is the most optimised and short approach
class Solution
{
public:
    int tour(petrolPump p[], int n)
    {
        int deficit = 0;
        int balance = 0;
        int start = 0;

        for (int i = 0; i < n; i++)
        {
            balance += p[i].petrol - p[i].distance;
            if (balance < 0)
            {
                deficit += balance;
                start = i + 1;
                balance = 0;
            }
        }
        if (deficit + balance >= 0)
        {
            return start;
        }
        else
            return -1;
    }
};

// we also write this same approach by ourselves were we iterated over the array again to check if we can go from start to that index
// but in this approach we are calculating the deficit (the petrol which we lack) and equating it with remaining balance at last
