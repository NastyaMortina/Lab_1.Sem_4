#include "pch.h"
#include "../base/HashTableSomething.h"
#include "../base/HashTableSomething.cpp"

TEST(HashTableSomething, can_create_hash_table) //возможность создания таблицы
{
	ASSERT_NO_THROW(HashTableSomething testTable);
}

TEST(HashTableSomething, can_insert_data) //возможность вставить полином
{
	Data testData;
	string testString = "xyz";
	testData.polynomString = testString;
	Polynom tesPolynom(testString);
	testData.key = "tesPolynom1";
	testData._polynom = tesPolynom;
	HashTableSomething testTable;
	ASSERT_NO_THROW(testTable.insert(testData));
}

TEST(HashTableSomething, cant_insert_twice) //невозможность вставить дважды один и тот же полином
{
	Data testData;
	string testString = "xyz";
	testData.polynomString = testString;
	Polynom testPoly(testString);
	testData.key = "tesPolynom";
	testData._polynom = testPoly;
	HashTableSomething testTab;
	testTab.insert(testData);
	ASSERT_ANY_THROW(testTab.insert(testData));
}

TEST(HashTableSomething, cant_insert_data_with_same_name) //невозможность вставить полиномы с одинаковыми именами
{
	string testString = "xyz+z";
	string addS = "+2xz";
	HashTableSomething testTab;
	Data testData;
	string tS = testString;
	testData.polynomString = tS;
	Polynom testPoly(tS);
	testData.key = "tesPolynom";
	testData._polynom = testPoly;
	testTab.insert(testData);
	testString += addS;
	tS = testString;
	testData.polynomString = tS;
	Polynom testPoly1(tS);
	testData.key = "tesPolynom";
	testData._polynom = testPoly1;
	ASSERT_ANY_THROW(testTab.insert(testData));
}

TEST(HashTableSomething, cant_find_anything) //возвращение nullptr, если ничего не нашлось
{
	HashTableSomething testTab;
	EXPECT_EQ(nullptr, testTab.find("testData"));
}

TEST(HashTableSomething, can_find_data) //возможность найти полином в таблице
{
	Data testData;
	string testString = "xyz";
	string tS = testString;
	int rightHash = 0;
	for (unsigned int i = 0; i < testString.size(); i++) 
	{ 
		rightHash += (int)testString[i]; 
	}
	rightHash *= testString.size();
	rightHash %= 1000;
	testData.polynomString = testString;
	Polynom tesPolynom(testString);
	testData.key = "tesPolynom";
	testData._polynom = tesPolynom;
	HashTableSomething testTab;
	testTab.insert(testData);
	Data* testAdd = testTab.find("tesPolynom");
	EXPECT_EQ(tS, testAdd->polynomString);
}
//возможность удаления полинома 
TEST(HashTableSomething, can_delete_data) {
	HashTableSomething testTable;

	Data testData;
	string testString = "y^2 +2x^2y + 3z^2y";
	testData.polynomString = testString;
	Polynom tesPolynom(testString);

	testData.key = "tesPolynom";
	testData._polynom = tesPolynom;

	testTable.insert(testData);
	ASSERT_NO_THROW(testTable.deleteByKey("tesPolynom"));
}

TEST(HashTableSomething, cant_delete_data_when_empty) //возможность удаления пустой таблицы
{
	HashTableSomething testTab;
	ASSERT_ANY_THROW(testTab.deleteByKey("testPoly"));
}