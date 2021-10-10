/* Vivek Arora */
#include <iostream>
#include <vector>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <unordered_set>
#include <cmath>
#include <numeric>
#include <iterator>
#include <set>
#include <unordered_map>
#include <map>
#include <queue>
#include <cstring>
#include <stdio.h>
#include <fstream>
#include <iomanip>
#include <functional>
#include <bitset>
#include <chrono>
#include <climits>
#include <assert.h>

using namespace std;
using namespace chrono;

#define fastio()                        \
      ios_base::sync_with_stdio(false); \
      cin.tie(NULL);                    \
      cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) (int)(x.size())

#ifndef ONLINE_JUDGE
#define debug(x)         \
      cerr << #x << " "; \
      _print(x);         \
      cerr << endl;
#else
#define debug(x) ;
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
      cerr << "{";
      _print(p.ff);
      cerr << ",";
      _print(p.ss);
      cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
      cerr << "[ ";
      for (T i : v)
      {
            _print(i);
            cerr << " ";
      }
      cerr << "]";
}
template <class T>
void _print(set<T> v)
{
      cerr << "[ ";
      for (T i : v)
      {
            _print(i);
            cerr << " ";
      }
      cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
      cerr << "[ ";
      for (T i : v)
      {
            _print(i);
            cerr << " ";
      }
      cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
      cerr << "[ ";
      for (auto i : v)
      {
            _print(i);
            cerr << " ";
      }
      cerr << "]";
}

