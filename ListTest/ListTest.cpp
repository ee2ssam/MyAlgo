// ListTest.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <list>
#include <forward_list>

using namespace std;


//std::forward_list(단방향) 활용
int main()
{
    forward_list<int> l1{ 10, 20, 30, 40 };
    l1.push_front(40);
    l1.push_front(30);  // 30, 40, 10, 20, 30, 40

    for (auto a : l1)
    {
        cout << a << ", ";
    }
    cout << endl;

    int count = std::distance(l1.begin(), l1.end());
    cout << count << endl;

    //l1.remove(40);
    l1.remove_if([](int n) { return n > 20; });

    for (auto a : l1)
    {
        cout << a << ", ";
    }
    cout << endl;

}

/*
//std::list(양방향) 활용
int main()
{
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);

    list<int> l2{ 10, 20, 30, 40 };
    for (auto a : l2)
    {
        cout << a << ", ";
    }
    cout << endl;

    //다른 리스트와 연결
    l2.splice(l2.end(), l1);
    for (auto a : l2)
    {
        cout << a << ", ";
    }
    cout << endl;

    //정렬
    l2.sort();
    for (auto a : l2)
    {
        cout << a << ", ";
    }
    cout << endl;

    //중복 제거
    l2.unique();
    for (auto a : l2)
    {
        cout << a << ", ";
    }
    cout << endl;


}
*/

/*
template <typename T>
struct Node
{
    T data;
    Node* prev;     //현재 노드의 이전 노드
    Node* next;     //현재 노드의 다음 노드
};

template <typename T>
class DoubleLinkedList
{
private:
    int count;          //노드의 갯수
    Node<T>* header;       //리스트 앞부분 더미 노드
    Node<T>* trailer;       //리스트 뒷부분 더미 노드

public:
    //반복자(iterator) 클래스
    class iterator
    {
    private:
        Node<T>* ptr;
    public:
        //생성자
        iterator() : ptr(NULL) {}
        iterator(Node<T>* p) : ptr(p) {}

        T& operator*() { return ptr->data; }

        iterator& operator++() // ++it;
        {
            ptr = ptr->next;
            return *this;
        }

        iterator& operator--()  //--it
        {
            ptr = ptr->prev;
            return *this;
        }

        bool operator==(const iterator& it)
        {
            return ptr == it.ptr;
        }

        bool operator!=(const iterator& it)
        {
            return ptr != it.ptr;
        }

        friend class DoubleLinkedList;
    };

    //생성자
    DoubleLinkedList()
    {
        count = 0;
        header = new Node<T>{0, NULL, NULL};
        trailer = new Node<T>{ 0, NULL, NULL };
        header->next = trailer;
        trailer->prev = header;
    }

    //소멸자
    ~DoubleLinkedList()
    {
        //노드 메모리 해제
        while (!empty())
        {
            pop_front();
        }
        delete header;
        delete trailer;
    }

    //맨앞의 데이터 노드를 가진 iterator
    iterator begin()
    {
        return iterator(header->next);
    }

    //맨 뒤의 노드(trailer)를 가진 iterator
    iterator end()
    {
        return iterator(trailer);
    }


    //특정하는 iterator pos가 가진 노드(p)앞에 value값을 가진 노드 삽입하기
    void insert(const iterator& pos, T value)
    {
        //value값을 가진 노드를 생성
        Node<T>* p = pos.ptr;
        Node<T>* new_node = new Node<T>{ value, p->prev, p };
        new_node->prev->next = new_node;
        new_node->next->prev = new_node;
        count++;
    }

    //맨앞에 value값을 가진 노드 삽입하기
    void push_front(const T& value)
    {
        //헤더의 다음 node앞에 삽입하기
        insert(header->next, value);
    }

    //맨뒤에 value값을 가진 노드 삽입하기
    void push_back(const T& value)
    {
        //트레일러의 앞에 삽입하기
        insert(trailer, value);
    }

    //특정하는 iterator pos가 가진 노드(p)의 삭제
    void erase(const iterator& pos)
    {
        //10(p->prev) , 30(p->next)
        Node<T>* p = pos.ptr;
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        count--;
    }

    //맨앞에 있는 노드 삭제
    void pop_front()
    {
        //헤더의 next 노드 삭제
        if (!empty())
        {
            erase(header->next);
        }
    }


    //맨뒤에 있는 노드 삭제
    void pop_back()
    {
        //트레일러의 prev 노드 삭제
        if (!empty())
        {
            erase(trailer->prev);
        }
    }

    //데이터가 있는지 체크
    bool empty()
    {
        return count == 0;
    }

    //노드의 갯수
    int size()
    {
        return count;
    }

    //순서대로 노드에 있는 데이터 출력
    void print_all()
    {
        Node<T>* curr = header->next;          //맨앞 노드

        while (curr != trailer)
        {
            cout << curr->data << ", ";
            curr = curr->next;              //다음 노드로 이동
        }
        cout << endl;
    }

    //역순으로 노드에 있는 데이터 출력
    void print_reverse()
    {
        Node<T>* curr = trailer->prev;         //맨뒤 노드

        while (curr != header)
        {
            cout << curr->data << ", ";
            curr = curr->prev;              //이전 노드로 이동
        }
        cout << endl;
    }

    //특정 value를 갖는 iterator 찾기
    iterator find(const T& value)
    {
        Node<T>* curr = header->next;

        while (curr->data != value && curr != trailer)
        {
            curr = curr->next;
        }

        return iterator(curr);
    }

};



int main()
{
    //DoubleLinkedList dlList;
    //dlList.push_back(10);
    //dlList.push_back(20);
    //dlList.push_back(30);
    //dlList.print_all();
    //dlList.print_reverse();

    //dlList.pop_front();     //10제거
    //dlList.pop_back();      //30제거
    //dlList.print_all();

    //dlList.push_front(100);
    //dlList.push_back(300);
    //dlList.print_all();

    DoubleLinkedList<int> ll;
    ll.push_back(10);
    ll.push_back(20);
    ll.push_back(30);
    ll.print_all();

    auto it = ll.find(20);
    if (it != ll.end())
    {
        ll.insert(it, 50);
    }
    ll.print_all();
} 
*/

