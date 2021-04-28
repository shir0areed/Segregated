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
		int ComplexCalc(int a) const { return value * a; }
	private:
		int value = 1800;
	};

	class CFoobar0
	{
	public:
		int Calc(int a)const { return iVal.ComplexCalc(a); }
	private:
		CMyInt iVal;
	};
}
