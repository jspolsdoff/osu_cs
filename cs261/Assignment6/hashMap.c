#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "hashMap.h"



/*the first hashing function you can use*/
int stringHash1(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += str[i];
	return r;
}

/*the second hashing function you can use*/
int stringHash2(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += (i+1) * str[i]; /*the difference between stringHash1 and stringHash2 is on this line*/
	return r;
}

/* initialize the supplied hashMap struct*/
void _initMap (struct hashMap * ht, int tableSize)
{
	int index;
	if(ht == NULL)
		return;
	ht->table = (hashLink**)malloc(sizeof(hashLink*) * tableSize);
	ht->tableSize = tableSize;
	ht->count = 0;
	for(index = 0; index < tableSize; index++)
		ht->table[index] = NULL;
}

/* allocate memory and initialize a hash map*/
hashMap *createMap(int tableSize) {
	assert(tableSize > 0);
	hashMap *ht;
	ht = malloc(sizeof(hashMap));
	assert(ht != 0);
	_initMap(ht, tableSize);
	return ht;
}

/*
 Free all memory used by the buckets.
 Note: Before freeing up a hashLink, free the memory occupied by key and value
 */
void _freeMap (struct hashMap * ht)
{  
	/*write this*/	
	struct hashLink *bucket;
	struct hashLink *temp;

	// go through all buckets
	for (int i = 0; i < ht->tableSize; i++) {
		bucket = ht->table[i];

		// go through bucket and free memory
		while (bucket != NULL) {
			// set up next bucket
			temp = bucket->next;
			free(bucket);
			bucket = temp;
		}
	}
	free(ht->table);
}

/* Deallocate buckets and the hash map.*/
void deleteMap(hashMap *ht) {
	assert(ht!= 0);
	/* Free all memory used by the buckets */
	_freeMap(ht);
	/* free the hashMap struct */
	free(ht);
}

/* 
Resizes the hash table to be the size newTableSize 
*/
void _setTableSize(struct hashMap * ht, int newTableSize)
{
	/*write this*/	
	struct hashLink **oldTable = ht->table;
	int oldSize = ht->tableSize;

	_initMap(ht, newTableSize);

	for (int i = 0; i < oldSize; i++) {
		struct hashLink *current = oldTable[i];

		while (current != NULL) {
			struct hashLink *temp = current->next;
			insertMap(ht, current->key, current->value);
			free(current);
			current = temp;
		}
	}
	// free up memory from the old table
	free(oldTable);
	printf("The number of buckets in the bigger table: %d\n", ht->tableSize);
}

/*
 insert the following values into a hashLink, you must create this hashLink but
 only after you confirm that this key does not already exist in the table. For example, you
 cannot have two hashLinks for the word "taco".
 
 if a hashLink already exists in the table for the key provided you should
 replace that hashLink--this requires freeing up the old memory pointed by hashLink->value
 and then pointing hashLink->value to value v.
 
 also, you must monitor the load factor and resize when the load factor is greater than
 or equal LOAD_FACTOR_THRESHOLD (defined in hashMap.h).
 */
void insertMap (struct hashMap * ht, KeyType k, ValueType v)
{  
	/*write this*/	
	
	/* insertMap Version 1
	int hashIndex;

	if (HASHING_FUNCTION == 1)
		hashIndex = stringHash1(k) % ht->tableSize;
	if (HASHING_FUNCTION == 2)
		hashIndex = stringHash2(k) % ht->tableSize;

	// no bucket
	if (ht->table[hashIndex] == NULL) {
		struct hashLink *newLink = malloc(sizeof(struct hashLink));
		newLink->next = NULL;
		newLink->key = k;
		newLink->value = v;

		// move newLink into the table
		ht->table[hashIndex] = newLink;
		ht->count++;
	}

	// there is a bucket 
	else {
		// if the key doesn't exist then add to front of list
		if (containsKey(ht, k) == 0) {
			struct hashLink *newLink = malloc(sizeof(struct hashLink));
			newLink->next = ht->table[hashIndex];
			newLink->key = k;
			newLink->value = v;
			
			ht->table[hashIndex] = newLink;
			ht->count++;
		}
		// the key exist so replace the value
		else {
			struct hashLink *hashItr = ht->table[hashIndex];

			while (hashItr != NULL) {
				if (strcmp(hashItr->key, k) == 0) {
					// free(hashItr->value);
					hashItr->value = v;
				}
				hashItr = hashItr->next;
			}
		}
	}

	// check to see if the table needs to be resized
	if (tableLoad(ht) >= LOAD_FACTOR_THRESHOLD)
		_setTableSize(ht, 2 * ht->tableSize);
	*/ 

	int hashIndex;

	if (HASHING_FUNCTION == 1)
		hashIndex = stringHash1(k) % ht->tableSize;
	if (HASHING_FUNCTION == 2)
		hashIndex = stringHash2(k) % ht->tableSize;

	if (containsKey(ht, k)) {
		struct hashLink *hashItr = ht->table[hashIndex];

		while (hashItr != NULL) {
			if (strcmp(hashItr->key, k) == 0) {
				hashItr->value = v;
			}
		}
	}

	else {
		// create link
		struct hashLink *newLink = malloc(sizeof(struct hashLink));
		newLink->next = ht->table[hashIndex];
		newLink->key = k;
		newLink->value = v;

		// add to table
		ht->table[hashIndex] = newLink;
		ht->count++;

		// check load
		if (tableLoad(ht) >= LOAD_FACTOR_THRESHOLD)
			_setTableSize(ht, (ht->tableSize * 2));
	}

	return;
}

