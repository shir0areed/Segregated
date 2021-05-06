#ifndef SEGREGATED_SEGREGATED_H
#define SEGREGATED_SEGREGATED_H
#include <cstddef>

namespace Segregated
{
	template<typename TImpl, typename TLayout>
	class CSegregated
	{
	public:
		CSegregated();
		CSegregated(const CSegregated&);
		CSegregated& operator =(const CSegregated&);
		CSegregated(CSegregated&&);
		CSegregated& operator =(CSegregated&&);

		template<typename... Args>
		explicit CSegregated(Args&&... args);

		TImpl* get() noexcept;
		const TImpl* get() const noexcept { return const_cast<CSegregated*>(this)->get(); }
		TImpl* operator -> () noexcept { return get(); }
		const TImpl* operator -> () const noexcept { return get(); }
		TImpl& operator * () noexcept { return *get(); }
		const TImpl& operator * () const noexcept { return *get(); }

		~CSegregated();
	private:
		alignas(TLayout) char buf[sizeof(TLayout)]{};
	};
}
#endif
