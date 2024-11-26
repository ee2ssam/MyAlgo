// QueueTest.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <list>
#include <queue>

using namespace std;

//배열로 환형 큐 구현
template <typename T>
class CircularQueue
{
private:
	T* arr;				//데이터가 저장될 배열
	int front_idx;		//맨 앞 데이터의 인덱스
	int rear_idx;		//맨 마지막 데이터의 인덱스
	int count;			//큐에 들어간 데이터의 갯수
	int capacity;		//큐의 용량(데이터가 들어갈수 있는 총량)

public:
	//생성자
	CircularQueue(int sz)
	{
		arr = new T[sz];
		capacity = sz;
		count = 0;
		front_idx = 0;
		rear_idx = -1;
	}
	//소멸자
	~CircularQueue()
	{
		delete[] arr;
	}

	//맨 마지막 위치에 데이터 넣기
	void enqueue(const T& e)
	{
		//풀 체크
		if (full())
		{
			cout << "Overflow error!" << endl;
			return;
		}

		//넣을 자리 구한다
		//rear_idx++;
		//if (rear_idx == capacity) rear_idx = 0;

		rear_idx = (rear_idx + 1) % capacity;
		arr[rear_idx] = e;
		count++;
	}

	//맨 처음에 위치한 데이터 삭제
	void dequeue()
	{
		//데이터 유무 체크
		if (empty())
		{
			cout << "Underflow error!" << endl;
			return;
		}

		//front_idx의 위치를 오른쪽으로 이동한다
		front_idx = (front_idx + 1) % capacity;
		count--;
	}


	const T& front() const
	{
		return arr[front_idx];
	}

	bool empty() const
	{
		return count == 0;
	}

	bool full() const
	{
		return count == capacity;
	}

	int size() const
	{
		return count;
	}

};


int main()
{
	CircularQueue<int> q(5);

	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.dequeue();
	q.dequeue();

	q.enqueue(60);
	q.enqueue(70);

	q.enqueue(80);

	//q 출력
	while (!q.empty())
	{
		auto& e = q.front();
		cout << e << ", ";
		q.dequeue();
	}
	cout << endl;

}


/*
template <typename T>
class Queue
{
private:
	list<T> lst;

public:
	Queue() {}

	void enqueue(const T& e)
	{
		lst.push_back(e);
	}

	void dequeue()
	{
		lst.pop_front();
	}

	const T& front() const
	{
		return lst.front();
	}

	bool empty() const
	{
		return lst.empty();
	}

	int size() const
	{
		return lst.size();
	}

};


int main()
{
	
	//Queue<int> q;
	//q.enqueue(10);
	//q.enqueue(20);
	//q.enqueue(30);
	//q.dequeue();

	//cout << q.front() << endl;
	//q.enqueue(40);

	////큐에 내용 모두 출력
	//while (!q.empty())
	//{
	//	auto& e = q.front();
	//	cout << e << ", ";
	//	q.dequeue();
	//}
	//cout << endl;
	

	queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);
	q.pop();

	cout << q.front() << endl;
	q.push(40);

	while (!q.empty())
	{
		auto& e = q.front();
		cout << e << ", ";
		q.pop();
	}
	cout << endl;


}
*/