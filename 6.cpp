#include <iostream>
#include <fstream> 
#include <string>
#include <windows.h>
#include <vector>
#include <cstdio>
#include <cctype>   // для функции isdigit
#include <cstdlib> 
#include <iomanip>
#include <conio.h>
#include <regex>

// Вспомогательные файлы
#include "Example.h"

using namespace std;

struct Hotel
{
	string nameHotel;
	string phoneHotel;
	int number_rooms;
	int number_guests;
};

// TODO: Вынести структуру Room в отдельный "модуль". Под модулем подразумевается h-файл и cpp-файл. То есть добавить новый файлы Res.h и Res.cpp
struct Room
{
	unsigned short int room_no = 0;
	string category = "";
	unsigned short int cost_num = 0;
	unsigned short int local_no = 0;
	int status = 0;
	//Room(){}
	//Room(int num, unsigned short int room_no, string category, unsigned short int cost_num, unsigned short int local_no, string status)
	//{
	//    this->num = num;
	//    this->room_no = room_no;
	//    this->category = category;
	//    this->cost_num = cost_num;
	//    this->local_no = local_no;
	//    this->status = status;
	//}
	void showRoom(int N)
	{
		cout << " " << N - 1 << "\t";
		cout << setw(10) << left << this->room_no;
		cout << setw(15) << left << this->category;
		cout << setw(17) << left << this->cost_num;
		cout << setw(10) << left << this->local_no;
		if (this->status == 0)
		{
			cout << setw(5) << left << "свободен" << endl;
		}
		else
		{
			cout << setw(5) << left << "занят" << endl;
		}
	}
	void add_room()
	{
		cout << "\n\tМЕНЮ ДОБАВЛЕНИЯ НОМЕРА\n";
		cout << "\n Введите данные номера";
		cout << "\n ----------------------" << endl;
		cout << " № Номер: ";
		cin >> room_no;
		cin.get();
		cout << " Категория: ";
		cin >> category;
		cout << " Цена за сутки: ";
		cin >> cost_num;
		cout << " Кол.мест: ";
		cin >> local_no;
		//cout << " Статус: 0 - (свободен), 1 - (занят): ";
		status = 0;
		cout << "\n Номер добавлен...!!!" << endl;
	}
	void saveRoom();            //Для добовления номера
	void menuRoom();            //Для выбора просмотра номеров
	void main_menu();           //Главное меню
	void menuBookRoom();        //Меню выбора регистрации номера
	void listRoom();            //Отображения списока номеров
	void bookRoomCategory();    //Регистрация клиента по категории
	void bookRoom();            //Бронирование номера
	void bookRoomCost();        //Бронирование номера по стоимости
	void releaseNumber();       //Освобождение номера
};
void showHeadRoom()
{
	cout << "\n\t\t\t\tСписок номеров";
	cout << "\n\t\t\t-------------------------------\n";
	cout << endl;
	cout << "=========================================================================\n";
	cout << "|№ | № Номера\t" << "|Категория  " << "| Цена за сутки " << "| Кол.мест  " << "| Статус\t|" << endl;
	cout << "=========================================================================\n";
}
void infoHeadRoom()
{
	cout << "=======================================================================\n";
	cout << "| № Номера   " << "| Категория  " << "| Цена за сутки " << "| Кол.мест  " << "| Статус        |" << endl;
	cout << "=======================================================================\n";
}
void esc()
{
	Room h;
	cout << "\n\n\tНажмите клавишу Esc... для возврата в главное меню \n";
	do {
		char battom;
		battom = _getch();
		if ((int)battom == 27)
		{
			system("cls");
			h.main_menu();
		}
	} while (true);
}
void readFileRoom(string path, vector<string>& text, int N)
{
	ifstream fin;
	fin.open(path);
	if (fin.is_open())
	{
		string line;
		for (int i = 0; i < N; i++)
		{
			line.assign("");
			getline(fin, line);
			text.push_back(line);
		}

	}
	fin.close();
}
void createRoom(vector<string> text, Room& h)
{
	h.room_no = stoi(text[0]);
	h.category = text[1];
	h.cost_num = stoi(text[2]);
	h.local_no = stoi(text[3]);
	h.status = stoi(text[4]);
}
void displaysAllNumbers()
{
	showHeadRoom();
	vector<Room> rooms;
	int num = 1;
	do {
		string path;
		Room h;
		path = path + ("hotel\\rooms\\" + to_string(num) + ".txt");
		vector<string> text;
		readFileRoom(path, text, 5);
		if (text.empty())
		{
			break;
		}
		else
		{
			createRoom(text, h);
			rooms.push_back(h);
		}
		num++;
		h.showRoom(num);
	} while (true);
	esc();
}
// TODO: подсказка Room::SOME_METHOD() - это должно попасть в Room.cpp
void Room::saveRoom()
{
	showHeadRoom();
	int num = 1;
	vector<Room> rooms;
	do {
		string path;
		Room h;
		path = path + ("hotel\\rooms\\" + to_string(num) + ".txt");
		vector<string> text;
		readFileRoom(path, text, 5);
		if (text.empty())
		{
			break;
		}
		else
		{
			createRoom(text, h);
			rooms.push_back(h);
		}
		num++;
		h.showRoom(num);
	} while (true);
	cout << endl;
	cout << "\tНа текущий момент в отеле " << num - 1 << " номер(ов)";
	string ipath("hotel\\rooms\\" + to_string(num) + ".txt");
	ofstream fout;
	do {
		add_room();
		fout.open(ipath, ios::app);
		if (fout.is_open())
		{
			fout << room_no << endl;
			fout << category << endl;
			fout << cost_num << endl;
			fout << local_no << endl;
			fout << status << endl;
		}
		cout << "\nНажмите любую клавишу для возврата в предыдущее меню. \n";
		char battom;
		battom = _getch();
		if ((int)battom == 27)
		{
			break;
		}
		else
		{
			break;
		}
	} while (true);
	fout.close();
	system("cls");
}
void Room::menuRoom()
{
	cout << "1.Посмотреть все номера \n";
	cout << "2.Посмотреть категории номеров \n";
	cout << "3.Вернутся в главное меню \n";
	cout << " ВАШ ВЫБОР: ";
	do {
		int change = 0;
		if (cin >> change)
		{
			switch (change)
			{
			case 1:system("cls");
				displaysAllNumbers();
				break;
			case 2:system("cls");
				bookRoomCategory();
				break;
			case 3: system("cls");
				main_menu();
				break;
			}
		}
		else
		{
			break;
		}
	} while (true);
}
void Room::menuBookRoom()
{
	cout << "1.Забронировать номер по категории \n";
	cout << "2.Забронировать номер по стоимости \n";
	cout << "3.Вернутся в главное меню \n";
	cout << " ВАШ ВЫБОР: ";
	do {
		int change;
		if (cin >> change)
		{
			switch (change)
			{
			case 1:system("cls");
				bookRoomCategory();
				break;
			case 2:system("cls");
				bookRoomCost();
				break;
			case 3: system("cls");
				main_menu();
				break;
			}
		}
		else
		{
			break;
		}
	} while (true);
}
void Room::bookRoomCost()
{
	char battom;
	int r = 0, k = 0;
	cout << "Введите минимальную сумму:  \n";
	cin >> r;
	cout << "Введите максимальную сумму: \n";
	cin >> k;
	system("cls");
	infoHeadRoom();
	vector<Room> rooms;
	int num = 1;
	do {
		Room h;
		string path = "";
		path = path + ("hotel\\rooms\\" + to_string(num) + ".txt");
		vector<string> text;
		readFileRoom(path, text, 5);
		if (text.empty())
		{
			break;
		}
		else
		{
			createRoom(text, h);
			rooms.push_back(h);
		}
		if (h.cost_num >= r && h.cost_num <= k)
		{
			h.listRoom();
		}
		num++;
	} while (true);
	do {
		cout << "\nНажмите любую клавишу для продолжения или Esc...для выхода в главное меню.\n";
		battom = _getch();
		if ((int)battom == 27)
		{
			system("cls");
			main_menu();
		}
		else
		{
			bookRoom();
		}
	} while (true);
}
void Room::listRoom()
{
	cout << "  " << setw(13) << left << this->room_no;
	cout << setw(15) << left << this->category;
	cout << setw(16) << left << this->cost_num;
	cout << setw(10) << left << this->local_no;
	if (this->status == 0)
	{
		cout << setw(5) << left << "свободен" << endl;
	}
	else
	{
		cout << setw(5) << left << "занят" << endl;
	}
}
// TODO: Вынести структуру Client в отдельный "модуль": Client.h и Client.cpp
struct Client
{
	int number = 1;
	int room_num = 0;
	string name = "";
	string surename = "";
	string phone = "";
	unsigned short int days = 0;
	int cost_room = 0;
	// Hotel() {};
  /*   Hotel(int room_number,string name, string surename, string phone, int days, float cost)
	 {
		 this->room_number = room_number;
		 this->name = name;
		 this->surename = surename;
		 this->phone = phone;
		 this->days = days;
		 this->cost = cost;
	 }*/
	void showInfoClient(int N)
	{
		cout << "  " << N - 1 << "\t ";
		cout << setw(7) << left << this->room_num;
		cout << setw(17) << left << this->name;
		cout << setw(24) << left << this->surename;
		cout << setw(21) << left << this->phone;
		cout << setw(8) << left << this->days;
		cout << setw(8) << left << this->cost_room << endl;
	}
	string CheckingCorrectnessTelNumber(string& num)
	{
		do {
			getline(cin, num);
			regex rx("\\+[[:digit:]]{1}\\([0-9]{3}\\)[[:digit:]]{3}-[[:digit:]]{2}-[[:digit:]]{2}");
			if (regex_match(num, rx))
			{
				break;
			}
			else
			{
				cout << "Формат ввода +7(999)999-99-99\n";
				cout << "Повторите ввод телефона:";
			}
		} while (true);
		return num;
	}
	void add_client(int c)
	{
		cout << "\n Введите данные клиента";
		cout << "\n ----------------------\n";
		cout << "Имя:";
		cin.get();
		getline(cin, name);
		cout << "Фамилия:";
		getline(cin, surename);
		cout << "Номер телефона:";
		CheckingCorrectnessTelNumber(phone);
		cout << "Количество дней для проживания:";
		cin >> days;
		cost_room = days * c;
		cout << "\n\tИнформация о клиенте добавлена...!!!\n";
	}
	void client_menu();              //для отображения меню клиентов
	void save_customer(int, int);    //для добавления клиента
	void modify_customer();          //для редактирования записи клиента
	void display_all_customer();     //для отображения всех клиентов
	void display_a_customer();       //для отображения записи клиента
	void delete_customer();          //для удаления записи клиента
	void removeCustomerFromRoom(int);//для освобождения номера и удаления записи клиента

};
void createClient(vector<string> text, Client& c)
{
	c.room_num = stoi(text[0]);
	c.name = text[1];
	c.surename = text[2];
	c.phone = text[3];
	c.days = stoi(text[4]);
	c.cost_room = stoi(text[5]);
}
void readFileClient(string path, vector<string>& text, int N)
{
	ifstream fin;
	fin.open(path);
	if (fin.is_open())
	{
		string line;
		for (int i = 0; i < N; i++)
		{
			line.assign("");
			getline(fin, line);
			text.push_back(line);
		}

	}
	fin.close();
}
void reportClient()
{
	int nFile = 1;
	do {
		Client h;
		vector<Client> clients;
		string path;
		path = path + ("hotel\\clients\\" + to_string(nFile) + ".txt");
		vector<string> text;
		readFileClient(path, text, 6);
		if (text.empty())
		{
			break;
		}
		else
		{
			createClient(text, h);
			clients.push_back(h);
		}
		nFile++;
		h.showInfoClient(nFile);
	} while (true);
}
void showInfoGuest(int file)
{
	system("cls");
	string path("hotel\\clients\\" + to_string(file) + ".txt");
	ifstream fin;
	string t;
	vector<string> client;
	fin.open(path);
	if (fin.is_open())
	{
		while (getline(fin, t))
		{
			client.push_back(t);
		}
		cout << "\n Информация о клиенте";
		cout << "\n ------------------";
		cout << "\n № : " << file;
		cout << "\n № номера: " << client[0];
		cout << "\n Имя: " << client[1];
		cout << "\n Фамилия: " << client[2];
		cout << "\n Номер телефона: " << client[3];
		cout << "\n Забронированно дней: " << client[4];
		cout << "\n Общая стоимость: " << client[5];
		cout << endl;
	}
	else
	{
		cout << "\n Извините, файла с номером клиента нет....!!";
	}
	fin.close();
}
void Room::bookRoom()
{
	int nRoom = 0;
	int f = 1;
	int cost = 0;
	Client c;
	fstream fin;
	ofstream fout;
	vector<Room> rooms;
	cout << "Выберите № номера который вы хотите забронировать: \n";
	cin >> nRoom;
	do {
		Room h;
		string ispath = "";
		ispath = ispath + ("hotel\\rooms\\" + to_string(f) + ".txt");
		vector<string> text;
		ifstream fin;
		fin.open(ispath);
		if (fin.is_open())
		{
			string line;
			for (int i = 0; i < 5; i++)
			{
				line.assign("");
				getline(fin, line);
				text.push_back(line);
			}

		}
		fin.close();
		if (text.empty())
		{
			break;
		}
		else
		{
			createRoom(text, h);
			rooms.push_back(h);
		}
		if (h.room_no == nRoom)
		{
			if (h.status != 0)
			{
				cout << "Номер занят,выберите другой номер.";
				esc();
			}
			else
			{
				h.status = 1;
				fout.open(ispath);
				if (fout.is_open())
				{
					fout << h.room_no << endl;
					fout << h.category << endl;
					fout << h.cost_num << endl;
					fout << h.local_no << endl;
					fout << h.status << endl;
					cost = h.cost_num;
				}
				fout.close();
				c.save_customer(nRoom, cost);
				cout << "\n\n\t\tНомер забронирован! ";
				esc();
			}
		}
		f++;
	} while (true);
}
void Room::bookRoomCategory()
{
	char battom;
	int r = 0;
	cout << "1.Посмотреть информацию об одноместных номерах \n";
	cout << "2.Посмотреть информацию о двуместных номерах\n";
	cout << "3.Посмотреть информацию о трехместных номерах\n";
	cout << " ВАШ ВЫБОР: ";
	cin >> r;
	system("cls");
	infoHeadRoom();
	vector<Room> rooms;
	int num = 1;
	do {
		Room h;
		string path = "";
		path = path + ("hotel\\rooms\\" + to_string(num) + ".txt");
		vector<string> text;
		readFileRoom(path, text, 5);
		if (text.empty())
		{
			break;
		}
		else
		{
			createRoom(text, h);
			rooms.push_back(h);
		}
		if (h.local_no == r)
		{
			h.listRoom();
		}
		num++;
	} while (true);
	do {
		cout << "\nНажмите любую клавишу для продолжения или Esc...для выхода в главное меню.\n";
		battom = _getch();
		if ((int)battom == 27)
		{
			system("cls");
			main_menu();
			break;
		}
		else
		{
			bookRoom();
			break;
		}
	} while (true);
}
void Client::save_customer(int no, int cost)
{
	int numFile = 1;
	ofstream fout;
	vector<string> client;
	fstream fin;
	Room h;
	do {
		string path("hotel\\clients\\" + to_string(numFile) + ".txt");
		fin.open(path);
		if (!fin.is_open())
		{
			add_client(cost);
			fout.open(path);
			if (fout.is_open())
			{
				room_num = no;
				fout << room_num << endl;
				fout << name << endl;
				fout << surename << endl;
				fout << phone << endl;
				fout << days << endl;
				fout << cost_room << endl;
			}
			fout.close();
			break;
		}
		else
		{
			string line = "";
			while (getline(fin, line))
			{
				client.push_back(line);
			}
		}
		fin.close();
		numFile++;
	} while (true);
	cout << "\n\n Нажмите любую клавишу, что-бы продолжить....!!";
	numFile = _getch();
}
void Client::display_a_customer()
{
	system("cls");
	display_all_customer();
	int r = 0;
	cout << "\n Выберите № клиента: ";
	cin >> r;
	string path("hotel\\clients\\" + to_string(r) + ".txt");
	ifstream fin;
	string t;
	vector<string> client;
	fin.open(path);
	if (fin.is_open())
	{
		if (number = r)
		{
			while (getline(fin, t))
			{
				client.push_back(t);
			}
			cout << "\n Сведения о клиенте";
			cout << "\n ------------------";
			cout << "\n Клиент №: " << r;
			cout << "\n Номер: " << client[0];
			cout << "\n Имя: " << client[1];
			cout << "\n Фамилия: " << client[2];
			cout << "\n Номер телефона: " << client[3];
			cout << "\n Забронированно дней: " << client[4];
			cout << "\n Общая стоимость: " << client[5];
			cout << endl;
		}
	}
	else
	{
		cout << "\n Извините, информации о клиенте нет....!!";
	}
	fin.close();
	cout << "\nНажмите клавишу Esc... для возврата в главное меню \n";
	do {
		char battom;
		battom = _getch();
		if ((int)battom == 27)
		{
			break;
		}
	} while (true);
	system("cls");
}
void Client::modify_customer()
{
	system("cls");
	int numFile = 0;
	char button;
	Client c;
	fstream fp;
	ofstream fout;
	vector<string> client;
	display_all_customer();
	cout << "\n\n\tМеню редактирования";
	cout << "\n\n\tВыберите № клиента для изменения: ";
	cin >> numFile;
	string path("hotel\\clients\\" + to_string(numFile) + ".txt");
	fp.open(path, ios::in | ios::out);
	if (fp.is_open())
	{
		string line;
		while (getline(fp, line))
		{
			client.push_back(line);
		}
			showInfoGuest(numFile);
			cout << "\nВведите новую информацию" << endl;
			fout.open(path, ios::in | ios::out);
			if (fout.is_open())
			{
				cout << "Поменять номер (Y/N): \n";
				button = _getch();
				if (button == 'n' || button == 'N')
				{
					room_num = stoi(client[0]);
					fout << room_num << endl;
				}
				else
				{
					cout << "Введите номер: ";
					cin >> room_num;
					fout << room_num << endl;
				}
				cout << "Поменять имя (Y/N): \n";
				button = _getch();
				if (button == 'n' || button == 'N')
				{
					name = client[1];
					fout << name << endl;
				}
				else
				{
					cout << "Введите имя: ";
					cin >> name;
					fout << name << endl;
				}
				cout << "Поменять фамилию (Y/N): \n";
				button = _getch();
				if (button == 'n' || button == 'N')
				{
					surename = client[2];
					fout << surename << endl;
				}
				else
				{
					cout << "Введите фамилию: ";
					cin >> surename;
					fout << surename << endl;
				}
				cout << "Поменять номер телефона (Y/N): \n";
				button = _getch();
				if (button == 'n' || button == 'N')
				{
					 phone = client[3];
					fout << phone << endl;
				}
				else
				{
					cout << "Введите телефон: ";
					CheckingCorrectnessTelNumber(phone);
					fout << phone << endl;
				}
				cout << "Поменять количество дней проживания (Y/N): \n";
				button = _getch();
				if (button == 'n' || button == 'N')
				{
					days = stoi(client[4]);
					fout << days << endl;
				}
				else
				{
					cout << "Введите дни: ";
					cin >> days;
					fout << days << endl;
				}
				cout << "Поменять стоимость проживания (Y/N): \n";
				button = _getch();
				if (button == 'n' || button == 'N')
				{
					cost_room = stoi(client[5]);
					fout << cost_room << endl;
				}
				else
				{
					cout << "Введите сумму: ";
					cin >> cost_room;
					fout << cost_room << endl;
				}
			}
			fout.close();
			cout << "\n\n\t Данные изменены...";
	}
	fp.close();
	cout << "\n\n Нажмите любую клавишу, что-бы продолжить....!!";
	numFile = _getch();
	system("cls");
}
void showHeadClient()
{
	cout << "\n\t\t\tСписок проживающих клиентов";
	cout << "\n\t\t\t-------------------------------\n";
	cout << endl;
	cout << "===============================================================================================\n";
	cout << " № Кл. |" << "№ Номер|" << "Имя \t\t" << "|Фамилия\t\t" << "| № Телефон\t  " << "|Кол.Дней " << "|Стоимость|" << endl;
	cout << "===============================================================================================\n";
}
void Client::display_all_customer()
{
	system("cls");
	int numFile = 1;
	string path("hotel\\clients\\" + to_string(numFile) + ".txt");
	fstream fp;
	fp.open(path, ios::in);
	if (fp.is_open())
	{
		showHeadClient();
		reportClient();
	}
	else
	{
		cout << "ERROR!!! FILE COULD NOT BE OPEN ";
		numFile = _getch();
		return;
	}
	fp.close();
	cout << "\n Нажмите любую клавишу, чтобы продолжить.....!!";
	numFile = _getch();
}
void Client::delete_customer()
{
	display_all_customer();
	int numFile = 0;
	Client c;
	do {
		cout << "\nВыберите № Клиента, которого вы хотите удалить из списка: ";
		if (cin >> numFile)
		{
			cout << "\n\tВы действительно хотите удалить запись (Y/N): ";
			char battom;
			battom = _getch();
			if (battom == 'n' || battom == 'N')
			{
				break;
			}
			else
			{
				int f = 1;
				fstream fin;
				ofstream fout;
				Room h;
				vector<Room> rooms;
				do {
					string path_client("hotel\\clients\\" + to_string(numFile) + ".txt");
					vector<string> client;
					fin.open(path_client);
					if (!fin.is_open())
					{
						cout << "\n № файла клиента не найден.";
						break;
					}
					else
					{
						string line = "";
						while (getline(fin, line))
						{
							client.push_back(line);
						}
					}
					fin.close();
					string path_room("hotel\\rooms\\" + to_string(f) + ".txt");
					vector<string> text;
					readFileRoom(path_room, text, 5);
					if (text.empty())
					{
						break;
					}
					else
					{
						createRoom(text, h);
						rooms.push_back(h);
					}
					f++;
					if (stoi(client[0]) == h.room_no)
					{
						h.status = 0;
						fout.open(path_room);
						if (fout.is_open())
						{
							fout << h.room_no << endl;
							fout << h.category << endl;
							fout << h.cost_num << endl;
							fout << h.local_no << endl;
							fout << h.status << endl;
						}
						fout.close();
						cout << "\n\tНомер свободен! ";
					}
					string ipath("hotel\\clients\\" + to_string(numFile) + ".txt");
					remove(ipath.c_str());
					string newPath;
					do {
						numFile++;
						string path("hotel\\clients\\" + to_string(numFile) + ".txt");
						fin.open(path);
						if (!fin.is_open())
							break;
						fin.close();
						string newPath("hotel\\clients\\" + to_string(numFile - 1) + ".txt");

						if (rename(path.c_str(), newPath.c_str()) == 0)
						{
							continue;
						}
					} while (true);
					cout << "\n\tФайл удален!";
					break;
				} while (true);
				break;
			}
		}
		else
		{
			cout << "\nВведите корректные данные!";
			break;
		}
	} while (true);
	cout << "\n\n Нажмите любую клавишу, что-бы продолжить....!!";
	numFile = _getch();
}
void Client::removeCustomerFromRoom(int numRoom)
{
	Client c;
	int nFile = 1;
	do {
		vector<Client> clients;
		string ispath;
		ispath = ispath + ("hotel\\clients\\" + to_string(nFile) + ".txt");
		vector<string> text;
		readFileClient(ispath, text, 6);
		if (text.empty())
		{
			break;
		}
		else
		{
			createClient(text, c);
			clients.push_back(c);
		}
		if (c.room_num == numRoom)
		{
			cout << "\n\tХотите удалить запись клиента (Y/N): ";
			do {
				char battom;
				battom = _getch();
				if (battom == 'n' || battom == 'N')
				{
					break;
				}
				else
				{
					string ipath("hotel\\clients\\" + to_string(nFile) + ".txt");
					remove(ipath.c_str());
					ifstream fin;
					string newPath;
					do {
						nFile++;
						string path("hotel\\clients\\" + to_string(nFile) + ".txt");
						fin.open(path);
						if (!fin.is_open())
							break;
						fin.close();
						string newPath("hotel\\clients\\" + to_string(nFile - 1) + ".txt");

						if (rename(path.c_str(), newPath.c_str()) == 0)
						{
							continue;
						}
					} while (true);
					cout << "\n\tФайл удален!";
					break;
				}
			} while (true);
		}
		nFile++;
	} while (true);
	cout << "\n\n Нажмите любую клавишу, что-бы продолжить....!!";
	nFile = _getch();
}
void Room::releaseNumber()
{
	int numRoom = 0;
	int f = 1;
	fstream fin;
	ofstream fout;
	infoHeadRoom();
	vector<Room> rooms;
	do {
		string path;
		Room h;
		path = path + ("hotel\\rooms\\" + to_string(f) + ".txt");
		vector<string> text;
		readFileRoom(path, text, 6);
		if (text.empty())
		{
			break;
		}
		else
		{
			createRoom(text, h);
			rooms.push_back(h);
		}
		f++;
		h.listRoom();
	} while (true);
	f = 1;
	Client c;
	cout << "\nВыберите № номера который надо освободить: ";
	cin >> numRoom;
	do {
		Room r;
		string ispath = "";
		ispath = ispath + ("hotel\\rooms\\" + to_string(f) + ".txt");
		vector<string> text;
		fin.open(ispath);
		if (fin.is_open())
		{
			string line;
			for (int i = 0; i < 6; i++)
			{
				line.assign("");
				getline(fin, line);
				text.push_back(line);
			}
		}
		fin.close();
		if (text.empty())
		{
			system("cls");
			break;
		}
		else
		{
			createRoom(text, r);
			rooms.push_back(r);
		}
		if (r.room_no == numRoom)
		{
			r.status = 0;
			fout.open(ispath);
			if (fout.is_open())
			{
				fout << r.room_no << endl;
				fout << r.category << endl;
				fout << r.cost_num << endl;
				fout << r.local_no << endl;
				fout << r.status << endl;
			}
			fout.close();
			c.removeCustomerFromRoom(numRoom);
		}
		f++;
	} while (true);
	cout << "\n\tНомер свободен! ";
	esc();
}
void Room::main_menu()
{
	Client c;
	int change = 0;
	do
	{
		system("cls");
		cout << "\n\n\t\t\t\tГЛАВНОЕ МЕНЮ\n";
		cout << "\t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
		cout << "\t\t\t 1.Посмотреть список номеров " << endl;
		cout << "\t\t\t 2.Меню записи клиентов \n";
		cout << "\t\t\t 3.Забронировать номер \n";
		cout << "\t\t\t 4.Освободить номер \n";
		cout << "\t\t\t 5.Открыть новый номер в отеле \n";
		cout << "\t\t\t 6.Выход \n";
		cout << "\t\t\t ВАШ ВЫБОР: ";
		if (cin >> change)
		{
			switch (change)
			{
			case 1:system("cls");
				menuRoom();
				break;
			case 2:system("cls");
				c.client_menu();
				break;
			case 3:system("cls");
				menuBookRoom();
				break;
			case 4:system("cls");
				releaseNumber();
				break;
			case 5:system("cls");
				saveRoom();
				break;
			case 6: exit(0);
				break;
			}
		}
		else
		{
			system("cls");
			system("pause");
			cout << "Incorrect input!" << endl;
			exit(0);
		}
	} while (true);
}
void Client::client_menu()
{
	Room h;
	int option = 0;
	while (true)
	{
		system("cls");
		cout << "\n\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
		cout << "\n\t\t1.Добавить клиента";
		cout << "\n\t\t2.Список клиентов";
		cout << "\n\t\t3.Информация о клиенте";
		cout << "\n\t\t4.Редактирование записи клиента";
		cout << "\n\t\t5.Удалить запись клиента";
		cout << "\n\t\t6.Вернутся в главное меню";
		cout << "\n\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
		cout << "\n\t\tВАШ ВЫБОР: ";
		if (cin >> option)
		{
			switch (option)
			{
			case 1:system("cls");
				save_customer(0, 0);
				break;
			case 2:display_all_customer();
				system("cls");
				break;
			case 3:
				display_a_customer();
				break;
			case 4:
				modify_customer();
				system("cls");
				break;
			case 5: delete_customer();
				system("cls");
				break;
			case 6: system("cls");
				h.main_menu();
				break;
			}
		}
		else
		{
			break;
		}
	}

}

int main()
{
	//Example example;
	//example.Print();

	setlocale(0, "");
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Room r;
	r.main_menu();

	return 0;
}