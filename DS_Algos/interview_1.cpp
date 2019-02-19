#include<iostream>
#include<sstream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using std::cout, std::cin, std::string, std::vector;

void sock_merchant_map()                // Using unordered_map
{
    int n, num;                         // number of sock in pile
    std::cin >> n;                      // first line read
    std::cin.ignore();
    std::string input;
    std::getline(std::cin, input);      // second line, sock colors
    std::stringstream ss(input);
    std::vector<int> socks;
    while (ss >> num) {
        socks.push_back(num);
    }
    std::unordered_map<int,int> counts;
    for (const auto i : socks) {
        counts[i]++;
    }
    int count = 0;
    for (auto itr : counts) {
        count += itr.second / 2;
    }
    std::cout << count;
}
;
void jumping_on_the_clouds()       
{
    int n,num;                          // number of clouds
    std::cin >> n;                      // first line read
    std::cin.ignore();
    std::string input;
    std::getline(std::cin, input);      // second line, sock colors
    std::stringstream ss(input);
    std::vector<int> clouds;
    while (ss >> num) {
        clouds.push_back(num);
    }
    int count = 0;
    for (int i = 0; i < n-2; ++i, ++count) {
        if (clouds[i+2] == 0) {
            ++i;
        }
    }
}

void counting_valleys() 
{
    int n, v_count = 0, sealevel = 0;
    std::string s;
    std::cin >> n;
    std::cin >> s;
    for (auto step : s) {
        std::cout << step << std::endl;
        if (step == 'U') {++sealevel;}
        if (step == 'D') {--sealevel;}
        if (sealevel == 0 && step == 'U') {++v_count;}
    }
    std::cout << v_count;
}


void Array_2D_DS()
{
    int size, num, temp;
    std::cin >> size;
    int arr[size];
    for (int i = 0; i != size; ++i) {
        std::cin >> num;
        arr[i] = num;
    }
    for (int i = 0; i != (size/2); ++i) {
        int temp = arr[i];
        arr[i] = arr[(size - 1) - i];
        arr[(size - 1) - i] = temp;
    }
    for (auto i : arr) {
        std::cout << i << " ";
    }
}

void left_rotation() 
{
    int n, d, temp;
    cin >> n >> d;
    vector<int> vec;
    for (int i = 0; i != n; ++i) {
        cin >> temp;
        vec.push_back(temp);
    }
    for (int i = 0; i != n; ++ i) {
        cout << vec[(i+d)%n] << " ";
    }
}

void sparse_strings()
{
    int n, q, cnt;
    string tmp;
    vector<string> strings;
    vector<string> queries;
    cin >> n;
    for (int i = 0; i != n; ++i) {
        cin >> tmp;
        strings.push_back(tmp);
    }
    cin >> q;
    for (int i = 0; i != q; ++i) {
        cin >> tmp;
        queries.push_back(tmp);
    }
    for (auto word : queries) {
        cout << std::count(strings.begin(), strings.end(), word) << "\n";
    }
}

void print_elements()
{
    int n, tmp;
    vector<int> vec;
    cin >> n;
    for (int i = 0; i != n; ++i) {
        cin >> tmp;
        vec.push_back(tmp);
    }
    for (auto num : vec) {
        cout << num << "\n";
    }
}


int main() 
{
    print_elements();
    return 0;
}
