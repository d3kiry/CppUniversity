#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;
struct CallRecord {
    char date[16];       
    char fio[32];
    char city[32];
    char phone[16];
    int duration;
    CallRecord(const char* date, const char* fio, const char* city, const char* phone, int duration) {
        strcpy(this->date, date);
        strcpy(this->fio, fio);
        strcpy(this->city, city);
        strcpy(this->phone, phone);
        this->duration = duration;
    }
    CallRecord() {}
};
void createDB(vector<CallRecord> &records, const string &fileName) {
    records.clear();
    ofstream file(fileName, ios::binary);
    file.close();
    cout << "Новая база данных создана." << endl;
}
void viewDB(const vector<CallRecord> &records) {
    if (records.empty()) {
        cout << "База данных пуста." << endl;
        return;
    }
    for (int i = 0; i < records.size(); i++) {
        cout << "Запись номер "<< i <<endl << "Дата: " << records[i].date << endl
             << "ФИО: " << records[i].fio << endl
             << "Город: " << records[i].city << endl
             << "Телефон: " << records[i].phone << endl
             << "Продолжительность: " << records[i].duration << " минут" << endl;
    }
}
void addRecords(vector<CallRecord> &records) {
    int count;
    cout << "Введите количество добавляемых записей: ";
    while (!(cin >> count) || count <= 0) {
        cout << "Пожалуйста, введите положительное число для количества записей: \n";
    }
    for (int i = 0; i < count; ++i) {
        CallRecord record;
        cout << "Введите дату (ДД.ММ.ГГГГ): ";cin >> record.date;cin.ignore();
        cout << "Введите фамилию и инициалы сотрудника: ";cin.getline(record.fio, sizeof(record.fio));
        cout << "Введите город: ";cin.getline(record.city, sizeof(record.city));
        cout << "Введите номер телефона: ";cin.getline(record.phone, sizeof(record.phone));
        cout << "Введите продолжительность разговора (в минутах): ";
        while (!(cin >> record.duration) || record.duration <= 0) { 
            cout << "Пожалуйста, введите положительное число для продолжительности: \n";
        }
        records.push_back(record);
    }
    cout << "Записи добавлены." << endl;
}
void writeToFile(string fileName, vector<CallRecord> &records) {
    ofstream F(fileName, ios::binary);
    for (CallRecord& v : records)
        F.write((char*)&v, sizeof(CallRecord));
    F.close();
    cout << "База данных сохранена в файл"<<endl;
}
void readFromFile(const string &fileName, vector<CallRecord> &records) {
    ifstream file(fileName, ios::binary);
    if (!file) {
        cout << "Файл не найден. Создайте новую базу данных." << endl;
        return;
    }
    records.clear();
    CallRecord record;
    while (file.read((char *)&record, sizeof(CallRecord))) {
        records.push_back(record);
    }
    file.close();
    cout << "Данные загружены из файла." << endl;
}
void editRecord(vector<CallRecord> &records) {
    if (records.empty()) {
        cout << "База данных пуста." << endl;
        return;
    }
    int index;
    cout << "Введите номер записи для редактирования (1-" << records.size() << "): ";cin >> index;
    if (index < 1 || index > records.size()) {
        cout << "Неверный номер записи." << endl;
        return;
    }
    CallRecord &record = records[index - 1];
    cout << "Текущие данные: " << record.date << " " << record.fio << " " << record.city<< " " << record.phone << " " << record.duration << " мин." << endl;
    cout << "Введите новую дату (ДД.ММ.ГГГГ): ";cin >> record.date;
    cout << "Введите фамилию и инициалы сотрудника: ";cin.getline(record.fio, sizeof(record.fio));
    cout << "Введите город: ";cin.getline(record.city, sizeof(record.city));
    cout << "Введите номер телефона: ";cin.getline(record.phone, sizeof(record.phone));
    cout << "Введите продолжительность разговора (в минутах): ";cin >> record.duration;
    cout << "Запись обновлена." << endl;
}
void generateReport(const vector<CallRecord> &records, const string &outputFile, const string &month) {
    ofstream report(outputFile);
    int longestDuration = 0;
    CallRecord longestCall;
    report << "Отчет по междугородним переговорам за месяц: " << month << endl;
    report << "Дата\t\tФИО\tГород\tТелефон\tДлительность" << endl;
    for (const CallRecord& record : records) {
        if (strncmp(record.date + 3, month.c_str(), 2) == 0) {
            report << record.date << "  "<< record.fio << "  "<< record.city << "  "<< record.phone << "  "<< record.duration << " мин." << endl;
            if (record.duration > longestDuration) {
                longestDuration = record.duration;
                longestCall = record;
            }
        }
    }
    report << "\nСамый продолжительный разговор:\n";
    report << "Дата: " << longestCall.date << "\n"<< "ФИО: " << longestCall.fio << "\n"<< "Город: " << longestCall.city << "\n"<< "Телефон: " << longestCall.phone << "\n"<< "Длительность: " << longestCall.duration << " мин." << endl;
    report.close();
    cout << "Отчет сохранен в файл: " << outputFile << endl;
}
int main() {
    string fileName = "calls.dat";
    vector<CallRecord> records;
    int choice;
    do {
        cout << "\nМеню:\n";
        cout << "1. Создать новую базу данных\n";
        cout << "2. Просмотреть базу данных\n";
        cout << "3. Добавить записи\n";
        cout << "4. Изменить запись\n";
        cout << "5. Сохранить базу данных в файл\n";
        cout << "6. Загрузить базу данных из файла\n";
        cout << "7. Сформировать отчет\n";
        cout << "0. Выход\n";
        cout << "Ваш выбор: ";
        cin >> choice;
        switch (choice) {
            case 1:
                createDB(records, fileName);
                break;
            case 2:
                viewDB(records);
                break;
            case 3:
                addRecords(records);
                break;
            case 4:
                editRecord(records);
                break;
            case 5:
                writeToFile(fileName, records);
                break;
            case 6:
                readFromFile(fileName, records);
                break;
            case 7: {
                string month, outputFile;
                cout << "Введите месяц для отчета (ММ): ";cin >> month;
                cout << "Введите имя файла для сохранения отчета: ";cin >> outputFile;
                generateReport(records, outputFile, month);
                break;
            }
            case 0:
                cout << "Выход из программы." << endl;
                break;
            default:
                cout << "Неверный выбор. Попробуйте снова." << endl;
        }
    } while (choice != 0);
    return 0;
}
