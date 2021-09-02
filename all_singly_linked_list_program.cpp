#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
void printlist(Node *head)
{
    // Node *curr=head;
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
// function 1:-
int search_in_ll(Node *head, int x)
{
    int count = 1;
    while (head != NULL)
    {
        if (head->data == x)
        {
            return count;
        }
        head = head->next;
        count++;
    }
    return -1;
}
int search_recursive(Node *head, int x)
{
    static int count = 1;
    if (head == NULL)
    {
        return -1;
    }
    if (head->data == x)
    {
        return count;
    }
    count++;
    search_recursive(head->next, x);
}

//  function 2:-

Node *insertbegin(Node *head, int x)
{
    Node *temp = new Node(x);
    temp->next = head;
    return temp;
}

// function 3:-

Node *insert_end(Node *head, int x)
{
    Node *temp = new Node(x);
    if (head == NULL) // LL is already NULL then we explicitly add this...
    {
        return temp;
    }
    Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}

// function 4:-

// method 1:-

Node *dlt_first_node(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *temp = head->next;
    delete (head);
    return temp;
}

// method :- 2

Node *dlt_first_node(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *curr = head;
    while (curr->next->next != NULL)
    {
        curr = curr->next;
    }
    delete (curr->next);
    curr->next = NULL;
    return head;
}

//  function 5 :-

Node *dlt_end_node(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *curr = head;
    while (curr->next->next != NULL)
    {
        curr = curr->next;
    }
    delete (curr->next);
    curr->next = NULL;
    return head;
}

// function 6 :-

Node *insert_inLL(Node *head, int pos, int D)
{
    Node *temp = new Node(D);
    if (pos == 1)
    {
        temp->next = head;
        return temp;
    }
    Node *curr = head;
    for (int i = 1; i <= pos - 2 && curr != NULL; i++)
    {
        curr = curr->next;
    }
    if (curr == NULL)
    {
        return head;
    }
    temp->next = curr->next;
    curr->next = temp;
    return head;
}

// function 7:-

Node *sorted_insert_ll(Node *head, int D)
{
    Node *temp = new Node(D);
    if (head == NULL)
    {
        return temp;
    }
    if (D < head->data)
    {
        temp->next = head;
        return temp;
    }
    Node *curr = head;
    while (curr->next != NULL && curr->next->data < D)
    {
        curr = curr->next;
    }
    // if(curr==NULL)
    // {
    //     curr->next=temp;
    //     temp->next=NULL;
    // }
    temp->next = curr->next;
    curr->next = temp;
    return head;
}

// function 8:-

// method 1: find the length and simple (length+1-n)th node return

void findendof(Node *head, int n)
{
    int count = 0;
    // Node *curr=head;
    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        count++;
    }
    if (count < n)
    {
        return;
    }
    // now we find (count-n+1)th node in likned list
    Node *curr = head;
    for (int i = 1; i < (count + 1 - n); i++)
    {
        curr = curr->next;
    }
    cout << curr->data << endl;
}
// method 2 :-> using two pointer method:- >

// approach :-
// 1). move 'first' n position ahead.
// 2). start "second" pointer head(start).
// 3). move both first pointer and second pointer. when second pointer is null so return first->data is the requried ans

void find_nth_term_from_end_of_LL(Node *head, int n)
{
    if (head == NULL)
    {
        return;
    }
    Node *first = head;
    Node *second = head;
    for (int i = 1; i <= n; i++)
    {
        if (first == NULL)
            return;
        first = first->next;
    }

    while (first != NULL)
    {
        second = second->next;
        first = first->next;
    }
    cout << second->data << endl;
}

// function 9:-

Node *reverese_linked_list(Node *head)
{
    //  method 1 :->

    vector<int> arr;
    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        arr.push_back(curr->data);
    }
    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        curr->data = arr.back(); // here [$arr.back()$] function gives the last element in vector...
        arr.pop_back();
    }
    return head;

    //  METHOD:->2  $ using reverse function we also reverse the linked list ...

    //    reverse(arr.begin(),arr.end());
    //     Node *curr=head;
    //     int i=0;
    //     while(curr!=NULL)
    //     {
    //         curr->data=arr[i];
    //         i++;
    //         curr=curr->next;
    //     }
    //     return head;
}

// method:- 3

// recursive method to reverse the linkedlist

Node *rec_rev_LL(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *rest_of_ll = rec_rev_LL(head->next);
    Node *rest_tail = head->next;
    rest_tail->next = head;
    head->next = NULL;
    return rest_of_ll;
}

// method :-> 3 recursive approach...

Node *rec_rev_LL(Node *curr, Node *prev)
{
    if (curr == NULL)
    {
        return prev;
    }
    Node *next = curr->next;
    curr->next = prev;
    rec_rev_LL(next, curr);
}

