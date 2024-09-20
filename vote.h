#ifndef VOTE_H
#define VOTE_H

typedef struct elector {
	char* name;
	long cin_num;
	int choice;
	struct elector* next;
} *T_Elector;

void freelist(T_Elector* head);

void addelector(T_Elector* ptr_to_head, const char* name, long cin_num, int choice);

void displaylist(T_Elector head);

T_Elector creationelector(T_Elector head);

T_Elector creation_T_Elector_Linked_List(void);

T_Elector insertSorted(T_Elector head, T_Elector newVoter);

int alphaOrder(const char* name1, const char* name2);

int countelector(T_Elector head);

int findelector(T_Elector head, long cin_num);

void decomposelist(T_Elector originalList, T_Elector* leftList, T_Elector* rightList, T_Elector* whiteList);

void deletelector(T_Elector* head,long cin_num);

void sortlist(T_Elector head);

T_Elector mergelists(T_Elector headLeft, T_Elector headRight);

int countLR(T_Elector mergedList);

#endif
