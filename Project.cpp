//first part of the project:
//anti climatic for how much code it is
//i made a player struct with first name, last name, and team. i made a function that finds players who are in both basketball and football arrays by checking their full names.
//i used an unordered_set to store basketball player names and then checked if any football player names matched. if they do, i added them to an output array and printed them.


#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int findCommonPlayers(const Player basketballPlayers[], int basketballCount,
                  	const Player footballPlayers[], int footballCount,
                  	string output[], int maxOutputSize);

struct Player
 {
	string firstName;
	string lastName;
	string team;

	string getName() const 
{
    	return firstName + " " + lastName;
	}
};




int main() {
	const int basketballCount = 5;
	const int footballCount = 5;
  Player basketballPlayers[basketballCount] = 
{
    	{"Jill", "Huang", "Gators"},
    	{"Janko", "Barton", "Sharks"},
    	{"Wanda", "Vakulskas", "Sharks"},
    	{"Jill", "Moloney", "Gators"},
    	{"Luuk", "Watkins", "Gators"}
	};
  Player footballPlayers[footballCount] =
 {
    	{"Hanzla", "Radosti", "32ers"},
    	{"Tina", "Watkins", "Barleycorns"},
    	{"Alex", "Patel", "32ers"},
    	{"Jill", "Huang", "Barleycorns"},
    	{"Wanda", "Vakulskas", "Barleycorns"}
	};

	string commonPlayers[10];
	int commonCount = findCommonPlayers(basketballPlayers, basketballCount,
                                    	footballPlayers, footballCount,
                                    	commonPlayers, 10);

	for (int i = 0; i < commonCount; i++) 
{
    	cout << commonPlayers[i] << endl;
	}
}



int findCommonPlayers(const Player basketballPlayers[], int basketballCount,
                  	const Player footballPlayers[], int footballCount,
                  	string output[], int maxOutputSize)
 {
	unordered_set<string> nameSet;
	int resultCount = 0;

	for (int i = 0; i < basketballCount; i++) 
{
    	nameSet.insert(basketballPlayers[i].getName());
	}

	for (int i = 0; i < footballCount; i++) {
    	string name = footballPlayers[i].getName();
    	if (nameSet.count(name) && resultCount < maxOutputSize) 
{
        	output[resultCount++] = name;
    	}
	}

	return resultCount;
}



//second part of the project:
//this felt like a brain teaser and despite it being done in one simple function took alot of thinking
//The function calculates the expected sum of numbers from 0 to N, subtracts the actual sum of the array, and returns the missing number.

int findMissingNumber(int nums[], int size) 
{
    int n = size;
    int expectedSum = n * (n + 1) / 2;
    int actualSum = 0;

    for (int i = 0; i < size; i++) {
        actualSum += nums[i];
    }

    return expectedSum - actualSum;
}


//third part of the project:

//The function keeps track of the lowest price seen so far and checks the profit if we sell at the current price. It updates the maximum profit whenever it finds a higher one. It does all this in one loop for the O(n).

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

//fourth part of the project:
//i finished this one last because it was kinda annoying
//the function loops through the array once, updating the top two largest and bottom two smallest numbers as it goes, then compares their products to find the highest one.

int highestProduct(int nums[], int size) {
    if (size < 2) return 0;

    int max1 = nums[0], max2 = nums[1];
    int min1 = nums[0], min2 = nums[1];

    if (max2 > max1) swap(max1, max2);
    if (min2 < min1) swap(min1, min2);

    for (int i = 2; i < size; i++) {
        int n = nums[i];

        if (n > max2) {
            if (n > max1) {
                max2 = max1;
                max1 = n;
            } else {
                max2 = n;
            }
        }

        if (n < min2) {
            if (n < min1) {
                min2 = min1;
                min1 = n;
            } else {
                min2 = n;
            }
        }
    }

    int prodMax = max1 * max2;
    int prodMin = min1 * min2;

    if (prodMax > prodMin) {
        return prodMax;
    }
    return prodMin;
}




//fifth part of the project:
//this one was the easiest.

#include <iostream>
using namespace std;

void sortTemperatures(float temps[], int size);

int main() 
{
    float temperatures[] = {98.6, 98.0, 97.1, 99.0, 98.9, 97.8, 98.5, 98.2, 98.0, 97.1};
    int size = sizeof(temperatures) / sizeof(temperatures[0]);

    sortTemperatures(temperatures, size);

    for (int i = 0; i < size; i++) 
    {
        cout << temperatures[i] << " ";
    }
    cout << "\n";

    return 0;
}

void sortTemperatures(float temps[], int size) 
{
    int count[21] = {0};

    for (int i = 0; i < size; i++)
      {
        int index = static_cast<int>((temps[i] - 97.0) * 10 + 0.5);
        count[index]++;
    }

    int position = 0;
    for (int i = 0; i < 21; i++) 
    {
        while (count[i] > 0) 
        {
            temps[position] = 97.0 + i * 0.1;
            position++;
            count[i]--;
        }
    }
}

//last part of the project
//heres your funtion, it  puts all numbers in a set for fast lookup, then for each number that starts a sequence, it counts how long the consecutive run is and keeps track of the longest one.

int longestConsecutiveSequence(int nums[], int size) {
    unordered_set<int> numSet;
    for (int i = 0; i < size; i++) numSet.insert(nums[i]);

    int longestSeq = 0;
    for (int i = 0; i < size; i++) {
        int num = nums[i];
        if (numSet.find(num - 1) == numSet.end()) {
            int current = num;
            int length = 1;
            while (numSet.find(current + 1) != numSet.end()) {
                current++;
                length++;
            }
            if (length > longestSeq) longestSeq = length;
        }
    }
    return longestSeq;
}
