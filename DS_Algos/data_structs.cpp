#include<iostream>
#include<sstream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using std::cout, std::cin, std::endl, std::string, std::vector;

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

/*                              Linked List                                 */

// node* build_linked_list()
// {
//     node *head, *newNode, *tail;
//     int num;
//     cout << "Enter a list of integers ending with -999." << endl;
//     cin  >> num;
//     head = nullptr;
//     tail = nullptr;
//     while (num != -999) 
//     {   
//         newNode = new node;
//         newNode->info = num;
//         newNode->link = nullptr;
//         if (head == nullptr) {
//             head = newNode;
//             tail = newNode;
//         }
//         else {
//             tail->link = newNode;
//             tail = newNode;
//         }
//         cin >> num;
//     }
//     return head;
// }

// node* build_linked_list_backward()
// {
//     node *head, *newNode;
//     int num;
//     cout << "Enter a list of integers ending with -999." << endl;
//     cin  >> num;
//     head = nullptr;
//     while (num != -999) 
//     {   
//         newNode = new node;
//         newNode->info = num;
//         newNode->link = head;
//         head = newNode;
//         cin >> num;
//     }
//     return head;
// }


struct ListNode {
        int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Merge two linked lists
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode temp(INT_MIN);
        
        // Pointer = Address of Temp
        ListNode *tail = &temp;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                std::cout << "L1: " << l1->val <<"\n";
                l1 = l1->next;
            } else {
                tail->next = l2;
                std::cout << "L2: " << l2->val <<"\n";
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = (l1 ? l1 : l2);
        return temp.next;
    }
};

int main() 
{
    return 0;
}
