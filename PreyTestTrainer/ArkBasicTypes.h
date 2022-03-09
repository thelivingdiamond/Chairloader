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
