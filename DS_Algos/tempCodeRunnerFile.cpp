
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