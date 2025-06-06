#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

struct Player {
    string firstName;
    string lastName;
    string team;

    string getName() const {
        return firstName + " " + lastName;
    }
};

int findCommonPlayers(const Player basketballPlayers[], int basketballCount,
                      const Player footballPlayers[], int footballCount,
                      string output[], int maxOutputSize);

int main() {
    const int basketballCount = 5;
    const int footballCount = 5;

    Player basketballPlayers[basketballCount] = {
        {"Jill", "Huang", "Gators"},
        {"Janko", "Barton", "Sharks"},
        {"Wanda", "Vakulskas", "Sharks"},
        {"Jill", "Moloney", "Gators"},
        {"Luuk", "Watkins", "Gators"}
    };

    Player footballPlayers[footballCount] = {
        {"Hanzla", "Radosti", "32ers"},
        {"Tina", "Watkins", "Barleycorns"},
        {"Alex", "Patel", "32ers"},
        {"Jill", "Huang", "Barleycorns"},
        {"Wanda", "Vakulskas", "Barleycorns"}
    };

    string commonPlayers[10];
    int commonCount = findCommonPlayers(basketballPlayers, basketballCount,
                                        footballPlayers, footballCou               nt,
                                        commonPlayers, 10);

    for (int i = 0; i < commonCount; i++) {
        cout << commonPlayers[i] << endl;
    }

    return 0;
}

int findCommonPlayers(const Player basketballPlayers[], int basketballCount,
                      const Player footballPlayers[], int footballCount,
                      string output[], int maxOutputSize) {
    unordered_set<string> nameSet;
    int resultCount = 0;

    for (int i = 0; i < basketballCount; i++) {
        nameSet.insert(basketballPlayers[i].getName());
    }

    for (int i = 0; i < footballCount; i++) {
        string name = footballPlayers[i].getName();
        if (nameSet.count(name) && resultCount < maxOutputSize) {
            output[resultCount++] = name;
        }
    }

    return resultCount;
}
 
