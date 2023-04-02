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
    F1Car* cars;
    int num_cars;
};

void writeToFile(const F1Team& team, const std::string& filename) {
    std::ofstream outfile(filename, std::ios::binary);
    if (outfile.is_open()) {
        outfile.write((char*)&team.num_cars, sizeof(int));
        for (int i = 0; i < team.num_cars; i++) {
            int name_size = team.cars[i].name.size();
            outfile.write((char*)&name_size, sizeof(int));
            outfile.write((char*)team.cars[i].name.c_str(), name_size);
            outfile.write((char*)&team.cars[i].year, sizeof(int));
            outfile.write((char*)&team.cars[i].wins, sizeof(int));
            outfile.write((char*)&team.cars[i].engine_capacity, sizeof(float));
        }
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
        infile.read((char*)&team.num_cars, sizeof(int));
        team.cars = new F1Car[team.num_cars];
        for (int i = 0; i < team.num_cars; i++) {
            int name_size;
            infile.read((char*)&name_size, sizeof(int));
            char* name_buf = new char[name_size + 1];
            infile.read(name_buf, name_size);
            name_buf[name_size] = '\0';
            team.cars[i].name = std::string(name_buf);
            delete[] name_buf;
            infile.read((char*)&team.cars[i].year, sizeof(int));
            infile.read((char*)&team.cars[i].wins, sizeof(int));
            infile.read((char*)&team.cars[i].engine_capacity, sizeof(float));
        }
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
        new F1Car[2]{
            { "Ferrari", 2021, 3, 1.6f },
            { "Mercedes", 2021, 6, 1.8f }
        },
        2
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