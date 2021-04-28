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
		CMyInt(int value) : value{ value } {}
		int ComplexCalc(int a) const { return value * a; }
	private:
		int value;
	};

	class CFoobar0
	{
	public:
		CFoobar0(int wage) : iVal{ wage } {}
		int Calc(int a)const { return iVal.ComplexCalc(a); }
	private:
		CMyInt iVal;
	};

	class CFoobar1
	{
	public:
		CFoobar1(int wage);
		~CFoobar1();
		int Calc(int a)const;
	private:
		struct Impl;
		std::unique_ptr<Impl> pImpl;
	};

	class CFoobar2
	{
	public:
		CFoobar2(int wage);
		~CFoobar2();
		int Calc(int a)const;
	private:
		struct Impl;
		Segregated::CSegregated<Impl, 4> pImpl;
	};
}
