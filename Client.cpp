#include <iostream>
#include <fstream> 
#include <string>
#include <windows.h>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cctype>   // ��� ������� isdigit
#include <cstdlib> 
#include <iomanip>
#include <conio.h>
#include <regex>
using namespace std;
//struct Client
//{
//	int number = 1;
//	int room_num = 0;
//	string name = "";
//	string surename = "";
//	string phone = "";
//	unsigned short int days = 0;
//	int cost_room = 0;
//	// Hotel() {};
//  /*   Hotel(int room_number,string name, string surename, string phone, int days, float cost)
//	 {
//		 this->room_number = room_number;
//		 this->name = name;
//		 this->surename = surename;
//		 this->phone = phone;
//		 this->days = days;
//		 this->cost = cost;
//	 }*/
//	void showInfoClient(int N)
//	{
//		cout << "  " << N - 1 << "\t ";//��� ����������� ����������� ������
//		cout << setw(7) << left << this->room_num;
//		cout << setw(17) << left << this->name;
//		cout << setw(24) << left << this->surename;
//		cout << setw(21) << left << this->phone;
//		cout << setw(8) << left << this->days;
//		cout << setw(8) << left << this->cost_room << endl;
//	}
//	string checkingCorrectnessTelNumber(string& num)
//	{
//		do {
//			getline(cin, num);
//			regex rx("\\+[[:digit:]]{1}\\([0-9]{3}\\)[[:digit:]]{3}-[[:digit:]]{2}-[[:digit:]]{2}");
//			if (regex_match(num, rx))
//			{
//				break;
//			}
//			else
//			{
//				cout << "������ ����� +7(999)999-99-99\n";
//				cout << "��������� ���� ��������:";
//			}
//		} while (true);
//		return num;
//	}
//	void add_client(int c)
//	{
//		cout << "\n ������� ������ �������";
//		cout << "\n ----------------------\n";
//		cout << "���:";
//		cin.get();
//		getline(cin, name);
//		cout << "�������:";
//		getline(cin, surename);
//		cout << "����� ��������:";
//		checkingCorrectnessTelNumber(phone);
//		cout << "���������� ���� ��� ����������:";
//		cin >> days;
//		cost_room = days * c;
//		cout << "\n\t���������� � ������� ���������...!!!\n";
//	}
//	void client_menu();              //��� ����������� ���� ��������
//	void save_customer(int, int);    //��� ���������� �������
//	void modify_customer();          //��� �������������� ������ �������
//	void display_all_customer();     //��� ����������� ���� ��������
//	void display_a_customer();       //��� ����������� ������ �������
//	void delete_customer();          //��� �������� ������ �������
//	void removeCustomerFromRoom(int);//��� ������������ ������ � �������� ������ �������
//
//};
//void Client::save_customer(int no, int cost)
//{
//	int numFile = 1;
//	ofstream fout;
//	vector<string> client;
//	fstream fin;
//	Room h;
//	do {
//		string path("hotel\\clients\\" + to_string(numFile) + ".txt");
//		fin.open(path);
//		if (!fin.is_open())
//		{
//			add_client(cost);
//			fout.open(path);
//			if (fout.is_open())
//			{
//				room_num = no;
//				fout << room_num << endl;
//				fout << name << endl;
//				fout << surename << endl;
//				fout << phone << endl;
//				fout << days << endl;
//				fout << cost_room << endl;
//			}
//			fout.close();
//			break;
//		}
//		else
//		{
//			string line = "";
//			while (getline(fin, line))
//			{
//				client.push_back(line);
//			}
//		}
//		fin.close();
//		numFile++;
//	} while (true);
//	cout << "\n\n ������� ����� �������, ���-�� ����������....!!";
//	numFile = _getch();
//}
//void Client::display_a_customer()
//{
//	system("cls");
//	display_all_customer();
//	int r = 0;
//	cout << "\n �������� � �������: ";
//	cin >> r;
//	string path("hotel\\clients\\" + to_string(r) + ".txt");
//	ifstream fin;
//	string t;
//	vector<string> client;
//	fin.open(path);
//	if (fin.is_open())
//	{
//		while (getline(fin, t))
//		{
//			client.push_back(t);
//		}
//		cout << "\n �������� � �������";
//		cout << "\n ------------------";
//		cout << "\n ������ �: " << r;
//		cout << "\n �����: " << client[0];
//		cout << "\n ���: " << client[1];
//		cout << "\n �������: " << client[2];
//		cout << "\n ����� ��������: " << client[3];
//		cout << "\n �������������� ����: " << client[4];
//		cout << "\n ����� ���������: " << client[5];
//		cout << endl;
//	}
//	else
//	{
//		cout << "\n ��������, ���������� � ������� ���....!!";
//	}
//	fin.close();
//	cout << "\n������� ������� Esc... ��� �������� � ������� ���� \n";
//	do {
//		char battom;
//		battom = _getch();
//		if ((int)battom == 27)
//		{
//			break;
//		}
//	} while (true);
//	system("cls");
//}
//void Client::modify_customer()
//{
//	system("cls");
//	int numFile = 0;
//	char button;
//	Client c;
//	fstream fp;
//	ofstream fout;
//	vector<string> client;
//	display_all_customer();
//	cout << "\n\n\t���� ��������������";
//	cout << "\n\n\t�������� � ������� ��� ���������: ";
//	cin >> numFile;
//	string path("hotel\\clients\\" + to_string(numFile) + ".txt");
//	fp.open(path, ios::in | ios::out);
//	if (fp.is_open())
//	{
//		string line;
//		while (getline(fp, line))
//		{
//			client.push_back(line);
//		}
//		showInfoGuest(numFile);
//		cout << "\n������� ����� ����������" << endl;
//		fout.open(path, ios::in | ios::out);
//		if (fout.is_open())
//		{
//			cout << "�������� ����� (Y/N):\n";
//			button = _getch();
//			if (button == 'n' || button == 'N')
//			{
//				room_num = stoi(client[0]);
//				fout << room_num << endl;
//			}
//			else
//			{
//				cout << "������� �����: ";
//				cin >> room_num;
//				fout << room_num << endl;
//			}
//			cout << "�������� ��� (Y/N):\n";
//			button = _getch();
//			if (button == 'n' || button == 'N')
//			{
//				name = client[1];
//				fout << name << endl;
//			}
//			else
//			{
//				cout << "������� ���: ";
//				cin.get();
//				getline(cin, name);
//				fout << name << endl;
//			}
//			cout << "�������� ������� (Y/N): \n";
//			button = _getch();
//			if (button == 'n' || button == 'N')
//			{
//				surename = client[2];
//				fout << surename << endl;
//			}
//			else
//			{
//				cout << "������� �������: ";
//				cin.get();
//				getline(cin, surename);
//				fout << surename << endl;
//			}
//			cout << "�������� ����� �������� (Y/N): \n";
//			button = _getch();
//			if (button == 'n' || button == 'N')
//			{
//				phone = client[3];
//				fout << phone << endl;
//			}
//			else
//			{
//				cout << "������� �������: ";
//				checkingCorrectnessTelNumber(phone);
//				fout << phone << endl;
//			}
//			cout << "�������� ���������� ���� ���������� (Y/N): \n";
//			button = _getch();
//			if (button == 'n' || button == 'N')
//			{
//				days = stoi(client[4]);
//				fout << days << endl;
//			}
//			else
//			{
//				cout << "������� ���: ";
//				cin >> days;
//				fout << days << endl;
//			}
//			cout << "�������� ��������� ���������� (Y/N): \n";
//			button = _getch();
//			if (button == 'n' || button == 'N')
//			{
//				cost_room = stoi(client[5]);
//				fout << cost_room << endl;
//			}
//			else
//			{
//				cout << "������� �����: ";
//				cin >> cost_room;
//				fout << cost_room << endl;
//			}
//		}
//		fout.close();
//		cout << "\n\n\t ������ ��������...";
//	}
//	fp.close();
//	cout << "\n\n ������� ����� �������, ���-�� ����������....!!";
//	button = _getch();
//	system("cls");
//}
//void showHeadClient()
//{
//	cout << "\n\t\t\t������ ����������� ��������";
//	cout << "\n\t\t\t-------------------------------\n";
//	cout << endl;
//	cout << "===============================================================================================\n";
//	cout << " � ��. |" << "� �����|" << "��� \t\t" << "|�������\t\t" << "| � �������\t  " << "|���.���� " << "|���������|" << endl;
//	cout << "===============================================================================================\n";
//}
//void Client::display_all_customer()
//{
//	system("cls");
//	int numFile = 1;
//	string path("hotel\\clients\\" + to_string(numFile) + ".txt");
//	fstream fp;
//	fp.open(path, ios::in);
//	if (fp.is_open())
//	{
//		showHeadClient();
//		reportClient();
//	}
//	else
//	{
//		cout << "ERROR!!! FILE COULD NOT BE OPEN ";
//		numFile = _getch();
//		return;
//	}
//	fp.close();
//	cout << "\n ������� ����� �������, ����� ����������.....!!";
//	numFile = _getch();
//}
//void Client::delete_customer()
//{
//	display_all_customer();
//	int numFile = 0;
//	Client c;
//	do {
//		cout << "\n�������� � �������, �������� �� ������ ������� �� ������: ";
//		if (cin >> numFile)
//		{
//			cout << "\n\t�� ������������� ������ ������� ������ (Y/N): ";
//			char battom;
//			battom = _getch();
//			if (battom == 'n' || battom == 'N')
//			{
//				break;
//			}
//			else
//			{
//				int f = 1;
//				fstream fin;
//				ofstream fout;
//				Room h;
//				vector<Room> rooms;
//				do {
//					string path_client("hotel\\clients\\" + to_string(numFile) + ".txt");
//					vector<string> client;
//					fin.open(path_client);
//					if (!fin.is_open())
//					{
//						cout << "\n � ����� ������� �� ������.";
//						break;
//					}
//					else
//					{
//						string line = "";
//						while (getline(fin, line))
//						{
//							client.push_back(line);
//						}
//					}
//					fin.close();
//					string path_room("hotel\\rooms\\" + to_string(f) + ".txt");
//					vector<string> text;
//					readFileRoom(path_room, text, 6);
//					if (text.empty())
//					{
//						break;
//					}
//					else
//					{
//						createRoom(text, h);
//						rooms.push_back(h);
//					}
//					f++;
//					if (stoi(client[0]) == h.room_no)
//					{
//						h.status = 0;
//						fout.open(path_room);
//						if (fout.is_open())
//						{
//							fout << h.room_no << endl;
//							fout << h.category << endl;
//							fout << h.cost_num << endl;
//							fout << h.local_no << endl;
//							fout << h.status << endl;
//						}
//						fout.close();
//						cout << "\n\t����� ��������! ";
//					}
//					string ipath("hotel\\clients\\" + to_string(numFile) + ".txt");
//					remove(ipath.c_str());
//					string newPath;
//					do {
//						numFile++;
//						string path("hotel\\clients\\" + to_string(numFile) + ".txt");
//						fin.open(path);
//						if (!fin.is_open())
//							break;
//						fin.close();
//						string newPath("hotel\\clients\\" + to_string(numFile - 1) + ".txt");
//
//						if (rename(path.c_str(), newPath.c_str()) == 0)
//						{
//							continue;
//						}
//					} while (true);
//					cout << "\n\t���� ������!";
//					break;
//				} while (true);
//				break;
//			}
//		}
//		else
//		{
//			cout << "\n������� ���������� ������!";
//			break;
//		}
//	} while (true);
//	cout << "\n\n ������� ����� �������, ���-�� ����������....!!";
//	numFile = _getch();
//}
//void Client::removeCustomerFromRoom(int numRoom)
//{
//	Client c;
//	int nFile = 1;
//	do {
//		vector<Client> clients;
//		string ispath;
//		ispath = ispath + ("hotel\\clients\\" + to_string(nFile) + ".txt");
//		vector<string> text;
//		readFileClient(ispath, text, 6);
//		if (text.empty())
//		{
//			break;
//		}
//		else
//		{
//			createClient(text, c);
//			clients.push_back(c);
//		}
//		if (c.room_num == numRoom)
//		{
//			cout << "\n\t������ ������� ������ ������� (Y/N): ";
//			do {
//				char battom;
//				battom = _getch();
//				if (battom == 'n' || battom == 'N')
//				{
//					break;
//				}
//				else
//				{
//					string ipath("hotel\\clients\\" + to_string(nFile) + ".txt");
//					remove(ipath.c_str());
//					ifstream fin;
//					string newPath;
//					do {
//						nFile++;
//						string path("hotel\\clients\\" + to_string(nFile) + ".txt");
//						fin.open(path);
//						if (!fin.is_open())
//							break;
//						fin.close();
//						string newPath("hotel\\clients\\" + to_string(nFile - 1) + ".txt");
//
//						if (rename(path.c_str(), newPath.c_str()) == 0)
//						{
//							continue;
//						}
//					} while (true);
//					cout << "\n\t���� ������!";
//					break;
//				}
//			} while (true);
//		}
//		nFile++;
//	} while (true);
//	cout << "\n\n ������� ����� �������, ���-�� ����������....!!";
//	nFile = _getch();
//}
//void Client::client_menu()
//{
//	Room h;
//	int option = 0;
//	while (true)
//	{
//		system("cls");
//		cout << "\n\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
//		cout << "\n\t\t1.�������� �������";
//		cout << "\n\t\t2.������ ��������";
//		cout << "\n\t\t3.���������� � �������";
//		cout << "\n\t\t4.�������������� ������ �������";
//		cout << "\n\t\t5.������� ������ �������";
//		cout << "\n\t\t6.�������� � ������� ����";
//		cout << "\n\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
//		cout << "\n\t\t��� �����: ";
//		if (cin >> option)
//		{
//			switch (option)
//			{
//			case 1:system("cls");
//				save_customer(0, 0);
//				break;
//			case 2:display_all_customer();
//				system("cls");
//				break;
//			case 3:
//				display_a_customer();
//				break;
//			case 4:
//				modify_customer();
//				system("cls");
//				break;
//			case 5: delete_customer();
//				system("cls");
//				break;
//			case 6: system("cls");
//				h.main_menu();
//				break;
//			}
//		}
//		else
//		{
//			break;
//		}
//	}
//
//}