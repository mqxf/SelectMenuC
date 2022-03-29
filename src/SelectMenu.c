/*
 ============================================================================
 Name        : SelectMenu.c
 Author      : Maxim Savenkov
 Version     :
 Copyright   : © Maxim Savenkov 2022
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

unsigned int selection = 1;
unsigned int max = 5;
void select(int i, int );
void listenMenu();
void gotoxy(int x, int y) {
	printf("%c[%d;%df",0x1B,y,x);
}

int main(void) {
	system("clear");
	printf("Please input how many options you want your menu to have:\n");
	scanf("%d", &max);
	system("clear");
	printf("> Option 1\n");
	for (int i = 2; i <= max; i++) {
		printf("Option %d\n", i);
	}
	printf("\nNavigate the menu with 'W' and 'S', press enter to select, and 'e' to exit.\n");
	gotoxy(0, max + 4);
	listenMenu();
	system("clear");
	return 0;
}

void select(int i, int p) {
	gotoxy(0, p);
	printf("Option %d            ", p);
	gotoxy(0, i);
	printf("> Option %d          ", i);
	gotoxy(0, max + 4);
}

void listenMenu() {
	int c;
	system ("/bin/stty raw");
	c = getchar();
	switch(c) {
	case 115:
		if (selection < max) {
			select(selection + 1, selection);
			selection++;
		}
		else {
			select(1, selection);
			selection = 1;
		}
		break;
	case 119:
		if (selection > 1) {
			select(selection - 1, selection);
			selection--;
		}
		else {
			select(max, selection);
			selection = max;
		}
		break;
	case 13:
		gotoxy(0, max + 3);
		printf("\rYou chose option %d!        ", selection);
		gotoxy(0, max + 4);
		break;
	case 101:
		system ("/bin/stty cooked");
		return;
		break;
	default:
		break;
	}
	//up = 279165
	//down = 279166
	//enter = 13
	//e = 101
	system ("/bin/stty cooked");
	listenMenu();
}
