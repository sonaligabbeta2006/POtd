class Solution
{
public:
    long long pairAndSum(int n, long long arr[])
    {
        // code here
        long long ans = 0;
        for (int i = 0; i < 32; i++)
        {
            // should be long long or you have to convert it back in last step data type convertion error
            /* on breaking the numbers into bits and analysing we absorve that only set bits contribute in and
            so we calculate the number pair of set bits */
            long long countset = 0;
            for (int j = 0; j < n; j++)
            {
                if ((arr[j] & (1 << i)) != 0)
                    countset++;
            }
            ans += (1 << i) * ((countset * (countset - 1)) / 2);
            // kinda got the the itution but can not uderstand it properly
        }
        return ans;
    }
};