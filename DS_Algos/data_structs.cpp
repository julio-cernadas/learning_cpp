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

/*                                  Linked List                                     */

struct node                           
{
    int data;
    node* next;
};

class linked_list
{
    node* head
    int length;
    linked_list():
        head {NULL}, tail {NULL} {}
};

void createnode(int val)
{
    node* temp = new node;
    temp->data = val;
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
        tail = temp;
        temp = NULL;
    }
    else {
        tail->next = temp;
        tail = temp;
    }
}

void display_list()
{
    node* temp = new node;
    temp = head;
    while ()
}


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
};

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2)
{
    // Result 
    ListNode *result;                             
    ListNode *dump = new ListNode((int)0);
    ListNode **sum = &result;
    int carry = 0;
    int now = 0;
    while(l1 != dump || l2 != dump || carry != 0)
    {
        // grabs the ones place number
        now = (l1->val + l2->val + carry)%10;
        // grabs the tens place number to be carried, if any...
        carry = (l1->val + l2->val + carry)/10;
        // the value pointed by sum (result ptr) now points to a ListNode(7,then 0, then 8)
        *sum = new ListNode(now); // this result's next member will be accessed below
        // (the address of the value pointed to by sum, result ptr)->next
        sum = &(*sum)->next;    
        // proceeds to next numbers in linked list for while loop
        if (l2->next == NULL)
            l2 = dump;
        else l2 = l2->next;
        if (l1->next == NULL)
            l1 = dump;
        else l1 = l1->next;
    }
    delete dump;
    return result;
}

double find_median(vector<int>& nums1, vector<int>& nums2)
{
    




    return nums1
}





int main() 
{
    return 0;
}
