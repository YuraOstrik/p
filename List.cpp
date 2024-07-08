#include <iostream>
using namespace std;


struct Element
{
    // Данные
    char data;
    // Адрес следующего элемента списка
    Element* Next;
};

// Односвязный список
class List
{
    // Адрес головного элемента списка
    Element* Head;
    // Адрес головного элемента списка
    Element* Tail;
    // Количество элементов списка
    int Count;

public:
    // Конструктор
    List();
    // Деструктор
    ~List();

    // Добавление элемента в список
    // (Новый элемент становится последним)
    void Add(char data);

    // Удаление элемента списка
    // (Удаляется головной элемент)
    void Del();
    // Удаление всего списка
    void DelAll();

    // Распечатка содержимого списка
    // (Распечатка начинается с головного элемента)
    void Print();

    // Получение количества элементов, находящихся в списке
    int GetCount();

    void AddInd(char c, int num)
    {
        int i = 1;
        Element* temp = Head;
        while (i < num) {
            temp = temp->Next;
            i++;
        }

        Element* nElem = new Element;

        nElem->data = c;
        nElem->Next = temp->Next;

        temp->Next = nElem;
    }

    void DelInd(int number)
    {
        Element* prevdel = Head;
        Element* del;
        int i = 1;
        while (i < number - 1)
        {
            prevdel = prevdel->Next;
            i++;
        }
        del = prevdel->Next;
        prevdel->Next = del->Next;
        delete del;

    }
    void Find(char m)
    {
        Element* ball = Head;
        int i = 1;
        bool found = false;

        while (ball != nullptr) {
            if (ball->data == m) {
                cout << "Your letter " << i << endl;
                found = true;
            }
            ball = ball->Next;
            i++;
        }

        if (!found)
        {
            cout << "Null" << endl;
        }
    }

};

List::List()
{
    // Изначально список пуст
    Head = Tail = NULL;
    Count = 0;
}

List::~List()
{
    // Вызов функции удаления
    DelAll();
}

int List::GetCount()
{
    // Возвращаем количество элементов
    return Count;
}

void List::Add(char data)
{
    // создание нового элемента
    Element* temp = new Element;

    // заполнение данными
    temp->data = data;
    // следующий элемент отсутствует
    temp->Next = NULL;
    // новый элемент становится последним элементом списка
    // если он не первый добавленный
    if (Head != NULL) {
        Tail->Next = temp;
        Tail = temp;
    }
    // новый элемент становится единственным
    // если он первый добавленный
    else {
        Head = Tail = temp;
    }
}

void List::Del()
{
    // запоминаем адрес головного элемента
    Element* temp = Head;
    // перебрасываем голову на следующий элемент
    Head = Head->Next;
    // удаляем бывший головной элемент
    delete temp;
}

void List::DelAll()
{
    // Пока еще есть элементы
    while (Head != 0)
        // Удаляем элементы по одному
        Del();
}

void List::Print()
{
    // запоминаем адрес головного элемента
    Element* temp = Head;
    // Пока еще есть элементы
    while (temp != 0)
    {
        // Выводим данные
        cout << temp->data << " ";
        // Переходим на следующий элемент
        temp = temp->Next;
    }

    cout << "\n\n";
}

// Тестовый пример
void main()
{
    // Создаем объект класса List
    List lst;




    lst.Add('H');
    lst.Add('e');
    lst.Add('l');
    lst.Add('p');
    lst.Add('o');
    lst.Add('o');
    
    lst.Print();
    lst.Find('o');
    //// Тестовая строка
    //char s[] = "Hello, World !!!\n";
    //// Выводим строку
    //cout << s << "\n\n";
    //// Определяем длину строки
    //int len = strlen(s);
    //// Загоняем строку в список
    //for (int i = 0; i < len; i++)
    //    lst.Add(s[i]);
    //// Распечатываем содержимое списка
    //lst.Print();
    //// Удаляем три элемента списка
    //lst.Del();
    //lst.Del();
    //lst.Del();
    ////Распечатываем содержимое списка
    //lst.Print();
}



































