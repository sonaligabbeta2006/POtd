// optimise approach
// block can omy store water if there is a block whose hieght i sgreater the current element on both the sides
/* done using two pointer thoda brain*/
int trap(vector<int> &height)
{
    int left = 0;
    int right = height.size() - 1;
    int lmax = 0;
    int rmax = 0;
    int water = 0;

    while (left <= right)
    {
        lmax = max(lmax, height[left]);
        rmax = max(rmax, height[right]);
        if (lmax < rmax)
        {
            water += lmax - height[left];
            left++;
        }
        else
        {
            water += rmax - height[right];
            right--;
        }
    }
    return water;
}
// brute
int maxWater(int arr[], int n)
{
    // To store the maximum water
    // that can be stored
    int res = 0;

    // For every element of the array
    for (int i = 1; i < n - 1; i++)
    {

        // Find the maximum element on its left
        int left = arr[i];
        for (int j = 0; j < i; j++)
            left = max(left, arr[j]);

        // Find the maximum element on its right
        int right = arr[i];
        for (int j = i + 1; j < n; j++)
            right = max(right, arr[j]);

        // Update the maximum water
        res = res + (min(left, right) - arr[i]);
    }

    return res;
}