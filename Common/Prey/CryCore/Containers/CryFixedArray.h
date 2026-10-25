// Based on CryEngine 5.2 CryCore/Containers/CryFixedArray.h; debug range logging dropped.
#pragma once
#include <cstdint>
#include <cstring>
#include <new>

template<unsigned int align> struct CryFixedArrayDatum
{
};

template<>
struct CryFixedArrayDatum<4>
{
	typedef uint32_t TDatum;
};

template<>
struct CryFixedArrayDatum<8>
{
	typedef uint64_t TDatum;
};

template<class T, unsigned int N> class CryFixedArray
{
protected:
	enum { ALIGN = (alignof(T) > sizeof(unsigned int)) ? alignof(T) : sizeof(unsigned int) };   //!< ALIGN at least sizeof(unsigned int).

	typedef typename CryFixedArrayDatum<ALIGN>::TDatum TDatum;

	uint32_t m_curSize[sizeof(TDatum) / sizeof(uint32_t)];                    //!< Padded for alignment.

	TDatum m_data[(N * sizeof(T) + (sizeof(TDatum) - 1)) / sizeof(TDatum)];   //!< In VS add to a watch as "(T*)m_data, <N>".

public:
	typedef T*       iterator;
	typedef const T* const_iterator;

	CryFixedArray()
	{
		m_curSize[0] = 0;
	}

	CryFixedArray(const CryFixedArray& other)
	{
		m_curSize[0] = other.m_curSize[0];
		const unsigned int size = m_curSize[0];
		for (unsigned int i = 0; i < size; i++)
		{
			new(&at(i)) T(other.at(i));     // Placement new.
		}
	}

	CryFixedArray& operator=(const CryFixedArray& other)
	{
		if (this != &other)
		{
			clear();
			m_curSize[0] = other.m_curSize[0];
			const unsigned int size = m_curSize[0];
			for (unsigned int i = 0; i < size; i++)
			{
				new(&at(i)) T(other.at(i));     // Placement new.
			}
		}
		return *this;
	}

	virtual ~CryFixedArray()
	{
		clear();
	}

	inline T&       at(unsigned int i)            { return reinterpret_cast<T*>(m_data)[i]; }
	inline const T& at(unsigned int i) const      { return reinterpret_cast<const T*>(m_data)[i]; }
	inline const T& operator[](unsigned int i) const { return at(i); }
	inline T&       operator[](unsigned int i)       { return at(i); }

	inline void clear()
	{
		for (uint32_t i = 0; i < m_curSize[0]; i++)
		{
			at(i).~T();
		}
		m_curSize[0] = 0;
	}

	inline iterator       begin()       { return reinterpret_cast<T*>(m_data); }
	inline const_iterator begin() const { return reinterpret_cast<const T*>(m_data); }
	inline iterator       end()         { return &(reinterpret_cast<T*>(m_data))[m_curSize[0]]; }
	inline const_iterator end() const   { return &(reinterpret_cast<const T*>(m_data))[m_curSize[0]]; }
	inline const T*       data() const  { return reinterpret_cast<const T*>(m_data); }

	inline unsigned int max_size() const { return N; }
	inline unsigned int capacity() const { return N; }
	inline unsigned int size() const     { return m_curSize[0]; }
	inline bool         empty() const    { return size() == 0; }
	inline unsigned int isfull() const   { return (size() == max_size()); }

	//! Push back a default constructed element (no-op when full).
	inline void push_back()
	{
		const unsigned int curSize = size();
		if (curSize < N)
		{
			new(&at(curSize)) T();
			m_curSize[0]++;
		}
	}

	inline void push_back(const T& ele)
	{
		const unsigned int curSize = size();
		if (curSize < N)
		{
			new(&at(curSize)) T(ele);   //!< Placement new copy constructor - sets up vtable etc.
			m_curSize[0]++;
		}
	}

	inline void pop_back()
	{
		if (size() > 0)
		{
			back().~T();    //!< Destruct back.
			m_curSize[0]--;
		}
	}

protected:
	inline const T& backEx() const
	{
		return at(m_curSize[0] - 1);
	}

public:
	inline const T& back() const { return backEx(); }
	inline T&       back()       { return const_cast<T&>(backEx()); }

	//! Returns true when an element was swapped into element[i] (it moved in memory).
	inline bool removeAt(uint32_t i)
	{
		bool swappedElement = false;
		if (i < m_curSize[0])
		{
			if (i != m_curSize[0] - 1)
			{
				at(i).~T();                  // Destruct element being removed.
				new(&at(i)) T(back());       // Copy back() into element i.
				swappedElement = true;
			}
			pop_back();                      // Will destruct back().
		}
		return swappedElement;
	}
};
