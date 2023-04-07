#include "pch.h"
#include "../base/SearchTreeTable.h"
#include "../base/SearchTreeTable.cpp"
TEST(SearchTreeTable, can_create_linear_table)
{
	ASSERT_NO_THROW(SearchTreeTable testTable);
}

TEST(SearchTreeTable, can_insert_elem_in_tab) //возможность вставки полинома в таблицу
{
	Data testData;
	string testStr1= "xyz";
	testData.polynomString = testStr1;
	Polynom tesPolynom(testStr1);

	testData.key = "testPoly";
	testData._polynom = tesPolynom;

	SearchTreeTable testTable;
	ASSERT_NO_THROW(testTable.insert(testData));
}

TEST(SearchTreeTable, can_insert_elem_in_tab_when_its_not_empty) //возможность вставить полином в таблицу, когда она не пустая
{
	Data testData;
	string testStr1 = "xyz";
	testData.polynomString = testStr1;
	Polynom tesPolynom(testStr1);

	testData.key = "tesPolynom1";
	testData._polynom = tesPolynom;

	SearchTreeTable testTable;
	testTable.insert(testData);

	string testStr2 = "2xyz";
	testData.polynomString = testStr2;
	Polynom tesPolynom2(testStr2);
	testData.key = "tesPolynom2";
	testData._polynom= tesPolynom2;
	ASSERT_NO_THROW(testTable.insert(testData));
}

TEST(SearchTreeTable, cant_insert_elem_with_same_name) //невозможность вставить полиномы с одинаковыми именами
{
	Data testData;
	string testStr1 = "xyz";
	string testStr2 = "2xyz";
	testData.polynomString = testStr1;
	Polynom tesPolynom(testStr1);

	testData.key = "tesPolynom";
	testData._polynom = tesPolynom;

	SearchTreeTable testTable;
	testTable.insert(testData);

	testData.polynomString = testStr2;
	Polynom testP(testStr2);
	testData.key = "tesPolynom";
	testData._polynom = testP;
	ASSERT_ANY_THROW(testTable.insert(testData));
}

TEST(SearchTreeTable, cant_find_when_is_empty) //невозможность найти полином в пустой таблице (возврат nullptr)
{
	SearchTreeTable testTable;
	string testStr1 = "xyz";
	EXPECT_EQ(nullptr, testTable.find(testStr1));
}

TEST(SearchTreeTable, can_find_elem_in_tab) //возможность найти полином в таблице
{
	Data testData;
	string testStr1 = "xyz";
	string tS = testStr1;
	string testName = "tesPolynom";
	testData.polynomString = testStr1;
	Polynom tesPolynom(testStr1);

	testData.key = testName;
	testData._polynom = tesPolynom;

	SearchTreeTable testTable;
	testTable.insert(testData);
	Data* testD = testTable.find(testName);
	EXPECT_EQ(tS, testD->polynomString);
}

TEST(SearchTreeTable, cant_find_elem_in_tab_when_it_isnt_there) //невозможность найти полином в таблице, когда его там нет (возврат nullptr)
{

	Data testData;
	string testStr1 = "xyz";
	testData.polynomString = testStr1;
	Polynom tesPolynom(testStr1);
	testData.key = "tesPolynom";
	testData._polynom = tesPolynom;
	SearchTreeTable testTab;
	testTab.insert(testData);
	EXPECT_EQ(nullptr, testTab.find("tesPolynom2"));
}

TEST(SearchTreeTable, cant_delete_elem_when_its_empty) //невозможность удалить полином, когда таблица пустая
{
	SearchTreeTable testTable;
	ASSERT_ANY_THROW(testTable.deleteByKey("tesPolynom"));
}

TEST(SearchTreeTable, can_delete_existing_elem) //возможность удалить существующий полином
{
	Data testData;
	string testStr1 = "xyz";
	testData.polynomString = testStr1;
	Polynom tesPolynom(testStr1);

	testData.key = "tesPolynom";
	testData._polynom = tesPolynom;

	SearchTreeTable testTable;
	testTable.insert(testData);

	ASSERT_NO_THROW(testTable.deleteByKey("tesPolynom"));
}

TEST(SearchTreeTable, cant_delete_non_existing_elem) //невозможность удалить несуществующий полином
{
	Data testData;
	string testStr1 = "xyz";
	testData.polynomString = testStr1;
	Polynom tesPolynom(testStr1);

	testData.key = "tesPolynom1";
	testData._polynom = tesPolynom;

	SearchTreeTable testTable;
	testTable.insert(testData);
	ASSERT_ANY_THROW(testTable.deleteByKey("tesPolynom2"));
}