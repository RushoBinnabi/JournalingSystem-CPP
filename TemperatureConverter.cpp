/**
 * @file TemperatureConverter.cpp
 * @author Rusho Binnabi
 * @date 2022-08-08
 * @copyright Copyright (c) 2022
 * Contact Information: Email: RushoBinnabi123@yahoo.com or Phone Number: 518-364-7101
 * Code File Updated: August 8th, 2022 at 11:07 PM
 */

#include <iostream> // includes the iostream library for use in this program.
#include <iomanip> // includes the iomanip library for use in this program.
using namespace std; // this program uses the std namespace.

// this program calculates either a fahrenheit or celsius temperature value based on what type of conversion that the user wants.

double input; // creates a double variable called input.
string choice; // creates a string variable called choice.
char character = 248; // creates a char variable called character which is initialized to the ASCII value of the degree "°" symbol.

/**
 * this double celsiusConversion() method calculates the celsius conversion of a given fahrenheit temperature value from the user.
 * @param input this double input parameter value is the fahrenheit value that gets entered by the user which will later be converted into celsius within the method.
 * @return double returns a double value called celsius which is the converted celsius temperature value from input.
 */

double celsiusConversion(double input) {
    double celsius; // creates a double variable called celsius.
    celsius = (input - 32) / 1.8; // using the formula, celsius stores the converted fahrenheit value using input.
    return celsius; // returns celsius.
} // the end of the celsiusConversion() method.

/**
 * this double fahrenheitConversion() method calculates the fahrenheit conversion of a given celsius temperature value from the user.
 * @param input this double input parameter value is the celsius value that gets entered by the user which will later be converted into fahrenheit within the method.
 * @return double returns a double value called fahrenheit which is the converted fahrenheit temperature value from input.
 */

double fahrenheitConversion(double input) {
    double fahrenheit; // creates a double variable called fahrenhit.
    fahrenheit = (input * 1.8) + 32; // using the formula, fahrenheit stores the converted celsius value using input.
    return fahrenheit; // returns fahrenheit.
} // the end of the fahrenheitConversion() method.

/**
 * this void resetValues() method resets the values of the variables.
 * this method is void because it doesn't return anything. 
 */

void resetValues() {
    input = 0; // resets input to 0.
    character = 0; // resets character to 0.
    choice = ""; // resets choice to an empty string.
} // the end of the resetValues() method.

/**
 * this int main() method runs the program.
 * @return int returns a 0 which means the program ran successfully.
 */

int main() {
    cout << "Do you want to convert a fahrenheit or celsius temperature (f/c)? "; // asks the user to enter either a f or a c which indicates what kind of temperature conversion that they want to do.
    cin >> choice; // stores the user input inside choice.
    if (choice == "f") { // if the value of choice was a f which means that the user wants to convert a fahrenheit temperature, then it runs the code inside the if statement.
        cout << "\nEnter a fahrenheit temperature: "; // prompts the user to enter a fahrenheit temperature.
        cin >> input; // stores the user input inside input.
        std::cout << std::fixed; // makes the output value to a fixed value.
        std::cout << std::setprecision(2); // sets the precision of the output value to 2.
        std::cout << "\nThe celsius conversion is " << celsiusConversion(input) << character << "C\n\n"; // shows the user what the converted celsius temperature is by calling the celsiusConversion() method and using input as it's argument.
        cin.get(); // calls the get() method from the cin object so that the program doesn't immediately end and so that the user can actualy use the output.
    } // the end of the if statement.
    else if (choice == "c") { // if the value of choice was a c which means that the user wants to convert a celsius temperature, then it runs the code inside the else if statement.
        cout << "\nEnter a celsius temperature: "; // prompts the user to enter a celsius temperature.
        cin >> input; // stores the user input inside input.
        std::cout << std::fixed; // makes the output value to a fixed value.
        std::cout << std::setprecision(2); // sets the precision of the output value to 2.
        std::cout << "\nThe fahrenheit conversion is " << fahrenheitConversion(input) << character << "F\n\n"; // shows the user what the converted fahrenheit temperature is by calling the fahrenheitConversion() method and using input as it's argument.
        cin.get(); // calls the get() method from the cin object so that the program doesn't immediately end and so that the user can actualy use the output.
    } // the end of the else if statement.
    cin.get(); // calls the get() method from the cin object so that the program doesn't immediately end and so that the user can actualy use the output.
    resetValues(); // calls the resetValues() method.
    return 0; // returns a 0.
} // the end of the main() method.