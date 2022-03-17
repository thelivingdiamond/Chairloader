#pragma once
template<typename T> class CryStringT
{
public:
	T* m_str; //0x0000
}; //Size: 0x0008

class CCryName
{
public:
	char* m_str; //0x0000
}; //Size: 0x0008

class CSharedString {
public:

};
// template<typename T> class vector {
// 	char pad[24];
// };
template<typename T> class ArkIntrusiveList;
	template<typename T> class ArkIntrusiveListElement {
	public:
		ArkIntrusiveList<T>* m_pList;
		ArkIntrusiveListElement<T>* m_pPrev;
		ArkIntrusiveListElement<T>* m_pNext;

	};
	template<typename T> class ArkIntrusiveList {
	public:
		uint64_t m_size;
		ArkIntrusiveListElement<T> m_head;
	};
	class ArkContiguousMemory {
	public:
		std::vector<unsigned char> m_memory;
	};
	class ArkUnanimous {
	public:
		uint64_t m_trueCount,
			m_falseCount;

	};
	template<typename T> class ArkInterval {
	public:
		T minimum;
		T maximum;
	};
template<typename T> struct Vec3_tpl { T x, y, z; };
template<typename T> struct Quat_tpl { T x, y, z, w; };
template<typename T> struct Vec2_tpl { T x, y; };

typedef Vec3_tpl<float> Vec3;
typedef Quat_tpl<float> Vec4;
typedef Vec2_tpl<float> Vec2;

typedef char undefined;
template<uint32_t i> class CryFixedStringT {
public:
	char pad[i];
};

template<typename T, uint32_t i> class CryFixedArray {
public:
	void* ptr;
	uint32_t m_curSize;
	T arr[i];
};

template<typename T> class CCryFlags {
public:

	T m_bitStorage;
};

class CryHashStringId {
public:
	uint32_t id;
};
class CRndGen {
public:
	uint64_t m_state;
};
template<typename F> struct Matrix34_tpl {


	F m00, m01, m02, m03;
	F m10, m11, m12, m13;
	F m20, m21, m22, m23;

	inline Matrix34_tpl() {}

	inline Matrix34_tpl<F>(F v00, F v01, F v02, F v03, F v10, F v11, F v12, F v13, F v20, F v21, F v22, F v23)
	{
		m00 = v00;
		m01 = v01;
		m02 = v02;
		m03 = v03;
		m10 = v10;
		m11 = v11;
		m12 = v12;
		m13 = v13;
		m20 = v20;
		m21 = v21;
		m22 = v22;
		m23 = v23;
	}
};