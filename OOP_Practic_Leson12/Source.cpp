//ƒана строка символов, содержаща€(){}[] и другие символы.
//ѕроверить есть ли в строке баланс открывающих и закрывающих скобок.

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
	string str{ "(asdf)(asdfs)[dssfe]" };
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

bool stack::IsEmpty()//проверка на то, что список пуст
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
	bool Bal;
	stack st;
	char temp;
	char c1 = '(';
	char c2 = ')';

	char c3 = '{';
	char c4 = '}';

	char c5 = '[';
	char c6 = ']';
	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == c1 || str.at(i) == c3 || str.at(i) == c5)
		{
			st.Add(str.at(i));
		}
		else if (str.at(i) == c2 || str.at(i) == c4 || str.at(i) == c6)
		{
			if (st.IsEmpty()) Bal = false;
			else
			{
				temp = st.Extract();
				if (
					temp == c1 && str.at(i) == c2 ||
					temp == c3 && str.at(i) == c4 ||
					temp == c5 && str.at(i) == c6
					)Bal = true;
				else
				{
					Bal = false;
					break;
				}
			}
		}
	}
	if (Bal && st.IsEmpty()) cout << "Good" << endl;//проверка на пустоту стека. ≈сли он не пуст, то в строке были не закрытые скобки
	else cout << "Bad" << endl;
}
