#include "pch.h"
//#include "../base/OrderedTableOnArray.cpp"
#include "../base/OrderedTableOnArray.h"
#include "../base/OrderedTableOnArray.cpp"

TEST(OrderedTableOnArray, can_create_linear_table) //возможность создания таблицы
{
	ASSERT_NO_THROW(OrderedTableOnArray testTab);
}

TEST(OrderedTableOnArray, cant_insert_elem_with_same_name) //невозможность вставить полиномы с одинаковыми именами
{
	Data testData;
	string testStr1 = "x^5y^3z^2";
	string testStr2 = "y^2y";
	testData.polynomString = testStr1;
	Polynom tesPolynom(testStr1); // сделали первый

	testData.key = "test1";
	testData._polynom = tesPolynom;

	OrderedTableOnArray testTable; //табличку сделали
	testTable.insert(testData);

	testData.polynomString = testStr2;
	Polynom testP(testStr2);
	testData.key = "test1";
	testData._polynom = testP;
	ASSERT_ANY_THROW(testTable.insert(testData));
}

TEST(OrderedTableOnArray, cant_find_when_is_empty) //невозможность найти в пустой таблице
{
	OrderedTableOnArray testTable;
	string testString = "xyz";
	EXPECT_EQ(nullptr, testTable.find(testString));
}

TEST(OrderedTableOnArray, can_find_elem_in_tab) //возможность найти полином в таблице
{
	Data testData;
	string testStr1= "xyz";
	string tS = testStr1;
	string testName = "testPoly";
	testData.polynomString = testStr1;
	Polynom tesPolynom(testStr1);

	testData.key = testName;
	testData._polynom = tesPolynom;

	OrderedTableOnArray testTable;
	testTable.insert(testData);
	Data* testD = testTable.find(testName);
	EXPECT_EQ(tS, testD->polynomString);
}

TEST(OrderedTableOnArray, cant_find_elem_in_tab_when_it_isnt_there) //невозможность найти полином в таблице, когда его там нет (возврат nullptr)
{
	Data testData;
	string testStr1 = "x^5y^3z^2 + x^3y^3z^3 - 5x^2y^3z^2";
	testData.polynomString = testStr1;
	Polynom tesPolynom(testStr1);

	testData.key = "testPoly";
	testData._polynom = tesPolynom;

	OrderedTableOnArray testTab;
	testTab.insert(testData);
	EXPECT_EQ(nullptr, testTab.find("testP"));
}

TEST(OrderedTableOnArray, cant_delete_elem_when_its_empty) //невозможность удалить полином из пустой таблице
{
	OrderedTableOnArray testTab;
	ASSERT_ANY_THROW(testTab.deleteByKey("testPoly"));
}

TEST(OrderedTableOnArray, can_delete_existing_elem) //возможность удалить существующий полином
{
	Data testData;
	string testStr1 = "xyz";
	testData.polynomString = testStr1;
	Polynom tesPolynom(testStr1);

	testData.key = "tesPolynom";
	testData._polynom = tesPolynom;

	OrderedTableOnArray testTable;
	testTable.insert(testData);

	ASSERT_NO_THROW(testTable.deleteByKey("tesPolynom"));
}

TEST(OrderedTableOnArray, cant_delete_non_existing_elem) //невозможность удалить несуществующий полином
{
	Data testData;
	string testStr1 = "xyz";
	testData.polynomString = testStr1;
	Polynom testPoly(testStr1);

	testData.key = "tesPolynom";
	testData._polynom = testPoly;

	OrderedTableOnArray testTable;
	testTable.insert(testData);

	ASSERT_NO_THROW(testTable.deleteByKey("tesPolynom")); //ANY exseption
}
	
