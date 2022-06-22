#include <iostream>
#include <fstream> 
#include <string>
#include <windows.h>
#include <vector>
#include <cstdio>
#include <iomanip>
#include <conio.h>
using namespace std;
struct Booking
{
    int room_num;
    string data;
    int num_days;
    int sum_pay;
};
struct Room
{
    int room_no;
    string category;
    int local_no;
};
struct Otel
{
    string name_otel;
    string address_hotel;
    int r_no;
    string phone_otel;
    unsigned int cost_no;
};
struct Client
{
    int room_number;
    string name;
    string address;
    string phone;
    int days;
    float cost;
   // Hotel() {};
 /*   Hotel(int room_number,string name, string address, string phone, int days, float cost)
    {
        this->room_number = room_number;
        this->name = name;
        this->address = address;
        this->phone = phone;
        this->days = days;
        this->cost = cost;
    }*/
    void showInfo(int& N)
    {
        cout << N - 1 <<"\t";
        cout << setw(19) << left << this->name;
        cout << setw(26) << left << this->address;
        cout << setw(22) << left << this->phone;
        cout << setw(8) << left << this->days;
        cout << setw(5) << left << this->cost << endl;
    }
    void show_customer(int)
    {
        system("cls");
        string path("hotel\\" + to_string(room_number) + ".txt");
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
                cout << "\n N номера: " << room_number;
                cout << "\n Имя: " << client[0];
                cout << "\n Адрес: " << client[1];
                cout << "\n Номер телефона: " << client[2];
                cout << "\n Забронировано дней: " << client[3];
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
        cout << " Адрес: ";
        getline(cin, address);
        cout << " Номер телефона: ";
        getline(cin, phone);
        cout << " Количество дней для проживания: ";
        cin >> days;
        cost = days * 900;//900 стоимость номера в день
        cout << "\n Номер забронирован...!!!"<<endl;
    }
    void modify_customer_record()
    {
        cout << "\nN Номер : " << room_number;
        cout << "\n ----------------------" << endl;
        cout << "Новое Имя: ";
        getline(cin, name);
        cout << "Новый Адрес: ";
        getline(cin, address);
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
            path = path + ("hotel\\" + to_string(number) + ".txt");
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
         h.address = text[1];
         h.phone= text[2];
         h.days = stod(text[3]);
         h.cost = stod(text[4]);
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
    cout << "\n\nВыберите номер для заселения: ";
    cin >> r;
    cin.get();
    string path("hotel\\" + to_string(r) + ".txt");
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
                cout << "\n Извините..!!!Номер уже забронирован";
            }
            else
            {
                room_number = r;
                add_customer();
                if (fout.is_open())
                {
                    fout << name << endl;
                    fout << address << endl;
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
    string path("hotel\\" + to_string(r) + ".txt");
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
            cout << "\n Адрес: " << client[1];
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
    string path("hotel\\" + to_string(numFile) + ".txt");
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
                fout << address << endl;
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
    string path("hotel\\" + to_string(numFile) + ".txt");
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
        cout << "Клиент|" << setw(5) << "Имя" << setw(20) << "|Адрес" << setw(30) << "|№ Телефон" << setw(15) << "|Дни" << setw(15) << "|Стоимость|" << endl;
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
                string path("hotel\\" + to_string(numFile) + ".txt");
                remove(path.c_str());
                string newPath("hotel\\" + to_string(numFile - 1) + ".txt");
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

void Client::client_menu()
{
    int option;
    while(true)
    {
        cout << "\n\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
        cout << "\n\t\t1.Добавить клиента";
        cout << "\n\t\t2.Иформация о клиентах";
        cout << "\n\t\t3.ИНФОРМАЦИЯ О КЛИЕНТЕ";
        cout << "\n\t\t4.РЕДАКТИРОВАНИЕ";
        cout << "\n\t\t5.УДАЛЕНИЕ";
        cout << "\n\t\t6.ВЫХОД";
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
        case 6: exit(0);
            break;
        default:cout << "\a";
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
    Client h;
    intro();
    h.client_menu();
    return 0;
}