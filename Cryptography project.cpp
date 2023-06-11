// Cryptography project.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include <cmath>
using namespace std;
class party
{
	int n;
	int g;
	int lgNum;

public:
	party()
	{
		n = g = lgNum = 0;
	}
	void getdata();
	int isPrime(int num);
	int publicKey();
	int privateKey(int a);
	int display();
};
void party::getdata()
{
	int x, y, z;
	cout << "Enter two prime numbers N,G and large number, please." << endl;

	while (true)
	{
		cin >> x;
		if (isPrime(x) == x)
		{
			n = x;
			break;
		}
		else
		{
			cout << "your input(" << x << ") is not prime number, re-enter a prime number" << endl;
			continue;
		}
	}
	while (true)
	{
		cin >> y;
		if (isPrime(y) == y)
		{
			g = y;
			break;
		}
		else
		{
			cout << "your input(" << y << ") is not prime number, re-enter a prime number" << endl;
			continue;
		}
	}
	cin >> z;
	lgNum = z;
}
int party::publicKey()
{
	int x = (int)pow(g, lgNum);
	return x % n;
}
int party::privateKey(int a)
{
	int x = (int)pow(a, lgNum);
	return x % n;
}
int party::isPrime(int num)
{
	int count = 0;
	for (int i = 1; i < num; i++)
	{
		if (num % i == 0)
		{
			count = count + 1;
		}
	}
	if (count == 1)
	{
		cout << num << " is prime number" << endl;
		return num;
	}
	else
		cout << "It's not prime number" << endl;
	return -1;
}

int main()
{
	party ob1;
	ob1.getdata();
	int A = ob1.publicKey();
	party ob2;
	ob2.getdata();
	int B = ob2.publicKey();

	int k1 = ob1.privateKey(B);
	int k2 = ob2.privateKey(A);
	if (k1 == k2)
	{
		cout << "the keys exchange process has done successfully" << endl;
	}
	return 0;
}