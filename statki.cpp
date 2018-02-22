
#include <stdio.h>
#include <tchar.h>
#include "time.h"
#include "windows.h"
#include "conio.h"
#include <iostream>

void dwojki(int tab[][10]);
void pokaz(char tab2[][10]);
void gotoxy(int x, int y);

void los(int tab[][10])
{
	int ileStatkow = 1, kierunek, i, j, ileMasztow = 4, x, y, k;
	//	kierunek=rand()%2;
	//	x=rand()%10;
	//	y=rand()%10;
	ileMasztow = 4;
	ileStatkow = 1;
	bool spr = true;
	for (i = 0; i<4; i++)
	{
		for (j = 0; j<ileStatkow; j++)
		{
			kierunek = rand() % 2;	//je¿eli 1 wtedy pionowo ,je¿eli 0 wtedy poziomo
			x = rand() % 10;
			y = rand() % 10;
			if (kierunek == 1)
			{
				if (y>10 - ileMasztow)
				{

					for (k = 0; k<ileMasztow; k++)
					{
						if (tab[y - k][x] == 1 || tab[y - k][x] == 2)
							spr = false;
					}
					if (spr != false)
						for (k = 0; k<ileMasztow; k++)
							tab[y - k][x] = 1;
				}
				else
				{
					for (k = 0; k<ileMasztow; k++)
					{
						if (tab[y + k][x] == 1 || tab[y + k][x] == 2)
							spr = false;
					}
					if (spr != false)
						for (k = 0; k<ileMasztow; k++)
							tab[y + k][x] = 1;
				}

			}
			else
			{
				if (x>10 - ileMasztow)
				{
					for (k = 0; k<ileMasztow; k++)
					{
						if (tab[y][x - k] == 1 || tab[y][x - k] == 2)
							spr = false;
					}
					if (spr != false)
						for (k = 0; k<ileMasztow; k++)
							tab[y][x - k] = 1;
				}
				else
				{
					for (k = 0; k<ileMasztow; k++)
					{
						if (tab[y][x + k] == 1 || tab[y][x + k] == 2)
							spr = false;
					}
					if (spr != false)
						for (k = 0; k<ileMasztow; k++)
							tab[y][x + k] = 1;
				}
			}
			if (spr == false)
			{
				spr = true;
				j--;
			}
			dwojki(tab);
		}
		ileMasztow--;
		ileStatkow++;

	}
	
	/*printf("   1 2 3 4 5 6 7 8 9 10\n");
	for (i = 0; i<10; i++)
	{
		printf("%2d", i + 1);
		for (j = 0; j<10; j++)
		{
			printf("%2c", tab[i][j]);
		}
		printf("\n");
	}*/
	
}
void zeruj(int tab[10][10], char tab2[][10])
{
	int i, j;
	for (i = 0; i<10; i++)
		for (j = 0; j<10; j++)
		{
			tab[i][j] = 0;
			tab2[i][j] = ' ';
		}

}
void dwojki(int tab[][10])
{
	int i, j;
	for (i = 0; i<10; i++)
		for (j = 0; j<10; j++)
		{
			if (tab[i][j] == 1)
			{
				if (tab[i - 1][j] != 1 && i>0)
					tab[i - 1][j] = 2;
				if (tab[i][j - 1] != 1 && j>0)
					tab[i][j - 1] = 2;
				if (tab[i - 1][j - 1] != 1 && i>0 && j>0)
					tab[i - 1][j - 1] = 2;
				if (tab[i + 1][j] != 1 && i<9)
					tab[i + 1][j] = 2;
				if (tab[i + 1][j + 1] != 1 && i<9 && j<9)
					tab[i + 1][j + 1] = 2;
				if (tab[i - 1][j + 1] != 1 && i>0 && j<9)
					tab[i - 1][j + 1] = 2;
				if (tab[i][j + 1] != 1 && j<9)
					tab[i][j + 1] = 2;
				if (tab[i + 1][j - 1] != 1 && j>0 && i<9)
					tab[i + 1][j - 1] = 2;

			}
		}
}
void strzal(int tab[][10], char tab2[][10])
{
	bool koniec = false;
	int zlicz = 0;
	//char tab3[10][10];
	int znak, i = 4, j = 4, score = 0, x, y, k, l;
	pokaz(tab2);
	while (score <20)
	{
		
		znak = _getch();
		x = i; y = j;
		switch (znak)
		{
		case 72:if (i>0)	--i; gotoxy(2 * j + 4, i + 2); printf("*");	gotoxy(2 * y + 4, x + 2); printf("%c", tab2[x][y]); gotoxy(2 * j + 4, i + 2);		break;	//strzalka w gore
		case 80:if (i<9)	++i; gotoxy(2 * j + 4, i + 2); printf("*");	gotoxy(2 * y + 4, x + 2); printf("%c", tab2[x][y]); gotoxy(2 * j + 4, i + 2);		break;	//strzalka w dol
		case 75:if (j>0)	--j; gotoxy(2 * j + 4, i + 2); printf("*");	gotoxy(2 * y + 4, x + 2); printf("%c", tab2[x][y]); gotoxy(2 * j + 4, i + 2);		break;	//strzalka w lewo
		case 77:if (j<9)	++j; gotoxy(2 * j + 4, i + 2); printf("*");	gotoxy(2 * y + 4, x + 2); printf("%c", tab2[x][y]); gotoxy(2 * j + 4, i + 2);		break;	//strzalka w prawo
		case 13:/*tab3[i][j]='x';*/tab2[i][j] = 'x'; gotoxy(2 * y + 4, x + 2); printf("%c", tab2[x][y]); gotoxy(1, 13);
			if (tab[i][j] == 1)
			{
				tab2[i][j] = 2;
				zlicz = 0;
				tab[i][j] = 0;
				score++;
				for (k = 1; k<4; k++)
				{
					if (tab[i + k][j] == 1)
						zlicz++;
					else if (tab[i - k][j] == 1)
						zlicz++;
					else if (tab[i][j + k] == 1)
						zlicz++;
					else if (tab[i][j - k] == 1)
						zlicz++;
					else break;
				}
				printf("Trafiony ");
				if (zlicz == 0)
					printf("zatopiony");
				printf("\n");
			}
			else
				printf("Pudlo                   \n");
			break;		//ENTER
		case 27:gotoxy(1, 13); 
			printf("\nKoniec gry\nZdobyte punkty: %d", score);
			getchar();
			getchar();
			exit(0);
			break;
		}

	}
	printf("\nKoniec gry\nZdobyte punkty: %d", score);

}
void pokaz(char tab2[][10])
{
	int i, j;
	printf("   1 2 3 4 5 6 7 8 9 10\n");
	for (i = 0; i<10; i++)
	{
		printf("%2d", i + 1);
		for (j = 0; j<10; j++)
		{
			printf("%2c", tab2[i][j]);
		}
		printf("\n");
	}
}
void gotoxy(int x, int y)
{
	COORD c;
	c.X = x - 1;
	c.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int main()
{
	srand(time(NULL));
	int tablicaDoLosowania[10][10];
	char tablicaDoStrzelania[10][10];
	zeruj(tablicaDoLosowania, tablicaDoStrzelania);
	printf("---------INSTRUKCJA--------\nUstrzel wszystkie statki.\nPoruszaj sie strzalkami aby wybrac pole ,w ktore chcesz trafic.\nAby strzelic uzyj klawisza ENTER.\nPOWODZENIA!\n");
	printf("Jezeli chcesz zakonczyc rozgrywke wcisnij klawisz ESC\n");
	printf("Wcisnij dowolny klawisz aby rozpoczac\n");
	getchar();
	system("cls");
	los(tablicaDoLosowania);
	strzal(tablicaDoLosowania, tablicaDoStrzelania);
	getchar();
	getchar();
	return 0;
}
