// BtsTest.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

//노드: 정수형 데이터를 가진 트리 자료구조
struct Node
{
    int data;
    Node* left;
    Node* right;

    //생성자
    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};

//이진 탐색 트리
class BinarySearchTree
{
private:
    Node* root = nullptr;

public:
    BinarySearchTree() {}
    ~BinarySearchTree() {}

    void insert(int value)
    {
        if (!root)
        {
            root = new Node(value);
        }
        else
        {   
            insert_impl(root, value);
        }
    }

    //중위순회하여 데이터 출력
    void inorder()
    {
        inorder_impl(root);
    }

    //value 데이터를 가진 노드 찾기
    Node* find(int value)
    {
        return find_impl(root, value);
    }

    //value 데이터를 가진 노드 삭제
    void erase(int value)
    {
        root = erase_impl(root, value);
    }

private:
    //value 값에 알맞은 자리찾아서 넣는다
    void insert_impl(Node* curr, int value)
    {
        if (value < curr->data) //curr의 왼쪽에 데이터를 넣는다
        {
            if (!curr->left)    //curr->left nullptr 이면 노드를 생성하여 넣는다
            {
                curr->left = new Node(value);
            }
            else
            {
                insert_impl(curr->left, value);
            }
        }
        else //curr의 오른쪽에 데이터를 넣는다
        {
            if (!curr->right)   //curr->right nullptr 이면 노드를 생성하여 넣는다
            {
                curr->right = new Node(value);
            }
            else
            {
                insert_impl(curr->right, value);
            }
        }
    }

    //중위순회하여 데이터 출력: 왼쪽->노드->오른쪽
    void inorder_impl(Node* node)
    {
        if (node)
        {
            inorder_impl(node->left);
            cout << node->data << ", ";
            inorder_impl(node->right);
        }
    }

    //value 데이터를 가진 노드 찾기
    Node* find_impl(Node* node, int value)
    {
        if (node == nullptr)
            return nullptr;

        if (value == node->data)
        {
            return node;
        }
        else
        {
            if (value < node->data)
            {
                return find_impl(node->left, value);
            }
            else
            {
                return find_impl(node->right, value);
            }
        }
    }

    //후속 노드 찾기
    Node* successor(Node* node)
    {
        auto curr = node->right;
        while (curr && curr->left)
            curr = curr->left;

        return curr;
    }



    //노드 삭제후, 부모 포인터가 가리켜야할 노도의 주소를 반환
    Node* erase_impl(Node* node, int value)
    {
        //해당 노드가 없는 경우
        if (!node)
        {
            return nullptr;
        }


        if (value == node->data) //현재 노드 삭제
        {
            //자식 노드가 둘다 있는 경우
            if (node->left && node->right)
            {
                //후속 노드를 찾아서 값 복사 후 후속 노드를 삭제
                auto succ = successor(node);
                node->data = succ->data;
                //후속 노드를 삭제
                node->right = erase_impl(node->right, succ->data);
            }
            else //하나만 있거나 없는 경우,  left nullptr, nullptr right, nullptr nullptr
            {
                auto tmp = node->left ? node->left : node->right;
                delete node;
                return tmp;
            }
        }
        else
        {
            if (value < node->data) //삭제할 노드가 왼쪽 트리에 있다
            {
                node->left = erase_impl(node->left, value);
            }
            else //삭제할 노드가 오른쪽 트리에 있다
            {
                node->right = erase_impl(node->right, value);
            }
        }

        return node;
    }

};



int main()
{
    //이진탐색 트리 만들기
    BinarySearchTree bts;
    bts.insert(10);
    bts.insert(14);
    bts.insert(5);
    bts.insert(7);
    bts.insert(18);
    bts.insert(4);
    bts.insert(6);
    bts.insert(20);
    bts.insert(16);

    //출력: 중위순회 
    bts.inorder();
    cout << endl;

    //탐색
    // 7을 노드 찾기
    if (bts.find(7))
    {
        cout << "7 is found!!!" << endl;
    }
    else
    {
        cout << "7 is not found!!!" << endl;
    }

    // 15을 노드 찾기
    if (bts.find(15))
    {
        cout << "15 is found!!!" << endl;
    }
    else
    {
        cout << "15 is not found!!!" << endl;
    }


    bts.insert(9);
    bts.insert(12);
    bts.inorder();
    cout << endl;

    bts.erase(4);
    bts.erase(5);
    bts.erase(14);
    bts.inorder();
    cout << endl;

    bts.insert(15);
    bts.erase(10);
    bts.inorder();
    cout << endl;

}
