#include<iostream>
#include<sstream>
#include<vector>
#include<unordered_map>

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


int main() 
{
    counting_valleys();
}
