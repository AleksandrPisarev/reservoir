#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include "reservoir.h"
void reservoir::show() {
	cout << "��� �������: " << title << endl;
	cout << "����� �������: " << length << endl;
	cout << "������ �������: " << width << endl;
	cout << "������� �������: " << depth << endl;
}
void reservoir::setReservoir() {
	cout << "������� ��� �������: ";
	cin >> title;
	cout << "������� ����� �������: ";
	cin >> length;
	cout << "������� ������ �������: ";
	cin >> width;
	cout << "������� ������� �������: ";
	cin >> depth;
}
void reservoir::volumeReservoir() {
	int volume;
	volume = length * width * depth;
	cout << "����� �������: " << volume << endl;
}
void reservoir::water_surface_area() {
	int area;
	area = length * width;
	cout << "������� ������ �����������: " << area << endl;
}
void reservoir::writing_file() {
	ofstream out("reservoir.txt", ios::app);
	if (out.is_open()) {
		out << "��� �������: " << title << ", " << "�����: " << length << ", " << "������: " << width << ", " << "�������: " << depth << endl;
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
		cout << "������ �: " << i + 1 << endl;
		arr[i].show();
	}
	cout << "������� ����� ������� ������� ������ �������:";
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
	cout << "������ ������." << endl;
}