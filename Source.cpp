#include <iostream>
#include <fstream>
using namespace std;
int main();
                           
void checkInput()
{
	if (cin.fail())
	{
		throw "Error: Incorrect input, enter correct value.\n";
	}
} 
void checkN(int n)
{
	if (n < 3)
	{
		throw "Error: n<3, enter correct value.\n";
	}
}
void checkX(double x1, double x2)
{
	if (x1 > x2)
	{
		throw "Error: x1>x2, enter correct value.\n";
	}
}
void checkStep(double step)
{
	if (step <= 0)
	{
		throw "Error: step<=0, enter correct value.\n";
	}
}

double calc(double x1, int n)
{
	if (x1 < 0)
	{
		double y = 0; int i = 1;
		while (i <= n)
		{
			int j = 1; double s = 0;
			while (j <= n) { s += 1 / (x1 - i - j);  j++; }
			y += s; i++;
		}
		return y;
	}
	else {
		double y = 1; int i = 1;
		while (i <= (n - 3))
		{
			y *= (x1 - i);
			i++;
		}
		return y;
	}
}
int main()
{
	int  n; double x1, x2, step;  char save;

	ofstream fout;
	fout.open("file.txt", ofstream::app); 

	cout << "Do you want to save results? (Y/N)   ";
	cin >> save;
	switch (save)
	{
	case 'N': fout.close();
	case 'Y':;
	}
start:
	try // îáðîáêà âèêëþ÷åíü
	{
		fout << "Input: ";
		cout << "Enter:\n[x1]";
		cin >> x1;
		checkInput();
		fout << " [x1] " << x1 << ";";

		cout << "[x2]";
		cin >> x2;
		checkInput();
		checkX(x1, x2);
		fout << " [x2] " << x2 << ";";

		cout << "[step]";
		cin >> step;
		checkInput();
		checkStep(step);
		fout << " [step] " << step << ";";

		cout << "[n](n>3)";
		cin >> n;
		checkInput();
		checkN(n);
		fout << " [n](n>3) " << n << ";\n";

		fout << "Output:\n";
		while (x1 <= x2)
		{
			cout << "\n[x] " << x1 << "\n[y]" << calc(x1, n) << endl;
			fout << "[x] " << x1 << ";\t";
			fout << "[y] " << calc(x1, n) << ";\n\n";
			x1 += step;
		}
		fout.close();
		system("pause");
	}
	catch (const char* ex)         
	{
		cout << ex << endl;
		cin.clear();
		cin.ignore();
		goto start;   
	}
	catch (...)                   
	{
		cout << "Unknown error" << endl;
		cin.clear();
		goto start;              
	}
	
}
