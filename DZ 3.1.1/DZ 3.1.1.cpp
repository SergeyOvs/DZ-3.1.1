#include <iostream>
#include <string>
#include <vector>
#include <optional>
#include <functional>
#include <iomanip>


using namespace std;

    
class Person
{
public:
    string name, surname;
    optional <string>patronymic;

    Person() :name(0), surname(0),  patronymic () {}
    Person(string s,string n,optional<string> p):surname(s),name (n),patronymic(p){}

    friend bool operator< (const Person& p1, const Person& p2);
};

bool operator<= (const Person& p1, const Person& p2)
{
   
    return tie(p1.surname, p1.name, p1.patronymic) <=
           tie(p2.surname, p2.name, p2.patronymic);
}
void print_Person(const string& surname, string& name, string& patronymic)
{
    cout << "Фамилия:" << surname << "Имя:" << name << "Отчество" << patronymic << endl;
}

ostream& operator <<(ostream& os, const Person& user)
{
    os << user.surname ;
    os << user.name  ;
    if (user.patronymic)
        os << "      " << *user.patronymic;
    return os;
}
int main()
{
    setlocale(LC_ALL, "ru");

    Person p1("Иванов  ","Иван  ","Иванович");
    Person p2("Пушкин  ","Александр  ","Сергеевич");
    Person p3("Горький  ", "Максим  ",nullopt);

    cout << boolalpha << (p1 <= p2) << endl;
   
    tuple<string, string, string> tuple1("Толстой  ", "Лев  ", "Николаевич");
    auto tuple2 = make_tuple("Петров  ", "Олег  ", "Иванович");
    
    string n, s, p;
    tie(s, n, p) = tuple1;
    cout << s << n << p << endl;
    tie(s, n, p) = tuple2;
    cout << s << n << p << endl << endl;
   
    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;
  
    
    
}

