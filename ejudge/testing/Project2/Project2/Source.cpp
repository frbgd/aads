#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
	int count = 0;
	string str;
	double sum = 0;
	do 
	{
		double r = 0;
		bool minus = false;
		getline(cin, str);
		if (str.empty())
		{
			count++;
			continue;
		}
		else
			count = 0;
		for (auto ch : str)
		{
			if (ch >= '0' && ch <= '9')
				r = r * 10 + ch - '0';
			else
			{
				if (minus)
					sum -= r;
				else
					sum += r;
				r = 0;
				minus = false;
				if (ch == '-')
					minus = true;
			}
		}
		if (r != 0)
		{
			if (minus)
				sum -= r;
			else
				sum += r;
		}
	} while (count <= 1);
	cout << setprecision(0) << fixed << sum;
	return 0;
}