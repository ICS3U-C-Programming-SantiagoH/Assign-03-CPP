// Copyright (c) 2023 Santiago Hewett All rights reserved.
//
// Created by: Santiago Hewett
// Date: Nov 8, 2023
// This program asks the user for the amount
// This program asks the user for the amount
// and calculate the total with tax or not.

#include <iostream>
// Include this for std::setprecision
#include <cmath>
#include <iomanip>
#include <string>  // Include this for std::string

int main() {
    // declare constants
    const float HST = 0.13;
    const float PRICE_PER_CROISSANT = 2.55;
    const float PRICE_PER_BAGEL = 2.55;

    // declare variables
    std::string user_croissants_string;
    std::string user_bagels_string;

    // get the diameter in inches from the user and display message
    std::cout << "This program will calculate the total ";
    std::cout << " with tax or not based on the amount on food ";
    std::cout << "the user orders ";
    std::cout << "Enter the number of croissants: ";
    std::cin >> user_croissants_string;
    std::cout << "Enter the number of bagels: ";
    std::cin >> user_bagels_string;

    try {
        // Convert user input to integers
        int user_croissants_int = stoi(user_croissants_string);
        int user_bagels_int = stoi(user_bagels_string);

        // Calculate the amount of food
        int amount_of_food = user_croissants_int + user_bagels_int;

        // Check if the amount of food is within a valid range
        if (0 <= amount_of_food && amount_of_food <= 99) {
            if (amount_of_food >= 6) {
                // Calculate subtotal for croissants and bagels
                float croissant_subtotal = PRICE_PER_CROISSANT
                * user_croissants_int;
                float bagel_subtotal = PRICE_PER_BAGEL * user_bagels_int;

                // Calculate total with tax
                float total_subtotal = croissant_subtotal + bagel_subtotal;
                float total_tax = total_subtotal * (1 + HST);

                // Display total with tax
                std::cout << "Your total is: $" << std::fixed
                << std::setprecision(2) << total_tax << std::endl;
            } else {
                // Calculate subtotal for croissants and bagels
                float croissant_subtotal = PRICE_PER_CROISSANT
                * user_croissants_int;
                float bagel_subtotal = PRICE_PER_BAGEL * user_bagels_int;

                // Calculate total without tax
                float total_subtotal = croissant_subtotal + bagel_subtotal;

                // Display total without tax
                std::cout << "Your total is: $" << std::fixed
                << std::setprecision(2) << total_subtotal << std::endl;
            }
        } else {
            // Display an error message for an invalid amount of food
            std::cout << amount_of_food
            << " is not a valid number of items\n";
        }
    } catch (std::invalid_argument& e) {
        // Handle invalid integer input
        std::cout << "Invalid input. Please enter ";
        std::cout << "valid integers for croissants and bagels.\n";
    }
}
