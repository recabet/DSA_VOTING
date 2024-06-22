# Vote Management System

This project implements a Vote Management System using a linked list data structure in C. It allows users to manage a list of voters, perform operations like adding, deleting, sorting, and displaying voters, and handle specific requirements such as voter choices and ID uniqueness.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Functionality](#functionality)
- [Contributing](#contributing)
- [License](#license)

## Introduction

This Vote Management System is implemented in C language and utilizes a linked list (`T_Elector`) to store voter information. The system provides various functionalities to manage voters dynamically, including adding new voters, displaying voter details, sorting voters, deleting voters by ID, and more.

## Features

- **Add Voter**: Add a new voter to the list, ensuring sorted insertion based on voter's name.
- **Display Voters**: Display the list of voters with their names, ID numbers, and choices.
- **Delete Voter**: Remove a voter from the list based on their ID number.
- **Sort Voters**: Sort the list of voters based on their ID numbers in ascending order.
- **Search Voter**: Find and display details of a voter based on their ID number.
- **Merge Lists**: Merge two sorted lists of voters into a single sorted list.
- **Count Voters**: Calculate the total number of voters in the list.
- **Decompose List**: Divide the list into three separate lists based on voter's choices.
- **Memory Management**: Proper memory allocation and deallocation using `malloc` and `free`.
- **Error Handling**: Handle errors for memory allocation failures and null pointer operations.

## Installation

To use this Vote Management System:

1. Clone the repository: git clone https://github.com/recabet/DSA_VOTING.git

2. Navigate to the directory:
cd DSA_VOTING

3. Compile the program (assuming you have `gcc` installed): gcc main.c vote.c -o main

4. Run the executable: ./main

## Usage

Once compiled and executed, follow the prompts to interact with the Vote Management System. Here's a brief overview of how to use the system:

- **Adding Voters**: Choose to add a single voter or create a list of voters.
- **Displaying Voters**: View the list of voters along with their details.
- **Deleting Voters**: Remove a voter by entering their ID number.
- **Sorting Voters**: Sort the list of voters by their ID numbers.
- **Merging Lists**: Combine two sorted lists of voters into a single sorted list.
- **Decomposing List**: Separate the list into three categories based on voter choices.
- **Exiting**: Option to exit the program.

## Functionality

### Detailed Functions

- **`freelist`**: Frees memory allocated for the linked list of voters.
- **`addelector`**: Adds a new voter to the list in a sorted manner based on the voter's name.
- **`displaylist`**: Displays the entire list of voters with their details.
- **`creationelector`**: Creates a new voter node and prompts the user for details (name, ID, choice).
- **`creation_T_Elector_Linked_List`**: Creates a linked list of voters based on user input.
- **`insertSorted`**: Inserts a new voter node into the list in sorted order based on the voter's name.
- **`alphaOrder`**: Compares two strings alphabetically.
- **`countelector`**: Counts the number of voters in the list.
- **`findelector`**: Finds and displays details of a voter based on their ID number.
- **`decomposelist`**: Divides the list into three separate lists based on the voter's choice (left, right, white).
- **`deletelector`**: Deletes a voter from the list based on their ID number.
- **`sortlist`**: Sorts the list of voters based on their ID numbers in ascending order.
- **`mergelists`**: Merges two sorted lists of voters into a single sorted list.
- **`countLR`**: Counts the number of voters in a merged list.

## Contributing

Contributions are welcome! If you'd like to contribute to this project, feel free to fork the repository and submit pull requests with your improvements. Please follow the existing coding style and ensure that your code is well-documented.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

This README provides a comprehensive overview of the Vote Management System, detailing its functionality, installation instructions, usage guidelines, and contribution opportunities. For further details, refer to the source code and documentation within the repository.
