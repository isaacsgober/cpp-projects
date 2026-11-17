#include <cctype>
#include <iostream>
#include <stdexcept>
#include <string>

char readChoice(const std::string& prompt, char a, char b) {
	std::string input;
	char output;

	a = std::tolower(a);
	b = std::tolower(b);

	while (true) {
		std::cout << prompt;

		std::getline(std::cin, input);
		output = std::tolower(input[0]);

		if (output == a || output == b) {
			return output;
		}
		else {
			std::cout << "Please enter " << a << " or " << b << ":\n";
		}
	}
}

double readTemp(const std::string& prompt) {
	std::string input;
	size_t used;
	double value;

	while (true) {
		std::cout << prompt;

		std::getline(std::cin, input);
		try {
			value = std::stod(input, &used);
			if (input.size() != used) {
				throw std::invalid_argument("extra characters");
			}
			return value;
		}
		catch (const std::invalid_argument&) {
			std::cout << "Not a number. Please input temperature as a number.\n";
		}
		catch (const std::out_of_range&) {
			std::cout << "Number out of range. Please input a temperature with range of a double.\n";
		}
	}
	
}

double fToC(double fahrenheit) {
	return (fahrenheit - 32) * 5 / 9;
}

double cToF(double celsius) {
	return (celsius * 9 / 5) + 32;
}

int main()
{
	using std::cout;
	
	double unitIn;
	double unitOut;
	char again = 'y';
	char choice;

	do {
		choice = readChoice("Convert to (f)ahrenheit or (c)elsius? f/c: ", 'f', 'c');

		switch (choice) {
		case 'f':
			unitIn = readTemp("Enter temperature in Celsius: ");
			unitOut = cToF(unitIn);
			cout << unitIn << " C is " << unitOut << " F\n";
			break;
		case 'c':
			unitIn = readTemp("Enter temperature in Fahrenheit: ");
			unitOut = fToC(unitIn);
			cout << unitIn << " F is " << unitOut << " C\n";
			break;
		}
		again = readChoice("Convert another? y/n: ", 'y', 'n');
	} while (again == 'y');
}