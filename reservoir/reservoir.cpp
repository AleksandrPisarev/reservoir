#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include "reservoir.h"
void reservoir::show() {
	cout << "Тип водоема: " << title << endl;
	cout << "Длина водоема: " << length << endl;
	cout << "Ширина водоема: " << width << endl;
	cout << "Глубина водоема: " << depth << endl;
}
void reservoir::setReservoir() {
	cout << "Введите тип водоема: ";
	cin >> title;
	cout << "Введите длину водоема: ";
	cin >> length;
	cout << "Введите ширину водоема: ";
	cin >> width;
	cout << "Введите глубину водоема: ";
	cin >> depth;
}
void reservoir::volumeReservoir() {
	int volume;
	volume = length * width * depth;
	cout << "Объем водоема: " << volume << endl;
}
void reservoir::water_surface_area() {
	int area;
	area = length * width;
	cout << "Площадь водной поверхности: " << area << endl;
}
void reservoir::writing_file() {
	ofstream out("reservoir.txt", ios::app);
	if (out.is_open()) {
		out << "Тип водоема: " << title << ", " << "Длина: " << length << ", " << "Ширина: " << width << ", " << "Глубина: " << depth << endl;
		out.close();
	}
	else cout << "Error openfile.";
}
void add_arr(reservoir*& arr, int& size) {
	reservoir* newarr = new reservoir[size + 1];
	for (int i = 0; i < size; i++) {
		newarr[i] = arr[i];
	}
	newarr[size].setReservoir();
	newarr[size].writing_file();
	size++;
	delete[] arr;
	arr = newarr;
}
void del_from_file(int ind) {
	int size = 0;
	string str;
	ifstream in("reservoir.txt");
	if (in.is_open()) {
		while (getline(in, str))
		{
			size++;
		}
		in.close();
	}
	else cout << "Error openfile.";
	string* line = new string[size];
	in.open("reservoir.txt");
	if (in.is_open()) {
		for (int i = 0; i < size; i++) {
			getline(in, line[i]);
		}
		in.close();
	}
	else cout << "Error openfile.";
	ofstream out("reservoir.txt", ios::out);
	if (out.is_open()) {
		for (int i = 0; i < ind - 1; i++) {
			out << line[i] << endl;
		}
		for (int i = ind; i < size; i++) {
			out << line[i] << endl;
		}
		out.close();
	}
	else cout << "Error openfile.";
}

void removal_arr(reservoir*& arr, int& size) {
	int index;
	for (int i = 0; i < size; i++) {
		cout << "Водоем №: " << i + 1 << endl;
		arr[i].show();
	}
	cout << "Введите номер водоема который хотите удалить:";
	cin >> index;
	del_from_file(index);
	reservoir* newarr = new reservoir[size - 1];
	for (int i = 0; i < index - 1; i++) {
		newarr[i] = arr[i];
	}
	for (int i = index - 1; i < size - 1; i++) {
		newarr[i] = arr[i + 1];
	}
	size--;
	delete[] arr;
	arr = newarr;
	cout << "Объект удален." << endl;
}