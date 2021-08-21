#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

void draw_map(const char* iMap[], int iCurrentRow, int iCurrentColumn);
bool IsOK(const char* iMap[], int iRow, int iColumn);

int main()
{
	const char* map[] = {
	//   123456789012345678901234567890
		"** ***************************", // 1
		"** ***************************", // 2
		"**   *************************", // 3
		"****  ************************", // 4
		"***** ************************", // 5
		"*****     ********************", // 6
		"***** *** ********************", // 7
		"***** ***     ****************", // 8
		"***** *******    *************", // 9
		"***** ************************", // 0
		"***** ************************", // 1
		"** ** ************************", // 2
		"**    ************************", // 3
		"****  ************************", // 4
		"***** ************************", // 5
		"*****     ********************", // 6
		"***** *** ********************", // 7
		"***** ***     ****************", // 8
		"***** *******    *************", // 9
		"***** ******** ***************", // 0
		NULL
	};

	int cur_r = 10;
	int cur_c = 5;
	
	while (1) {
		draw_map(map, cur_r, cur_c);

		_kbhit();
		int c = _getch();

		int row = cur_r;
		int column = cur_c;
		bool bOK = false;

		if (c == 104) // 'h'
			--column;
		else if (c == 106) // 'j'
			++row;
		else if (c == 107) // 'k'
			--row;
		else if (c == 108) // 'l'
			++column;
		else if (c == 113) // 'q'
			break;

		if (IsOK(map, row, column) == true) {
			cur_r = row;
			cur_c = column;
		}
	}
}

bool IsOK(const char* iMap[], int iRow, int iColumn)
{
	int row_sz = 0;
	for (int r = 0; iMap[r] != NULL; r++) ++row_sz;

	if (iRow < 0 || iColumn < 0 || row_sz <= iRow || strlen(iMap[0]) <= iColumn) {
		Beep(440, 300);
		Beep(494, 300);
		Beep(554, 300);
		Beep(587, 300);
		Beep(659, 300);
		Beep(740, 300);
		Beep(830, 300);
		Beep(880, 300);
		return false;
	}

	bool ret = false;
	if (iMap[iRow][iColumn] == ' ')	ret = true;

	return ret;
}

void draw_map(const char* iMap[], int iCurrentRow, int iCurrentColumn)
{
	for (int i = 0; iMap[i] != NULL ; i++) {
		for (int j = 0; iMap[i][j] != '\0' ; j++) {
			if (iCurrentRow == i && iCurrentColumn == j)
				printf("@");
			else
				printf("%c", iMap[i][j]);
		}
		printf("\n");
	}
}