/*
 this returns the value (which is void*) stored in a hashLink specified by the key k.
 
 if the user supplies the key "taco" you should find taco in the hashTable, then
 return the value member of the hashLink that represents taco.
 
 if the supplied key is not in the hashtable return NULL.
 */
ValueType* atMap (struct hashMap * ht, KeyType k)
{ 
	/*write this*/
	if (containsKey(ht, k)) {
		int hashIndex;
		struct hashLink *hashItr;

		if (HASHING_FUNCTION == 1)
			hashIndex = stringHash1(k) % ht->tableSize;
		if (HASHING_FUNCTION == 2)
			hashIndex = stringHash2(k) % ht->tableSize;

		
		hashItr = ht->table[hashIndex];

		while (hashItr != NULL) {
			if (strcmp(hashItr->key, k) == 0) {
				return &hashItr->value;
			}

			hashItr = hashItr->next;
		}
	}

	return NULL;
}

/*
 a simple yes/no if the key is in the hashtable. 
 0 is no, all other values are yes.
 */
int containsKey (struct hashMap * ht, KeyType k)
{  
	/*write this*/
	int hashIndex;
	struct hashLink *hashItr;

	if (HASHING_FUNCTION == 1)
		hashIndex = stringHash1(k) % ht->tableSize;
	if (HASHING_FUNCTION == 2)
		hashIndex = stringHash2(k) % ht->tableSize;

	if (ht->table[hashIndex] != NULL) {
		hashItr = ht->table[hashIndex];

		while (hashItr != NULL) {
			if (strcmp(hashItr->key, k) == 0) {
				return 1;
			}
			hashItr = hashItr->next;
		}
	}

	return 0;
}

/*
 find the hashlink for the supplied key and remove it, also freeing the memory
 for that hashlink. it is not an error to be unable to find the hashlink, if it
 cannot be found do nothing (or print a message) but do not use an assert which
 will end your program.
 */
void removeKey (struct hashMap * ht, KeyType k)
{  
	/*write this*/
	/*
	if (containsKey(ht, k) == 1) {
		int hashIndex;
		struct hashLink *hashItr;
		struct hashLink *temp;

		if (HASHING_FUNCTION == 1)
			hashIndex = stringHash1(k) % ht->tableSize;
		if (HASHING_FUNCTION == 2)
			hashIndex = stringHash2(k) % ht->tableSize;
			
		hashItr = ht->table[hashIndex];

			while (hashItr != NULL) {
				if (strcmp(hashItr->next->key, k) == 0) {
					temp = hashItr->next;
					hashItr->next = hashItr->next->next;
					free(temp);
					return;
				}
				hashItr = hashItr->next;
			}
		
	}
	*/
	return;
}

/*
 returns the number of hashLinks in the table
 */
int size (struct hashMap *ht)
{  
	/*write this*/
	return ht->count;
	
}

/*
 returns the number of buckets in the table
 */
int capacity(struct hashMap *ht)
{  
	/*write this*/
	return ht->tableSize;
}

/*
 returns the number of empty buckets in the table, these are buckets which have
 no hashlinks hanging off of them.
 */
int emptyBuckets(struct hashMap *ht)
{  
	/*write this*/
	int empty = 0;

	for (int i = 0; i < ht->tableSize; i++) {
		if (ht->table[i] == NULL)
			empty++;
	}

	return empty;
}

/*
 returns the ratio of: (number of hashlinks) / (number of buckets)
 
 this value can range anywhere from zero (an empty table) to more then 1, which
 would mean that there are more hashlinks then buckets (but remember hashlinks
 are like linked list nodes so they can hang from each other)
 */
float tableLoad(struct hashMap *ht)
{  
	/*write this*/
	return ((float)ht->count / ht->tableSize);
}
void printMap (struct hashMap * ht)
{
	int i;
	struct hashLink *temp;	
	for(i = 0;i < capacity(ht); i++){
		temp = ht->table[i];
		if(temp != 0) {		
			printf("\nBucket Index %d -> ", i);		
		}
		while(temp != 0){			
			printf("Key:%s|", temp->key);
			printValue(temp->value);
			printf(" -> ");
			temp=temp->next;			
		}		
	}
}


