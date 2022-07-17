#include <iostream>
#include <fstream> 
#include <string>
#include <windows.h>
#include <vector>
#include <cstdio>
#include <iomanip>
#include <conio.h>
using namespace std;
struct Room
{
    int num = 1;
    unsigned short int room_no = 1;
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
    void showRo(int& N)
    {
        num = N - 1;
        cout << "  " << this->num << "\t";
        cout << setw(12) << left << this->room_no;
        cout << setw(21) << left << this->category;
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
        //№ | №Номер | статус (vip, обычный) | цена за сутки | категория | статус (занят/нет)
       // 1	17	vip			3000	     1		занят
        cout << "\n\t\t\t\tСписок номеров";
        cout << "\n\t\t\t-------------------------------\n";
        cout << endl;
        cout << "==============================================================================================\n";
        cout << "| № " << setw(5) << "| № Номера" << setw(15) << "| Категория" << setw(20) << "| Цена за сутки" << setw(15) << "| Кол.мест" << setw(15) << "| Статус            |" << endl;
        cout << "==============================================================================================\n";
        vector<Room> rooms;
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
        //cout << "\n\n\tНажмите клавишу Esc... для возврата в главное меню \n";
        //do {
        //    char battom;
        //    battom = _getch();
        //    if ((int)battom == 27)
        //    {
        //        system("cls");
        //        main_menu();
        //    }
        //} while (true);
    }
    void createRoom(vector<string> text, Room& h)
    {
        h.room_no = stoi(text[0]);
        h.category = text[1];
        h.cost_num = stod(text[2]);
        h.local_no = stod(text[3]);
        h.status = stod(text[4]);
    }
    void add_customer_room()
    {
        cout << "\tМЕНЮ ДОБАВЛЕНИЯ НОМЕРА\n";
        cout << "\n Введите данные номера";
        cout << "\n ----------------------" << endl;
        cout << " № Номер: ";
        cin >> room_no;
        cin.get();
        cout << " Категория: ";
        getline(cin, category);
        cout << " Цена за сутки: ";
        cin >> cost_num;
        cout << " Кол.мест: ";
        cin >> local_no;
        cin.get();
        cout << " Статус: ";
        cin>>status;
        cout << "\n Номер добавлен...!!!" << endl;
    }
    void showHeadRoom()
    {
        cout << "\n\t\t\t\tСписок номеров";
        cout << "\n\t\t\t-------------------------------\n";
        cout << endl;
        cout << "==============================================================================================\n";
        cout << "| № " << setw(5) << "| № Номера" << setw(15) << "| Категория" << setw(20) << "| Цена за сутки" << setw(15) << "| Кол.мест" << setw(15) << "| Статус            |" << endl;
        cout << "==============================================================================================\n";
    }
    void showInfoRoom();
    void main_menu();
    void saveRoom();
    void oneRoomCat();
    void bookRoom();
    void bookRoomCategory();
    void showRoomCategory();
};
struct Hotel
{
    string city;
    string street;
    int number;
    vector<Room> rooms;

};
void Room::bookRoomCategory()
{
    showRoomCategory();
}
void Room::bookRoom()
{
    Room r;
    cout << "1.Забронировать номер по категории \n";
    cout << "2.Забронировать номер по стоимости \n";
    cout << "3.Вернутся в главное меню \n";
    cout << " ВАШ ВЫБОР: ";
    do {
        int change;
        cin >> change;
        switch (change)
        {
        case 1:system("cls");
            r.bookRoomCategory();
            break;
        case 2:system("cls");
            //bookRoomCost();
            break;
        case 3: system("cls");
            main_menu();
            break;
        }
    } while (true);
}
void Room::saveRoom()
{
    showAllRoom();
    int option = 0;
    string path("hotel\\rooms\\" + to_string(num) + ".txt");
    ofstream fout;
    fout.open(path, ios::app);
    do {
            add_customer_room();
            if (fout.is_open())
            {
                fout << room_no << endl;
                fout << category << endl;
                fout << cost_num << endl;
                fout << local_no << endl;
                fout << status << endl;
            }
            cout << "\n\tНажмите 1, чтобы добавить больше клиентов.";
            cout << "\n\tНажмите 2, чтобы вернуться в главное меню.\n";
            cout << "Ваш выбор: ";
            cin >> option;
            cin.get();
    } while (option == 1);
    fout.close();
    system("cls");
}
void Room::oneRoomCat()
{
    showHeadRoom();
    vector<Room> rooms;
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
}
void Room::showRoomCategory()
{
    Room r;
    cout << "1.Посмотреть информацию об одноместных номерах \n";
    cout << "2.Посмотреть информацию о двуместных номерах\n";
    cout << "3.Посмотреть информацию о трехместных номерах\n";
    cout << "4.Вернутся в главное меню \n";
    cout << " ВАШ ВЫБОР: ";
    do {
        int change;
        cin >> change;
        switch (change)
        {
        case 1:system("cls");
            r.oneRoomCat();
            break;
        case 2:system("cls");
            //twoRoomCat();
            break;
        case 3:system("cls");
            //threeRoomCat;
            break;
        case 4: system("cls");
            main_menu();
            break;
        }
    } while (true);
}
void Room::showInfoRoom()
{
    cout << "1.Посмотреть все номера \n";
    cout << "2.Посмотреть категории номеров \n";
    cout << "3.Вернутся в главное меню \n";
    cout << " ВАШ ВЫБОР: ";
    do {
        int change;
        cin >> change;
        switch (change)
        {
        case 1:system("cls");
            showAllRoom();
            break;
        case 2:system("cls");
            showRoomCategory();
            break;
        case 3: system("cls");
            main_menu();
            break;
        }
    } while (true);
}

