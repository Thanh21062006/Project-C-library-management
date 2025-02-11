#include <stdbool.h>
#include <stdio.h>

struct Date{
	int month,day,year;
};

struct Book{
	char bookid[10];
	char title[30];
	char author[30];
	int quantity;
	int price;
	struct Date publication;
};

struct member{
	char memberId[10];
	char name[20];
	char phone[10];
	bool status;
	struct Book Borrowedbooks[];
};
