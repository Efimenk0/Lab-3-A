#include "gtest/gtest.h"
#include "TernaryVectorLib/TernaryVectorLib.h"


/* --------------------------------------------------------- */
/*				    	  Конструкторы					 	 */
/* --------------------------------------------------------- */


// Пустой конструктор по умолчанию
TEST(Constructors, EmptyConstructor) {
	TernaryVectorClass::TernaryVector vector;
	EXPECT_EQ(0, vector.GetCurrentSize());
}

// Конструктор с инициализацией заданным кол-вом неопредленных значений с выбрасыванием исключений
TEST(Constructors, DefaultConstructor1) {
	TernaryVectorClass::TernaryVector vector(5);
	EXPECT_EQ(10, vector.GetMaxSize());
	EXPECT_EQ(5, vector.GetCurrentSize());
	for (int i = 0; i < vector.GetCurrentSize(); ++i)
		EXPECT_EQ('X', vector.GetValue(i));
	// Исключение при неположительном кол-ве неопределенных значений
	EXPECT_THROW(TernaryVectorClass::TernaryVector v(-1), std::exception);
	// Исключение при кол-ве неопределенных значений больших, чем максималтный размер вектора
	EXPECT_THROW(TernaryVectorClass::TernaryVector v(vector.GetMaxSize() + 1), std::exception);
}

// Констурктор с инициализацией значениями элементов вектора как строки символов
TEST(Constructors, DefaultConstructor2) {
	TernaryVectorClass::TernaryVector vector("102kc012");
	EXPECT_EQ(8, vector.GetCurrentSize());
	EXPECT_EQ('1', vector.GetValue(0));
	EXPECT_EQ('0', vector.GetValue(1));
	EXPECT_EQ('X', vector.GetValue(2));
	EXPECT_EQ('X', vector.GetValue(3));
	EXPECT_EQ('X', vector.GetValue(4));
	EXPECT_EQ('0', vector.GetValue(5));
	EXPECT_EQ('1', vector.GetValue(6));
	EXPECT_EQ('X', vector.GetValue(7));
	TernaryVectorClass::TernaryVector vector2("");
	EXPECT_EQ(0, vector2.GetCurrentSize());
	// Исключение в случае, когда длина первого слова в строке больше максимального размера массива
	EXPECT_THROW(TernaryVectorClass::TernaryVector v("20010l02001  wqw"), std::exception);
}


/* --------------------------------------------------------- */
/*				      Сеттеры - set'теры					 */
/* --------------------------------------------------------- */

// Инвертирование вектора
TEST(Setters, Invertion) {
	TernaryVectorClass::TernaryVector v("000111XXX");
	~v;
	EXPECT_EQ(9, v.GetCurrentSize());
	EXPECT_EQ('1', v.GetValue(0));
	EXPECT_EQ('1', v.GetValue(1));
	EXPECT_EQ('1', v.GetValue(2));
	EXPECT_EQ('0', v.GetValue(3));
	EXPECT_EQ('0', v.GetValue(4));
	EXPECT_EQ('0', v.GetValue(5));
	EXPECT_EQ('X', v.GetValue(6));
	EXPECT_EQ('X', v.GetValue(7));
	EXPECT_EQ('X', v.GetValue(8));
}


// Выполнение поразрядной конъюнкции данного вектора с другим 
TEST(Setters, Conjunction) {
	TernaryVectorClass::TernaryVector v1("000111XXX");
	std::string str = "01X01X01X";
	v1 &= str;
	EXPECT_EQ(9, v1.GetCurrentSize());
	EXPECT_EQ('0', v1.GetValue(0));
	EXPECT_EQ('0', v1.GetValue(1));
	EXPECT_EQ('0', v1.GetValue(2));
	EXPECT_EQ('0', v1.GetValue(3));
	EXPECT_EQ('1', v1.GetValue(4));
	EXPECT_EQ('X', v1.GetValue(5));
	EXPECT_EQ('0', v1.GetValue(6));
	EXPECT_EQ('X', v1.GetValue(7));
}

 // Выполнение порязрядной дизъюнкции данного вектора с другим
TEST(Setters, Disjunction) {
	TernaryVectorClass::TernaryVector v1("000111XXX");
	TernaryVectorClass::TernaryVector v2("01X01X01X");
	TernaryVectorClass::TernaryVector v3 = v1 | v2;
	EXPECT_EQ(9, v1.GetCurrentSize());
	EXPECT_EQ(9, v2.GetCurrentSize());
	EXPECT_EQ(9, v3.GetCurrentSize());
	EXPECT_EQ('0', v3.GetValue(0));
	EXPECT_EQ('1', v3.GetValue(1));
	EXPECT_EQ('X', v3.GetValue(2));
	EXPECT_EQ('1', v3.GetValue(3));
	EXPECT_EQ('1', v3.GetValue(4));
	EXPECT_EQ('1', v3.GetValue(5));
	EXPECT_EQ('X', v3.GetValue(6));
	EXPECT_EQ('1', v3.GetValue(7));
	EXPECT_EQ('X', v3.GetValue(8));
}

// Сравнение двух векторов
TEST(Setters, Compare) {
	TernaryVectorClass::TernaryVector v1("000111XX");
	TernaryVectorClass::TernaryVector v2("01X01X01");
	EXPECT_EQ(true, v1 == v1);
	EXPECT_EQ(false, v1 == v2);
	TernaryVectorClass::TernaryVector v3("01X01");
	EXPECT_EQ(false, v2 == v3);
	EXPECT_EQ(false, v1 == v3);
}

// Анализ неопределенности кода - возвращает индекс первой встреченной неопределенности, либо -1, если ее нет
TEST(Setters, Analysis) {
	TernaryVectorClass::TernaryVector v1("000111XX");
	TernaryVectorClass::TernaryVector v2("011010010");
	EXPECT_EQ(6, v1.Analysis());
	EXPECT_EQ(-1, v2.Analysis());
}




