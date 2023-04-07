#include "pch.h"
#include "../base/UnorderedTableOnList.h"
#include "../base/UnorderedTableOnList.cpp"
TEST(UnorderedTableOnList, can_create_linear_table) //����������� �������� �������
{
	ASSERT_NO_THROW(UnorderedTableOnList testTable);
}

TEST(UnorderedTableOnList, can_insert_elem_in_tab_when_its_not_empty) //����������� ������� �������� � ������ ������� 
{
	Data testData;
	string testStr1 = "x^5y^3z^2";
	testData.polynomString = testStr1;
	Polynom tesPolynom(testStr1); // ������� ������

	testData.key = "test1";
	testData._polynom = tesPolynom;
	UnorderedTableOnList testTable; //�������� �������
	testTable.insert(testData);

	Data testDataTwo;
	string testStr2 = "xyz";
	testDataTwo.polynomString = testStr2;
	Polynom tesPolynomTwo(testStr2); // ������� ������

	testDataTwo.key = "test2";
	testDataTwo._polynom = tesPolynomTwo;
	ASSERT_NO_THROW(testTable.insert(testDataTwo));


}

TEST(UnorderedTableOnList, cant_insert_elem_with_same_name) //������������� �������� �������� � ����������� �������
{
	Data testData;
	string testStr1 = "x^5y^3z^2";
	testData.polynomString = testStr1;
	Polynom tesPolynom(testStr1); // ������� ������

	testData.key = "test1";
	testData._polynom = tesPolynom;
	UnorderedTableOnList testTable; //�������� �������
	testTable.insert(testData);

	Data testDataTwo;
	string testStr2 = "xyz";
	testDataTwo.polynomString = testStr2;
	Polynom tesPolynomTwo(testStr2); // ������� ������

	testDataTwo.key = "test1";
	testDataTwo._polynom = tesPolynomTwo;
	ASSERT_ANY_THROW(testTable.insert(testDataTwo));
}

TEST(UnorderedTableOnList, cant_find_when_is_empty) //������������� ����� � ������ �������
{
	UnorderedTableOnList testTab;
	string testStr = "xyz";
	EXPECT_EQ(nullptr, testTab.find(testStr));
}

TEST(UnorderedTableOnList, can_find_elem_in_tab) //����������� ����� ������� � �������
{
	Data testData;
	Data testData1;
	Data testData2;
	Data testData3;
	Polynom tesPolynom1("x+y");
	Polynom tesPolynom2("x+12+y");
	Polynom tesPolynom3("x+xyz");
	string testString = "x+5";
	string testS = testString;
	string testName = "name";
	testData.polynomString = testString;
	Polynom tesPolynom(testString);
	testData.key = testName;
	testData._polynom = tesPolynom;
	testData1.key = "A";
	testData1._polynom = tesPolynom1;
	testData2.key = "B";
	testData2._polynom = tesPolynom2;
	testData3.key = "C";
	testData3._polynom = tesPolynom3;
	UnorderedTableOnList testTab;
	testTab.insert(testData);
	testTab.insert(testData1);
	testTab.insert(testData2);
	testTab.insert(testData3);
	Data* testD = testTab.find(testName);
	EXPECT_EQ(testS, testD->polynomString);
}

TEST(UnorderedTableOnList, cant_find_elem_in_tab_when_it_isnt_there) //������������� ����� ������� � �������, ����� ��� ��� ��� (������� nullptr)
{
	Data testData;
	string testString = "xyz";
	testData.polynomString = testString;
	Polynom testPoly(testString);
	testData.key = "tesPolynom";
	testData._polynom = testPoly;
	UnorderedTableOnList testTab;
	testTab.insert(testData);
	EXPECT_EQ(nullptr, testTab.find("testP"));
}

TEST(UnorderedTableOnList, cant_delete_elem_when_its_empty) //������������� ������� ������� �� ������ �������
{
	UnorderedTableOnList testTab;
	ASSERT_ANY_THROW(testTab.deleteByKey("tesPolynom"));
}

TEST(UnorderedTableOnList, can_delete_existing_elem) //����������� ������� ������������ �������
{

	Data testData;
	string testString = "xyz";
	testData.polynomString = testString;
	Polynom testPoly(testString);
	testData.key = "tesPolynom";
	testData._polynom = testPoly;
	UnorderedTableOnList testTab;
	testTab.insert(testData);
	ASSERT_NO_THROW(testTab.deleteByKey("tesPolynom"));
}

TEST(UnorderedTableOnList, cant_delete_non_existing_elem) //������������� ������� �������������� �������
{
	//Data testData;
	//string testString = "xyz";
	//testData.polynomString = testString;
	//Polynom testPoly(testString);
	//testData.key = "tesPolynom";
	//testData._polynom = &testPoly;
	//UnorderedTableOnList testTab;
	//testTab.insert(testData);
	//ASSERT_ANY_THROW(testTab.deleteByKey("tesPolynom1"));
}