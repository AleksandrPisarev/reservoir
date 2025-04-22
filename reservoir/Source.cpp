//Задание.
//Разработать класс Reservoir(водоем).Класс должен обязательно иметь поле «название».Класс должен содержать :
//конструктор по умолчанию, конструктор с параметрами,
//при необходимости реализовать деструктор и конструктор копирования.
//Добавить методы для :
//1. Определения приблизительного объема(ширина * длина * максимальная глубина);
//2. Определения площади водной поверхности;
//3. Метод для проверки относятся ли водоемы к одному
//типу(море - море; бассейн - пруд);
//4. Для сравнения площади водной поверхности водоемов
//одного типа;
//5. Для копирования объектов;
//6. Остальные методы на усмотрение разработчика(методы set и get).
//Написать интерфейс для работы с классом.Реализовать
//динамический массив объектов класса с возможностью
//добавления, удаления объектов из массива.Реализовать
//возможность записи информации об объектах массива
//в текстовый файл, бинарный файл.
//Используйте explicit конструктор и константные функциичлены(например, для отображения данных о водоёме и т.д.).
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include "reservoir.h"
void add_arr(reservoir*&, int&);    //создать объект
void removal_arr(reservoir*&, int&);//удалить объект
void del_from_file(int);            //удалить из файла
int main() {
	setlocale(0, "ru");
	ofstream out("reservoir.txt", ios::out);
	int size = 0, choice, index;
	reservoir* arr = nullptr;
	do
	{
		cout << "Выберите действие." << endl;
		cout << "1. Создать объект и записать в файл." << endl;
		cout << "2. Удалить объект." << endl;
		cout << "3. Показать объекты." << endl;
		cout << "4. Определение объема водоема." << endl;
		cout << "5. Определение площади водной поверхности." << endl;
		cout << "6. Выход." << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			add_arr(arr, size);
			break;
		case 2:
			if (arr == nullptr) {
				cout << "Нет объектов для удаления." << endl;
			}
			else removal_arr(arr, size);
			break;
		case 3:
			if (arr == nullptr) {
				cout << "Нет объектов для вывода." << endl;
			}
			else {
				for (int i = 0; i < size; i++) {
					arr[i].show();
				}
			}
			break;
		case 4:
			if (arr == nullptr) {
				cout << "Нет объектов." << endl;
			}
			else {
				for (int i = 0; i < size; i++) {
					cout << "Водоем №: " << i + 1 << endl;
					arr[i].show();
				}
				cout << "Введите номер водоема для определения его объема: ";
				cin >> index;
				arr[index - 1].volumeReservoir();
			}
			break;
		case 5:
			if (arr == nullptr) {
				cout << "Нет объектов." << endl;
			}
			else {
				for (int i = 0; i < size; i++) {
					cout << "Водоем №: " << i + 1 << endl;
					arr[i].show();
				}
				cout << "Введите номер водоема для определения площади водной повехности: ";
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