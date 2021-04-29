#include <memory>

#include "Segregated.h"

namespace Hoge
{
	class CHoge
	{
	public:
		CHoge();
		~CHoge();
		int Func(int a) const;
	private:
		struct Impl;
		Segregated::CSegregated<Impl, 24> impl;
	};

	class CMyInt
	{
	public:
		CMyInt(const int* values)
		{
			value0 = values[0];
			value1 = values[1];
			value2 = static_cast<char>(values[2]);
			value3 = values[3];
		}
		int ComplexCalc(int a) const
		{
			if (value2 ^ a)
				return static_cast<int>((value0 + value1) * a);
			else
				return static_cast<int>(value3 * a);
		}
	private:
		int64_t value0;
		int64_t value1;
		char value2;
		int64_t value3;
	};

	class CFoobar0
	{
	public:
		CFoobar0(const int* values) : iVal{ values } {}
		int Calc(int a)const { return iVal.ComplexCalc(a); }
	private:
		CMyInt iVal;
	};

	class CFoobar1
	{
	public:
		CFoobar1(const int* values);
		~CFoobar1();
		int Calc(int a)const;
	private:
		struct Impl;
		std::unique_ptr<Impl> pImpl;
	};

	class CFoobar2
	{
	public:
		CFoobar2(const int* values);
		~CFoobar2();
		int Calc(int a)const;
	private:
		struct Impl;
		Segregated::CSegregated<Impl, 32> pImpl;
	};
}
