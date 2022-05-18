#include <iostream>
using namespace std;

int main()
{
	int m, n;

	cout << "Number of bits in divisor: ";
	cin >> m;
	cout << "Bits of divisor: ";

	int divisor[m];
	for (int i = 0; i < m; i++) cin >> divisor[i];

	cout << "Number of bits in dividend: ";
	cin >> n;
	cout << "Bits of dividend: ";

	int dividend[m + n], original[m + n];
	for (int i = 0; i < m; i++)
	{
		cin >> dividend[i];
		original[i] = dividend[i];
	}
	for (int i = m; i < m + n; i++)
	{
		dividend[i] = 0;
		original[i] = dividend[i];
	}

        //division using xor
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			dividend[i + j] = dividend[i + j] ^ divisor[j];
		}
	}

	for (int i = n; i < m + n; i++) original[i] = dividend[i];
	cout << endl << "Sent Word: ";
	for (int i = 0; i < m + n; i++) cout << original[i];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			original[i + j] = original[i + j] ^ divisor[j];
		}
	}

	cout << endl << "Remainder on Reciever's side: ";
	for (int i = m; i < m + n; i++) cout << original[i];

	return 0;
}