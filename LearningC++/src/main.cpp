#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <sstream>
using namespace std;

// Introducing data types
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
// ----------------------------------------

// Introducing if-else statements
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
// ----------------------------------------


// Introducing basic for loops
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
// ----------------------------------------


//  Finding the greatest number of four
int max_of_four(int a, int b, int c, int d) 
{
    return max(max(a,b),max(c,d));
}

int greatest_of_four_integers() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = max_of_four(a, b, c, d);
    cout << ans << endl;
    return 0;
}
// ----------------------------------------


// Handling string inputs with stringstream
int stringstreams1()
{
	string mystr;
	int a,b,c;
	getline(cin,mystr);
	stringstream(mystr) >> a >> b >> c;
	cout << a << endl << b << endl << c << endl;
	return 0;
}

vector<int> parseInts(string str) 
{
	stringstream ss(str);
	vector<int> vec;
	char commas;
	int tmp;
	while (ss >> tmp) {
		vec.push_back(tmp);
		ss >> commas;
	}
	return vec;
}

int stringstream2()
{
	string str;
	getline(cin,str);
	vector<int> result = parseInts(str);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}
	return 0;
}
// ----------------------------------------


// Introducing pointer
// void is used for a func that doesn't return anything
void update(int *pa, int *pb)			
{
	int a = *pa;
	int b = *pb;
	*pa = a + b;
	*pb = abs(a - b);
}

int pointers()
{
	int a, b;
	int *pa = &a, *pb = &b;
	cin >> a >> b;
	update(pa,pb);
	cout << a << endl << b << endl;
	return 0;
}

int arrays()
{
	int len;
	cin >> len;
	int arr[len];
	for (int i = 0; i < len; i++) {
		cin >> arr[i];
	}
	for (int i = len - 1; i >= len; i--) {
		cout << arr[i] << " ";
	}
	return 0;
}


int main()
{
	arrays();
	return 0;
}