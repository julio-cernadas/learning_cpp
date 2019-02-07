#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <algorithm>
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
/* -----------------------------------------------------------------*/

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
/* -----------------------------------------------------------------*/


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
/* -----------------------------------------------------------------*/


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
/* -----------------------------------------------------------------*/


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
/* -----------------------------------------------------------------*/


// Introducing Pointer
// off topic: void is used for a func that doesn't return anything
// 			  void type - typeless
/* 
pointers - integers that store memory address of a value
*/

// Introducing Memory Concepts
/*  
Stack - stores automatic variable, faster than heap and free store
		, b/c memory allocation invovles only pointer increment. Objects
		are constructed immediately after memory is allocated and
		destroyed immediately before memory is deallocated.
	  - Includes all local variables
Free store & Heap - dynamic memory areas, allocated by new/delete
	Operators:
		* new - used to allocate storage space
			  - returns the address of a the newly initialized memory,
			  	to a pointer variable. Thus... 'char *p = new char[10]'
		* delete - used to delete object, must be used to avoid
					undesired memory leaks.
		https://www.geeksforgeeks.org/new-and-delete-operators-in-cpp-for-dynamic-memory/ 

When typing 'int a' or 'char b', memory is automatically allocated.
vs.
Dynamically allocated memory is like 'int *p = new int[10]'; here we
initialize an array of memory or block of memory and it then becomes 
your responsability to deallocate the memory when no longer needed.


*/
void update(int *pa, int *pb)	// initializing pointers
{
	int a = *pa;
	int b = *pb;
	*pa = a + b;
	*pb = abs(a - b);
}

int pointers()
{								// *  = value of pointer | pointed by
	int a, b;					// &  = reference | address of
	int *pa = &a, *pb = &b;		// dtype *x = initializing pointer
	cin >> a >> b;
	update(pa,pb);
	cout << a << endl << b << endl;
	return 0;
}
/* -----------------------------------------------------------------*/


// Introducing Arrays
int arrays()
{
	int len;
	cin >> len;
	int arr[len];
	for (int i = 0; i < len; i++) {
		cin >> arr[i];
	}
	for (int i = len - 1; i >= 0; i--) {
		cout << arr[i] << " ";
	}
	return 0;
}

int arrays_output()
{
	arrays();
	return 0;
}
/* -----------------------------------------------------------------*/


// String Operations
int string_ops()
{
	string a, b;
	char a_1st, b_1st;
	cin >> a >> b;
	cout << a.size() << " " << b.size() << endl;
	cout << a + b << endl;
	swap(a[0],b[0]);
	cout << a << " " << b << endl;
	return 0;
}
/* -----------------------------------------------------------------*/


/* 	Structs vs. Classes
- The main difference is that classes are private by default, while
structs are public by default.
- structs are used, but are there to maintain c backwards compatability.

	More on Classes
- Private vs Public Members: 
	* Private members cannot be accessed from the object.
	* Public members can be accessed.
	* To access private members, we need to have a function within the 
	class to access these members; setter and getters.
- 



*/

// Structs
struct Student1 {
	int age;
	string first_name, last_name;
	int standard;
};

// Classes
class Student2 {
	private:
		int age, standard;
		string first_name, last_name;
	public:
		void set_age(int a) {
			age = a;
		}
		int get_age() {return age;}

		void set_first_name(string fn) {
			first_name = fn;
		}
		string get_first_name() {return first_name;}	
		
		void set_last_name(string ln) {
			last_name = ln;
		}
		string get_last_name() {return last_name;}
		
		void set_standard(int s) {
			standard = s;
		}
		int get_standard() {return standard;}

		string to_string() {
			stringstream ss;
			char c = ',';
			ss << age << c << first_name << c << last_name 
			<< c << standard;
			return ss.str();
		}
};

class Student {
	private:
		int arr[4];
		int score;

	public:
		void input() {
			for (int i = 0; i < 4; i++) {
				cin >> arr[i];
			}
		}
		int caculateTotalScore() {
			score = 0;
			for (int i = 0; i < 4; i++) {
				score = score + arr[i];
			}
			return score;
		}
};

// Constructors
class Student3 {
	public:
		int score, gpa;
		Student3(int s, int g) {		// Constructor
			score = s;					// Allows for parameters too!
			gpa = g;
		}
		void Print() {
			cout << score << " " << gpa << endl;
		}
};
/* -----------------------------------------------------------------*/


/* Multi-Dimension Arrays in C++
We use an array of arrays, but in C++, this consists of an array of 
pointers pointing to other arrays.

This would be a regular array...   int arr[50]

Yet this would be with pointers... int* arr = new int[50]

Both are the same, meaning both 'arr' are just pointers to stored data.
If you were to print them out, then you would get an address for both.

For a two dimensional arrays...    int** arr = new int*[50]


*/
int variable_sized_arrs()
{
	int n,q;
	cin >> n >> q;
	int** arr2D = new int*[n];				// Initialize 2D Array
	for (int i = 0; i < n; i++) {
		int len;
		cin >> len;
		int* arr1D = new int[len];
		for (int j = 0; j < len; j++) {
			int vars;
			cin >> arr1D[vars];				// Initialize 1D Array	
		}
		arr2D[i] = arr1D;
	}

	for (int i = 0; i < q; i++) {			// 
		int x, y;
		cin >> x >> y;
		cout << arr2D[x][y] << endl;
	}
	// You have to delete the 1D array first, in order to not have a
	// memory leak caused by deleting the 2D array first, which would
	// delete only the array containing pointers but not the 1D arrays
	// left in memory, leaving them unobtainable -> memory leak.
	for (int i = 0; i < n; i++) {
		delete[] arr2D[i];
	}
	delete[] arr2D;

	return 0;
}

/* 	References
ex. int& ref: not to be confused with address of...
These are very similar to pointers but not as complex

References can be thought of as aliases for memory... for example:
int a = 5;
int& ref = a;
cout << ref;

output -- 5
--------------------------
void Increment(int& value) 	// This is like setting 'int& value = a'
{
	value++
}

int main() 
{
	int a = 5;
	Increment(a);
	cout << a;
}

output -- 6
-------------------------
*/ 

class Box {
	private: 
		int length, breadth, height;
	public:
		Box () {
			length = 0;
			breadth = 0;
			height = 0;
		}
		Box(int l, int b, int h) {
			length = l;
			breadth = b;
			height = h;
		}
		Box(const Box& B) {
			length = B.length;
			breadth = B.breadth;
			height = B.height;
		}

		int getLength() {
			return length;
		}
		int getBreadth() {
			return breadth;
		}
		int getHeight() {
			return height;
		}

		long long CalculateVolume() {
			return (long long) length * breadth * height;
		}
};
/* -----------------------------------------------------------------*/


/*	OOP Concepts - Inheritance




*/

class Entity {
	public:
		float X, Y;
		void Move(float xa, float ya) {
			X += xa;
			Y += ya;
		}
};

// Player inherited from Entity
class Player : public Entity {
	public:
		const char* Name;
		void PrintName() {
			cout << Name << endl;
		}
};