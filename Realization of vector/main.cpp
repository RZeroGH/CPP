#include <iostream>
#include "vector.h"
using namespace std;

int main()
{
	I::vector<int> tmp;
	tmp.pushback(1);
	tmp.pushback(2);
	tmp.pushback(3);
	tmp.pushback(4);
	//tmp.pushback(5);

	display_int(tmp);

	tmp.insert(tmp.begin() + 2, 30);
	display_int(tmp);

	auto pos = find(tmp.begin(), tmp.end(), 4);
	tmp.insert(pos, 200);
	display_int(tmp);

	return 0;
}