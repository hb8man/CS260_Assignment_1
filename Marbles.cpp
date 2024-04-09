#include <iostream>
#include <vector>
#include <string> 
#include <random>

int generateRandNum(int len) {

    // Seed the random number generator
    std::random_device rd;
    std::mt19937 gen(rd()); // Mersenne Twister engine

    // Define the range
    std::uniform_int_distribution<int> distribution(0, len - 1);

    return distribution(gen);
}

class Marble {
public:
    std::string color;

    Marble(std::string c) : color(c) {}

    void setColor(std::string c) {
        color = c;
    }

    std::string getColor() const {
        return color;
    }
};

class Sack {
public:
    std::vector<Marble> marbles;

    Sack(std::vector<Marble> m) : marbles(m) {}

    void addMarble(std::string colorVal) {
        int rand = generateRandNum(marbles.size());
        
        Marble newMarble = Marble("");

        if (colorVal == "1") {
            newMarble.color = "Red";
        } else if (colorVal == "2") {
            newMarble.color = "Blue";
        } else if (colorVal == "3") {
            newMarble.color = "Green";
        } else if (colorVal == "4") {
            newMarble.color = "Yellow";
        } else if (colorVal == "5") {
            newMarble.color = "Orange";
        }

        marbles.insert(marbles.begin() + rand, newMarble);
    };

    void removeMarble() {
        int rand = generateRandNum(marbles.size());
        marbles.erase(marbles.begin() + rand);
    }
};

int main() {
    std::vector<Marble> myMarbles{
        Marble("Red"),
        Marble("Blue"),
        Marble("Green"),
        Marble("Yellow"),
        Marble("Orange")
    };
    
    Sack mainSack(myMarbles);

    bool isRunning = true;
    while (isRunning == true) {

        std::cout << "1. Add marble to sack.\n";
        std::cout << "2. Remove marble from sack.\n";
        std::cout << "3. Exit\n";

        std::string menuInput;
        std::cin >> menuInput;
        if (menuInput == "1") {
            bool keepLooping = true;
            
            while (keepLooping == true) {
                Marble newMarble = Marble("");
                
                std::string colorInput;
                std::cout << "Choose color to add: 1. Red 2. Blue 3. Green 4. Yellow 5. Orange 6. Go Back" << std::endl;
                std::cin >> colorInput;
                
                if (colorInput == "1") {
                    newMarble.color = "Red";
                } else if (colorInput == "2") {
                    newMarble.color = "Blue";
                } else if (colorInput == "3") {
                    newMarble.color = "Green";
                } else if (colorInput == "4") {
                    newMarble.color = "Yellow";
                } else if (colorInput == "5") {
                    newMarble.color = "Orange";
                } else if (colorInput == "6") {
                    // Break through loop while doing nothing (go back)
                    keepLooping = false;
                } else {
                    std::cout << "INVALID INPUT" << std::endl;
                }
            }
        } else if (menuInput == "2") {
            int randIndex = generateRandNum(3);
            mainSack.marbles.erase(mainSack.marbles.begin() + randIndex);
        } else if (menuInput == "3") {
            return 0;
        } else {
            std::cout << "\nINVALID INPUT\n";
        }
    };
};