//���� ������ ��������, ����������(){}[] � ������ �������.
//��������� ���� �� � ������ ������ ����������� � ����������� ������.
// ���� �� ������� ����������� ������ �� ���������� ������� � ����
// 
// ������� ��������, ���� ��������� ������� ����� ����� ����������� �������, � ���������� ��������� ����� ������???
// ����� ���������, ����� ������������� ������ � ����, ����� ������ ������ ��� ����������� ������???
//

#include <iostream>
#include <cstring>
using namespace std;

struct node
{
	char c;
	node* next;
};

class stack
{
private:
	node* top;
public:
	stack(): top{nullptr}{}
	~stack();
	bool IsEmpty();
	int GetCount();
	void Add(char symb);
	char Extract();
	void Print();
};

void Balance(string str);

int main()
{
	string str{ "(asdf){asdfs}[dssfe]" };
	Balance(str);

	return 0;
}

stack::~stack()
{
	while (top != nullptr)
	{
		node* work = top;
		top = top->next;
		delete work;
	}
}

bool stack::IsEmpty()//�������� �� ��, ��� ������ ����
{
	return top == nullptr;
}

int stack::GetCount()
{
	int count{ 0 };
	node* work = top;
	while (work != nullptr)
	{
		count++;
		work = work->next;
	}

	return count;
}

void stack::Add(char symb)
{
	node* work = new node;
	work->next = top;
	top = work;
	work->c = symb;
}

char stack::Extract()
{
	if (top != nullptr)
	{
		node* work = top;
		char symb = work->c;
		top = top->next;
		delete work;
		return symb;
	}
	return -1;
}

void stack::Print()
{
	node* work{ top };
	while (work != nullptr)
	{
		cout << work->c << " ";
		work = work->next;
	}cout << endl;
}

void Balance(string str)
{
	bool Bal = false;
	stack st;
	char c1 = '(';
	char c2 = ')';

	char c3 = '{';
	char c4 = '}';

	char c5 = '[';
	char c6 = ']';
	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == c1) 
		{
			st.Add(c1);
		}
		else if (str.at(i) == c3)
		{
			st.Add(c3);
		}
		else if (str.at(i) == c5)
		{
			st.Add(c5);
		}
	}
	//�������� � ���� ��� ����������� ������
	//������ ����� ��������� ��������� ���� ������ ����� ����� �������� ����������� ������
	//�������� ������ �� ������ ���������� �� �������� � ������ ����������� ������
	//����({[[{( �����)}]]}) - ���� ��� ��������� - ���
	// � ���� {[()[])]} - {[([
	//���� �� ����� ), �� ����������� ������ ���� ( - ����� ������ �� ���, ���� ��� ���������� ������ �� ����

	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == c2)
		{
			if (st.Extract() == c1)
				Bal = true;
			else Bal = false;
		}
		else if (str.at(i) == c4)
		{
			if (st.Extract() == c3)
				Bal = true;
			else Bal = false;
		}
		else if (str.at(i) == c6)
		{
			if (st.Extract() == c5)
				Bal = true;
			else Bal = false;
		}
	}
	if (Bal) cout << "Good" << endl;
	else cout << "Bad" << endl;
}
