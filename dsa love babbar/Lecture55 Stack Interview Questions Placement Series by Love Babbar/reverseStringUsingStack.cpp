// https://www.geeksforgeeks.org/problems/reverse-a-string-using-stack/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
char* reverse(char *S, int len)
{
    //code here
    int* arr = new int[len];
    int top = -1;
    for(int i = 0;i<len;i++){
        arr[++top] = S[i];
    }
    for(int i = 0;i<len;i++){
        S[i] = arr[top--];
    }
    return S;
}// time and space complexity = O(n)