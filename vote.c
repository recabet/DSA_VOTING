#include "vote.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void freelist(T_Elector* head)
{
	if(!head)
	{
		fprintf(stderr, "Error: Null pointer provided to freelist\n");
		exit(EXIT_FAILURE);
	}

	T_Elector current = *head;
	while(current)
	{
		const T_Elector temp = current;
		current = current->next;
		free(temp->name);
		free(temp);
	}
	*head = NULL;
	printf("The memory is freed.\n");
}

void addelector(T_Elector* ptr_to_head, const char* name, const long cin_num, const int choice)
{
	T_Elector newVoter = malloc(sizeof(struct elector));
	if(!newVoter)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	newVoter->name = strdup(name);  // Duplicate the string
	if(!newVoter->name)
	{
		perror("strdup");
		exit(EXIT_FAILURE);
	}
	newVoter->choice = choice;
	newVoter->cin_num = cin_num;
	*ptr_to_head = insertSorted(*ptr_to_head, newVoter);
}

void displaylist(const T_Elector head)
{
	T_Elector voter = head;
	printf("\nThe list of voters : ");
	int count = 1;
	while(voter)
	{
		printf("\n%d) Name: %s, ID number: %ld, Choice: %d", count, voter->name, voter->cin_num, voter->choice);
		voter = voter->next;
		count++;
	}
	printf("\n\n");
}

T_Elector creationelector(T_Elector head)
{
	long cin_num;
	char name[100];
	T_Elector voter = malloc(sizeof(struct elector));
	if(!voter)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	printf("\nEnter the new voter's name: ");
	scanf("%99s", name);
	voter->name = strdup(name);  // Duplicate the string
	if(!voter->name)
	{
		perror("strdup");
		exit(EXIT_FAILURE);
	}
	printf("Enter the new voter's ID number: ");
	scanf("%ld", &cin_num);
	while(findelector(head, cin_num))
	{
		printf("\nThis user has the same ID. Please enter another ID: ");
		scanf("%ld", &cin_num);
	}
	voter->cin_num = cin_num;
	printf("The options for new voter's choice are as below: \n");
	printf("NAME1: 1\n");
	printf("NAME2: 2\n");
	printf("NAME3: 3\n");
	printf("NAME4: 4\n");
	printf("NAME5: 5\n");
	printf("Enter the new voter's choice: ");
	scanf("%d", &(voter->choice));
	voter->next = NULL;
	return voter;
}

T_Elector creation_T_Elector_Linked_List(void)
{
	T_Elector head = NULL;
	int number_of_voters;
	printf("\nEnter the number of voters: ");
	scanf("%d", &number_of_voters);
	for(int i = 0; i < number_of_voters; i++)
	{
		T_Elector newVoter = creationelector(head);
		head = insertSorted(head, newVoter);
	}
	return head;
}

T_Elector insertSorted(T_Elector head, T_Elector newVoter)
{
	if(!head || alphaOrder(newVoter->name, head->name) < 0)
	{
		newVoter->next = head;
		return newVoter;
	}
	T_Elector current = head;
	while(current->next && alphaOrder(newVoter->name, current->next->name) >= 0)
	{
		current = current->next;
	}
	newVoter->next = current->next;
	current->next = newVoter;
	return head;
}

int alphaOrder(const char* name1, const char* name2)
{
	return strcmp(name1, name2);
}

int countelector(const T_Elector head)
{
	T_Elector voter = head;
	int count = 0;
	while(voter)
	{
		count++;
		voter = voter->next;
	}
	return count;
}

int findelector(const T_Elector head, const long cin_num)
{
	T_Elector voter = head;
	while(voter)
	{
		if(voter->cin_num == cin_num)
		{
			printf("Name: %s, ID number: %ld, Choice: %d.\n", voter->name, voter->cin_num, voter->choice);
			return 1;
		}
		voter = voter->next;
	}
	return 0;
}