struct Client
{
    int num;
    unsigned int room_number;
    string name;
    string surename;
    string phone;
    int days;
    double cost;
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
    void showInfo(int& N)
    {
        cout << N - 1 <<"\t";
        cout << setw(19) << left << this->name;
        cout << setw(26) << left << this->surename;
        cout << setw(22) << left << this->phone;
        cout << setw(8) << left << this->days;
        cout << setw(5) << left << this->cost << endl;
    }
    void show_customer(int)
    {
        system("cls");
        string path("hotel\\clients\\" + to_string(room_number) + ".txt");
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
                cout << "\n № номера: " << room_number;
                cout << "\n Имя: " << client[0];
                cout << "\n Фамилия: " << client[1];
                cout << "\n Номер телефона: " << client[2];
                cout << "\n Забронированно дней: " << client[3];
                cout << "\n Общая стоимость: " << client[4];
                cout << endl;
        }
        else
        {
            cout << "\n Извините, номера нет. не найден или пустой....!!";
        }
        fin.close();
    }
    void add_customer()
    {
        cout << "\n Введите данные клиента";
        cout << "\n ----------------------" << endl;
        cout << " Имя: ";
        getline(cin, name);
        cout << " Фамилия: ";
        getline(cin, surename);
        cout << " Номер телефона: ";
        getline(cin, phone);
        cout << " Количество дней для проживания: ";
        cin >> days;
        cost = days * 900;//900 стоимость номера в день
        cout << "\n Клиент добавлен...!!!"<<endl;
    }
    void modify_customer_record()
    {
        cout << "\n№ Номер : " << room_number;
        cout << "\n ----------------------" << endl;
        cout << "Новое Имя: ";
        getline(cin, name);
        cout << "Новыая Фамилия: ";
        getline(cin, surename);
        cout << "Новый Номер телефона: ";
        getline(cin, phone);
        cout << " Количество дней для проживания: ";
        cin >> days;
        cout << "Введите сумму:";
        cin >> cost;//900 стоимость номера в день
     }
    void readFileHotel(string path, vector<string>& text, int N)
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
     void report()
     {
         int number = 1;
         vector<Client> hotels;
        do{
            string path;
            path = path + ("hotel\\clients\\" + to_string(number) + ".txt");
            vector<string> text;
            readFileHotel(path, text,5);
           if(text.empty())
           {
              break;
           }
           else
           {
               Client h;
               createHotel(text, h);
               hotels.push_back(h);
               number++;
               h.showInfo(number);
           }
        }while(true);
     /*   for (auto otel : hotels)
            otel.showInfo();*/
     }
     void createHotel(vector<string> text, Client& h)
     {
         h.name = text[0];
         h.surename = text[1];
         h.phone= text[2];
         h.days = stoi(text[3]);
         h.cost = stoi(text[4]);
     }
     void client_menu();                //для отображения главного меню
     void save_customer();            //для бронирования номера
     void modify_customer();          //для редактирования записи клиента
     void display_all_customer();     //для отображения забронированых номеров
     void display_a_customer();       //для отображения записи клиента
     void delete_customer();          //для удаления записи
     
};

