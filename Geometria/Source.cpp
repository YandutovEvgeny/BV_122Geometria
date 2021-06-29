#include<iostream>

using namespace std;
using std::cout;
using std::endl;
using std::cin;

//#define TRIANGLE_1
//#define TRIANGLE_2
//#define TRIANGLE_3
//#define TRIANGLE_4
//#define ROMBUS
//#define PLUS_MINUS
//#define ASCII_CHESSBOARD
#define HARD_CHESSBOARD

/*#define UPPER_LEFT_ANGLE  (char)218
#define DOWN_RIGHT_ANGLE  (char)217
#define UPPER_RIGHT_ANGLE (char)191
#define DOWN_LEFT_ANGLE   (char)192
#define VERT_LINE         (char)179
#define HORIZON_LINE      (char)196 << (char)196
#define WHITE_BOX         "\xDB\xDB" //char(219) << char(219)
#define BLACK_BOX         "\x20\x20" //char(12) << char(12)*/

#define STAR       "\x2A " //(char)42
#define BACKSPACE  "  "    //(char)8

void main()
{
	setlocale(LC_ALL, "Rus");
	int n;
	int mirror_n;
	cout << "Введите размер фигуры: "; cin >> n;
	

#ifdef TRIANGLE_1
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}
#endif // TRIANGLE_1
#ifdef TRIANGLE_2
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}
#endif // TRIANGLE_2
#ifdef TRIANGLE_3
	for (int i = 0; i < n; i++) //Повторяет вывод строки
	{
		for (int j = 0; j < i; j++)
		{
			cout << " ";
		}
		for (int j = i; j < n; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}
#endif // TRIANGLE_3
#ifdef TRIANGLE_4
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			cout << " ";
		}
		for (int j = 0; j <= i; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}
#endif // TRIANGLE_4
#ifdef ROMBUS
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++) cout << " ";
		cout << "/";
		for (int j = 0; j < i * 2; j++) cout << " ";
		cout << "\\";
		cout << endl;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++) cout << " ";
		cout << "\\";
		for (int j = 0; j < (n - i - 1) * 2; j++) cout << " ";
		cout << "/";
		cout << endl;
	}
#endif // ROMBUS
#ifdef PLUS_MINUS
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//if((i + j) % 2 == 0) cout << "+ "; else cout << "- ";
			//(i + j) % 2 == 0 ? cout << "+ " : cout << "- ";
			cout << ((i + j) % 2 == 0 ? "+ " : "- ");
		}
		cout << endl;
	}
#endif // PLUS_MINUS
#ifdef ASCII_CHESSBOARD
	setlocale(LC_ALL, "C"); //Возвращает кодировку по умолчанию
//for (int i = 0; i < 256; i++)
//{
//	cout << i << "\t" << (char)i << endl;
//}
	n++;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == 0 && j == 0)cout << UPPER_LEFT_ANGLE;
			else if (i == 0 && j == n)cout << UPPER_RIGHT_ANGLE;
			else if (i == n && j == 0)cout << DOWN_LEFT_ANGLE;
			else if (i == n && j == n)cout << DOWN_RIGHT_ANGLE;
			else if (i == 0 || i == n)cout << HORIZON_LINE;
			else if (j == 0 || j == n)cout << VERT_LINE;
			else
			{
				if ((i + j) % 2 == 0)cout << WHITE_BOX;
				else cout << BLACK_BOX;
				//cout << ((i + j) % 2 == 0) ? WHITE_BOX : BLACK_BOX;
			}
		}
		cout << endl;
	}
#endif // ASCII_CHESSBOARD
#ifdef HARD_CHESSBOARD
	mirror_n = n;
	n *= n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((i / mirror_n + j / mirror_n) & 1) cout << BACKSPACE;
			else cout << STAR;
			//cout << ((i / 5 + j / 5) & 1) ? BACKSPACE : STAR;
		}
		cout << endl;
	}
#endif // HARD_CHESSBOARD

}