void decomposelist(const T_Elector originalList, T_Elector* leftList, T_Elector* rightList, T_Elector* whiteList)
{
	if(!leftList || !rightList || !whiteList)
	{
		fprintf(stderr, "Error: Null pointer provided to decomposelist\n");
		exit(EXIT_FAILURE);
	}

	*leftList = NULL;
	*rightList = NULL;
	*whiteList = NULL;
	T_Elector leftTail = NULL;
	T_Elector rightTail = NULL;
	T_Elector whiteTail = NULL;

	T_Elector current = originalList;
	while(current)
	{
		T_Elector newNode = malloc(sizeof(struct elector));
		if(!newNode)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		newNode->name = strdup(current->name);
		if(!newNode->name)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
		newNode->cin_num = current->cin_num;
		newNode->choice = current->choice;
		newNode->next = NULL;
		if(current->choice == 1 || current->choice == 3)
		{
			if(!*leftList)
			{
				*leftList = newNode;
				leftTail = newNode;
			}
			else
			{
				leftTail->next = newNode;
				leftTail = newNode;
			}
		}
		else if(current->choice == 2 || current->choice == 4)
		{
			if(!*rightList)
			{
				*rightList = newNode;
				rightTail = newNode;
			}
			else
			{
				rightTail->next = newNode;
				rightTail = newNode;
			}
		}
		else
		{
			if(!*whiteList)
			{
				*whiteList = newNode;
				whiteTail = newNode;
			}
			else
			{
				whiteTail->next = newNode;
				whiteTail = newNode;
			}
		}
		current = current->next;
	}
}

void deletelector(T_Elector* head, const long cin_num)
{
	if(!head || !*head)
	{
		fprintf(stderr, "Error: Null pointer provided to deletelector\n");
		exit(EXIT_FAILURE);
	}

	T_Elector ptr_to_deleting_voter = *head;
	if(ptr_to_deleting_voter->cin_num == cin_num)
	{
		(*head) = ptr_to_deleting_voter->next;
		free(ptr_to_deleting_voter->name);
		free(ptr_to_deleting_voter);
	}
	else
	{
		T_Elector deleting_voter = ptr_to_deleting_voter->next;
		while(deleting_voter && deleting_voter->cin_num != cin_num)
		{
			ptr_to_deleting_voter = ptr_to_deleting_voter->next;
			deleting_voter = ptr_to_deleting_voter->next;
		}
		if(deleting_voter)
		{
			ptr_to_deleting_voter->next = deleting_voter->next;
			free(deleting_voter->name);
			free(deleting_voter);
		}
		else
		{
			fprintf(stderr, "Error: Voter with ID %ld not found\n", cin_num);
		}
	}
}

void sortlist(T_Elector head)
{
	if(!head)
	{
		printf("Your list doesn't exist\n");
		return;
	}

	T_Elector voter = head;
	int swapped = 1;
	while(swapped)
	{
		swapped = 0;
		voter = head;
		while(voter->next)
		{
			if(voter->cin_num > voter->next->cin_num)
			{
				const long tempVal = voter->cin_num;
				voter->cin_num = voter->next->cin_num;
				voter->next->cin_num = tempVal;
				swapped = 1;
			}
			voter = voter->next;
		}
	}
}

T_Elector mergelists(T_Elector headLeft, T_Elector headRight)
{
	T_Elector mergedHead = NULL, mergedTail = NULL;
	while(headLeft && headRight)
	{
		T_Elector* minNode = (alphaOrder(headLeft->name, headRight->name) < 0) ? &headLeft : &headRight;
		if(!mergedHead)
		{
			mergedHead = *minNode;
			mergedTail = *minNode;
		}
		else
		{
			mergedTail->next = *minNode;
			mergedTail = *minNode;
		}
		*minNode = (*minNode)->next;
	}
	if(headLeft)
	{
		mergedTail->next = headLeft;
	}
	if(headRight)
	{
		mergedTail->next = headRight;
	}
	return mergedHead;
}

int countLR(T_Elector mergedList)
{
	int count = 0;
	while(mergedList)
	{
		count++;
		mergedList = mergedList->next;
	}
	return count;
}