// function 10 :-

void remove_duplicate(Node *head)
{
    Node *curr = head;
    while (curr != NULL && curr->next != NULL)
    {

        if (curr->data == curr->next->data)
        {
            Node *temp = curr->next;
            curr->next = curr->next->next;
            delete (temp);
        }
        else
            curr = curr->next;
    }
    // return head;
}

// function 11:-

// method :- 1

void middle_found(Node *head)
{
    int count = 0;
    Node *curr;
    for (curr = head; curr != NULL; curr = curr->next)
    {
        count++;
    }
    curr = head;
    for (int i = 0; i < count / 2; i++)
    {
        curr = curr->next;
    }
    cout << curr->data << endl;
}

// method :-2

void middle_found(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << slow->data << endl;
}
void printlist(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    cout << head->data << " ";
    printlist(head->next);
}

int main()
{
    Node *head = new Node(10);
    // Node *temp1=new Node(20);
    // Node *temp2=new Node(30);
    // head->next=temp1;
    // // head->next=temp1;
    // temp1->next=temp2;
    // head->next=new Node(20);
    // head->next->next=new Node(22);
    // head->next->next->next =new Node(45);
    printlist(head);
    // for searching function line :-> below...
    // function 1:-
    //cout<<"\n your ans is :-> ("   << search_recursive(head,22)<<")"<<endl;
    // printlist(head);
    // printlist(head);

    // function 2:-

    //    Node *head=new Node(23);
    //     head=insertbegin(head,34);
    //     head=insertbegin(head,39);
    //     head=insertbegin(head,2);
    //     printlist(head);

    // function 3:-

    //  Node *head = new Node(10);
    //     head->next = new Node(20);
    //     head->next->next = new Node(22);
    //     head->next->next->next = new Node(45);
    //     head=insert_end(head,34);
    //    printlist(head);

    // function 4:-

    //   Node *head = new Node(10);
    //     head->next = new Node(20);
    //     head->next->next = new Node(22);
    //     head->next->next->next = new Node(45);
    //     printlist(head);
    //     cout<<endl;
    // head=dlt_first_node(head);
    //    printlist(head);

    // function 5:-

    //   Node *head = new Node(10);
    //     head->next = new Node(20);
    //     head->next->next = new Node(22);
    //     head->next->next->next = new Node(45);
    //     printlist(head);
    //     cout<<endl;
    // head=dlt_end_node(head);
    //    printlist(head);

    // function 6:-

    //  Node *head = new Node(10);
    //     head->next = new Node(20);
    //     head->next->next = new Node(22);
    //     head->next->next->next = new Node(45);
    //     printlist(head);
    //     cout<<endl;
    //     head=insert_inLL(head,3,23);
    //      printlist(head);

    // function 7:-

    //  Node *head = new Node(10);
    //     head->next = new Node(20);
    //     head->next->next = new Node(22);
    //     head->next->next->next = new Node(45);
    //     printlist(head);
    //     cout<<endl;
    //       head=sorted_insert_ll(head,500);
    //         head=sorted_insert_ll(head,500);

    // function 8:-

    //  Node *head = new Node(10);
    //     head->next = new Node(20);
    //     head->next->next = new Node(22);
    //     head->next->next->next = new Node(45);
    //     printlist(head);
    //     cout<<endl;
    //      find_nth_term_from_end_of_LL(head,5);

    // function 9:-

    // Node *head = new Node(20);
    // head->next = new Node(22);
    // head->next->next = new Node(25);
    // // head->next->next->next = new Node(30);
    // cout << "\nbefore reverese linkedlist " << endl;
    // printlist(head);
    // // head = reverese_linked_list(head);
    // head=rec_rev_LL(head,NULL);
    //  cout << "\nAfter reverese linkedlist " << endl;
    // printlist(head);

    // function 10 :-

    //  Node *head = new Node(23);
    //      head->next = new Node(23);
    //      head->next->next = new Node(24);
    //      head->next->next->next = new Node(25);
    //      head->next->next->next->next = new Node(25);
    //      head->next->next->next->next->next = new Node(25);
    //      head->next->next->next->next->next->next = new Node(25);
    //  head->next->next->next->next->next->next->next = new Node(24);
    //     printlist(head);
    //     cout << endl;
    //     remove_duplicate(head);
    //     printlist(head);

    // function 11 :->

    //  Node *head = new Node(10);
    //     head->next = new Node(20);
    //     head->next->next = new Node(22);
    //     head->next->next->next = new Node(45);
    //     // head->next->next->next->next = new Node(50);
    //      printlist(head);
    //   cout<<endl;
    //  middle_found(head);

    return 0;
}
