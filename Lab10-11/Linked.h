//#pragma once
//#include <vector>
//#include <iostream>
//template<typename ElementType>
//class LinkedList
//{
//private:
//	struct node {
//		ElementType data;
//		node *next;
//		node()noexcept : next{ NULL } {}
//	};
//	node* start;
//	int len;
//public:
//	LinkedList() noexcept:start{ NULL }, len{0} {}
//	~LinkedList() {
//		node* copie = start;
//		for (int i = 1; i <= len-1; i++)
//		{
//			copie=start-> next;
//			delete start;
//			start = copie;
//		}
//		delete start;
//		start = NULL;
//		len = 0;
//
//	}
//	void add(ElementType NextData) {
//		node* nextelem=new node;
//		nextelem->data = NextData;
//		nextelem->next = NULL;
//
//		if(len==0) start = nextelem;
//		else { 
//			node* copie = start;
//			while (copie->next != NULL)
//				copie = copie->next;
//			copie->next= nextelem; 
//		}
//		len++;
//	}
//	void del(ElementType Data) {
//		node * copie = start;
//		node* copy = NULL;
//		if (start->data == Data)
//		{
//			copy = start;
//			start = start->next;
//		}
//		else {
//			while (!(copie->next->data == Data))
//				copie = copie->next;
//			copy = copie->next;
//			copie->next = copie->next->next;
//		}
//		delete copy;
//		len--;
//	}
//	void upd(ElementType Data, ElementType NewData) {
//		node * copie = start;
//		while (!(copie->data == Data))
//			copie = copie->next;
//		copie->data = NewData;
//	}
//	ElementType getElem(int poz)noexcept {
//		node* copie = start;
//		for (int i = 0; i < poz; i++)
//		{
//			copie = copie->next;
//		}
//		return copie->data;
//	}
//	int getLen()noexcept {
//		return len;
//	}
//	std::vector<ElementType> getVector() {
//		std::vector<ElementType> vect;
//		for (int i = 0; i < len; i++)
//			vect.push_back(getElem(i));
//		return vect;
//	}
//};