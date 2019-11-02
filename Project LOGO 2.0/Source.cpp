#include<stdio.h>
#include<iostream>

char A[50][50] = { 0 };
class var
{
public:
		int  n, m = 0, l, p;
		static int i, j;
};
int var::i, var::j;
var a;
void move_pointer(int &, int &);
void horizontal_dashes(int);
void vertical_dashes(int);
void diagonal_dashes(int);
void display_matrix();

int main()
{
	#include"Input_descript.h"
	while (a.n != 5)
	{
		printf("Enter the modifier\n");
		scanf_s("%d", &a.n);
		switch (a.n) {
					case 1: {
							printf("Enter the location from where you want to start drawing\n");
							scanf_s("%d%d", &var::i, &var::j);
							move_pointer(var::i, var::j);
							}
					break;
					case 2: {
							printf("Enter the amount of horizontal dashes present\n");
							scanf_s("%d", &a.m);
							horizontal_dashes(a.m);
							}
					break;
					case 3: {
							printf("Enter the amount of vertical dashes present\n");
							scanf_s("%d", &a.l);
							vertical_dashes(a.l);
							}
					break;
					case 4: {
							printf("Enter the amount of diagonal dashes you want\n");
							scanf_s("%d", &a.p);
							diagonal_dashes(a.p);
							}
					break;
					}
	}
	printf("\t\tThe final diagram is----\n\n");
	display_matrix();
	std::cin.get();
}
void move_pointer(int &i, int &j)
{ 
	A[var::i][var::j] = ' ';
}
void horizontal_dashes(int m)
{
	int r;
	for (r = 0;r < m;r++)
	{
		A[var::i][r+var::j] = '*';
	}
	var::j = var::j + m;
}
void vertical_dashes(int l)
{
	int r;
	for (r = 0;r < l;r++)
	{
		A[r + var::i][var::j ] = '*';
	}
	var::i = var::i + l;
}
void diagonal_dashes(int p)
{
	int r;
	for (r = 0;r < p;r++)
	{
		A[r + var::i][var::j + r] = '*';
	}
	var::i = var::i + p;
	var::j = var::j + p;
}
void display_matrix()
{
	int r, q;
		for (r = 0;r < 50;r++)
		{
			for (q = 0;q < 50;q++)
			{
				printf("%c", A[r][q]);
			}
			printf("\n");
		}
}