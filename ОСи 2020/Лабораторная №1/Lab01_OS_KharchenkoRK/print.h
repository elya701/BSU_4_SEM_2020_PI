#include "employee.h"
#include <Windows.h>
#include <string>
#include <iostream>
#include <fstream>

void print_Creator(char* name_of_file, int number) {

    FILE* binary_input;
    fopen_s(&binary_input, name_of_file, "rb");

    std::cout << std::endl << std::endl << "Creator:" << std::endl;
    for (int i = 0; i < number; i++) {
        struct employee emp;
        fread(&emp, sizeof(struct employee), 1, binary_input);

        printf("%d %s %lf\n", emp.num, emp.name, emp.hours);
    }

    fclose(binary_input);

    /*std::string line;
    std::ifstream input(name_of_file, std::ios::binary | std::ios::in);


    while (!input.eof())
    {
        std::string tmp;
        std::getline(input, tmp);
        std::cout << tmp << std::endl;
    }
    input.close();
    */
}

void printReporterFile(std::string report_file_name) {
    std::string line;

    std::cout << std::endl << std::endl << "Reporter:" << std::endl;

    std::ifstream input(report_file_name);
    while (std::getline(input, line)) {
        std::cout << line << std::endl;
    }
    input.close();
}
