// SortTest.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

//탐색: 선형, 이진
//target을 찾으면 true, 못찾으면(데이터에 없다) false
bool linear_search(int data[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (data[i] == target)
        {
            return true;
        }
    }

    return false;
}

//이진탐색
bool binary_search(int data[], int n, int target)
{
    int lower = 0;
    int upper = n - 1;

    while (lower <= upper)
    {
        int middle = (lower + upper) / 2;

        if (data[middle] == target)
        {
            return true;
        }
        else if (data[middle] < target)
        {
            lower = middle + 1;
        }
        else
        {
            upper = middle - 1;
        }
    }

    return false;
}


int main()
{
    int data[] = {1, 2, 3, 5, 7, 10, 13, 15, 19, 23, 25, 27, 28, 30, 32, 33};
    //30찾기
    int target = 30;

    bool result1 = linear_search(data, size(data), target);
    bool result2 = binary_search(data, size(data), target);
    bool result3 = std::binary_search(begin(data), end(data), target);

    cout << result1 << endl;
    cout << result2 << endl;
    cout << result3 << endl;

}


/*
//std::sort 예제

//절대값 오름차순
bool abs_com(const int a, const int b)
{
    return std::abs(a) < std::abs(b);
}

struct AbsCmp {
    bool operator()(int a, int b)
    {
        return std::abs(a) < std::abs(b);
    }
};

class Person
{
public:
    string name;
    int age;

    bool operator<(const Person& a) const
    {
        return this->age < a.age;
    }

    void print() const
    {
        std::cout << name << ", " << age << endl;
    }
};


int main()
{
    vector<Person> v;
    v.push_back({"Amelia", 29});
    v.push_back({"Noah", 25 });
    v.push_back({"Olivia", 31 });
    v.push_back({"Shopi", 40 });
    v.push_back({"George", 35 });

    std::sort(v.begin(), v.end());

    for (const auto& p : v)
    {
        p.print();
    }


    //배열
    //int arr[5] = { 4, 2, 3, 5, 1 };
    //sort(arr, arr + 5);
    //sort(std::begin(arr), std::end(arr));
    //sort(begin(arr), end(arr), greater<>()); //내림차순
    //sort(std::begin(arr), std::end(arr), less<>()); //오름차순

    //for (const auto& n : arr)
    //{
    //    cout << n << ", ";
    //}
    //cout << endl;


    //vector
    //vector<string> vec = { "orange", "banana", "apple", "lemon" };
    //sort(vec.begin(), vec.end());
    //sort(vec.begin(), vec.end(), greater<>()); //내림차순

    //for (const auto& a : vec)
    //{
    //    cout << a << ", ";
    //}
    //cout << endl;

    //비교방법 정의하고 지정하기 : 절대값 오름차순
    //                           2, -3, 5, 7, 10
    //vector<int> nums = { 10, 2, -3, 5, 7 };
    //sort(nums.begin(), nums.end(), abs_com);
    //sort(nums.begin(), nums.end(), AbsCmp());
    //sort(nums.begin(), nums.end(), [](int a, int b) {
    //    return std::abs(a) < std::abs(b);
    //    });

    //for (const auto& a : nums)
    //{
    //    cout << a << ", ";
    //}
    //cout << endl;

}
*/


/*
//버블 정렬
void bubble_sort(int data[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (data[j] < data[j - 1])
            {
                swap(data[j], data[j - 1]);
            }
        }
    }
}

//선택 정렬
void selection_sort(int data[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int idx = i;    //정렬되지 않은 데이터중에 최소값을 가진 데이터의 인덱스
        for (int j = i + 1; j < n; j++)
        {
            if (data[j] < data[idx])
            {
                idx = j;
            }
        }
        swap(data[i], data[idx]);
    }
}

//삽입 정렬
void insertion_sort(int data[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = data[i];  //정렬되지 않은 데이터의 맨 왼쪽 값
        int j = i - 1;      //정렬되지 않은 데이터의 바로 앞 자리
        while (j >= 0 && data[j] > key)
        {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
}

//병합
int buff[256];

void merge(int data[], int left, int mid, int right)
{
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right)
    {
        if (data[i] <= data[j])
        {
            buff[k++] = data[i++];
        }
        else
        {
            buff[k++] = data[j++];
        }
    }

    //왼쪽에 데이터가 남아있으면
    while (i <= mid)
    {
        buff[k++] = data[i++];
    }

    //오른쪽 데이터가 남아있으면
    while (j <= right)
    {
        buff[k++] = data[j++];
    }

    //임시변수에 저장된 정렬된 데이터를 다시 옮기기
    for (int x = left; x <= right; x++)
    {
        data[x] = buff[x];
    }
}

//병합 정렬
// left: 정렬할 데이터의 맨 앞, right: 정렬할 데이터의 맨 뒤
void merge_sort(int data[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        merge_sort(data, left, mid);
        merge_sort(data, mid + 1, right);
        merge(data, left, mid, right);
    }
}

//분할
int partition(int data[], int left, int right)
{
    int pivot = data[left];
    int i = left + 1;
    int j = right;

    while (true)
    {
        //i의 위치를 pivot 보다 큰값까지 이동
        while (data[i] <= pivot && i <= right)
        {
            i++;
        }

        //j의 위치를 pivot 보다 작은값까지 이동
        while (data[j] > pivot && j > left)
        {
            j--;
        }

        //이동이 완료되면
        if (i < j)
        {
            swap(data[i], data[j]);
        }
        else
        {
            break;
        }
    }
    swap(data[left], data[j]);

    return j;
}

//퀵 정렬
void quic_sort(int data[], int left, int right)
{
    if (left < right)
    {
        int p = partition(data, left, right);
        quic_sort(data, left, p - 1);
        quic_sort(data, p + 1, right);
    }
}



int main()
{
    int data[] = { 5, 6, 7, 3, 1, 9, 2, 4, 8 };
    quic_sort(data, 0, size(data) - 1);

    for (auto n : data)
    {
        std::cout << n << ", ";
    }
    std::cout << endl;


    //int data[] = {2, 6, 7, 4, 1, 8, 5, 3 };
    //merge_sort(data, 0, 7);

    //for (auto n : data)
    //{
    //    cout << n << ", ";
    //}
    //cout << endl;

    //int data[] = { 4, 2, 3, 5, 1 };
    ////bubble_sort(data, 5);
    ////selection_sort(data, 5);
    //insertion_sort(data, 5);

    //for (auto n : data)
    //{
    //    cout << n << ", ";
    //}
    //cout << endl;

}
*/