#include <iostream>
#include <string>
#include <stdlib.h>
#include <Windows.h>

using namespace std;

string func(double n, bool ok=true) {
	string text = "";
	if (ok) {
		text = ".";
		text += (char)('0' + ((int)(n * 10) % 10));
	}
	int num = n;
	for (; num > 0; num /= 10) text = (char)('0' + num % 10) + text;
	return text;
}

int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const int Size = 2;
	double sumart = 0, sumdif = 0, dmark = 0, amark = 0, artmax = 0, artmin = 10, difmax = 0, difmin = 10, order = 0;
	char buf[100];
	double difunder[Size];
	string str[Size];
	string stroka[Size];

	for (int i = 0; i < Size; i++)
	{
		string name = "";
		cin.getline(buf, 100, '\n');
		stroka[i] = buf;

		sumart = 0;
		sumdif = 0;
		artmax = 0;
		artmin = 10;
		difmax = 0;
		difmin = 10;

		int j = stroka[i].length();
		int counter = 0;
		while (buf[j] != ':')
		{
			if (isdigit(buf[j]))
			{

				if (buf[j - 1] == '.')
				{
					double fraction = ((int)buf[j] - 48);
					sumart += ((fraction / 10) + ((int)buf[j - 2] - 48));
					if (artmax < ((fraction / 10) + ((int)buf[j - 2] - 48)));
						artmax = ((fraction / 10) + ((int)buf[j - 2] - 48));
					if (artmin > (((fraction / 10) + ((int)buf[j - 2] - 48))))
						artmin = (((fraction / 10) + ((int)buf[j - 2] - 48)));
					j -= 2;
				}
				if ((buf[j] == '0') && (buf[j - 1] == '1'))
				{
					sumart += 10;
					artmax = 10;
					j--;
				}
				else
				{
					sumart += ((int)buf[j] - 48);
					if (artmax < ((int)buf[j] - 48))
						artmax = ((int)buf[j] - 48);
					if (artmin > ((int)buf[j] - 48))
						artmin = ((int)buf[j] - 48);
				}
			}
			j--;
		}
		//cout << sumart << endl;

		int k = j - 1;
		while (buf[k] != ':')
		{
			if (isdigit(buf[k]))
			{
				if (buf[k - 1] == '.')
				{
					double fraction = ((int)buf[k] - 48);
					sumdif += ((int)buf[k - 2] - 48) + (fraction / 10);
					if (difmax < ((int)buf[k - 2] - 48) + (fraction / 10))
						difmax = ((int)buf[k - 2] - 48) + (fraction / 10);
					if (difmin > (((int)buf[k - 2] - 48) + (fraction / 10)));
					difmin = ((int)buf[k - 2] - 48) + (fraction / 10);
					k -= 2;
				}
				if ((buf[k] == '0') && (buf[k - 1] == '1'))
				{
					sumdif += 10;
					difmax = 10;
					k--;
				}
				else
				{
					sumdif += ((int)buf[k] - 48);
					if (difmax < ((int)buf[k] - 48))
						difmax = ((int)buf[k] - 48);
					if (difmin > ((int)buf[k] - 48))
						difmin = ((int)buf[k] - 48);
				}
			}
			k--;
		}
		//cout << sumdif << endl;

		amark = (sumart - (artmax + artmin)) / 6;
		dmark = (sumdif - (difmax + difmin)) / 6;

		int q = 0;
		while (buf[q] != ')')
		{
			if (buf[q + 1] == ')')
			{
				order = ((int)buf[q] - 48);
				q++;
			}
			else
			{
				double fr = (int)buf[q + 1] - 48;
				order = ((int)buf[q] - 48) * 10 + (fr);
				q += 2;
			}
		}
		int z = 3;
		while (buf[z] != ';') {
			name += buf[z];
			++z;
		}
		
		str[i] = func(order, false) + ") " + name + " Сложность программы: " + func(dmark) + "; артистизм: " + func(amark);
	}
	for (int i = 0; i < Size; ++i) {
		cout << str[i] << endl;
	}
}
