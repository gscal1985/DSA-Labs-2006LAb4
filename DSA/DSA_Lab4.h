#pragma once

#if LAB_4
#include <list>
#include <cstdio> 
using namespace std;

class DSA_Lab4 {

	friend class TestSuite;	// Giving access to test code

	// Data members
	list<float> mList;
	void Clear() {
		mList.clear();
	};
private:

	struct mNode
	{
		int value;
		int data;
		mNode * nextPtr;
		mNode(float val)
		{
			value = val;
			nextPtr = NULL;
		}
		
	};

	mNode* createListFromArray(const float* ptr, int arraySize)
	{
		mNode* nodePtr = NULL;
		mNode* rootNodePtr = NULL;
		mNode* lastNodePtr = NULL;
		for (int i = 0; i < arraySize; i++)
		{
			if (!nodePtr)
			{
				nodePtr = new mNode(*(ptr + i));
				if (!rootNodePtr)
					rootNodePtr = nodePtr;
				if (lastNodePtr)
					lastNodePtr->nextPtr = nodePtr;
			}
			lastNodePtr = nodePtr;
			nodePtr = nodePtr->nextPtr;
		}
		return rootNodePtr;
	}

	void destroyList(mNode* ptr)
	{
		if (ptr)
		{
			mNode* pNext = ptr->nextPtr;
			delete ptr;
			destroyList(pNext);
		}
	};
	void displayLinkedList(mNode* ptr)
	{
		while (ptr != NULL)
		{
		    ptr->value ;
			ptr = ptr->nextPtr;
		}
		std::cout << std::endl;
	};

	void nodeAtBegining(mNode** head, float insertData)
	{
		
		mNode* currentPos = new  mNode;
		currentPos->data = insertData;
		currentPos->nextPtr = NULL;
		if (*head == NULL)

			*head = currentPos;
		else {
			currentPos->nextPtr = *head;
			*head = currentPos;
		}

	};

	void displayHead(mNode**head) {
		mNode* temp = *head;
		while (temp!=NULL)
		{
			if (temp->nextPtr!=NULL)
			
				temp->data;
			
			else
			
				temp->data;
			
			temp = temp->nextPtr;
		}
	};
	mNode* getNodeTail(mNode *n) {
		while (n!=NULL && n->nextPtr!=NULL)
		
			n = n->nextPtr;
			return n;
		
	};
	mNode* splitList(mNode *head, mNode *end, mNode **newHead, mNode **newEnd) {
		mNode* pivot = end;
		mNode* prev = NULL, * cur = head, * tail = pivot;

		// During partition, both the head and end of the list might change
		// which is updated in the newHead and newEnd variables
		while (cur != pivot)
		{
			if (cur->data < pivot->data)
			{
				// First node that has a value less than the pivot - becomes
				// the new head
				if ((*newHead) == NULL)
					(*newHead) = cur;

				prev = cur;
				cur = cur->nextPtr;
			}
			else // If cur LLNode is greater than pivot
			{
				// Move cur LLNode to next of tail, and change tail
				if (prev)
					prev->nextPtr = cur->nextPtr;
				mNode* tmp = cur->nextPtr;
				cur->nextPtr= NULL;
				tail->nextPtr = cur;
				tail = cur;
				cur = tmp;
			}
		}
		//still working on this

		// If the pivot data is the smallest element in the current list,
		// pivot becomes the head
		if ((*newHead) == NULL)
			(*newHead) = pivot;

		// Update newEnd to the current last node
		(*newEnd) = tail;

		// Return the pivot LLNode
		return pivot;
	};
	mNode* quickSortRecursion(mNode *head, mNode *end) {
		if (!head || head == end)
			return head;
		mNode* newHead = NULL, * newEnd = NULL;
		mNode* pivot = splitList(head, end, &newHead, &newEnd);

		if (newHead != pivot)
		{
			mNode* tmp = newHead;
			while (tmp->nextPtr != pivot)
				tmp = tmp->nextPtr;
			tmp->nextPtr = NULL;

			newHead = quickSortRecursion(newHead, tmp);
			tmp = getNodeTail(newHead);
			tmp->nextPtr = pivot;
			
		}
		pivot->nextPtr = quickSortRecursion(pivot->nextPtr,newEnd);
		return newHead;


	};
	void quickSorterer(mNode **headRefStart) {
		(*headRefStart) = quickSortRecursion(*headRefStart, getNodeTail(*headRefStart)); return;
	};
	
public:
	
	// Add all of the values from the array into the list using queue ordering
	//
	// In:	_arr			The array of values
	//		_size			The number of elements in the array
	//
	// Note: Make sure the list is empty and shrunk to 0 capacity before adding values
	void QueueOrderingAdd(const float* _arr, int _size) {
		
		Clear();
		mNode* mPointer = createListFromArray(_arr, sizeof(_arr)/sizeof(_size));
		displayLinkedList(mPointer);
		destroyList(mPointer);
		mNode* head = NULL;
		mNode* tail = NULL;

		nodeAtBegining(&head, _size);
		quickSorterer(&head);
		displayHead(&head);
	
	}

	// Add all of the values from the array into the list using queue ordering
	//
	// In:	_arr			The array of values
	//		_size			The number of elements in the array
	//
	// Note: Make sure the list is empty and shrunk to 0 capacity before adding values
	void StackOrderingAdd(const float* _arr, int _size) {
		
	}

	// Remove a single value from the list using queue ordering
	//
	// Return: The value that was removed
	float QueueOrderingRemove() {
		
	}

	// Remove a single value from the list using stack ordering
	//
	// Return: The value that was removed
	float StackOrderingRemove() {
		
	}

	// Insert a value _index nodes away from the head node
	//		If _index is 0 - insert in front of the head/front node
	//		If _index is 5 - insert in front of the 5th node in the list
	//
	// Example:	
	//			0<-[5]<->[1]<->[6]<->[4]<->[2]->0
	//	
	// Inserting a 7 at index 2
	//
	//			0<-[5]<->[1]<->[7]<->[6]<->[4]<->[2]->0
	//
	//
	// In:	_val		The value to insert
	//		_index		The "index" to add at
	void Insert(float _val, int _index) {
		
	}

	// Insert a value at the spot specified by the iterator passed in
	// 
	// In:	_val		The value to insert
	//		_iter		The iterator at the place to insert
	void Insert(float _val, list<float>::iterator _iter) {
		
	}

	// Remove all values from mList that have a decimal place value larger than _decimal 
	//		Example:   
	//					_decimal: 0.45
	//
	//					mList: 498.28			// not removed, because .28 is not greater than .45
	//						   39812.181		// not removed, because .181 is not greater than .45
	//						   983.498			// removed, because .498 is greater than .45
	//						   3981.89			// removed, because .89 is greater than .45
	//						   487.2			// not removed, because .2 is not greater than .45
	//
	//					With these values, the function would return 2
	//
	// In:	_decimal		The decimal value to check against (always less than 1.0)
	//
	// Return: The total number of values removed
	int RemoveDecimalGreater(float _decimal) {
		
	}
};

#endif