void Client::save_customer()
{
    system("cls");
    int option = 0;
    display_all_customer();
    int r;
    cout << "\n\nВыберите номер клиента: ";
    cin >> r;
    cin.get();
    string path("hotel\\clients\\" + to_string(r) + ".txt");
    fstream fp;
    ofstream fout;
    fp.open(path);
    do{   
        string t;
        vector<string> client;
        if (fp.is_open())
        {
            while (getline(fp, t))
            {
                client.push_back(t);
            }
        }
            fout.open(path,ios::app);
            if (!client.empty())
            {
                cout << "\n Извините..!!!Клиент с таким номером уже есть";
            }
            else
            {
                room_number = r;
                add_customer();
                if (fout.is_open())
                {
                    fout << name << endl;
                    fout << surename << endl;
                    fout << phone << endl;
                    fout << days << endl;
                    fout << cost << endl;
                }
            }
        
            cout << "\n\tНажмите 1, чтобы добавить больше клиентов.";
            cout << "\n\tНажмите 2, чтобы вернуться в главное меню.\n";
            cout << "Ваш выбор: ";
            cin >> option;
            cin.get();
    } while (option == 1);
    fp.close();
    fout.close();
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
        if (room_number = r)
        {
            while (getline(fin, t))
            {
                client.push_back(t);
            }
            cout << "\n Сведения о клиенте";
            cout << "\n ------------------";
            cout << "\n Номер проживания: " << r;
            cout << "\n Имя: " << client[0];
            cout << "\n Фамилия: " << client[1];
            cout << "\n Номер телефона: " << client[2];
            cout << "\n Забронированно дней: " << client[3];
            cout << "\n Общая стоимость: " << client[4];
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
        if (room_number = numFile)
        {
            show_customer(numFile);
            cout << "\nВведите новую информацию" << endl;
            modify_customer_record();
            fout.open(path, ios::in | ios::out);
            if (fout.is_open())
            {
                fout << name << endl;
                fout << surename << endl;
                fout << phone << endl;
                fout << days << endl;
                fout << cost << endl;
            }
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

void Client::display_all_customer()
{
    system("cls");
    int numFile = 1;
    string path("hotel\\clients\\" + to_string(numFile) + ".txt");
    fstream fp;
    fp.open(path, ios::in);
    if (!fp.is_open())
    {
        cout << "ERROR!!! FILE COULD NOT BE OPEN ";
        _getch();
        return;
    }
    else
    {
        cout << "\n\t\t\tСписок проживающих клиентов";
        cout << "\n\t\t\t-------------------------------\n";
        cout << endl;
        cout << "==============================================================================================\n";
        cout << "Клиент|" << setw(5) << "Имя" << setw(20) << "|Фамилия" << setw(30) << "|№ Телефон" << setw(15) << "|Дни" << setw(15) << "|Стоимость|" << endl;
        cout << "==============================================================================================\n";
        report();
    }
    fp.close();
    cout << "\n Нажмите любую клавишу, чтобы продолжить.....!!";
    _getch();
}

void Client::delete_customer()
{
    system("cls");
    display_all_customer();
    int numFile = 0;
    cout << "\n\n\n МЕНЮ УДАЛЕНИЯ";
    cout << "\n\nВыберите Номер Клиента, которого вы хотите удалить: ";
    cin >> numFile;
    if (room_number = numFile)
    {
        cout << "\nВы действительно хотите удалить запись (Y/N): ";
        do {
            char battom;
            battom = _getch();
            if (battom == 'n')
            {
                break;
            }
            else
            {          
                    numFile++;
                    string path("hotel\\clients\\" + to_string(numFile) + ".txt");
                    remove(path.c_str());
                    string newPath("hotel\\clients\\" + to_string(numFile - 1) + ".txt");
                    rename(path.c_str(), newPath.c_str());
                    cout << "\nФайл удален!";
                    break;
            }
        } while (true);
    }
    else
    {
        cout << "\n\n Record Not Found ";
    }
    cout << "\n\n Нажмите любую клавишу, чтобы продолжить....!!";
    _getch();
}
void Room::main_menu()
{
    Client c;
    int change;
    do {
        cout << "\n\n\t\t\t\tГЛАВНОЕ МЕНЮ\n";
        cout << "\t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
        cout << "\t\t\t 1.Посмотреть список номеров " << endl;
        cout << "\t\t\t 2.Меню клиентов \n";
        cout << "\t\t\t 3.Забронировать номер \n";
        cout << "\t\t\t 4.Освободить номер \n";
        cout << "\t\t\t 5.Открыть новый номер в отеле \n";
        cout << "\t\t\t 6.Выход \n";
        cout << "\t\t\t ВАШ ВЫБОР: ";
        cin >> change;
        switch (change)
        {
        case 1:system("cls");
            showInfoRoom();
            break;
        case 2:system("cls");
            c.client_menu();
            break;
        case 3:system("cls");
            bookRoom();
            break;
        case 4:
            break;
        case 5:system("cls");
            saveRoom();
            break;
        case 6: exit(0);
            break;
        default:cout << "\a";
        }

    } while (true);
}

void Client::client_menu()
{
    Room r;
    int option;
    while(true)
    {
        cout << "\n\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
        cout << "\n\t\t1.Добавить клиента";
        cout << "\n\t\t2.Список клиентов";
        cout << "\n\t\t3.Выбрать информацию о клиенте";
        cout << "\n\t\t4.Редактирование";
        cout << "\n\t\t5.Удаление клиента";
        cout << "\n\t\t6.Вернутся в главное меню";
        cout << "\n\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
        cout << "\n\t\tВАШ ВЫБОР: ";
        cin >> option;
        switch (option)
        {
        case 1:save_customer();
            system("cls");
            break;
        case 2:display_all_customer();
            system("cls");
            break;
        case 3:
            display_a_customer();
            break;
        case 4: system("cls");
            modify_customer();
            break;
        case 5: delete_customer();
            system("cls");
            break;
        case 6: system("cls");
            r.main_menu();
            break;
        }
    }

}

void intro()
{
    system("color 07");
    system("cls");
    cout << "\t\t\t\t*\t*";
    cout << "\t\t\t\t**\t**";
    cout << "\t\t\t\t***\t***";
    cout << "\t\t\t\t****\t****";
    cout << "\t\t\t\t*****\t*****";
    cout << "\t\t\t\t******\t******";
    cout << "\t\t\t\t*******\t*******";
    cout << "\t\t\t\t*******\t*******";
    cout << "\t\t\t\t******\t******";
    cout << "\t\t\t\t*****\t*****";
    cout << "\t\t\t\t****\t****";
    cout << "\t\t\t\t***\t***";
    cout << "\t\t\t\t**\t**";
    cout << "\t\t\t\t*\t*";
}

int main()
{
    setlocale(0, "");
    srand(time(NULL));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Room r;
    r.main_menu();
    Client h;
    //intro();
    //h.client_menu();
    return 0;
}