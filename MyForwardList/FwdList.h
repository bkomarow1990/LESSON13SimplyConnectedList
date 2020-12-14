#pragma once
#define MY_DEBUG
#include <iostream>
using namespace std;
template<typename T>
class FwdList
{
public:
	FwdList() = default;
	void pushFront(const T& data);
	void print()const;
	void eraseFront();
	void pushAfter(const T& searchData,const T& data);
	void clear();
	void eraseAfter(const T& searchData);
	void eraseTail();
	void addTail(const T& data);

	~FwdList();
private:
	auto findNode(const T& data);
	struct Node {
		T data;
		Node* next;
		Node(const T& data,Node* next = nullptr) 
			:data(data),next(next)
		{}
	};
	Node* head=nullptr;
	Node* tail=nullptr;
	const bool isEmpty()const;
};

template<typename T>
inline void FwdList<T>::pushFront(const T& data)
{
	Node* tmp = new Node(data, head);
	if (isEmpty())
	{
		tail = tmp;
	}
	head = tmp;

}

template<typename T>
inline void FwdList<T>::print() const
{
	Node* tmp = head;
	while (tmp!=nullptr)
	{
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	cout << endl;
}

template<typename T>
inline void FwdList<T>::eraseFront()
{
	if (!isEmpty())
	{
		auto tmp = head;
		head = head->next;
		if (isEmpty())
		{
			tail = nullptr;
		}
#ifdef MY_DEBUG
		cout << "Was deleted " << tmp->data << endl;
#endif 
		delete tmp;
	}
}

template<typename T>
inline void FwdList<T>::pushAfter(const T&searchData,const T& data)
{
	Node* find = findNode(searchData);
	if (find!=nullptr)
	{
		Node* ins = new Node(data, find->next);
		find->next = ins;
		if (find == tail)
		{
			tail = ins;
		}
	}
}

template<typename T>
inline void FwdList<T>::clear()
{
	while (!isEmpty())
	{
		eraseFront();
	}
}

template<typename T>
inline void FwdList<T>::eraseAfter(const T& searchData)
{
	Node* find = findNode(searchData);
	if (find!=nullptr )
	{
		if (find->next!=nullptr)
		{
			auto tmp = find->next;
			find->next = tmp->next;
			delete tmp;
		}
			
	
	
	}
}

template<typename T>
inline void FwdList<T>::eraseTail()
{
	Node* tmp=head;
	if (!isEmpty())
	{
		while (next!=tail)
		{
			tmp = next;
		}
		tmp->
	}
}

template<typename T>
inline void FwdList<T>::addTail(const T& data)
{
	Node* add = new Node(data);
	if (!isEmpty)
	{
		tail->next = add;
	}
	else {
		head = add;
	}
	tail = add;
}

template<typename T>
inline FwdList<T>::~FwdList()
{
	clear();
}

template<typename T>
inline auto FwdList<T>::findNode(const T& data)
{
	Node* tmp = head;
	while (tmp!=nullptr && tmp->data!=data)
	{
		tmp = tmp->next;
	}
	return tmp;
}



template<typename T>
inline const bool FwdList<T>::isEmpty() const
{
	return head==nullptr;
}
