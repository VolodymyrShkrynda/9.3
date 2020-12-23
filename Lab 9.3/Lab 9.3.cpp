#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 

using namespace std;

struct Tel
{
	int tfnum;
	int roomnum;
	int k;
	string sl1;
	string sl2;
	string sl3;
	string sl4;
};
void Create(Tel* p, const int N);
void Print(Tel* p, const int N);
int TfnumSearch(Tel* p, const int N, int tfnum1);
int RoomnumSearch(Tel* p, const int N, int roomnum1);
int SlSearch(Tel* p, const int N, string sl);
int main()
{ 
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int N,tfnum,found,roomnum;
	string prizv;
	cout << "Введіть кількість номерів N: "; cin >> N;

	Tel* p = new Tel[N];
	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "Виберіть дію:" << endl << endl;
		cout << " [1] - введення даних з клавіатури" << endl;
		cout << " [2] - вивід даних на екран" << endl;
		cout << " [3] - пошук за номером телефону" << endl;
		cout << " [4] - пошук телефону за номером приміщення" << endl;
		cout << " [5] - пошук номеру телефону і номеру кімнати за прізвищем службовця"<< endl << endl;
		cout << " [0] - вихід та завершення роботи програми" << endl << endl;
		cout << "Введіть значення: "; cin >> menuItem;
		cout << endl << endl << endl;
		switch (menuItem)
		{
		case 1:
			Create(p, N);
			break;
		case 2:
			Print(p, N);
			break;
		case 3:
			cout << "Введіть номер телефону:";cin >> tfnum;
			if ((found = TfnumSearch(p, N, tfnum)) != -1)
			{
				cout << "Номер кімнати:  " << p[found].roomnum << endl;
				cout << "Прізвища службовців:";
				cout << endl;
				cout << p[found].sl1 << ' ' << p[found].sl2 << ' ' << p[found].sl3 << ' ' << p[found].sl4;
			}
			else
				cout << "Шуканих даних не знайдено" << endl;
			cout << endl;
			break;
		case 4:
			cout << "Введіть номер кімнати: ";cin >> roomnum;
			if ((found = RoomnumSearch(p, N, roomnum)) != -1)
			{
				cout << "Номер телефону:  " << p[found].tfnum << endl;
			}
			else
				cout << "Шуканих даних не знайдено" << endl;

			break;
		case 5:
			cout << " Прізвище: ";
			cin.get();
			cin.sync();
			getline(cin, prizv);
			cout << endl;

			if ((found = SlSearch(p, N, prizv)) != -1)
			{
				cout << "Номер телефону:  " << p[found].tfnum << endl;
				cout << "Номер кімнати:  " << p[found].roomnum << endl;
			}
			else
				cout << "Шуканого студента не знайдено" << endl;

			break;
		case 0:
			break;
		default:
			cout << "Ви ввели помилкове значення! "
				"Слід ввести число - номер вибраного пункту меню" << endl;
		}
	} while (menuItem != 0);
	return 0;
}
void Create(Tel* p, const int N)
{
	int k = 0;
	
	for (int i = 0; i <N; i++)
	{
		cout << "Номер телефону(двозначне число): ";cin >>p[i].tfnum;
		cin.get(); 
		cin.sync(); 
        cout << " Номер кімнати: "; cin>> p[i].roomnum;
		cout << " Кількість службовців в кімнаті: "; cin >> p[i].k;
		switch (p[i].k)
		{
		case 1:
			cin.get();
			cin.sync();
			cout << " Прізвище службовця 1 : ";getline(cin, p[i].sl1);
			break;
		case 2:
			cin.get();
			cin.sync();
			cout << " Прізвище службовця 1 : ";getline(cin, p[i].sl1);
			cout << " Прізвище службовця 2 : ";getline(cin, p[i].sl2);
			break;
		case 3:
			cin.get();
			cin.sync();
			cout << " Прізвище службовця 1 : ";getline(cin, p[i].sl1);
			cout << " Прізвище службовця 2 : ";getline(cin, p[i].sl2);
			cout << " Прізвище службовця 3 : ";getline(cin, p[i].sl3);
			break;
		case 4:
			cin.get();
			cin.sync();
			cout << " Прізвище службовця 1 : ";getline(cin, p[i].sl1);
			cout << " Прізвище службовця 2 : ";getline(cin, p[i].sl2);
			cout << " Прізвище службовця 3 : ";getline(cin, p[i].sl3);
			cout << " Прізвище службовця 4 : ";getline(cin, p[i].sl4);
			break;
		}
		cout << endl;
	}
}
void Print(Tel* p, const int N)
{
	cout << "========================================================================================"
		<< endl;
	cout << "| Номер телефону | Номер кімнати | Кількість службовців |     Прізвища службовців      | "
		<< endl;
	cout << "-----------------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "|" << "      " << p[i].tfnum << "        ";
		cout << "|  " << "      "<< p[i].roomnum << "      | " << "        " << p[i].k << "            "
			<< "| "  << p[i].sl1<<' '<< p[i].sl2 << ' '<<p[i].sl3 << ' ' << p[i].sl4 <<" | ";
		cout << endl;
	}
	cout << "========================================================================================" << endl;
}
int TfnumSearch(Tel* p, const int N, int tfnum1)
{
	for (int i = 0; i < N; i++)
	{
		if (p[i].tfnum == tfnum1)
			return i;
	}
	return -1;
}
int RoomnumSearch(Tel* p, const int N, int roomnum1)
{
	for (int i = 0; i < N; i++)
	{
		if (p[i].roomnum == roomnum1)
			return i;
	}
	return -1;
}
int SlSearch(Tel* p, const int N, string sl)
{
	for (int i = 0; i < N; i++)
	{
	if (p[i].sl1 == sl || p[i].sl2 == sl || p[i].sl3 == sl || p[i].sl4 == sl)
		return i;
	}
		return -1;
}