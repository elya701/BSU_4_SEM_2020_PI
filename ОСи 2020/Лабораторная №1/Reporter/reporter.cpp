#include "employee.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <iostream>

void write_to_textfile(const struct employee* p, FILE* f, const int hourly_payment) {
	fprintf(f, "%d %s %.3lf %.3lf\n", p->num, p->name, p->hours, p->hours * hourly_payment);
}

int main(int argc, char** argv) {
	
	
	char report_headline[256];
	int num_of_payments = 0;

	char* binary_input_file_name = argv[1];
	char* report_output_file_name = argv[2];
	double hourly_payment = strtod(argv[3], NULL);

	std::ifstream f(binary_input_file_name);
	if (f)
	{
		
		char c;
		while (f.get(c))
		{
			
			if (c == '@') {
				
				num_of_payments++;
			}
		}
	}

	FILE* report_output;
	fopen_s(&report_output, report_output_file_name, "w");
	FILE* binary_input;
	fopen_s(&binary_input, binary_input_file_name, "rb");


	sprintf_s(report_headline, "%s report\n", binary_input_file_name);
	fwrite(report_headline, sizeof(char), strlen(report_headline), report_output);


	

	employee* payments = new employee[num_of_payments];
	fread(payments, sizeof(struct employee), num_of_payments, binary_input);

	for (int i = 0; i < num_of_payments; i++) {
		write_to_textfile(payments + i, report_output, hourly_payment);
	}

	free(payments);

	fclose(binary_input);
	fclose(report_output);

	return 0;
}