//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
//void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b)
{
      if (b > a)
      {
            return gcd(b, a);
      }
      if (b == 0)
      {
            return a;
      }
      return gcd(b, a % b);
}
ll expo(ll a, ll b, ll mod)
{
      ll res = 1;
      while (b > 0)
      {
            if (b & 1)
                  res = (res * a) % mod;
            a = (a * a) % mod;
            b = b >> 1;
      }
      return res;
}
void extendgcd(ll a, ll b, ll *v)
{
      if (b == 0)
      {
            v[0] = 1;
            v[1] = 0;
            v[2] = a;
            return;
      }
      extendgcd(b, a % b, v);
      ll x = v[1];
      v[1] = v[0] - v[1] * (a / b);
      v[0] = x;
      return;
} //pass an arry of size1 3
ll mminv(ll a, ll b)
{
      ll arr[3];
      extendgcd(a, b, arr);
      return arr[0];
} //for non prime b
ll mminvprime(ll a, ll b) { return expo(a, b - 2, b); }
bool revsort(ll a, ll b) { return a > b; }
void swap(int &x, int &y)
{
      int temp = x;
      x = y;
      y = temp;
}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact)
{
      ll val1 = fact[n];
      ll val2 = ifact[n - r];
      ll val3 = ifact[r];
      return (((val1 * val2) % m) * val3) % m;
}
void google(int t) { cout << "Case #" << t << ": "; }
vector<ll> sieve(int n)
{
      int *arr = new int[n + 1]();
      vector<ll> vect;
      for (int i = 2; i <= n; i++)
            if (arr[i] == 0)
            {
                  vect.push_back(i);
                  for (int j = 2 * i; j <= n; j += i)
                        arr[j] = 1;
            }
      return vect;
}
ll mod_add(ll a, ll b, ll m)
{
      a = a % m;
      b = b % m;
      return (((a + b) % m) + m) % m;
}
ll mod_mul(ll a, ll b, ll m)
{
      a = a % m;
      b = b % m;
      return (((a * b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m)
{
      a = a % m;
      b = b % m;
      return (((a - b) % m) + m) % m;
}
ll mod_div(ll a, ll b, ll m)
{
      a = a % m;
      b = b % m;
      return (mod_mul(a, mminvprime(b, m), m) + m) % m;
} //only for prime m
ll phin(ll n)
{
      ll number = n;
      if (n % 2 == 0)
      {
            number /= 2;
            while (n % 2 == 0)
                  n /= 2;
      }
      for (ll i = 3; i <= sqrt(n); i += 2)
      {
            if (n % i == 0)
            {
                  while (n % i == 0)
                        n /= i;
                  number = (number / i * (i - 1));
            }
      }
      if (n > 1)
            number = (number / n * (n - 1));
      return number;
} //O(sqrt(N))
/*--------------------------------------------------------------------------------------------------------------------------*/

class Node
{
public:
      ll data;
      Node *next = NULL;
      Node *prev = NULL;

      Node(ll data)
      {
            this->data = data;
            next = NULL;
            prev = NULL;
      }
};

Node *takeInput()
{

      ll data;
      cin >> data;
      Node *head = NULL;
      Node *tail = NULL;
      while (data != -1)
      {

            Node *newNode = new Node(data);
            if (head == NULL)
            {
                  head = newNode;
                  tail = newNode;
            }
            else
            {
                  tail->next = newNode;
                  tail = newNode;
                  // or  tail = tail->next
            }
            cin >> data;
      }

      return head;
}

Node *takeInputAtAnyPoint(Node *head, ll i, ll d)
{
      Node *newNode = new Node(d);
      if (i == 0)
      {
            newNode->next = head;
            head = newNode;
            return head;
      }
      Node *temp = head;
      ll cnt = 0;
      while (temp != NULL && cnt < i - 1)
      {
            temp = temp->next;
            cnt++;
      }

      if (temp != NULL)
      {
            newNode->next = temp->next;
            temp->next = newNode;
      }

      return head;
}

Node *deleteAtAnyPoint(Node *head, ll i)
{
      //Node *newNode = new Node(d);

      if (i == 0)
      {
            head = head->next;
            return head;
      }
      Node *temp = head;

      ll cnt = 0;
      while (temp != NULL && cnt < i - 1)
      {
            temp = temp->next;
            cnt++;
      }

      if (temp != NULL)
      {
            Node *a = temp->next;
            Node *b = a->next;
            temp->next = b;
            delete a;
      }

      return head;
}

Node *midNode(Node *head)
{

      if (head == NULL || head->next == NULL)
      {
            return head;
      }

      Node *slow = head;
      Node *fast = head->next;

      while (fast != NULL && fast->next != NULL)
      {
            fast = fast->next->next;
            slow = slow->next;
      }

      return slow;
}

Node *mergeTwoSortedLinkedList(Node *head1, Node *head2)
{

      //Base Case
      if (head1 == NULL)
      {
            return head2;
      }

      if (head2 == NULL)
      {
            return head1;
      }

      Node *head3 = NULL;
      //Recursive Case
      if (head1->data < head2->data)
      {
            head3 = head1;
            head3->next = mergeTwoSortedLinkedList(head1->next, head2);
      }
      else
      {
            head3 = head2;
            head3->next = mergeTwoSortedLinkedList(head1, head2->next);
      }

      return head3;
}

Node *meregSort(Node *head)
{

      //Base Case
      if (head == NULL || head->next == NULL)
      {
            return head;
      }

      Node *mid = midNode(head);
      Node *a = head;
      Node *b = mid->next;
      mid->next = NULL;

      // Recursive Call

      a = meregSort(a);
      b = meregSort(b);

      Node *c = mergeTwoSortedLinkedList(a, b);

      return c;
}

Node *reverseLinkedList(Node *head)
{

      // Base case

      if (head == NULL || head->next == NULL)
      {
            return head;
      }

      Node *smallAns = reverseLinkedList(head->next);
      Node *temp = smallAns;

      while (temp->next != NULL)
      {
            temp = temp->next;
      }

      temp->next = head;
      head->next = NULL;

      return smallAns;
}

//Doubly Linked List

void insertAtHead(Node *head, ll val)
{

      Node *n = new Node(val);

      n->next = head;
      if (head != NULL)
      {
            head->prev = n;
      }

      head = n;
}

void insertAtTail(Node *head, ll val)
{

      if (head == NULL)
      {
            insertAtHead(head, val);
      }

      Node *n = new Node(val);
      Node *temp = head;

      while (temp->next != NULL)
      {
            temp = temp->next;
      }

      temp->next = n;
      n->prev = temp;
}

void printLinkedList(Node *head)
{

      Node *temp = head;

      while (temp != NULL)
      {
            cout << temp->data << " ";
            temp = temp->next;
      }
}

bool dectectLoop(Node *head)
{

      if (head == NULL || head->next == NULL)
      {
            return head;
      }

      Node *slow = head;
      Node *fast = head;

      while (fast != NULL && fast->next != NULL)
      {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast)
            {
                  return true;
            }
      }

      return false;
}

Node *removeLoop(Node *head)
{

      if (head == NULL || head->next == NULL)
      {
            return head;
      }

      Node *slow = head;
      Node *fast = head;

      while (fast != NULL && fast->next != NULL)
      {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast)
            {
                  slow = head;
                  if (slow == fast)
                  {
                        while (fast->next != slow)
                        {
                              fast = fast->next;
                        }
                  }
                  else
                  {
                        while (slow->next != fast->next)
                        {
                              slow = slow->next;
                              fast = fast->next;
                        }
                  }
                  fast->next = NULL;
            }
      }

      return head;
}

void deleteInDoublyLLHead(Node *head)
{

      Node *toDelete = head;
      head = head->next;
      head->prev = NULL;

      delete toDelete;
}

void deleteInDoublyLL(Node *head, ll i)
{

      if (i == 1)
      {
            deleteInDoublyLLHead(head);
            return;
      }

      Node *temp = head;
      ll cnt = 0;
      while (temp != NULL && cnt != i)
      {
            temp = temp->next;
            cnt++;
      }

      temp->prev->next = temp->next;
      if (temp->next != NULL)
      {
            temp->next->prev = temp->prev;
      }

      delete temp;
}

void solve()
{
      int t;
      t = 1;
      //    cin >> t;
      while (t--)
      {
            // cout << "Enter Linked List: " << nline;
            Node *head = takeInput();
            // Node *head2 = takeInput();

            // Node *head3 = mergeTwoSortedLinkedList(head1, head2);
            //printLinkedList(head);
            // Node *l = midNode(head);
            // cout << l->data << nline;
            //head = deleteAtAnyPoint(head, 3);
            Node *head1 = reverseLinkedList(head);
            printLinkedList(head1);
      }
}

int main()
{
      fastio();
#ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
      freopen("Error.txt", "w", stderr);
#endif
      auto start1 = high_resolution_clock::now();
      solve();
      auto stop1 = high_resolution_clock::now();
      auto duration = duration_cast<microseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE
      cerr << "Time: " << duration.count() / 1000 << endl;
#endif
      return 0;
}
