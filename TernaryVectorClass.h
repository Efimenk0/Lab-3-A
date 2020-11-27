#ifndef TERNARYVECTORCLASS_H_
#define TERNARYVECTORCLASS_H_



#include <stdio.h>
#include <iostream>
#include <exception>
#include <ctime>
#include <string>


namespace TernaryVectorClass {


	// ������ ������� �������� ����� ������ ���� ������ (1 � ������ �������, � 0 ��� ������)
	template <class T>
	int getType(T& a, std::istream& stream) {
		int rc = 0;
		stream >> a;
		if (!stream.good())
			rc = 1;				// ���������� ������ �����
		stream.clear();
		stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return rc;
	};

	// ������ ������� ��� ����� ����� �� �������� ������
	template<class T>
	void input_Type(T& p, std::istream& istream, std::ostream& ostream) {
		while (getType(p, istream))
			ostream << "����������, ��������� ����: --> ";
	}


	// ����� "�������� �������"
	class TernaryVector {
	private:

		// ������������ ������ ��������� �������
		static const int SZ = 10;

		// ������� ������ �������, �� ����������� SZ
		int top;

		// �������� ������
		// ��������: 0 - ����; 1 - ������; X - �������������� �������� (ASCII ��� 88)
		char vector[SZ];

	public:

		/* --------------------------------------------------------- */
		/*				    	  ������������					 	 */
		/* --------------------------------------------------------- */


		// ������ ����������� �� ���������
		TernaryVector() :top(0) {};

		// ����������� � �������������� �������� ���-��� ������������� ��������
		TernaryVector(int);

		// ����������� � �������������� ���������� ��������� ������� ��� ������ ��������
		TernaryVector(const std::string&);

		/* --------------------------------------------------------- */
		/*				      ������� - set'����					 */
		/* --------------------------------------------------------- */

		// �������������� �������
		TernaryVector& Invertion();

		// ���������� ����������� ���������� ������� ������� � ������ (������� ��������)
		TernaryVector& Conjunction(const TernaryVector&);

		/* --------------------------------------------------------- */
		/*						 ������ ������						 */
		/* --------------------------------------------------------- */

		// ���������� ����������� ���������� ������� ������� � ������ (�������� ��������)
		// �������� ������ ����������� ����, ��� ��� ������� - ���� ������
		friend const TernaryVector Disjunction(const TernaryVector&, const TernaryVector&);

		// ��������� ���� �������� (���������� ������ ������� ������������, ���� -1, ���� ������� ��������� � -2, ���� ������� �������� �� ���������)
		friend const int Compare(const TernaryVector&, const TernaryVector&);

		// ������ ���������������� ���� - ���������� ������ ������ ����������� ����������������, ���� -1, ���� �� ���
		int Analysis() const;

		/* --------------------------------------------------------- */
		/*						 ������ ������ 						 */
		/* --------------------------------------------------------- */

		// ����� ��������� ������� �� �������� ������ (� ��������� ������������� ����������)
		friend std::istream& operator >> (std::istream&, TernaryVector&);

		// ����� �������� ������� � �������� �����
		friend std::ostream& operator << (std::ostream&, const TernaryVector&);

	};

	// ����� ���, ������������ � ����������, ����� ������� ���������� � .cpp ����� ��� ������� �� ��������� � ������ ������
	const TernaryVector Disjunction(const TernaryVector&, const TernaryVector&);
	
	const int Compare(const TernaryVector&, const TernaryVector&);

}

#endif // !TERNARYVECTORCLASS_H_

