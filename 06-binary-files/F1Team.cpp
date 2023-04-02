#include <iostream>
#include <fstream>
#include <string>

struct F1Car {
    std::string name;
    int year;
    int wins;
    float engine_capacity;
};

struct F1Team {
    F1Car cars[2];
};

void writeToFile(const F1Team& team, const std::string& filename) {
    std::ofstream outfile(filename, std::ios::binary);
    if (outfile.is_open()) {
        outfile.write((char*)&team, sizeof(F1Team));
        outfile.close();
        std::cout << "Data written to file: " << filename << std::endl;
    }
    else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}

F1Team readFromFile(const std::string& filename) {
    std::ifstream infile(filename, std::ios::binary);
    F1Team team;
    if (infile.is_open()) {
        infile.read((char*)&team, sizeof(F1Team));
        infile.close();
        std::cout << "Data read from file: " << filename << std::endl;
    }
    else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
    return team;
}

int main() {
    F1Team team = {
        {
            { "Ferrari", 2021, 3, 1.6f },
            { "Mercedes", 2021, 6, 1.8f }
        }
    };
    writeToFile(team, "data.bin");

    F1Team team2 = readFromFile("data.bin");
    std::cout << "Car 1 name: " << team2.cars[0].name << std::endl;
    std::cout << "Car 1 year: " << team2.cars[0].year << std::endl;
    std::cout << "Car 1 wins: " << team2.cars[0].wins << std::endl;
    std::cout << "Car 1 engine capacity: " << team2.cars[0].engine_capacity << std::endl;
    std::cout << "Car 2 name: " << team2.cars[1].name << std::endl;
    std::cout << "Car 2 year: " << team2.cars[1].year << std::endl;
    std::cout << "Car 2 wins: " << team2.cars[1].wins << std::endl;
    std::cout << "Car 2 engine capacity: " << team2.cars[1].engine_capacity << std::endl;
    return 0;
}