/*
struct Node
{
    int data;           //저장할 데이터
    Node* next;         //다음에 오는 노드
};

class LinkedList
{
private:
    Node* head;         //맨 앞에 있는 노드

public:
    //생성자
    LinkedList() : head(NULL) {};
    //소멸자
    ~LinkedList() 
    {
        //생성한 node의 메모리 해제
        while (!empty())
        {
            pop_front();
        }
    }

    //매개변수를 데이터(value)를 입력받아 리스트 맨앞에 삽입하기
    void push_front(int value)
    {
        //데이터(value)를 가진 노드 생성
        Node* new_node = new Node{ value, NULL };
               
        if (head != NULL)
        {
            new_node->next = head;
        }
        head = new_node;
    }

    //리스트 맨 앞에 있는 데이터 삭제하기
    void pop_front()
    {
        if (head == NULL)
            return;

        Node* first = head;
        head = head->next;
        delete first;
    }

    //리스트의 모든 노드 데이터 출력
    void print_all()
    {
        Node* curr = head;

        //curr가 null이 될때까지 반복
        while (curr != NULL)
        {
            //현재 curr 노드의 데이터를 출력
            cout << curr->data << ", ";

            //curr 노드가 다음 노드로 이동한다
            curr = curr->next;
        }
        cout << endl;
    }

    //데이터 유무
    bool empty()
    {
        return head == NULL;
    }
};


int main()
{
    LinkedList ll;
    ll.push_front(10);
    ll.push_front(20);
    ll.push_front(30);
    ll.print_all();

    ll.pop_front();
    ll.print_all();

    ll.push_front(40);
    ll.print_all();
}
*/
