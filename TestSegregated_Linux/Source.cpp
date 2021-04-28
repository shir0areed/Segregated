#include "Header.h"

#include "Segregated.inl"

#include <vector>

namespace Hoge
{
	using namespace std;

	struct CHoge::Impl
	{
		Impl()
			: values{ 0, 8 }
		{

		}
		Impl(int v1, int v2)
			: values{ v1, v2 }
		{

		}
		~Impl()
		{

		}
		vector<int>values;
	};

	CHoge::CHoge()
		: impl{ 1800, 8 }
	{
	}

	CHoge::~CHoge() = default;

	int CHoge::Func(int a) const
	{
		//constexpr auto realSize = sizeof(CHoge::Impl);
		return a * impl->values[0] * impl->values[1];
	}

	struct CFoobar1::Impl
	{
		CMyInt iVal;
	};

	CFoobar1::CFoobar1(int wage) : pImpl{ new Impl{ wage } } {}
	CFoobar1::~CFoobar1() = default;
	int CFoobar1::Calc(int a) const { return pImpl->iVal.ComplexCalc(a); }

	struct CFoobar2::Impl
	{
		Impl(int wage) : iVal{ wage } {}

		CMyInt iVal;

		static constexpr size_t Size() { return sizeof(Impl); }
	};

	CFoobar2::CFoobar2(int wage) : pImpl{ wage } {}
	CFoobar2::~CFoobar2() = default;
	int CFoobar2::Calc(int a) const { return pImpl->iVal.ComplexCalc(a); }
}
