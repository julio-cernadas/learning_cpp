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
    for (int i = 0; i != clouds.size(); ++i) {
        std::cout << i;
    }
}


int main() 
{
    jumping_on_the_clouds();
}
