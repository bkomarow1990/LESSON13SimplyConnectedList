#pragma once
#define MY_DEBUG
#include <iostream>
using namespace std;
template<typename T>
class FwdList
{
public:
	FwdList() = default;
	void pushFront(const T& data); //addtoHead
	void print()const; // Show
	void eraseFront();
	void pushAfter(const T& searchData,const T& data);// вставка нового елемента після заданого
	void clear();
	void eraseAfter(const T& searchData);
	void eraseTail(); //deleteFromTail 
	size_t findAndReplace(const T& searchData,const T& data);
	void addTail(const T& data); //addToTail
	void deleteElemWithData(const T& data);
	void reverseList();
	FwdList(const FwdList& other);
	FwdList& operator=(const FwdList& other);
	bool operator==(const FwdList& other);
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
	
	if (!isEmpty())
	{
		Node* tmp = head;
		if (tmp->next==nullptr)
		{
			tail = nullptr;
			head = nullptr;
			return;
		}
		while (tmp->next != tail)
		{
			tmp = tmp->next;
		}
		delete tmp->next;
		tail = tmp;
		tmp->next = nullptr;
	//delete tmp->next;
	//	delete tmp->next;
	
	}

}

template<typename T>
inline size_t FwdList<T>::findAndReplace(const T& searchData, const T& data)
{
	size_t count = 0;
	if (isEmpty())
	{
		return 0;
	}
	Node* tmp = head;
	
	while (tmp != tail)
	{
		if (tmp->data==searchData)
		{
			tmp->data = data;
			++count;
		}
		tmp = tmp->next;
	}
	if (tail->data == searchData)
	{
		tail->data = data;
		++count;
	}
	return count;
}

template<typename T>
inline void FwdList<T>::addTail(const T& data)
{
	Node* add = new Node(data);
	if (!isEmpty())
	{
		tail->next = add;
	}
	else {
		head = add;
	}
	tail = add;
}

template<typename T>
inline void FwdList<T>::deleteElemWithData(const T& data)
{
	if (isEmpty())
	{
		return;
	}
	Node* tmp = head;
	while (tmp != nullptr && tmp->next->data != data)
	{
		tmp = tmp->next;
	}
	if (tmp != nullptr)
	{
	
		if (tmp->next!=tail)
		{
			tmp->next=tmp->next->next;
		}
		else if (tmp==head && tmp->next==tail)
		{
			tail = nullptr;
			head = nullptr;
		}
		else {
			tail = nullptr;
		}
	}
	tmp = nullptr;
}

template<typename T>
inline void FwdList<T>::reverseList()
{
	if (isEmpty())
	{
		return;
	}
	if (head->next==nullptr)
	{
		return;
	}
	Node* tmp=head;
	Node* tmp2=nullptr;
	Node* list;
	while (tmp!=nullptr)
	{
		list = tmp;
		tmp = tmp->next;
		list->next = tmp2;
		tmp2 =list ;
	}
	head = tmp2;
	}

template<typename T>
inline FwdList<T>::FwdList(const FwdList& other)
{
//	this->addTail(other.head->data);
	Node* tmp = other.head;
	while (tmp!=nullptr)
	{
		this->addTail(tmp->data);
		tmp = tmp->next;
	}

}

template<typename T>
inline FwdList<T>& FwdList<T>::operator=(const FwdList& other)
{
	Node* tmp = other.head;
	while (tmp != nullptr)
	{
		this->addTail(tmp->data);
		tmp = tmp->next;
	}
	return *this;
}

template<typename T>
inline bool FwdList<T>::operator==(const FwdList& other)
{
	if (isEmpty() || other.isEmpty() )
	{
		return false;
	}
	Node* tmp = head;
	Node* other_tmp = other.head;
	while (tmp!=nullptr)
	{
		if (tmp->data != other_tmp->data)
		{
			return false;
		}
		tmp=tmp->next;
		other_tmp=other_tmp->next;
	}
	return true;
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
