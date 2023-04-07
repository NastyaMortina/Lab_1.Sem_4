#include "pch.h"
#include "../base/LineTable.h"
#include "../base/LineTable.cpp"

TEST(LineTable, can_create_linear_table)
{
	ASSERT_NO_THROW(LineTable testTab);
}

TEST(LineTable, can_insert_elem_in_tab) //возможность вставки полинома в таблицу
{
	Data testData;
	string testString = "10x^8y^2z^3 - 2x^2y^9z^4 + 50x^3y^7z^8";
	testData.polynomString = testString;
	Polynom testPol(testString);

	testData.key = "tesPolynom";
	testData._polynom = testPol;

	LineTable testTab;
	ASSERT_NO_THROW(testTab.insert(testData));
}

TEST(LineTable, can_insert_elem_in_tab_when_its_not_empty) //возможность вставить полином в таблицу, когда она не пустая
{
	Data testData;
	string testStr1 = "10x^8y^2z^3 - 2x^2y^9z^4 + 50x^3y^7z^8";
	string testStr2 = "y^2 +2x^2y + 3z^2y";
	testData.polynomString = testStr1;
	Polynom testPol1(testStr1);

	testData.key = "testPoli1";
	testData._polynom = testPol1;

	LineTable testTab;
	testTab.insert(testData);

	testData.polynomString = testStr2;
	Polynom testPol2(testStr2);
	testData.key = "testPol2";
	testData._polynom = testPol2;
	ASSERT_NO_THROW(testTab.insert(testData));
}

TEST(LineTable, cant_insert_elem_with_same_name) //невозможность вставить полиномы с одинаковыми именами
{
	Data testData;
	string testStr1 = "10x^8y^2z^3 - 2x^2y^9z^4 + 50x^3y^7z^8";
	string testStr2 = "y^2 +2x^2y + 3z^2y";
	testData.polynomString = testStr1;
	Polynom testPol1(testStr1);

	testData.key = "testPol";
	testData._polynom = testPol1;

	LineTable testTab;
	testTab.insert(testData);

	testData.polynomString = testStr2;
	Polynom testPol2(testStr2);
	testData.key = "testPol";
	testData._polynom = testPol2;
	ASSERT_ANY_THROW(testTab.insert(testData));
}

TEST(LineTable, cant_find_when_is_empty) //невозможность найти полином в пустой таблице (возврат nullptr)
{
	LineTable testTab;
	string testStr = "10x^8y^2z^3 - 2x^2y^9z^4 + 50x^3y^7z^8";
	EXPECT_EQ(nullptr, testTab.find(testStr));
}

TEST(LineTable, can_find_elem_in_tab) //возможность найти полином в таблице
{
	Data testData;
	string testString = "10x^8y^2z^3 - 2x^2y^9z^4 + 50x^3y^7z^8";
	string tS = testString;
	string testName = "tesPolynom";
	testData.polynomString = testString;
	Polynom testPol(testString);

	testData.key = testName;
	testData._polynom = testPol;

	LineTable testTab;
	testTab.insert(testData);
	Data* testD = testTab.find(testName);
	EXPECT_EQ(tS, testD->polynomString);
}

TEST(LineTable, cant_find_elem_in_tab_when_it_isnt_there) //невозможность найти полином в таблице, когда его там нет (возврат nullptr)
{
	Data testData;
	string testString = "10x^8y^2z^3 - 2x^2y^9z^4 + 50x^3y^7z^8";
	testData.polynomString = testString;
	Polynom testPol(testString);

	testData.key = "tesPolynom";
	testData._polynom = testPol;

	LineTable testTab;
	testTab.insert(testData);
	EXPECT_EQ(nullptr, testTab.find("testP"));
}

TEST(LineTable, cant_delete_elem_when_its_empty) //невозможность удалить полином, когда таблица пустая
{
	LineTable testTab;
	ASSERT_ANY_THROW(testTab.deleteByKey("A"));
}

TEST(LineTable, can_delete_existing_elem) //возможность удалить существующий полином
{	
	Data testData;
	string testString = "10x^8y^2z^3 - 2x^2y^9z^4 + 50x^3y^7z^8";
	testData.polynomString = testString;
	Polynom testPol(testString);

	testData.key = "tesPolynom";
	testData._polynom = testPol;

	LineTable testTab;
	testTab.insert(testData);

	ASSERT_NO_THROW(testTab.deleteByKey("tesPolynom"));
}

TEST(LineTable, cant_delete_non_existing_elem) //невозможность удалить несуществующий полином
{
	Data testData;
	string testString = "10x^8y^2z^3 - 2x^2y^9z^4 + 50x^3y^7z^8";
	testData.polynomString = testString;
	Polynom testPol(testString);

	testData.key = "tesPolynom";
	testData._polynom = testPol;

	LineTable testTab;
	testTab.insert(testData);
	ASSERT_ANY_THROW(testTab.deleteByKey("testP"));
}