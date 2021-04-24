#ifndef SIMPL_SIMPLIMPL_H
#define SIMPL_SIMPLIMPL_H
#include "Segregated.h"

#include <utility>

template<typename T, size_t size>
inline Segregated::CSegregated<T, size>::CSegregated()
{
	new(buf)T;
}

template<typename T, size_t size>
inline Segregated::CSegregated<T, size>::CSegregated(const CSegregated& a)
{
	new(buf)T(*a.get());
}

template<typename T, size_t size>
inline Segregated::CSegregated<T, size>& Segregated::CSegregated<T, size>::operator=(const CSegregated& a)
{
	*get() = *a.get();
	return *this;
}

template<typename T, size_t size>
inline Segregated::CSegregated<T, size>::CSegregated(CSegregated&& a)
{
	new(buf)T(std::move(*a.get()));
}

template<typename T, size_t size>
inline Segregated::CSegregated<T, size>& Segregated::CSegregated<T, size>::operator=(CSegregated&& a)
{
	*get() = std::move(*a.get());
	return *this;
}

template<typename T, size_t size>
template<typename... Args>
inline Segregated::CSegregated<T, size>::CSegregated(Args&&... args)
{
	new(buf)T(std::forward<Args>(args)...);
}

template<typename T, size_t size>
inline T* Segregated::CSegregated<T, size>::get() noexcept
{
	static_assert(sizeof(CSegregated<T, size>) >= sizeof(T), "too small size");
	return reinterpret_cast<T*>(buf);
}

template<typename T, size_t size>
inline Segregated::CSegregated<T, size>::~CSegregated()
{
	reinterpret_cast<T*>(buf)->~T();
}
#endif
