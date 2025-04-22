//�������.
//����������� ����� Reservoir(������).����� ������ ����������� ����� ���� ���������.����� ������ ��������� :
//����������� �� ���������, ����������� � �����������,
//��� ������������� ����������� ���������� � ����������� �����������.
//�������� ������ ��� :
//1. ����������� ���������������� ������(������ * ����� * ������������ �������);
//2. ����������� ������� ������ �����������;
//3. ����� ��� �������� ��������� �� ������� � ������
//����(���� - ����; ������� - ����);
//4. ��� ��������� ������� ������ ����������� ��������
//������ ����;
//5. ��� ����������� ��������;
//6. ��������� ������ �� ���������� ������������(������ set � get).
//�������� ��������� ��� ������ � �������.�����������
//������������ ������ �������� ������ � ������������
//����������, �������� �������� �� �������.�����������
//����������� ������ ���������� �� �������� �������
//� ��������� ����, �������� ����.
//����������� explicit ����������� � ����������� ������������(��������, ��� ����������� ������ � ������ � �.�.).
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include "reservoir.h"
void add_arr(reservoir*&, int&);    //������� ������
void removal_arr(reservoir*&, int&);//������� ������
void del_from_file(int);            //������� �� �����
int main() {
	setlocale(0, "ru");
	ofstream out("reservoir.txt", ios::out);
	int size = 0, choice, index;
	reservoir* arr = nullptr;
	do
	{
		cout << "�������� ��������." << endl;
		cout << "1. ������� ������ � �������� � ����." << endl;
		cout << "2. ������� ������." << endl;
		cout << "3. �������� �������." << endl;
		cout << "4. ����������� ������ �������." << endl;
		cout << "5. ����������� ������� ������ �����������." << endl;
		cout << "6. �����." << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			add_arr(arr, size);
			break;
		case 2:
			if (arr == nullptr) {
				cout << "��� �������� ��� ��������." << endl;
			}
			else removal_arr(arr, size);
			break;
		case 3:
			if (arr == nullptr) {
				cout << "��� �������� ��� ������." << endl;
			}
			else {
				for (int i = 0; i < size; i++) {
					arr[i].show();
				}
			}
			break;
		case 4:
			if (arr == nullptr) {
				cout << "��� ��������." << endl;
			}
			else {
				for (int i = 0; i < size; i++) {
					cout << "������ �: " << i + 1 << endl;
					arr[i].show();
				}
				cout << "������� ����� ������� ��� ����������� ��� ������: ";
				cin >> index;
				arr[index - 1].volumeReservoir();
			}
			break;
		case 5:
			if (arr == nullptr) {
				cout << "��� ��������." << endl;
			}
			else {
				for (int i = 0; i < size; i++) {
					cout << "������ �: " << i + 1 << endl;
					arr[i].show();
				}
				cout << "������� ����� ������� ��� ����������� ������� ������ ����������: ";
				cin >> index;
				arr[index - 1].water_surface_area();
			}
			break;
		default:
			break;
		}
	} while (choice !=6);
	delete[] arr;
}