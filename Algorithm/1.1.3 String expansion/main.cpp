#include <iostream>
#include <algorithm> 

using namespace std;

string obj;
string tmp;
int p1;
int p2;
int p3;

bool isdig(char a)
{
	return a >= '0' && a <= '9';
}

bool islet(char a)
{
	return a >= 'a' && a <= 'z';
}

void add(char left, char right)
{
	string st;
	
	for (char ch = left + 1; ch < right; ++ch)
	{
		char chtmp = ch;
		
		if (p1 == 2 && islet(chtmp))
		{
			chtmp -= 32;
		}
		else if (p1 == 3)
		{
			chtmp = '*';
		}
		
		for (int i = 0; i < p2; ++i)
		{
			st += chtmp;
		}
	}
	
	if (p3 == 2)
	{
		reverse(st.begin(), st.end());
	}
	
	tmp += st;
}

int main()
{
	cin >> p1 >> p2 >> p3 >> obj;
	int sz = obj.size();
	
	for (int i = 0; i < sz; ++i)
	{
		if (obj[i] != '-' || i == 0 || i == sz - 1)
		{
			tmp += obj[i];
		}
		else
		{
			if ((isdig(obj[i - 1]) && isdig(obj[i + 1]) && obj[i - 1] < obj[i + 1])
			||(islet(obj[i - 1]) && islet(obj[i + 1]) && obj[i - 1] < obj[i + 1]))
			{
			  	add(obj[i - 1], obj[i + 1]);
			}
			else
			{
				tmp += obj[i];
			}
		}
	}
	
	cout << tmp;
	return 0;
}
