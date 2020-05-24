#include "C_Library.h"  /**< підключення файлу C_Library.h*/
#include"Conteiner.h"
#include "Test.h"/**< підключення файлу Test.h*/

bool Testvector()
{
	vector <int> vector = { 1, 2, 5, 3 };
	int vectorSize = vector.size();
	int count = 0;
	vector.push_back(1233);
	if (vectorSize < vector.size())
		count++;
	auto vectorItForDelete = vector.begin();
	vector.erase(vectorItForDelete);
	if (vectorSize == vector.size())
		count++;
	if (vector[1] == 5)
		count++;
	if (count == 3)
		return true;
	else
		return false;
}

bool Testlist()
{
	list <int> List = { 122, 13, -1215, 9345, 45 };
	int listSize = List.size();
	int count = 0;
	List.push_back(234);
	if (listSize < List.size())
		count++;
	std::list<int>::iterator listItForDelete = List.begin();
	List.erase(listItForDelete);
	if (listSize == List.size())
		count++;
	std::list<int>::iterator listItForGetObj = List.begin();
	if (List.begin() == listItForGetObj)
		count++;
	if (count == 3)
		return true;
	else
		return false;
}
bool Testset()
{
	set <int> Set = { 122, 13, -1215, 9345, 45 };
	int setSize = Set.size();
	int count = 0;
	Set.insert(234);
	if (setSize < Set.size())
		count++;
	std::set<int>::iterator setItForDelete = Set.begin();
	Set.erase(setItForDelete);
	if (setSize == Set.size())
		count++;
	std::set<int>::iterator setItForGetObj = Set.begin();
	if (Set.find(13) == setItForGetObj)
		count++;
	if (count == 3)
		return true;
	else
		return false;
}
bool Testmap()
{
	map <int, int> Map;
	Map.insert(std::pair<int, int>(1, 21));
	Map.insert(std::pair<int, int>(21, 2));
	Map.insert(std::pair<int, int>(-12, 221));
	Map.insert(std::pair<int, int>(78, 98));
	int mapSize = Map.size();
	int count = 0;
	Map.insert(std::pair<int, int>(12, 34));
	if (mapSize < Map.size())
		count++;
	std::map<int, int>::iterator mapItForDelete = Map.begin();
	Map.erase(mapItForDelete);
	if (mapSize == Map.size())
		count++;
	std::map<int, int>::iterator mapItForGetObj = Map.begin();
	if (Map.find(1) == mapItForGetObj)
		count++;
	if (count == 3)
		return true;
	else
		return false;
}