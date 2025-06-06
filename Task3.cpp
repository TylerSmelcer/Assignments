
#include <iostream>
using namespace std;

int maxProfit(int prices[], int size);

int main()
{
    int prices[] = {10, 7, 5, 8, 11, 2, 6};
    int size = sizeof(prices) / sizeof(prices[0]);

    cout << "max profit: " << maxProfit(prices, size) << "\n";
}



int maxProfit(int prices[], int size)
{
    if (size <= 1) return 0;

    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < size; i++) 
    {
        if (prices[i] < minPrice) 
        {
            minPrice = prices[i];
        } else {
            int profit = prices[i] - minPrice;
            if (profit > maxProfit) {
                maxProfit = profit;
            }
        }
    }

    return maxProfit;
}
