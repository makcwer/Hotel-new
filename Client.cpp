#include <iostream>
#include <fstream> 
#include <string>
#include <windows.h>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cctype>   // для функции isdigit
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
//		cout << "  " << N - 1 << "\t ";//Для отображения порядкового номера
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
//				cout << "Формат ввода +7(999)999-99-99\n";
//				cout << "Повторите ввод телефона:";
//			}
//		} while (true);
//		return num;
//	}
//	void add_client(int c)
//	{
//		cout << "\n Введите данные клиента";
//		cout << "\n ----------------------\n";
//		cout << "Имя:";
//		cin.get();
//		getline(cin, name);
//		cout << "Фамилия:";
//		getline(cin, surename);
//		cout << "Номер телефона:";
//		checkingCorrectnessTelNumber(phone);
//		cout << "Количество дней для проживания:";
//		cin >> days;
//		cost_room = days * c;
//		cout << "\n\tИнформация о клиенте добавлена...!!!\n";
//	}
//	void client_menu();              //для отображения меню клиентов
//	void save_customer(int, int);    //для добавления клиента
//	void modify_customer();          //для редактирования записи клиента
//	void display_all_customer();     //для отображения всех клиентов
//	void display_a_customer();       //для отображения записи клиента
//	void delete_customer();          //для удаления записи клиента
//	void removeCustomerFromRoom(int);//для освобождения номера и удаления записи клиента
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
//	cout << "\n\n Нажмите любую клавишу, что-бы продолжить....!!";
//	numFile = _getch();
//}
//void Client::display_a_customer()
//{
//	system("cls");
//	display_all_customer();
//	int r = 0;
//	cout << "\n Выберите № клиента: ";
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
//		cout << "\n Сведения о клиенте";
//		cout << "\n ------------------";
//		cout << "\n Клиент №: " << r;
//		cout << "\n Номер: " << client[0];
//		cout << "\n Имя: " << client[1];
//		cout << "\n Фамилия: " << client[2];
//		cout << "\n Номер телефона: " << client[3];
//		cout << "\n Забронированно дней: " << client[4];
//		cout << "\n Общая стоимость: " << client[5];
//		cout << endl;
//	}
//	else
//	{
//		cout << "\n Извините, информации о клиенте нет....!!";
//	}
//	fin.close();
//	cout << "\nНажмите клавишу Esc... для возврата в главное меню \n";
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
//	cout << "\n\n\tМеню редактирования";
//	cout << "\n\n\tВыберите № клиента для изменения: ";
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
//		cout << "\nВведите новую информацию" << endl;
//		fout.open(path, ios::in | ios::out);
//		if (fout.is_open())
//		{
//			cout << "Поменять номер (Y/N):\n";
//			button = _getch();
//			if (button == 'n' || button == 'N')
//			{
//				room_num = stoi(client[0]);
//				fout << room_num << endl;
//			}
//			else
//			{
//				cout << "Введите номер: ";
//				cin >> room_num;
//				fout << room_num << endl;
//			}
//			cout << "Поменять имя (Y/N):\n";
//			button = _getch();
//			if (button == 'n' || button == 'N')
//			{
//				name = client[1];
//				fout << name << endl;
//			}
//			else
//			{
//				cout << "Введите имя: ";
//				cin.get();
//				getline(cin, name);
//				fout << name << endl;
//			}
//			cout << "Поменять фамилию (Y/N): \n";
//			button = _getch();
//			if (button == 'n' || button == 'N')
//			{
//				surename = client[2];
//				fout << surename << endl;
//			}
//			else
//			{
//				cout << "Введите фамилию: ";
//				cin.get();
//				getline(cin, surename);
//				fout << surename << endl;
//			}
//			cout << "Поменять номер телефона (Y/N): \n";
//			button = _getch();
//			if (button == 'n' || button == 'N')
//			{
//				phone = client[3];
//				fout << phone << endl;
//			}
//			else
//			{
//				cout << "Введите телефон: ";
//				checkingCorrectnessTelNumber(phone);
//				fout << phone << endl;
//			}
//			cout << "Поменять количество дней проживания (Y/N): \n";
//			button = _getch();
//			if (button == 'n' || button == 'N')
//			{
//				days = stoi(client[4]);
//				fout << days << endl;
//			}
//			else
//			{
//				cout << "Введите дни: ";
//				cin >> days;
//				fout << days << endl;
//			}
//			cout << "Поменять стоимость проживания (Y/N): \n";
//			button = _getch();
//			if (button == 'n' || button == 'N')
//			{
//				cost_room = stoi(client[5]);
//				fout << cost_room << endl;
//			}
//			else
//			{
//				cout << "Введите сумму: ";
//				cin >> cost_room;
//				fout << cost_room << endl;
//			}
//		}
//		fout.close();
//		cout << "\n\n\t Данные изменены...";
//	}
//	fp.close();
//	cout << "\n\n Нажмите любую клавишу, что-бы продолжить....!!";
//	button = _getch();
//	system("cls");
//}
//void showHeadClient()
//{
//	cout << "\n\t\t\tСписок проживающих клиентов";
//	cout << "\n\t\t\t-------------------------------\n";
//	cout << endl;
//	cout << "===============================================================================================\n";
//	cout << " № Кл. |" << "№ Номер|" << "Имя \t\t" << "|Фамилия\t\t" << "| № Телефон\t  " << "|Кол.Дней " << "|Стоимость|" << endl;
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
//	cout << "\n Нажмите любую клавишу, чтобы продолжить.....!!";
//	numFile = _getch();
//}
//void Client::delete_customer()
//{
//	display_all_customer();
//	int numFile = 0;
//	Client c;
//	do {
//		cout << "\nВыберите № Клиента, которого вы хотите удалить из списка: ";
//		if (cin >> numFile)
//		{
//			cout << "\n\tВы действительно хотите удалить запись (Y/N): ";
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
//						cout << "\n № файла клиента не найден.";
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
//						cout << "\n\tНомер свободен! ";
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
//					cout << "\n\tФайл удален!";
//					break;
//				} while (true);
//				break;
//			}
//		}
//		else
//		{
//			cout << "\nВведите корректные данные!";
//			break;
//		}
//	} while (true);
//	cout << "\n\n Нажмите любую клавишу, что-бы продолжить....!!";
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
//			cout << "\n\tХотите удалить запись клиента (Y/N): ";
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
//					cout << "\n\tФайл удален!";
//					break;
//				}
//			} while (true);
//		}
//		nFile++;
//	} while (true);
//	cout << "\n\n Нажмите любую клавишу, что-бы продолжить....!!";
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
//		cout << "\n\t\t1.Добавить клиента";
//		cout << "\n\t\t2.Список клиентов";
//		cout << "\n\t\t3.Информация о клиенте";
//		cout << "\n\t\t4.Редактирование записи клиента";
//		cout << "\n\t\t5.Удалить запись клиента";
//		cout << "\n\t\t6.Вернутся в главное меню";
//		cout << "\n\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
//		cout << "\n\t\tВАШ ВЫБОР: ";
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