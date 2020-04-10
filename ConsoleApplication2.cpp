#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main(int argc, char* argv[])
{

	setlocale(LC_ALL, "Russian");
	string temp;
	vector <string> vec;
	if (argc < 3) {
		cout << "Аргументы не введены" << endl;
		system("pause");
		return 1;
	}
	ifstream fl(argv[1]);
	ofstream of(argv[2]);


	if (!fl)
	{
		cout << "Файл не найден" << endl;
		system("pause");
		return 1;
	}
	else
		while (fl >> temp)
			vec.push_back(temp);
	
	string zamena;
	cout << "Введите строку: ";
	cin >> zamena;
	int max = 0;
	string str;

	for (string s : vec) {
		if (s.length() > max) {
			max = s.length();
			str = s;
		}
	}

	str.replace(0, zamena.length(), zamena);
	vec[vec.size()-1] = str;
	for (string s : vec) {
		of << s + " ";
	}
	fl.close();
	of.close();
}

