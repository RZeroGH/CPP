#include <iostream>

using namespace std;

int main()
{
	int n; cin >> n;
	int dx[] = { 0, 1, 0, -1 };
	int dy[] = { 1, 0, -1, 0 };
	int count = 1;
	int x = 1;
	int y = 1;
	int dim[10][10] = { 0 };
	int vec = 0;
	
	while(count <= n * n)
	{
		dim[x][y] = count++;
		
		int a = x + dx[vec];
		int b = y + dy[vec]; 
		
		if (a > n || a == 0 || b > n || b == 0 || dim[a][b] != 0)
		{
			vec = (vec + 1) % 4;
			a = x + dx[vec];
			b = y + dy[vec]; 
		}
		
		x = a;
		y = b;
	}
	
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			printf("%3d", dim[i][j]);
		}
		cout << endl;
	}
	return 0;
}
