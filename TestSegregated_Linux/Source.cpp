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

	CFoobar1::CFoobar1(const int* values) : pImpl{ new Impl{ values } } {}
	CFoobar1::~CFoobar1() = default;
	int CFoobar1::Calc(int a) const { return pImpl->iVal.ComplexCalc(a); }

	struct CFoobar2::Impl
	{
		Impl(const int* values) : iVal{ values } {}

		CMyInt iVal;

		static constexpr size_t Size() { return sizeof(Impl); }
	};

	CFoobar2::CFoobar2(const int* values) : pImpl{ values } {}
	CFoobar2::~CFoobar2() = default;
	int CFoobar2::Calc(int a) const { return pImpl->iVal.ComplexCalc(a); }
}
