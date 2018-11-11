#include <iostream>
//#include <Windows.h>

//#define CHECK_TIME_START __int64 freq, start, end; if(QueryPerformanceFrequency((_LARGE_INTEGER*)&freq)){QueryPerformanceCounter((_LARGE_INTEGER*)&start);
//// a는 float type milli second이고 b가 FALSE일때는 에러입니다
//#define CHECK_TIME_END(a,b) QueryPerformanceCounter((_LARGE_INTEGER*)&end); a=(float)((double)(end - start)/freq*1000); b=TRUE; } else b=FALSE;

using namespace std;

int cnt = 0; //result 

void print(char* arr, int map_len, int p)
{
	cout << "----------------------------------------------------------------" << endl;
	for (int i = 0; i < map_len; i++)
	{
		printf("%c ", arr[i]);
		if (i% p == p - 1)
		{
			cout << endl;
		}
	}
	cout << "----------------------------------------------------------------" << endl;
}

bool check(char* arr, int p, int q, int map_len, int index)
{
	bool check_flag = false;

	bool a = true; //* *
				   //*

	bool b = true; //* *
				   //  *

	bool c = true; //  *
				   //* *

	bool d = true; //*
				   //* *

	bool A = true;
	bool B = true;
	bool C = true;
	bool D = true;

	char* prior_arr = NULL;//이전의 배열
	prior_arr = new char[map_len];

	//print(arr, map_len, p);

	for (int i = index; i < map_len; i++)
	{
		if (arr[i] == '*')
		{
			if (
				a &&
				arr[i + 1] == '*' &&
				arr[i + p] == '*' &&
				//(i % p != p - 1) &&
				((i + 1) % p != 0) &&
				i + p < map_len
				)
			{
				//back up arr
				for (int j = 0; j < map_len; j++)
				{
					prior_arr[j] = arr[j];
				}

				//substitution
				arr[i] = 'X';
				arr[i + 1] = 'X';
				arr[i + p] = 'X';

				//recursion(arr, p, q, map_len, i );
				a = check(arr, p, q, map_len, i);

				//recovery arr
				for (int j = 0; j < map_len; j++)
				{
					arr[j] = prior_arr[j];
				}
			}
			else
			{
				A = true;
			}

			if (
				b &&
				arr[i + 1] == '*' &&
				arr[i + p + 1] == '*' &&
				//(i % p != p - 1) &&
				((i + 1) % p != 0) &&
				((i + p + 1) % p != 0) &&
				i + p + 1 < map_len
				)
			{
				//back up arr
				for (int j = 0; j < map_len; j++)
				{
					prior_arr[j] = arr[j];
				}

				//substitution
				arr[i] = 'X';
				arr[i + 1] = 'X';
				arr[i + p + 1] = 'X';

				//recursion(arr, p, q, map_len, i );
				b = check(arr, p, q, map_len, i);

				//recovery arr
				for (int j = 0; j < map_len; j++)
				{
					arr[j] = prior_arr[j];
				}
			}
			else
			{
				B = true;
			}

			if (
				c &&
				arr[i + p] == '*' &&
				arr[i + p - 1] == '*' &&
				//(i % p != 0) &&
				((i + p - 1) % p != p - 1) &&
				(i + p < map_len)
				)
			{
				//back up arr
				for (int j = 0; j < map_len; j++)
				{
					prior_arr[j] = arr[j];
				}

				//substitution
				arr[i] = 'X';
				arr[i + p] = 'X';
				arr[i + p - 1] = 'X';

				//recursion(arr, p, q, map_len, i );
				c = check(arr, p, q, map_len, i);

				//recovery arr
				for (int j = 0; j < map_len; j++)
				{
					arr[j] = prior_arr[j];
				}
			}
			else
			{
				C = true;
			}

			if (
				d &&
				arr[i + p] == '*' &&
				arr[i + p + 1] == '*' &&
				//(i % p != p - 1) &&
				((i + p + 1) % p != 0) &&
				(i + p + 1 < map_len)
				)
			{
				//back up arr
				for (int j = 0; j < map_len; j++)
				{
					prior_arr[j] = arr[j];
				}

				//substitution
				arr[i] = 'X';
				arr[i + p] = 'X';
				arr[i + p + 1] = 'X';

				//recursion(arr, p, q, map_len, i );
				d = check(arr, p, q, map_len, i);

				//recovery arr
				for (int j = 0; j < map_len; j++)
				{
					arr[j] = prior_arr[j];
				}
			}
			else
			{
				D = true;;
			}

			if (
				A &&
				B &&
				C &&
				D
				)
			{
				return false;
			}

		}
	}

	//check
	for (int i = 0; i < map_len; i++)
	{
		if (arr[i] == '*')
		{
			check_flag = false;
			break;
		}
		else
		{
			check_flag = true;
		}
	}

	if (check_flag)
	{
		cnt++;
		//cout << "cnt++ : " << cnt << endl;
		return false;
	}
	else
	{
		return false;
	}
}

int main()
{
//    float Time;
	
	char *map = NULL;
	int p, q = 0;
	int map_len = 0;
	//char map_input;

	cout << "col : "; cin >> p; cout << endl;
	cout << "row : "; cin >> q; cout << endl;

	map = new char[p*q];
	map_len = p*q; // map's length

	//입력
	for (int i = 0; i < map_len; i++)
	{
	cin >> map[i];
	}
	
	//test
	/*
	char map[] = 
	{
		'#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
		'#', '*', '*', '*', '*', '*', '*', '*', '*', '#',
		'#', '*', '*', '*', '*', '*', '*', '*', '*', '#',
		'#', '*', '*', '*', '*', '*', '*', '*', '*', '#',
		'#', '*', '*', '*', '*', '*', '*', '*', '*', '#',
		'#', '*', '*', '*', '*', '*', '*', '*', '*', '#',
		'#', '*', '*', '*', '*', '*', '*', '*', '*', '#',
		'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'
	};
	
	int map_len = 80;
	int p = 10;
	int q = 8;
	*/
	/*char map[] =
	{
		'*', '*', '#', '*', '*',
		'*', '*', '#', '*', '*',
		'*', '*', '#', '*', '*'
	};
	int map_len = 15;
	int p = 5;
	int q = 3;
	*/
	/*
	char map[] = 
	{
		'#', '#', '#', '#', '#', '#', '#', '#',
		'#', '*', '*', '*', '*', '*', '*', '#',
		'#', '*', '*', '*', '*', '*', '*', '#',
		'#', '*', '*', '*', '*', '*', '*', '#',
		'#', '*', '*', '*', '*', '*', '*', '#',
		'#', '*', '*', '*', '*', '*', '*', '#',
		'#', '*', '*', '*', '*', '*', '*', '#',
		'#', '#', '#', '#', '#', '#', '#', '#',

	}; // 162
	int map_len = 64;
	int p = 8;
	int q = 8;
	*/
//    CHECK_TIME_START;
	check(map, p, q, map_len, 0);
//    CHECK_TIME_END(Time, err);

	cout << cnt << endl;
//    cout << Time << " ms" << endl;
    
    return 0;
}
