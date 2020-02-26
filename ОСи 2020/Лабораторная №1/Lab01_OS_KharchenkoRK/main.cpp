#include "processes.h"
#include "print.h"

int main() {

    //MARK: OUR OUTLETS
    STARTUPINFO cre_si;
    PROCESS_INFORMATION processInfo;
    STARTUPINFO rep_si;
    PROCESS_INFORMATION rep_pi;

    std::string name;
    std::string reporter_name;
    std::string space = " ";
    std::string STRcommandLineForCreator;
    LPSTR commandLineForCreator;

    std::string STRcommandLineForReporter;
    LPSTR commandLineForReporter;

    double hourly_payment;
    int number;

    //MARK: AGRUMENTS FOR CREATOR
    std::cout << "Enter creator bin file name ( with .bin extension ): ";
    std::cin >> name;
    std::cout << "Enter number of records: ";
    std::cin >> number;

    STRcommandLineForCreator = "Creator.exe" + space + name + space + std::to_string(number);
    commandLineForCreator = (LPSTR)STRcommandLineForCreator.c_str();
    //MARK: FREE MEMORY FOR CREATOR
    freeMemory(&cre_si);
    //MARK:CREATE CREATOR PROCESS
    createProcessHeader(commandLineForCreator, &cre_si, &processInfo);


    char* c_name = const_cast<char*>(name.c_str());
    //MARK: PRINT CREATOR FILE
    print_Creator(c_name, number);


    //MARK: AGRUMENTS FOR REPORTER
    std::cout << "\nEnter reporter bin file name ( with .bin extension ): ";
    std::cin >> reporter_name;
    std::cout << "Enter hourly payment: ";
    std::cin >> hourly_payment;


    STRcommandLineForReporter = "Reporter.exe" + space + name + space + reporter_name + space + std::to_string(hourly_payment);
    commandLineForReporter = (LPSTR)STRcommandLineForReporter.c_str();
    
    //MARK: FREE MEMORY FOR REPORTER
    freeMemory(&rep_si);
    //MARK:CREATE REPORTER PROCESS
    createProcessHeader(commandLineForReporter, &rep_si, &rep_pi);
    //MARK: PRINT REPORTER FILE
    printReporterFile(reporter_name);
}


