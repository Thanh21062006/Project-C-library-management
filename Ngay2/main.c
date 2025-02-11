#include <stdio.h>
#include <stdlib.h>
#include "datatype.h"
#include "function.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int choice, current = 0;
	struct Book book[1000];
	
	while(true){
		showBookMenu();
		printf("Enter the choice: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				showListBook(book, current);
				break;
			case 2:
				addBook(book, &current);
				break;
			case 3:
				fixBook(book, &current);
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				printf("Exit!!!\n");
				break;
			default:
				printf("Invaild choice!\n");
				break;			
		}
		if(choice == 7){
			break;
		}				
	}
	return 0;
}
