#include <bits/stdc++.h>
#include <fstream>
using namespace std;
vector<int *> collect;
void DP(int a[12][12], int i, int j, bool visited[100][100], int row, int collumn)
{

	collect.push_back((*(a + i) + j));
	visited[i][j] = true;

	{
		if (j - 1 >= 0 && a[i][j - 1] == 0 && !visited[i][j - 1])
			DP(a, i, j - 1, visited, row, collumn);
		if (j + 1 < collumn && a[i][j + 1] == 0 && !visited[i][j + 1])
			DP(a, i, j + 1, visited, row, collumn);
		if (i + 1 < row && a[i + 1][j] == 0 && !visited[i + 1][j])
			DP(a, i + 1, j, visited, row, collumn);
	}
}
void DP1(int a[12][12], int i, int j, bool visited[100][100], int row, int collumn)
{
	collect.push_back(&a[i][j]);
	visited[i][j] = true;

	{
		if (j - 1 >= 0 && a[i][j - 1] == 0 && !visited[i][j - 1])
			DP1(a, i, j - 1, visited, row, collumn);
		if (j + 1 < collumn && a[i][j + 1] == 0 && !visited[i][j + 1])
			DP1(a, i, j + 1, visited, row, collumn);
		if (i - 1 > row && a[i - 1][j] == 0 && !visited[i - 1][j])
			DP1(a, i - 1, j, visited, row, collumn);
	}
}
void out(int a[12][12], int row, int collumn, int n, vector<int *> collect, int &count)
{
	int dem = 0;
	fstream f;
	f.open("./suggest_sheets/data_suggest.txt");
	f.seekp(0, ios_base::end);
	for (int i = 0; i < collect.size(); i++)
	{
		if (i + n <= collect.size())
		{
			count++;
			dem++;
			if (count > 3)
				break;
			for (int s = 0; s < collect.size(); s++)
			{
				*collect[s] = 0;
			}
			for (int j = 0; j < n; j++)
			{
				*collect[i + j] = 3;
			}

			f << "goi y " << count << endl;
			for (int k = 0; k < row; k++)
			{
				for (int j1 = 0; j1 < collumn; j1++)
				{
					if (j1 != collumn - 1)
						f << a[k][j1] << " ";
					else
						f << a[k][j1] << " " << endl;
				}
			}
		}
	}
	f.close();
}
void suggest_sheets(int l)
{
	fstream os;
	os.open("./suggest_sheets/data_film_sheet.txt");
	if (!os)
	{
		cerr << "error:file not opened.222" << endl;
	}
	string ch;
	getline(os, ch);

	int collumn = 0;
	while (getline(os, ch))
	{
		collumn = ch.size() / 2 + 1;

		break;
	}
	os.seekg(0, ios::beg);

	int count = 0;
	vector<int> phantu;
	os >> ch;
	char c;
	while (os >> c)
	{

		if (isdigit(c))
		{
			count++;
			phantu.push_back(c - 48);
			if (count == 120)
				break;
		}
	}
	int row, dem = 0;
	row = (count) / collumn;
	int a[12][12], cot = 0, dong = 0;
	for (int i = 0; i < phantu.size(); i++)
	{
		a[dong][cot] = phantu[i];
		cot++;
		if (cot == collumn)
		{
			dong++;
			cot = 0;
		}
	}
	cout << row / 2 << endl;
	bool visited[100][100];
	for (int i = 0; i < row; i++)
		memset(visited + i, false, sizeof(visited + i));

	count = 0;

	for (int i = (row - 1) / 2; i > 0; i--)
	{
		for (int j = 0; j < collumn; j++)
		{
			if (a[i][j] != 1 && visited[i][j] == false)
				DP1(a, i, j, visited, i - 2, collumn);
			if (collect.size() >= l)
			{
				for (int k = 0; k < collect.size(); k++)
					*collect[k] = 2;
			}
			else
				collect.clear();

			if (!collect.empty())
			{
				dem++;

				cout << endl;
				if (dem == 1)

					out(a, row, collumn, l, collect, count);
				for (int k = 0; k < collect.size(); k++)
					*collect[k] = 0;
				memset(visited + i - 1, false, sizeof(visited + i - 1));
				collect.clear();
			}
			if (count == 3)
			{
				break;
			}
		}
	}
	if (count < 3)
	{
		for (int i = 0; i < row; i++)
			memset(visited + i, false, sizeof(visited + i));
		for (int i = (row + 1) / 2; i < row - 1; i++)
		{
			for (int j = 0; j < collumn; j++)
			{
				if (a[i][j] != 1 && visited[i][j] == false)
					DP(a, i, j, visited, i + 2, collumn);
				if (collect.size() >= l)
				{
					for (int k = 0; k < collect.size(); k++)
						*collect[k] = 2;
				}
				else
					collect.clear();

				if (!collect.empty())
				{
					dem++;
					cout << endl;
					out(a, row, collumn, l, collect, count);
					for (int k = 0; k < collect.size(); k++)
						*collect[k] = 0;
					memset(visited + i + 1, false, sizeof(visited + i + 1));
					collect.clear();
				}
			}
			if (count == 3)
			{
				break;
			}
		}
	}
	os.close();
}