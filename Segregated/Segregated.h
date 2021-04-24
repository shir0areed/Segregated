#ifndef SEGREGATED_SEGREGATED_H
#define SEGREGATED_SEGREGATED_H
#include <cstddef>

namespace Segregated
{
	template<typename T, size_t size>
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

		T* get() noexcept;
		const T* get() const noexcept { return const_cast<CSegregated*>(this)->get(); }
		T* operator -> () noexcept { return get(); }
		const T* operator -> () const noexcept { return get(); }
		T& operator * () noexcept { return *get(); }
		const T& operator * () const noexcept { return *get(); }

		~CSegregated();
	private:
		char buf[size]{};
	};
}
#endif
