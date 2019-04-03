#include <iostream>

int main(int argc, char const *argv[])
{
    // Write a program that prints a few details to the terminal window about you
    // It should print each detail to a new line.
    //  - Your name
    //  - Your age
    //  - Your height in meters (as a decimal fraction)
    //
    //  Example output:
    //  John Doe
    //  31
    //  1.87

    std::cout << "Balazs Zboray" << std::endl;
    std::cout << 30 << std::endl;
    std::cout << 1.80 << std::endl;

    // Create a program that prints a few operations on two numbers: 22 and 13
    int a = 22;
    int b = 13;

    std::cout << "\nOperations on two numbers: 22 and 13\n";
    // Print the result of 13 added to 22
    std::cout << "adding: " << a + b << std::endl;
    // Print the result of 13 substracted from 22
    std::cout << "substracting: " << a - b << std::endl;
    // Print the result of 22 multiplied by 13
    std::cout << "multiplication: " << a * b << std::endl;
    // Print the result of 22 divided by 13 (as a decimal fraction)
    std::cout << "division: " << a / (double)b << std::endl;
    // Print the integer part of 22 divided by 13
    std::cout << "integer part of division: " << a / b << std::endl;
    // Print the reminder of 22 divided by 13
    std::cout << "reminder part of division: " << a % b << std::endl;

    // An average Green Fox attendee codes 6 hours daily
    // The semester is 17 weeks long
    //
    // Print how many hours is spent with coding in a semester by an attendee,
    // if the attendee only codes on workdays.
    //
    // Print the percentage of the coding hours in the semester if the average
    // working hours weekly is 52

    std::cout << std::endl;
    std::cout << "The average hours spent coding in a semester: " << 6 * 17 * 5 << std::endl;
    std::cout << "That's " << 5 * 6 / (double)52 * 100 << "% percent of the working hours.";
    return 0;
}