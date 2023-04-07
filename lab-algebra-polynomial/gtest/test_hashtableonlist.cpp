#include "pch.h"
#include "../base/HashTableOnList.h"
#include "../base/HashTableOnList.cpp"

TEST(HashTableOnList, can_create_hash_table) //возможность создать таблицу
{
	ASSERT_NO_THROW(HashTableOnList testTable);
}

TEST(HashTableOnList, can_insert_data) //возможность вставить полином
{
	Data testData;
	string testString = "xyz";
	testData.polynomString = testString;
	Polynom tesPolynom(testString);
	testData.key = "tesPolynom";
	testData._polynom = tesPolynom;
	HashTableOnList testTab;
	ASSERT_NO_THROW(testTab.insert(testData));
}

TEST(HashTableOnList, cant_insert_twice) //невозможность вставить дважды один и тот же полином
{
	Data testData;
	string testString = "xyz";
	testData.polynomString = testString;
	Polynom tesPolynom(testString);

	testData.key = "tesPolynom";
	testData._polynom = tesPolynom;

	HashTableOnList testTab;
	testTab.insert(testData);

	ASSERT_ANY_THROW(testTab.insert(testData));
}

TEST(HashTableOnList, cant_insert_data_with_same_name) //невозможность вставить полиномы с одинаковыми именами
{
	string testString = "xyz";
	string addS = "+2xz";
	HashTableOnList testTab;
	Data testData;
	string tS = testString;
	testData.polynomString = tS;
	Polynom tesPolynom(tS);
	testData.key = "tesPolynom";
	testData._polynom = tesPolynom;
	testTab.insert(testData);
	testString += addS;
	tS = testString;
	testData.polynomString = tS;
	Polynom tesPolynom1(tS);
	testData.key = "tesPolynom";
	testData._polynom = tesPolynom1;
	ASSERT_ANY_THROW(testTab.insert(testData));
}

TEST(HashTableOnList, can_find_existing_data) //возможность найти полином в таблице
{
	Data testData;
	string testString = "xyz";
	string tS = testString;
	int rightHash = 0;
	for (unsigned int i = 0; i < testString.size(); i++) { rightHash += (int)testString[i]; }
	rightHash *= testString.size();
	rightHash %= 1000;
	testData.polynomString = testString;
	Polynom testPoly(testString);
	testData.key = "tesPolynom";
	testData._polynom = testPoly;
	HashTableOnList testTab;
	testTab.insert(testData);
	Data* testAdd = testTab.find("tesPolynom");
	EXPECT_EQ(tS, testAdd->polynomString);
}

TEST(HashTableOnList, can_find_not_existing_data) //возвращение nullptr, если ничего не нашлось
{
	HashTableOnList testTable;
	EXPECT_EQ(nullptr, testTable.find("testData"));
}

TEST(HashTableOnList, can_delete_existing_data) //возможность удаления полинома
{
	HashTableOnList testTab;
	Data testData;
	string testString = "xyz";
	testData.polynomString = testString;
	Polynom testPoly(testString);
	testData.key = "tesPolynom";
	testData._polynom = testPoly;
	testTab.insert(testData);
	ASSERT_NO_THROW(testTab.deleteByKey("tesPolynom"));
}

TEST(HashTableOnList, cant_delete_not_existing_data) //возможность удаления полинома
{
	HashTableOnList testTab;
	Data testData;
	string testString = "xyz";
	testData.polynomString = testString;
	Polynom testPoly(testString);
	testData.key = "tesPolynom";
	testData._polynom = testPoly;
	testTab.insert(testData);
	ASSERT_ANY_THROW(testTab.deleteByKey("tesPolynom1"));
}

TEST(HashTableOnList, cant_delete_data_when_empty) //возможность удаления из пустой таблицы
{
	HashTableOnList testTable;
	ASSERT_ANY_THROW(testTable.deleteByKey("tesPolynom"));
}
