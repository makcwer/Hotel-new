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

using namespace std;

struct Room
{
    unsigned short int room_no;
    string category;
    unsigned short int cost_num;
    unsigned short int local_no;
    int status;
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
    void showRo(int N)
    {
        cout << " " << N - 1<<"\t";
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
    void showAllRoom()
    {
        showHeadRoom();
        vector<Room> rooms;
        int num = 1;
        do {
            string path;
            Room h;
            path = path + ("hotel\\rooms\\" + to_string(num) + ".txt");
            vector<string> text;
            readFileRoom(path, text, 20);
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
            h.showRo(num);
        } while (true);
        esc();
    }
    void esc()
    {
        cout << "\n\n\tНажмите клавишу Esc... для возврата в главное меню \n";
        do {
            char battom;
            battom = _getch();
            if ((int)battom == 27)
            {
                system("cls");
                main_menu();
            }
        } while (true);
    }
    void createRoom(vector<string> text, Room& h)
    {
        h.room_no = stoi(text[0]);
        h.category = text[1];
        h.cost_num = stoi(text[2]);
        h.local_no = stoi(text[3]);
        h.status = stoi(text[4]);
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
    void showHeadRoom()
    {
        cout << "\n\t\t\t\tСписок номеров";
        cout << "\n\t\t\t-------------------------------\n";
        cout << endl;
        cout << "==========================================================================\n";
        cout << "|№ | № Номера   "  << "| Категория  " << "| Цена за сутки " << "| Кол.мест  " << "| Статус        |" << endl;
        cout << "==========================================================================\n";
    }
    void saveRoom();
    void menuRoom();
    void main_menu();
    void menuBookRoom();
    void listRoom();
    void infoHeadRoom();
    void bookRoomCategory();
    void bookRoom();
    void bookRoomCost();
    void releaseNumber();
};
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
    void showRoom(int N)
    {
        cout << "  " << N - 1 << "\t ";
        cout << setw(7) << left << this->room_num;
        cout << setw(17) << left << this->name;
        cout << setw(24) << left << this->surename;
        cout << setw(21) << left << this->phone;
        cout << setw(8) << left << this->days;
        cout << setw(8) << left << this->cost_room << endl;
    }
    void show_customer(int)
    {
        system("cls");
        string path("hotel\\clients\\" + to_string(number) + ".txt");
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
            cout << "\n Сведения о клиенте";
            cout << "\n ------------------";
            cout << "\n № : " << number;
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
            cout << "\n Извините, номера клиента нет....!!";
        }
        fin.close();
    }
    string CheckingCorrectnessTelNumber(string& num)
    {
        do {
            getline(cin, num);
            regex rx("\\+[[:digit:]]{1}\\([[:digit:]]{3}\\)[[:digit:]]{3}-[[:digit:]]{2}-[[:digit:]]{2}");
            if (regex_match(num, rx))
            {
                break;
            }
            else
            {
                cout << "Формат ввода +7(999)999-99-99\n";
                cout << "Повторите ввод:";
            }
        } while (true);
        return num;
    }
    void add_customer(int c)
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
        cout << "\n Клиент добавлен...!!!" << endl;
    }
    void modify_customer_record()
    {
        cout << "\n№ Номер : " << number;
        cout << "\n ----------------------" << endl;
        cout << "Новый номер:";
        cin >> room_num;
        cout << "Новое имя: ";
        cin.get();
        getline(cin, name);
        cout << "Новыая фамилия: ";
        getline(cin, surename);
        cout << "Новый номер телефона:";
        CheckingCorrectnessTelNumber(phone);
        cout << " Количество дней для проживания: ";
        cin >> days;
        cout << "Введите сумму:";
        cin >> cost_room;
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
            h.showRoom(nFile);
        } while (true);
    }
    void createClient(vector<string> text, Client& c)
    {
        c.room_num = stoi(text[0]);
        c.name = text[1];
        c.surename = text[2];
        c.phone = text[3];
        c.days = stoi(text[4]);
        c.cost_room = stoi(text[5]);
    }
    void client_menu();              //для отображения меню клиентов
    void save_customer(int,int);     //для добавления клиента
    void modify_customer();          //для редактирования записи клиента
    void display_all_customer();     //для отображения всех клиентов
    void display_a_customer();       //для отображения записи клиента
    void delete_customer();          //для удаления записи клиента
    void removeCustomerRoom(int);    //для освобождения номера и удаления записи клиента

};
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
        h.showRo(num);
    } while (true);
    cout << endl;
    cout << "\tНа текущий момент в отеле " << num - 1 << " номер(ов)";
    string path("hotel\\rooms\\" + to_string(num) + ".txt");
    ofstream fout;
    do {
        add_room();
        fout.open(path, ios::app);
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
    int r = 0,k = 0;
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
void Room::infoHeadRoom()
{
    cout << "=======================================================================\n";
    cout << "| № Номера   " << "| Категория  " << "| Цена за сутки " << "| Кол.мест  " << "| Статус        |" << endl;
    cout << "=======================================================================\n";
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
                c.save_customer(nRoom,cost);
                cout <<"\n\n\t\tНомер забронирован! ";
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
                showAllRoom();
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
void Client::save_customer(int no,int cost)
{
    //display_all_customer();
    int r = 1;
    ofstream fout;
    vector<string> client;
    fstream fin;
    Room h;
    do {
        string path("hotel\\clients\\" + to_string(r) + ".txt");
        fin.open(path);
        if (!fin.is_open())
        {
            add_customer(cost);
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
                //h.esc();
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
        r++;
    } while (true);
    system("cls");
}
void Client::display_a_customer()
{
    system("cls");
    display_all_customer();
    int r = 0;
    cout << "\n Выберите клиента: ";
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
        cout << "\n Извините, клиента нет....!!";
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
    fstream fp;
    ofstream fout;
    display_all_customer();
    cout << "\n\n\tМеню редактирования";
    cout << "\n\n\tВыберите № клиента для изменения: ";
    cin >> numFile;
    cin.get();
    string path("hotel\\clients\\" + to_string(numFile) + ".txt");
    fp.open(path,ios::in | ios::out);
    if(fp.is_open())
    {
        if (number = numFile)
        {
            show_customer(numFile);
            cout << "\nВведите новую информацию" << endl;
            modify_customer_record();
            fout.open(path, ios::in | ios::out);
            if (fout.is_open())
            {
                fout << room_num << endl;
                fout << name << endl;
                fout << surename << endl;
                fout << phone << endl;
                fout << days << endl;
                fout << cost_room << endl;
            }
            fout.close();
            cout << "\n\n\t Данные изменены...";
        }
        else
        {
            cout << "\n\n Record Not Found ";
        }
        
    }
    fp.close();
    cout << "\n\n Нажмите любую клавишу, чтобы продолжить....!!";
    _getch();
    system("cls");
}
void showHeadClient()   
{
    cout << "\n\t\t\tСписок проживающих клиентов";
    cout << "\n\t\t\t-------------------------------\n";
    cout << endl;
    cout << "===============================================================================================\n";
    cout << " № Кл. |"<<"№ Номер|" << "Имя \t\t" << "|Фамилия\t\t" << "| № Телефон\t  " << "|Кол.Дней " << "|Стоимость|" << endl;
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
        _getch();
        return;
    }
    fp.close();
    cout << "\n Нажмите любую клавишу, чтобы продолжить.....!!";
    _getch();
}
void Client::delete_customer()
{
    display_all_customer();
    int numFile = 0;
    cout << "\n\n\n МЕНЮ УДАЛЕНИЯ";
    cout << "\n\nВыберите № Клиента, которого вы хотите удалить: ";
    cin >> numFile;
    if (number = numFile)
    {
        cout << "\n\tВы действительно хотите удалить запись (Y/N): ";
        do {
            char battom;
            battom = _getch();
            if (battom == 'n')
            {
                break;
            }
            else
            {    
                string path("hotel\\clients\\" + to_string(numFile) + ".txt");
                remove(path.c_str());
                ifstream fin;
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
            }
        } while (true);
    }
    else
    {
        cout << "\n\n Record Not Found ";
    }
    cout << "\n\n Нажмите любую клавишу, что-бы продолжить....!!";
    _getch();
}
void Client::removeCustomerRoom(int n)
{
    int numFile = 1;
    Client c;
    int nFile = 1;
    do {
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
            createClient(text, c);
            clients.push_back(c);
        }
        nFile++;
        if (c.room_num == n)
        {
            cout << "\n\tХотите удалить запись клиента (Y/N): ";
            do {
                char battom;
                battom = _getch();
                if (battom == 'n')
                {
                    break;
                }
                else
                {
                    string path("hotel\\clients\\" + to_string(numFile) + ".txt");
                    remove(path.c_str());
                    ifstream fin;
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
                }
            } while (true);
        }
    } while (true);
    cout << "\n\n Нажмите любую клавишу, что-бы продолжить....!!";
    _getch();
}
void Room::releaseNumber()
{
    int n = 0;
    int f = 1;
    fstream fin;
    ofstream fout;
    infoHeadRoom();
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
        h.listRoom();
    } while (true);
    f = 1;
    Client c;
    cout << "Выберите № номера который надо освободить: \n";
    cin >> n;
    do {
        Room r;
        string ispath = "";
        ispath = ispath + ("hotel\\rooms\\" + to_string(f) + ".txt");
        vector<string> text;
        ifstream fin;
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
        if (r.room_no == n)
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
            c.removeCustomerRoom(n);
            cout << "\n\tНомер свободен! ";
            esc();
        }
        f++;
    } while (true);
}
void Room::main_menu()
{
    Client c;
    int change = 0;
    do
    {
        cout << "\n\n\t\t\t\tГЛАВНОЕ МЕНЮ\n";
        cout << "\t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
        cout << "\t\t\t 1.Посмотреть список номеров " << endl;
        cout << "\t\t\t 2.Меню клиентов \n";
        cout << "\t\t\t 3.Забронировать номер \n";
        cout << "\t\t\t 4.Освободить номер \n";
        cout << "\t\t\t 5.Открыть новый номер в отеле \n";
        cout << "\t\t\t 6.Выход \n";
        cout << "\t\t\t ВАШ ВЫБОР: ";
        if (cin>>change)
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
            cout << "Incorrect input" << endl;
            return;
            exit(0);
        }
    } while (true);
}
void Client::client_menu()
{
    Room h;
    Client c;
    int option = 0;
    while(true)
    {
        cout << "\n\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
        cout << "\n\t\t1.Добавить клиента";
        cout << "\n\t\t2.Список клиентов";
        cout << "\n\t\t3.Информация о клиенте";
        cout << "\n\t\t4.Редактирование";
        cout << "\n\t\t5.Удаление клиента";
        cout << "\n\t\t6.Вернутся в главное меню";
        cout << "\n\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
        cout << "\n\t\tВАШ ВЫБОР: ";
        if (cin >> option)
        {
            switch (option)
            {
            case 1:system("cls");
                save_customer(0 ,0);
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
    setlocale(0, "");
    srand(time(NULL));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Room r;
    r.main_menu();

    return 0;
}