#include <iostream>
#include <Windows.h>
#include <ctime>

using namespace std;

template <typename T, typename T1, typename T2, typename T3, typename T4>
void create(T* a, const T1 n, const T2 i, const T3 HIGH, const T4 LOW)
{
	a[i] = LOW + rand() % (HIGH - LOW + 1);
	if (i < n - 1)
		create(a, n, i + 1, HIGH, LOW);
}
template <typename T, typename T1, typename T2>
void print(T* a, const T1 n, const T2 i)
{
	cout << a[i] << " ";
	if (i < n - 1)
		print(a, n, i + 1);
}
template <typename T, typename T1, typename T2, typename T3>
T find_sum(T* a, const T1 n, const T2 i, T3& sum)

{

	if (a[i] > 0) {

		if (i < n - 1)
			sum += a[i];
		find_sum(a, n, i + 1, sum);
	}

	else
		return sum;
}

int main()
{
	srand(time(NULL));

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const int n = 10;
	int S[n];
	const int HIGH = 37;
	const int LOW = 1;
	const int i = 0;
	cout << "S[10] = { ";
	create(S, n, i, HIGH, LOW);
	print(S, n, i);
	cout << "}" << endl;
	int sum = S[0];
	cout << "Сума додатних чисел = " << find_sum(S, n, i, sum) << endl;
	return 0;
}
