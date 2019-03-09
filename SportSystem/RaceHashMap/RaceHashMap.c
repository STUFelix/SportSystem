//
// Created by 黎钰晖 on 2019-02-18.
//
#include "RaceHashMap.h"


//获取指定数值后的最小2的幂
int get_rcapacity(const int n)
{
	return (int)pow(2, ceil(log(n) / log(2)));
}

//得到对象在哈希表中的存储索引
int getHashIndex(RaceItem* obj, RaceItemHashMap map)
{
	return obj->eventsID % map->capacity;
}

//初始化哈希表
RaceItemHashMap init_raceitem_map(int capacity)
{
	RaceItemHashMap map = (RaceItemHashMap)malloc(sizeof(struct __RHashMap));
	map->size = 0;
	map->capacity = get_rcapacity(capacity);
	map->hashIndex = getHashIndex;
	//map->table = malloc(sizeof(REntry)*capacity);
	for (int i = 0; i < map->capacity; ++i) {
		map->table[i] = NULL;
	}
	return map;
}

//创建存储节点
REntry* create_race_entry(int hash, KeyType key, ValueType value)
{
	REntry* entry = (REntry*)malloc(sizeof(struct _REntry));
	if (entry == NULL) exit(-1);
	entry->hash = hash;
	entry->key = key;
	entry->value = value;
	entry->next = NULL;
	return entry;
}

// 把一个元素放入Hash表中
void add_raceitem_map(RaceItemHashMap map, KeyType key, ValueType value)
{
	//通过绑定的hash函数计算出Hash值
	int index = 0;
	index = map->hashIndex((void*)key, map);
	//如果Hash表位置没有被占用,则添加进位置中
	if (map->table[index] == NULL)
	{
		map->table[index] = create_race_entry(index, key, value);
		map->size++;
	}
	//如果hash值已经存在了
	else
	{
		REntry* entry = map->table[index];
		REntry* newNode = create_race_entry(index, key, value);
		newNode->next = entry;
		map->table[index] = newNode;
		map->size++;
	}
}

//根据键查找HashMap中的值
ValueType get_raceitem(RaceItemHashMap map, KeyType key)
{
	//计算并得到哈希链表的入口
	int index = map->hashIndex((void*)key, map);
	REntry* entryList = map->table[index];
	//在链表中寻找
	while (entryList != NULL)
	{

		if (entryList->key == key)
		{
			return entryList->value;
		}
		if (entryList->next != NULL)
			entryList = entryList->next;
		else
			return NULL;
	}
	//查找不到，返回空
	return NULL;
}

//查看表中是否有对应的Key
bool contains_raceitem(RaceItemHashMap map, KeyType key)
{
	int index = map->hashIndex((void*)key, map);
	REntry* node = map->table[index];
	while (node != NULL)
	{
		if (key == node->key)
			return true;
		else
		{
			if (node->next != NULL)
				node = node->next;
			else
				return false;
		}
	}
	return false;

}

//设置hash表中key的value，同时返回旧的value
ValueType set_raceitem_map(RaceItemHashMap map, KeyType key, ValueType value)
{
	int index = map->hashIndex(key, map);
	//创建虚拟头节点
	REntry* dummyHead = (REntry*)malloc(sizeof(REntry));
	dummyHead->next = map->table[index];
	REntry* node = dummyHead;
	while (node != NULL)
	{
		//如果匹配key，则记录旧值
		if (node->key == key)
		{
			ValueType oldVal = node->value;
			node->value = value;
			return oldVal;
		}
		node = node->next;

	}
	free(dummyHead);

	return NULL;
}