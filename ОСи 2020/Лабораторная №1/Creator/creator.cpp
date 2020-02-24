#include "employee.h"
#include <Windows.h>
#include <string>
#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
	

	std::string file_name = argv[1];
	std::string num = argv[2];
	int number = std::stoi(num);

	std::ofstream fout;
	fout.open(file_name, std::ios::binary | std::ios::app);

	employee* ourStructArray = new employee[number];
	
	for (int i = 0; i < number; i++) {
		std::cout << "Enter id, name and number of hours worked: ";
		std::cin >> ourStructArray[i].num >> ourStructArray[i].name >> ourStructArray[i].hours;
		fout.write((char*)&ourStructArray[i], sizeof(employee));
	}

	fout.close();
}
