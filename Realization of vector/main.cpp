#include <iostream>
#include "vector.h"
using namespace std;

int main()
{
	myContainer::vector<int> tmp;
	tmp.push_back(1);
	tmp.push_back(2);
	tmp.push_back(3);
	tmp.push_back(4);
	//tmp.push_back(5);

	display_vector(tmp);

	tmp.insert(tmp.begin() + 2, 30);
	display_vector(tmp);

	auto pos = find(tmp.begin(), tmp.end(), 4);
	tmp.insert(pos, 200);
	//After insertion, the value in the position will not be origin(iterator fails)
	display_vector(tmp);

	//remove all the odd numbers(iterator fails)
	//auto it = tmp.begin();
	//while (it != tmp.end())
	//{
	//	if (*it % 2 == 0)
	//	{
	//		tmp.erase(it);
	//		display_vector(tmp);
	//	}
	//	++it;
	//}

	pos = find(tmp.begin(), tmp.end(), 4);
	tmp.erase(pos);
	display_Container(tmp);

	int i = int();
	int j = int(1);
	double k(2);

	myContainer::vector<int> ins(tmp);

	return 0;
}