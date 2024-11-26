// StackTest.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

//매개변수로 입력 받은 문자열을 뒤집어 반환
string reverse(const string& str)
{
    stack<char> stk;

    for (char c : str)
    {
        stk.push(c);
    }

    string result;

    while (!stk.empty())
    {
        result += stk.top();
        stk.pop();
    }

    return result;
}

//매개변수로 들어온 vector 데이터를 뒤집어 저장
template <typename T>
void reverse(vector<T>& vec)
{
    stack<T> stk;

    for (auto e : vec)
    {
        stk.push(e);
    }

    for (int i = 0; i < vec.size(); i++)
    {
        vec[i] = stk.top();
        stk.pop();
    }
}

//매개변수로 들어온 괄호 문자열을 받아 올바른 괄호인지 체크
bool paren_check(const string& str)
{
    stack<char> stk;

    for (char c : str)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            stk.push(c);
        }
        else //닫는 괄호인 경우 ), }, ] 스택의 top과 비교
        {
            if (stk.empty())
                return false;

            if (stk.top() == '(' && c == ')'
                || stk.top() == '{' && c == '}'
                || stk.top() == '[' && c == ']')
            {
                stk.pop();
            }
        }
    }
        
    return stk.empty();
}


int main()
{
    /*
    string str1 = "HELLO";
    string str2 = "ALGORITHM";

    cout << str1 << " -> " << reverse(str1) << endl;
    cout << str2 << " -> " << reverse(str2) << endl;

    //
    vector<int> vec1{ 10, 20, 30, 40, 50 };
    // -> 50, 40, 30, 20, 10
    reverse<int>(vec1);

    for (auto e : vec1)
    {
        cout << e << ", ";
    }
    cout << endl;
    */

    cout << paren_check("(){}[]") << endl;
    cout << paren_check("((((()))))") << endl;
    cout << paren_check("(){[]}") << endl;

    cout << paren_check("((({}))") << endl;
    cout << paren_check(")(") << endl;
    cout << paren_check("({)}") << endl;
}

/*
template <typename T>
class Stack
{
private:
    vector<T> v;

public:
    Stack() {}

    void push(const T& e)
    {
        v.push_back(e);
    }

    void pop()
    {
        v.pop_back();
    }

    const T& top() const
    {
        return v.back();
    }

    bool empty() const
    {
        return v.empty();
    }

    int size() const
    {
        return v.size();
    }
};

int main()
{
    stack<int> stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.pop();
    cout << stk.top() << endl;

    stk.push(40);

    //스택에 있는 모든 내용 출력
    while (!stk.empty())
    {
        auto e = stk.top();
        cout << e << ", ";

        stk.pop();
    }
    cout << endl;

}
*/