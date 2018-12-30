#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int data_types()
{	/* This focuses on introducing the different data types offered
	by c++, we also use a set precision for the decimal counts. */
	int a; 
	long b; 
	char c; 
	float d; 
	double e;
	cin >> a >> b >> c >> d >> e;
	cout << a << '\n' << b << '\n' << c << endl;
	cout.precision(3);			// Set desired decimal value
	cout << fixed << d << endl;	// Fixed sets it to the precision
	cout.precision(9);
	cout << fixed << e << endl;
	return 0;
	// cin -> 3 12345678912345 a 334.23 14049.30493
}

int conditional_statements_with_arrays()
{
	int n;
	// Here we have a string array, we use this to index our cout
	string lst[10] = {"Greater than 9", "one", "two", "three", 
					"four", "five", "six", "seven", "eight", "nine"};
	cin >> n;
	if ((n >= 1) && (n <= 9)) {
		cout << lst[n] << endl;
	}
	else {
		cout << lst[0] << endl;
	}
	return 0;
}

int for_loop()
{
	string lst[11] = {"even", "odd", "one", "two", "three", 
					"four", "five", "six", "seven", "eight", "nine"};
	int a, b;
	cin >> a >> b;
	for (int n = a; n <= b; n++) {
		if ((n >= 1) && (n <= 9)) {
			cout << lst[n+1] << endl;
		}
		else if ((n > 9) && (n % 2 == 0)) {
			cout << lst[0] << endl;
		}
		else {
			cout << lst[1] << endl;
		}
	}
	return 0;
}

int max_of_four(int a, int b, int c, int d) {
    return max(max(a,b),max(c,d));
}

int greatest_of_four_integers() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = max_of_four(a, b, c, d);
    cout << ans << endl;
    return 0;
}

int main()
{
	greatest_of_four_integers();
	return 0;
}
