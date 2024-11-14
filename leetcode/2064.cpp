#include <vector>
#include <algorithm>

int minMaxProducts(int n, std::vector<int>& quantities) 
{
    int low = 1, high = *max_element(quantities.begin(), quantities.end());
    int result = high;

    while (low <= high) 
    {
        int mid = low + (high - low) / 2;
        int requiredStores = 0;
        
        for (int qty : quantities) 
        {
            requiredStores += (qty + mid - 1) / mid;
        }

        if (requiredStores <= n) 
        {
            result = mid;
            high = mid - 1;
        } 
        else 
        {
            low = mid + 1;
        }
    }
    return result;
}
