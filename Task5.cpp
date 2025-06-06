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
