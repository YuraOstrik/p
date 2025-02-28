#include <iostream>
using namespace std;


struct Element
{
    // ������
    char data;
    // ����� ���������� �������� ������
    Element* Next;
};

// ����������� ������
class List
{
    // ����� ��������� �������� ������
    Element* Head;
    // ����� ��������� �������� ������
    Element* Tail;
    // ���������� ��������� ������
    int Count;

public:
    // �����������
    List();
    // ����������
    ~List();

    // ���������� �������� � ������
    // (����� ������� ���������� ���������)
    void Add(char data);

    // �������� �������� ������
    // (��������� �������� �������)
    void Del();
    // �������� ����� ������
    void DelAll();

    // ���������� ����������� ������
    // (���������� ���������� � ��������� ��������)
    void Print();

    // ��������� ���������� ���������, ����������� � ������
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
    // ���������� ������ ����
    Head = Tail = NULL;
    Count = 0;
}

List::~List()
{
    // ����� ������� ��������
    DelAll();
}

int List::GetCount()
{
    // ���������� ���������� ���������
    return Count;
}

void List::Add(char data)
{
    // �������� ������ ��������
    Element* temp = new Element;

    // ���������� �������
    temp->data = data;
    // ��������� ������� �����������
    temp->Next = NULL;
    // ����� ������� ���������� ��������� ��������� ������
    // ���� �� �� ������ �����������
    if (Head != NULL) {
        Tail->Next = temp;
        Tail = temp;
    }
    // ����� ������� ���������� ������������
    // ���� �� ������ �����������
    else {
        Head = Tail = temp;
    }
}

void List::Del()
{
    // ���������� ����� ��������� ��������
    Element* temp = Head;
    // ������������� ������ �� ��������� �������
    Head = Head->Next;
    // ������� ������ �������� �������
    delete temp;
}

void List::DelAll()
{
    // ���� ��� ���� ��������
    while (Head != 0)
        // ������� �������� �� ������
        Del();
}

void List::Print()
{
    // ���������� ����� ��������� ��������
    Element* temp = Head;
    // ���� ��� ���� ��������
    while (temp != 0)
    {
        // ������� ������
        cout << temp->data << " ";
        // ��������� �� ��������� �������
        temp = temp->Next;
    }

    cout << "\n\n";
}

// �������� ������
void main()
{
    // ������� ������ ������ List
    List lst;




    lst.Add('H');
    lst.Add('e');
    lst.Add('l');
    lst.Add('p');
    lst.Add('o');
    lst.Add('o');
    
    lst.Print();
    lst.Find('o');
    //// �������� ������
    //char s[] = "Hello, World !!!\n";
    //// ������� ������
    //cout << s << "\n\n";
    //// ���������� ����� ������
    //int len = strlen(s);
    //// �������� ������ � ������
    //for (int i = 0; i < len; i++)
    //    lst.Add(s[i]);
    //// ������������� ���������� ������
    //lst.Print();
    //// ������� ��� �������� ������
    //lst.Del();
    //lst.Del();
    //lst.Del();
    ////������������� ���������� ������
    //lst.Print();
}



































