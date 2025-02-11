#include <stdio.h>
#include <string.h>
#include "datatype.h"

void showBookMenu(){
	printf("\n===========MENU===========\n");
	printf("1. Show list of books\n");
	printf("2. Add book\n");
	printf("3. Edit book information\n");
	printf("4. Delete Book\n");
	printf("5. Search books by name\n");
	printf("6. Sort books by price\n");
	printf("7. Exit!\n");

};

//10,30,30,10,10,20.
void showListBook(struct Book *book, int current){
	printf("\n\t\t\t\t\t\t******All book*******\n");
	printf("|==========|==============================|==============================|==========|==========|====================|\n");
	printf("|    %-6s|             %-17s|            %-18s| %-9s|  %-8s|  %-18s|\n", "Id", "Title", "Author", "Quantity", "Price", "Date publication");
	printf("|==========|==============================|==============================|==========|==========|====================|\n");
	for(int i = 0; i < current; i++){
		printf("|%-10s|%30s|%30s|%10d|%10d|%13d/%d/%d|\n", book[i].bookid, book[i].title, book[i].author, book[i].quantity, book[i].price, book[i].publication.day, book[i].publication.month, book[i].publication.year);
		printf("|----------|------------------------------|------------------------------|----------|----------|--------------------|\n");
	}
};

void addBook(struct Book *book, int *current){
	char id[10];
	printf("enter the id: ");
	fflush(stdin);
	fgets(id, 10, stdin);
	id[strcspn(id,"\n")] = '\0';
	int checkId = 0; 
	for(int i = 0; i < *current; i++){
		if(strcmp(id, book[i].bookid) == 0){
			checkId = 1;
			break;										
		} 
	}
	if(checkId){
		printf("Invalid id!\n"); //id khong hop le
	}else{
		strcpy(book[*current].bookid, id);
		printf("enter the title: ");
		fgets(book[*current].title,30,stdin);
		book[*current].title[strcspn(book[*current].title, "\n")] = '\0';
		printf("enter the author: ");
		fgets(book[*current].author,30,stdin);
		book[*current].author[strcspn(book[*current].author, "\n")] = '\0';
		printf("enter the quantity: ");
		fflush(stdin);
		scanf("%d", &book[*current].quantity);
		printf("enter the price: ");
		scanf("%d", &book[*current].price);	
		printf("enter the Day: ");
		scanf("%d", &book[*current].publication.day);
		printf("enter the month: ");
		scanf("%d", &book[*current].publication.month);
		printf("enter the year: ");
		scanf("%d", &book[*current].publication.year);	
		(*current)++;
		
		printf("successfully added book\n"); //Da them sach thanh cong
	}
	return;
};

void fixBook(struct Book *book, int current){
	char id[10];
	int index = 0;
	printf("enter the id: ");
	fflush(stdin);
	fgets(id, 10, stdin);
	id[strcspn(id,"\n")] = '\0';
	int checkId = 1;
	for(int i = 0; i < current; i++){
		if(strcmp(id, book[i].bookid) == 0){
			checkId = 0;
			index = i;
			break;										
		} 
	}
	if(checkId){
		printf("id does not exist!\n"); //id khong ton tai
	}else{
		showBook(book, index);
		printf("\n");
		
		printf("enter the title: ");
		fgets(book[index].title,30,stdin);
		book[index].title[strcspn(book[index].title, "\n")] = '\0';
		printf("enter the author: ");
		fgets(book[index].author,30,stdin);
		book[index].author[strcspn(book[index].author, "\n")] = '\0';
		printf("enter the quantity: ");
		fflush(stdin);
		scanf("%d", &book[index].quantity);
		printf("enter the price: ");
		scanf("%d", &book[index].price);	
		printf("enter the Day: ");
		scanf("%d", &book[index].publication.day);
		printf("enter the month: ");
		scanf("%d", &book[index].publication.month);
		printf("enter the year: ");
		scanf("%d", &book[index].publication.year);	
		
		printf("fix success!\n"); //sua thanh cong
	}
	return;	
};

void showBook(struct Book *book, int index){
	printf("\nTitle: %s\n", book[index].title);
	printf("Author: %s\n", book[index].author);
	printf("Quantity: %d\n", book[index].quantity);
	printf("Price: %d\n", book[index].price);
	printf("Date publication: %d/%d/%d\n", book[index].publication.day, book[index].publication.month, book[index].publication.year);
	
	return;
}

