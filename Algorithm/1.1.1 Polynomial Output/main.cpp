#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main() 
{
	int n ; cin >> n;
	for (int i = n; i >= 0; --i)
	{
		int num; cin >> num;
		int abvalue = num;
		if (num < 0) abvalue = -num;
		
		if (num == 0) continue;
		
		if (num < 0) cout << '-';
		else if (i != n) cout << '+'; 
		
		if (abvalue != 1|| (abvalue == 1 && i == 0)) cout << abvalue;
		
		if (i > 1) cout << "x^" << i;
		else if (i == 1) cout << 'x'; 
	}
	return 0;
}
