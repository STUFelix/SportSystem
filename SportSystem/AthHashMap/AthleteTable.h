//
// Created by ������ on 2019-02-18.
//����ַ����HashMapʵ��(From JDK 1.8)
//���Զ����ݰ汾
//

#ifndef INC_2019SPRINGDSA_LINKEDHASHMAP_H
#define INC_2019SPRINGDSA_LINKEDHASHMAP_H
#include "../Athlete.h"
#include <stdbool.h>


typedef struct __Entry
{
	long hash;
	int key;
	Athlete* value;
	struct __Entry* next;
}Entry;

struct __AHashMap
{
	//array of Entry
	Entry* table[1048576];
	//Entry** table;
	int size;
	int capacity;
	
};

typedef struct __AHashMap* AthHashMap;



//��ȡָ����ֵ�����С2����
int minTwoPow(const int n);
//�õ������ڹ�ϣ���еĴ洢����
int getHashIndex(int key, AthHashMap map);
//��ʼ����ϣ��
AthHashMap InitHashMap(int capacity);

//�����洢�ڵ�
Entry* createEntry(int hash, int key, Athlete* value);

// ��һ��Ԫ�ط���Hash����
void HashMapPut(AthHashMap map, int key, Athlete* value);

//���ݼ�����HashMap�е�ֵ
Athlete* get_athlete(AthHashMap map, int key);

//�鿴�����Ƿ��ж�Ӧ��Key
bool HashMapContains(AthHashMap map, int key);

//����hash����key��value��ͬʱ���ؾɵ�value
Athlete* set_athlete(AthHashMap map, int key, Athlete* value);

//�Ƴ���ϣ���е�Ԫ��
void HashMapRemove(AthHashMap map, int key);
#endif //INC_2019SPRINGDSA_LINKEDHASHMAP_H