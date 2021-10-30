// Copyright (c) 2021 Michael Zagon All rights reserved

// Created by: Michael Zagon
// Created on: October 2021
// This program finds the average of random numbers

#include <iostream>
#include <random>

template <int rows, int cols>
int averageOfNumbers(int (&randomList)[rows][cols],
                          int rowElement, int columnElement) {
    // this function gets the average

    int total = 0;

    for (size_t rowElement = 0; rowElement < rows; ++rowElement) {
        for (size_t columnElement = 0; columnElement < cols; ++columnElement)
            total += randomList[rowElement][columnElement];
    }
    total = total / (rowElement * columnElement);

    return total;
}


int main() {
    // this function generates the random numbers

    int randomNumber = 0;
    int average = 0;
    const int rows = 2;
    const int columns = 2;
    int generatedRandomList[rows][columns];

    std::random_device rseed;
    std::mt19937 rgen(rseed());
    std::uniform_int_distribution<int> idist(1, 50);

    std::cout << "Starting ... " << std::endl;
    std::cout << "" << std::endl;

    for (int rowElement = 0; rowElement < rows; rowElement++) {
        for (int columnElement = 0; columnElement < columns; columnElement++) {
            randomNumber = idist(rgen);
            generatedRandomList[rowElement][columnElement] = randomNumber;
            std::cout << randomNumber << ", ";
        }
        std::cout << std::endl;
    }

    average = averageOfNumbers(generatedRandomList, rows, columns);
    std::cout << "\nThe average of all the numbers is: " << average
    << std::endl;

    std::cout << "\nDone." << std::endl;
}
