// Sample.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class drob
{
public:
	int up;
	int down;
	drob operator+(const drob &var)
	{
		drob tmp;
		tmp.up = (up*var.down) + (var.up*down);
		tmp.down = down * var.down;
		return tmp;
	}
	drob operator-(const drob &var)
	{
		drob tmp;
		tmp.up = (up*var.down) - (var.up*down);
		tmp.down = down * var.down;
		return tmp;
	}
	drob operator*(const drob &var)
	{
		drob tmp;
		tmp.up = up * var.up;
		tmp.down = down * var.down;
		return tmp;
	}
	drob operator/(const drob &var)
	{
		drob tmp;
		tmp.up = up * var.down;
		tmp.down = down * var.up;
		return tmp;
	}
	void NOD()
	{
		double tmpup = up;
		if (tmpup < 0)
			tmpup = tmpup*(-1);
		double tmpdown = down;
		int tmp=1;
		double tmp1=1;
		double tmp2 = 2;
		if (tmpup == 0)
			return;
		if (tmpdown == 0)
			return;
		while (tmp1!=tmp2)
		{
			if (tmpup > tmpdown) 
			{
				tmp2 = tmpup / tmpdown;
				tmp = tmpup / tmpdown;
				tmp1 = tmp + 0.0;
				tmpup = tmpup - tmpdown*tmp;
			}
			else
			{
				tmp2 = tmpdown / tmpup;
				tmp = tmpdown / tmpup;
				tmp1 = tmp + 0.0;
				tmpdown = tmpdown - tmpup*tmp;
			}
		}
		if (tmpup < tmpdown)
		{
			up = up / tmpdown;
			down = down / tmpdown;
		}
		else
		{
			up = up / tmpup;
			down = down / tmpup;
		}
	}
	friend istream& operator >> (istream &in, drob &mt)
	{
		in >> mt.up;
		cout << "-----" << endl;
		in >> mt.down;
		cout << endl;
		return in;
	}
};

int main()
{
	drob mas[3][6];
	setlocale(LC_ALL, "Russian");
	int i, j;
	int choice;
	int i1, i2;
	drob tmp;
	cout << "Ввод таблицы" << endl;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 6; j++)
		{
			cout << i+1 << " столбец | строка " << j+1 << endl;;
			cin >> mas[i][j];
		}
	
	while (true)
	{
		for (i = 0; i < 3; i++)
			for (j = 0; j < 6; j++)
				mas[i][j].NOD();
		cout << "     Текущая таблица" << endl;
		for (j = 0; j < 6; j++)
		{
			cout << mas[0][j].up << "     " << mas[1][j].up << "     " << mas[2][j].up << endl;
			cout << mas[0][j].down << "     " << mas[1][j].down << "     " << mas[2][j].down << endl;
			cout << endl;
		}
		cout << "Введите 0 для выхода из программы" << endl;
		cout << "Введите 1 для сложения двух столбцов" << endl;
		cout << "Введите 2 для вычитания двух столбцов" << endl;
		cout << "Введите 3 для умножения столбца на число" << endl;
		cin >> choice;
		if (choice == 1)
		{
			cout << "Номер столбца для которого производится вычисление" << endl;
			cin >> i1;
			cout << "Номер столбца, который складывается" << endl;
			cin >> i2;
			i1--;
			i2--;
			cout << "Ввод дроби, на которую умножается столбец при сложении" << endl;
			cin >> tmp;
			for (j = 0; j< 6; j++)
				mas[i1][j]=mas[i1][j] + (mas[i2][j]*tmp);
		}
		if (choice == 2)
		{
			cout << "Номер столбца для которого производится вычисление" << endl;
			cin >> i1;
			cout << "Номер столбца, который  вычитается" << endl;
			cin >> i2;
			i1--;
			i2--;
			cout << "Ввод дроби, на которую умножается столбец при вычитании" << endl;
			cin >> tmp;
			for (j = 0; j< 6; j++)
				mas[i1][j] = mas[i1][j] - (mas[i2][j]*tmp);
		}
		if (choice == 3)
		{
			cout << "Номер столбца" << endl;
			cin >> i1;
			i1--;
			cout << "Ввод дроби, на которую умножается столбец" << endl;
			cin >> tmp;
			for (j = 0; j<6; j++)
				mas[i1][j] = mas[i1][j]*tmp;
		}
		if (choice == 0)
			break;

	}
    return 0;
}

