#pragma once
class reservoir
{
	string title;
	int length;
	int width;
	int depth;
public:
	reservoir(string titl, int l, int w, int d) {
		title = titl;
		length = l;
		width = w;
		depth = d;
	}
	reservoir() : reservoir("��� �� ���������", 0, 0, 0) {}
	void show();
	void setReservoir();
	void volumeReservoir();    //����� �������
	void water_surface_area(); //������� ������ �����������
	void writing_file();       //������ � ����
};

