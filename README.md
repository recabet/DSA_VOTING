# Vote Management System

This project implements a Vote Management System using a linked list data structure in C. It allows users to manage a list of voters, perform operations like adding, deleting, sorting, and displaying voters, and handle specific requirements such as voter choices and ID uniqueness.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Functionality](#functionality)
- [Example](#example)
- [Contributing](#contributing)
- [License](#license)

## Introduction

The Vote Management System is implemented in C language, using a linked list (`T_Elector`) to store voter information dynamically. It provides various functionalities for administrators to add, delete, display, sort, and manage voters efficiently.

## Features

- **Add Voter**: Insert a new voter into the list in sorted order based on the voter's name.
- **Display Voters**: View the list of voters with their names, ID numbers, and choices.
- **Delete Voter**: Remove a voter from the list using their ID number.
- **Sort Voters**: Arrange the list of voters by their ID numbers in ascending order.
- **Search Voter**: Find and display details of a voter based on their ID number.
- **Merge Lists**: Combine two sorted lists of voters into one sorted list.
- **Count Voters**: Calculate the total number of voters in the list.
- **Decompose List**: Split the list into three separate lists based on voter choices.
- **Memory Management**: Proper allocation and deallocation of memory using `malloc` and `free`.
- **Error Handling**: Manage errors related to memory allocation failures and null pointer operations.

## Installation

To use the Vote Management System:

1. Clone the repository: git clone https://github.com/recabet/DSA_VOTING.git

2. Navigate to the project directory: cd DSA_VOTING

3. Compile the program (assuming `gcc` is installed):
   gcc main.c vote.c -o main
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
- **`addelector`**: Adds a new voter to the list in sorted order based on the voter's name.
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

## Example

Here's an example of how to use the voting system in C:

```c 
#include "vote.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
 T_Elector head = NULL;
 int choice;
 long cin_num;
 const char* name;

 // Add electors
 addelector(&head, "John Doe", 123456789, 1);
 addelector(&head, "Jane Smith", 987654321, 2);
 addelector(&head, "Michael Brown", 456789123, 3);

 // Display the list of electors
 printf("List of Electors:\n");
 displaylist(head);

 // Delete an elector
 cin_num = 987654321;
 printf("Deleting elector with ID number %ld\n", cin_num);
 deletelector(&head, cin_num);

 // Display the updated list
 printf("\nUpdated List of Electors:\n");
 displaylist(head);

 // Count the number of electors
 int num_electors = countelector(head);
 printf("\nNumber of Electors: %d\n", num_electors);

 // Free memory
 freelist(&head);

 return 0;
}
```
## Contributing

Contributions to this project are welcome! If you'd like to contribute, please follow these steps:

1. Fork the repository.
2. Create a new branch (`git checkout -b feature`)
3. Make your changes.
4. Commit your changes (`git commit -am 'Add new feature'`)
5. Push to the branch (`git push origin feature`)
6. Create a new Pull Request.

Please ensure that your code follows the existing coding style and conventions.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.




