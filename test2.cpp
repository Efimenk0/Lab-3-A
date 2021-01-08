#include "gtest/gtest.h"
#include "TernaryVectorLib/TernaryVectorLib.h"


/* --------------------------------------------------------- */
/*				    	  ������������					 	 */
/* --------------------------------------------------------- */


// ������ ����������� �� ��������� � ������������� ����������
TEST(Constructors, EmptyConstructor) {
	TernaryVectorClass::TernaryVector v;
	EXPECT_EQ(0, v.GetSize());
	EXPECT_EQ(nullptr, v.GetMasAdress());
}

// ����������� � �������������� �������� ���-��� ������������� �������� � ������������� ���������� (����� ��������� � ����� �������) 
TEST(Constructors, DefaultConstructor1) {
	TernaryVectorClass::TernaryVector v(10);
	EXPECT_EQ(10, v.GetSize());
	for (int i = 0; i < v.GetSize(); ++i)
		EXPECT_EQ('X', v.GetValue(i));
	// ������������� ������� ������������� ������ 
	EXPECT_THROW(TernaryVectorClass::TernaryVector v(-5), std::exception);
}

// ����������� � �������������� ���������� ��������� ������� ��� ������ ��������
TEST(Constructors, DefaultConstructor2) {
	std::string str = "211wkd0a  rewjn2";
	TernaryVectorClass::TernaryVector v(str);
	EXPECT_EQ('X', v.GetValue(0));
	EXPECT_EQ('1', v.GetValue(1));
	EXPECT_EQ('1', v.GetValue(2));
	EXPECT_EQ('X', v.GetValue(3));
	EXPECT_EQ('X', v.GetValue(4));
	EXPECT_EQ('X', v.GetValue(5));
	EXPECT_EQ('0', v.GetValue(6));
	EXPECT_EQ('X', v.GetValue(7));
}


// ���� ����������� ������������
TEST(COPY, CopyConstructor) {
	TernaryVectorClass::TernaryVector v1("1X00X1010X");
	TernaryVectorClass::TernaryVector v2(v1);
	EXPECT_EQ(false, v1.GetMasAdress() == v2.GetMasAdress());
	EXPECT_EQ(10, v2.GetSize());
	EXPECT_EQ('1', v2.GetValue(0));
	EXPECT_EQ('X', v2.GetValue(1));
	EXPECT_EQ('0', v2.GetValue(2));
	EXPECT_EQ('0', v2.GetValue(3));
	EXPECT_EQ('X', v2.GetValue(4));
	EXPECT_EQ('1', v2.GetValue(5));
	EXPECT_EQ('0', v2.GetValue(6));
	EXPECT_EQ('1', v2.GetValue(7));
	EXPECT_EQ('0', v2.GetValue(8));
	EXPECT_EQ('X', v2.GetValue(9));
}

/* --------------------------------------------------------- */
/*				      ������� - set'����					 */
/* --------------------------------------------------------- */

// // ���������� ����������� ���������� ������� ������� � ������
TEST(Setters, Disjunction) {
	std::string str1 = "000111XX";
	TernaryVectorClass::TernaryVector v1(str1);
	std::string str2 = "01X01X01";
	TernaryVectorClass::TernaryVector v2(str2);
	TernaryVectorClass::TernaryVector v3 =  v1 | v2;
	EXPECT_EQ('0', v3.GetValue(0));
	EXPECT_EQ('1', v3.GetValue(1));
	EXPECT_EQ('X', v3.GetValue(2));
	EXPECT_EQ('1', v3.GetValue(3));
	EXPECT_EQ('1', v3.GetValue(4));
	EXPECT_EQ('1', v3.GetValue(5));
	EXPECT_EQ('X', v3.GetValue(6));
	EXPECT_EQ('1', v3.GetValue(7));
}



// ���������� ����������� ���������� ������� ������� � ������ 
TEST(Setters, Conjunction) {
	std::string str1 = "000111XX";
	TernaryVectorClass::TernaryVector v1(str1);
	std::string str2 = "01X01X01";
	TernaryVectorClass::TernaryVector v2(str2);
	v1 &= v2;
	EXPECT_EQ('0', v1.GetValue(0));
	EXPECT_EQ('0', v1.GetValue(1));
	EXPECT_EQ('0', v1.GetValue(2));
	EXPECT_EQ('0', v1.GetValue(3));
	EXPECT_EQ('1', v1.GetValue(4));
	EXPECT_EQ('X', v1.GetValue(5));
	EXPECT_EQ('0', v1.GetValue(6));
	EXPECT_EQ('X', v1.GetValue(7));
}


// �������������� �������
TEST(Setters, Invertion) {
	std::string str = "000111XX";
	TernaryVectorClass::TernaryVector v(str);
	~v;
	EXPECT_EQ('1', v.GetValue(0));
	EXPECT_EQ('1', v.GetValue(1));
	EXPECT_EQ('1', v.GetValue(2));
	EXPECT_EQ('0', v.GetValue(3));
	EXPECT_EQ('0', v.GetValue(4));
	EXPECT_EQ('0', v.GetValue(5));
	EXPECT_EQ('X', v.GetValue(6));
	EXPECT_EQ('X', v.GetValue(7));
}

// ��������� ���� �������� (���������� ������ ������� ������������, ���� -1, ���� ������� ���������)
TEST(Setters, Compare) {
	std::string str1 = "000111XX";
	TernaryVectorClass::TernaryVector v1(str1);
	std::string str2 = "01X01X01";
	TernaryVectorClass::TernaryVector v2(str2);
	EXPECT_EQ(false, v1 == v2);
	std::string str3 = "01X01X01";
	TernaryVectorClass::TernaryVector v3(str3);
	EXPECT_EQ(false, v1 == v3);
	EXPECT_EQ(true, v2 == v3);
}

// ������ ���������������� ���� - ���������� ������ ������ ����������� ����������������, ���� -1, ���� �� ���
TEST(Setters, Analysis) {
	std::string str1 = "000111XX";
	TernaryVectorClass::TernaryVector v1(str1);
	std::string str2 = "011010010";
	TernaryVectorClass::TernaryVector v2(str2);
	EXPECT_EQ(6, v1.Analysis());
	EXPECT_EQ(-1, v2.Analysis());
}



