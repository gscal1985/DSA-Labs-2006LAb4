// Dictionary.h - A hash-mapped data structure using key/value pairs
//				  and separate chaining

#pragma once

/************/
/* Includes */
/************/
#include <list>
using namespace std;

#if LAB_7

template<typename Key, typename Value>
class Dictionary {

	friend class TestSuite;	// Giving access to test code

	// The objects stored in the hash-table
	struct Pair {
		Key key;			// The key for insertion/lookup
		Value value;		// The data

		// Constructor
		//
		// In:	_key		The key value used for insertion/lookup
		//		_value		The value stored at the key
		Pair(const Key& _key, const Value& _value) {

		}

		// Is-equals operator used for testing
		//
		// In:	_comp		The Pair to compare with
		//
		// Return:	True, if they are equal
		// NOTE:	DO NOT CHANGE THIS CODE
		bool operator==(const Pair& _comp) {
			return (_comp.key == key &&
				_comp.value == value);
		}
	};

	// Data members
	list<Pair>* mTable;						// A dynamic array of lists (these are the buckets)
	unsigned int mNumBuckets;				// Number of elements in mTable
	unsigned int(*mHashFunc)(const Key&);	// Pointer to the hash function

public:

	// Constructor
	//
	// In:	_numBuckets			The number of elements to allocate
	//		_hashFunc			The hashing function to be used
	Dictionary(unsigned int _numBuckets, unsigned int (*_hashFunc)(const Key&)) {

	}

	// Destructor
	//			Cleans up any dynamically allocated memory
	~Dictionary() {

	}

	// Copy constructor
	//			Used to initialize one object to another
	// In:	_copy				The object to copy from
	Dictionary(const Dictionary& _copy) {
		*this = _dict;
	}

	// Assignment operator
	//		Used to assign one object to another
	// In:	_assign				The object to assign from
	//
	// Return: The invoking object (by reference)
	//		This allows us to daisy-chain
	Dictionary& operator=(const Dictionary& _assign) {

	}

	// Clear
	//		Clears all internal data being stored
	//  NOTE:	Does not delete table or reset hash function
	void Clear() {

	}

	// Insert an item into the table
	//
	// In:	_key				The key to hash with
	//		_pair				The value stored at the key
	//
	// NOTE:	If there is already an item at the provided key, overwrite it.
	void Insert(const Key& _key, const Value& _value) {

	}

	// Find a value at a specified key
	//
	// In:	_key				The key to hash with
	//
	// Return: A const pointer to the value at the searched key
	// NOTE:		Return a null pointer if key is not present
	const Value* Find(const Key& _key) {

	}

	// Remove a Pair at the supplied key
	//
	// In:	_key				The key to hash with
	//
	// Return:	True, if a Pair was removed
	bool Remove(const Key& _key) {

	}
};

#endif