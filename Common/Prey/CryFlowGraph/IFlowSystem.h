// Header file automatically created from a PDB.

#pragma once
#include <boost/variant.hpp>
#include <Prey/CryCore/StdAfx.h>
#include <Prey/CryCore/functor.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryFlowGraph/SFlowSystemVoid.h>
#include <Prey/CryFlowGraph/NFlowSystemUtils__IFlowSystemTyped.h>
#include <Prey/CryFlowGraph/NFlowSystemUtils__Wrapper.h>
#include <Prey/CryFlowGraph/IFlowNodeIterator.h>
#include <Prey/CryFlowGraph/IFlowEdgeIterator.h>
#include <Chairloader/PreyFunction.h>

typedef uint8  TFlowPortId;
typedef uint16 TFlowNodeId;
typedef uint16 TFlowNodeTypeId;
typedef uint32 TFlowGraphId;
typedef int    TFlowSystemContainerId;

static const TFlowNodeId InvalidFlowNodeId = ~TFlowNodeId(0);
static const TFlowPortId InvalidFlowPortId = ~TFlowPortId(0);
static const TFlowNodeTypeId InvalidFlowNodeTypeId = 0; //!< Must be 0 - FlowSystem.cpp relies on it.
static const TFlowGraphId InvalidFlowGraphId = ~TFlowGraphId(0);
static const TFlowSystemContainerId InvalidContainerId = ~TFlowSystemContainerId(0);


//! By adding types to this list, we can extend the flow system to handle new data types.
//! Important: If types need to be added, add them at the end, otherwise it breaks serialization.
//! \note CFlowData::ConfigureInputPort must be updated simultaneously.
//! \see CFlowData::ConfigureInputPort.
typedef boost::mpl::vector<
    SFlowSystemVoid,
    int,
    float,
    EntityId,
    Vec3,
    string,
    bool
    > TFlowSystemDataTypes;

//! Default conversion uses C++ rules.
template<class From, class To>
struct SFlowSystemConversion
{
	static ILINE bool ConvertValue(const From& from, To& to)
	{
		to = (To)from;
		return true;
	}
};

#define FLOWSYSTEM_NO_CONVERSION(T)                                                   \
  template<> struct SFlowSystemConversion<T, T> {                                     \
    static ILINE bool ConvertValue(const T &from, T & to) { to = from; return true; } \
  }
FLOWSYSTEM_NO_CONVERSION(SFlowSystemVoid);
FLOWSYSTEM_NO_CONVERSION(int);
FLOWSYSTEM_NO_CONVERSION(float);
FLOWSYSTEM_NO_CONVERSION(EntityId);
FLOWSYSTEM_NO_CONVERSION(Vec3);
FLOWSYSTEM_NO_CONVERSION(string);
FLOWSYSTEM_NO_CONVERSION(bool);
#undef FLOWSYSTEM_NO_CONVERSION

//! Specialization for converting to bool to avoid compiler warnings.
template<class From>
struct SFlowSystemConversion<From, bool>
{
	static ILINE bool ConvertValue(const From& from, bool& to)
	{
		to = (from != 0);
		return true;
	}
};
//! "Void" conversion needs some help.
//! Converting from void to anything yields default value of type.
template<class To>
struct SFlowSystemConversion<SFlowSystemVoid, To>
{
	static ILINE bool ConvertValue(SFlowSystemVoid, To& to)
	{
		to = To();
		return true;
	}
};
template<>
struct SFlowSystemConversion<SFlowSystemVoid, bool>
{
	static ILINE bool ConvertValue(const SFlowSystemVoid& from, bool& to)
	{
		to = false;
		return true;
	}
};
template<>
struct SFlowSystemConversion<SFlowSystemVoid, Vec3>
{
	static ILINE bool ConvertValue(const SFlowSystemVoid& from, Vec3& to)
	{
		to = Vec3(0, 0, 0);
		return true;
	}
};
template<>
struct SFlowSystemConversion<Vec3, SFlowSystemVoid>
{
	static ILINE bool ConvertValue(const Vec3& from, SFlowSystemVoid&)
	{
		return true;
	}
};

//! Converting to void is trivial - just lose the value info.
template<class From>
struct SFlowSystemConversion<From, SFlowSystemVoid>
{
	static ILINE bool ConvertValue(const From& from, SFlowSystemVoid&)
	{
		return true;
	}
};

//! Vec3 conversions.
template<class To>
struct SFlowSystemConversion<Vec3, To>
{
	static ILINE bool ConvertValue(const Vec3& from, To& to)
	{
		return SFlowSystemConversion<float, To>::ConvertValue(from.x, to);
	}
};
template<class From>
struct SFlowSystemConversion<From, Vec3>
{
	static ILINE bool ConvertValue(const From& from, Vec3& to)
	{
		float temp;
		if (!SFlowSystemConversion<From, float>::ConvertValue(from, temp))
			return false;
		to.x = to.y = to.z = temp;
		return true;
	}
};
template<>
struct SFlowSystemConversion<Vec3, bool>
{
	static ILINE bool ConvertValue(const Vec3& from, bool& to)
	{
		to = from.GetLengthSquared() > 0;
		return true;
	}
};

#define FLOWSYSTEM_STRING_CONVERSION(type, fmt)                   \
  template<>                                                      \
  struct SFlowSystemConversion<type, string>                      \
  {                                                               \
    static ILINE bool ConvertValue(const type &from, string & to) \
    {                                                             \
      to.Format(fmt, from);                                       \
      return true;                                                \
    }                                                             \
  };                                                              \
  template<>                                                      \
  struct SFlowSystemConversion<string, type>                      \
  {                                                               \
    static ILINE bool ConvertValue(const string &from, type & to) \
    {                                                             \
      return 1 == sscanf(from.c_str(), fmt, &to);                 \
    }                                                             \
  };

FLOWSYSTEM_STRING_CONVERSION(int, "%d");
FLOWSYSTEM_STRING_CONVERSION(float, "%g");
FLOWSYSTEM_STRING_CONVERSION(EntityId, "%u");

#undef FLOWSYSTEM_STRING_CONVERSION

template<>
struct SFlowSystemConversion<bool, string>
{
	static ILINE bool ConvertValue(const bool& from, string& to)
	{
		to.Format("%s", from ? "true" : "false");
		return true;
	}
};

template<>
struct SFlowSystemConversion<string, bool>
{
	//! Leaves 'to' unchanged in case of error.
	static ILINE bool ConvertValue(const string& from, bool& to)
	{
		int to_i;
		if (1 == sscanf(from.c_str(), "%d", &to_i))
		{
			to = !!to_i;
			return true;
		}
		if (0 == stricmp(from.c_str(), "true"))
		{
			to = true;
			return true;
		}
		if (0 == stricmp(from.c_str(), "false"))
		{
			to = false;
			return true;
		}
		return false;
	}
};

template<>
struct SFlowSystemConversion<Vec3, string>
{
	static ILINE bool ConvertValue(const Vec3& from, string& to)
	{
		to.Format("%g,%g,%g", from.x, from.y, from.z);
		return true;
	}
};

template<>
struct SFlowSystemConversion<string, Vec3>
{
	static ILINE bool ConvertValue(const string& from, Vec3& to)
	{
		return 3 == sscanf(from.c_str(), "%g,%g,%g", &to.x, &to.y, &to.z);
	}
};

typedef boost::make_variant_over<TFlowSystemDataTypes>::type TFlowInputDataVariant;

struct SInputPortConfig;
struct SOutputPortConfig;
struct SFlowNodeActivationListener;
struct ICustomAction;

enum EHyperNodeFlags
{
    EHYPER_NODE_ENTITY        = 0x0001,
    EHYPER_NODE_ENTITY_VALID  = 0x0002,
    EHYPER_NODE_GRAPH_ENTITY  = 0x0004,    // This node targets graph default entity.
    EHYPER_NODE_GRAPH_ENTITY2 = 0x0008,    // Second graph default entity.
    EHYPER_NODE_INSPECTED     = 0x0010,    // Node is being inspected [dynamic, visual-only hint]
    EHYPER_NODE_HIDE_UI       = 0x0100,    // Not visible in components tree.
    EHYPER_NODE_CUSTOM_COLOR1 = 0x0200,    // Custom Color1
    EHYPER_NODE_UNREMOVEABLE  = 0x0400,    // Node cannot be deleted by user
};

template<class T>
struct DefaultInitialized
{
	T operator()() const { return T(); }
};

template<>
struct DefaultInitialized<Vec3>
{
	Vec3 operator()() const { return Vec3(ZERO); }
};

template<class Iter>
struct DefaultInitializedForTag
{
	bool operator()(int tag, TFlowInputDataVariant& v) const
	{
		if (tag == boost::mpl::distance<typename boost::mpl::begin<TFlowSystemDataTypes>::type, Iter>::type::value)
		{
			DefaultInitialized<typename boost::mpl::deref<Iter>::type> create;
			v = create();
			return true;
		}
		else
		{
			DefaultInitializedForTag<typename boost::mpl::next<Iter>::type> create;
			return create(tag, v);
		}
	}
};

template<>
struct DefaultInitializedForTag<typename boost::mpl::end<TFlowSystemDataTypes>::type>
{
	bool operator()(int tag, TFlowInputDataVariant& v) const
	{
		return false;
	}
};

// Header: MadeUp
// _unknown/SFlowNodeConfig.h
struct SFlowNodeConfig // Id=8001C3F Size=40
{
    SInputPortConfig const *pInputPorts;
    SOutputPortConfig const *pOutputPorts;
    unsigned nFlags;
    const char *sDescription;
    const char *sUIClassName;

#if 0
    void SetCategory(unsigned arg0);
	unsigned GetCategory() const;
	unsigned GetCoreFlags() const;
	unsigned GetUsageFlags() const;
	unsigned GetTypeFlags() const;
#endif
};

class ICrySizer;
struct IFlowNode;
TYPEDEF_AUTOPTR(IFlowNode);
typedef IFlowNode_AutoPtr IFlowNodePtr;

class TFlowInputData;
struct IFlowNode
{
    struct SActivationInfo // Id=8000F62 Size=48
    {
        IFlowGraph *pGraph = nullptr;
        uint16_t myID = 0;
        IEntity *pEntity = nullptr;
        uint8_t connectPort = 0;
        TFlowInputData *pInputPorts = nullptr;
        void *m_pUserData = nullptr;

#if 0
        void __dflt_ctor_closure();
#endif
    };

    enum EFlowEvent
    {
        eFE_Update,
        eFE_Activate,               //!< Sent if one or more input ports have been activated.
        eFE_FinalActivate,          //!< Must be eFE_Activate+1 (same as activate, but at the end of FlowSystem:Update).
        eFE_PrecacheResources,      //!< Called after flow graph loading to precache resources inside flow nodes.
        eFE_Initialize,             //!< Sent once after level has been loaded. it is NOT called on Serialization!.
        eFE_FinalInitialize,        //!< Must be eFE_Initialize+1.
        eFE_SetEntityId,            //!< This event is send to set the entity of the FlowNode. Might also be sent in conjunction (pre) other events (like eFE_Initialize).
        eFE_Suspend,
        eFE_Resume,
        eFE_EditorInputPortDataSet,
        eFE_ConnectInputPort,
        eFE_DisconnectInputPort,
        eFE_ConnectOutputPort,
        eFE_DisconnectOutputPort,
        eFE_DontDoAnythingWithThisPlease
    };

    IFlowNode() = default;


    // <interfuscator:shuffle>
    virtual ~IFlowNode(){}

    //! Provides base copy and move semantic without copying ref count in _i_reference_target_t
    IFlowNode(IFlowNode const&) { }

    //! Provides base copy and move semantic without copying ref count in _i_reference_target_t
    IFlowNode& operator= (IFlowNode const&) { return *this; }

    //! notification to be overridden in C# flow node
//    virtual void OnDelete() const {}


    virtual void AddRef() = 0;
    //! override to kick off a notification for C# flow node.
    //! to be removed when we get rid of C# flow node completely
    virtual void Release() = 0;

    virtual _smart_ptr<IFlowNode> Clone(SActivationInfo*) = 0;

    virtual void         GetConfiguration(SFlowNodeConfig&) = 0;
    virtual bool         SerializeXML(SActivationInfo*, const XmlNodeRef& root, bool reading) = 0;
    virtual void         Serialize(SActivationInfo*, TSerialize ser) = 0;
    virtual void         PostSerialize(SActivationInfo*) = 0;
    virtual void         ProcessEvent(EFlowEvent event, SActivationInfo*) = 0;

    virtual void         GetMemoryUsage(ICrySizer* s) const = 0;

    //! Used to return the global UI enum name to use for the given input port, if the port defines a UI enum of type 'enum_global_def'.
    //! \param[in] portId The input port Id for which to determine the global enum name.
    //! \param[in] pNodeEntity Current entity attached to the node.
    //! \param[in] szName The common name defined with the port (enum_global_def:commonName).
    //! \param[out] outGlobalEnum The global enum name to use for this port.
    //! \param[in] globalEnumMaxSize Maximum size of the possible resulting outGlobalEnum name (including null-terminated character).
    //! \returns true if a global enum name was determined and should be used. Otherwise the common name is used.
    virtual bool GetPortGlobalEnum(uint32 portId, IEntity* pNodeEntity, const char* szName, char* outGlobalEnum, size_t globalEnumMaxSize) const { return false; }

    // </interfuscator:shuffle>
};

struct IFlowNodeFactory // Id=8001C5D Size=8
{
    virtual ~IFlowNodeFactory();
    virtual void AddRef() = 0;
    virtual void Release() = 0;
    virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo *arg0) = 0;
    virtual void GetMemoryUsage(ICrySizer *arg0) const = 0;
    virtual void Reset() = 0;
    virtual bool AllowOverride() const { return FAllowOverride(this); }

    static inline auto FAllowOverride = PreyFunction<bool(IFlowNodeFactory const *const _this)>(0xDD23F0);
};


// Header: Exact
// CryEngine/crycommon/iflowsystem.h
class TFlowInputData
{
	class IsSameType
	{
		class StrictlyEqual : public boost::static_visitor<bool>
		{
		public:
			template<typename T, typename U>
			bool operator()(const T&, const U&) const
			{
				return false; // cannot compare different types
			}

			template<typename T>
			bool operator()(const T&, const T&) const
			{
				return true;
			}
		};

	public:
		bool operator()(const TFlowInputData& a, const TFlowInputData& b) const
		{
			return boost::apply_visitor(StrictlyEqual(), a.m_variant, b.m_variant);
		}
	};

	template<typename Ref>
	class IsSameTypeExpl
	{
		class StrictlyEqual : public boost::static_visitor<bool>
		{
		public:
			template<typename T>
			bool operator()(const T&) const
			{
				return false; // cannot compare different types
			}

			bool operator()(const Ref&) const
			{
				return true;
			}
		};

	public:
		bool operator()(const TFlowInputData& a) const
		{
			return boost::apply_visitor(StrictlyEqual(), a.m_variant);
		}
	};

	class IsEqual
	{
		class StrictlyEqual : public boost::static_visitor<bool>
		{
		public:
			template<typename T, typename U>
			bool operator()(const T&, const U&) const
			{
				return false; // cannot compare different types
			}

			template<typename T>
			bool operator()(const T& lhs, const T& rhs) const
			{
				return lhs == rhs;
			}
		};

	public:
		bool operator()(const TFlowInputData& a, const TFlowInputData& b) const
		{
			return boost::apply_visitor(StrictlyEqual(), a.m_variant, b.m_variant);
		}
	};

	class ExtractType : public boost::static_visitor<EFlowDataTypes>
	{
	public:
		template<typename T>
		EFlowDataTypes operator()(const T& value) const
		{
			return (EFlowDataTypes) boost::mpl::find<TFlowSystemDataTypes, T>::type::pos::value;
		}
	};

	template<typename To>
	class ConvertType_Get : public boost::static_visitor<bool>
	{
	public:
		ConvertType_Get(To& to_) : to(to_) {}

		template<typename From>
		bool operator()(const From& from) const
		{
			return SFlowSystemConversion<From, To>::ConvertValue(from, to);
		}

		To& to;
	};

	template<typename From>
	class ConvertType_Set : public boost::static_visitor<bool>
	{
	public:
		ConvertType_Set(const From& from_) : from(from_) {}

		template<typename To>
		bool operator()(To& to) const
		{
			return SFlowSystemConversion<From, To>::ConvertValue(from, to);
		}

		const From& from;
	};

	class ConvertType_SetFlexi : public boost::static_visitor<bool>
	{
	public:
		ConvertType_SetFlexi(TFlowInputData& to_) : to(to_) {}

		template<typename From>
		bool operator()(const From& from) const
		{
			return boost::apply_visitor(ConvertType_Set<From>(from), to.m_variant);
		}

		TFlowInputData& to;
	};

	class WriteType : public boost::static_visitor<void>
	{
	public:
		WriteType(TSerialize ser, bool userFlag) : m_ser(ser), m_userFlag(userFlag) {}

		template<class T>
		void operator()(T& v)
		{
			int tag = boost::mpl::find<TFlowSystemDataTypes, T>::type::pos::value;
			m_ser.Value("tag", tag);
			m_ser.Value("ud", m_userFlag);
			m_ser.Value("v", v);
		}

	private:
		TSerialize m_ser;
		bool       m_userFlag;
	};

	class LoadType : public boost::static_visitor<void>
	{
	public:
		LoadType(TSerialize ser) : m_ser(ser) {}

		template<class T>
		void operator()(T& v)
		{
			m_ser.Value("v", v);
		}

	private:
		TSerialize m_ser;
	};

	class MemStatistics : public boost::static_visitor<void>
	{
	public:
		MemStatistics(ICrySizer* pSizer) : m_pSizer(pSizer) {}

		template<class T>
		void operator()(T& v)
		{
			// m_pSizer->AddObject(v);
		}

	private:
		ICrySizer* m_pSizer;
	};

public:
	TFlowInputData()
		: m_variant()
		, m_userFlag(false)
		, m_locked(false)
	{}

	TFlowInputData(const TFlowInputData& rhs)
		: m_variant(rhs.m_variant)
		, m_userFlag(rhs.m_userFlag)
		, m_locked(rhs.m_locked)
	{}

	template<typename T>
	explicit TFlowInputData(const T& v, bool locked = false)
		: m_variant(v)
		, m_userFlag(false)
		, m_locked(locked)
	{}

	template<typename T>
	static TFlowInputData CreateDefaultInitialized(bool locked = false)
	{
		DefaultInitialized<T> create;
		return TFlowInputData(create(), locked);
	}

	static TFlowInputData CreateDefaultInitializedForTag(int tag, bool locked = false)
	{
		TFlowInputDataVariant v;
		DefaultInitializedForTag<boost::mpl::begin<TFlowSystemDataTypes>::type> create;
		create(tag, v);
		return TFlowInputData(v, locked);
	}

	TFlowInputData& operator=(const TFlowInputData& rhs)
	{
		if (this != &rhs)
		{
			m_variant = rhs.m_variant;
			m_userFlag = rhs.m_userFlag;
			m_locked = rhs.m_locked;
		}
		return *this;
	}

	bool operator==(const TFlowInputData& rhs) const
	{
		IsEqual isEqual;
		return isEqual(*this, rhs);
	}

	bool operator!=(const TFlowInputData& rhs) const
	{
		IsEqual isEqual;
		return !isEqual(*this, rhs);
	}

	bool SetDefaultForTag(int tag)
	{
		DefaultInitializedForTag<boost::mpl::begin<TFlowSystemDataTypes>::type> set;
		return set(tag, m_variant);
	}

	template<typename T>
	bool Set(const T& value)
	{
		IsSameTypeExpl<T> isSameType;
		if (IsLocked() && !isSameType(*this))
		{
			return false;
		}
		else
		{
			m_variant = value;
			return true;
		}
	}

	template<typename T>
	bool SetValueWithConversion(const T& value)
	{
		IsSameTypeExpl<T> isSameType;
		if (IsLocked() && !isSameType(*this))
		{
			return boost::apply_visitor(ConvertType_Set<T>(value), m_variant);
		}
		else
		{
			m_variant = value;
			return true;
		}
	}

	bool SetValueWithConversion(const TFlowInputData& value)
	{
		IsSameType isSameType;
		if (IsLocked() && !isSameType(*this, value))
		{
			return boost::apply_visitor(ConvertType_SetFlexi(*this), value.m_variant);
		}
		else
		{
			m_variant = value.m_variant;
			return true;
		}
	}

	template<typename T> T*       GetPtr()       { return boost::get<T>(&m_variant); }
	template<typename T> const T* GetPtr() const { return boost::get<const T>(&m_variant); }

	template<typename T>
	bool GetValueWithConversion(T& value) const
	{
		IsSameTypeExpl<T> isSameType;
		if (isSameType(*this))
		{
			value = *GetPtr<T>();
			return true;
		}
		else
		{
			return boost::apply_visitor(ConvertType_Get<T>(value), m_variant);
		}
	}

	EFlowDataTypes GetType() const         { return boost::apply_visitor(ExtractType(), m_variant); }

	bool           IsUserFlagSet() const   { return m_userFlag; }
	void           SetUserFlag(bool value) { m_userFlag = value; }
	void           ClearUserFlag()         { m_userFlag = false; }

	bool           IsLocked() const        { return m_locked; }
	void           SetLocked()             { m_locked = true; }
	void           SetUnlocked()           { m_locked = false; }

	void           Serialize(TSerialize ser)
	{
		// MEMSTAT_CONTEXT(EMemStatContextTypes::MSC_Other, 0, "Configurable variant serialization");

		if (ser.IsWriting())
		{
			WriteType visitor(ser, IsUserFlagSet());
			boost::apply_visitor(visitor, m_variant);
		}
		else
		{
			int tag = -2; // should be safe
			ser.Value("tag", tag);

			SetDefaultForTag(tag);

			bool ud = m_userFlag;
			ser.Value("ud", ud);
			m_userFlag = ud;

			LoadType visitor(ser);
			boost::apply_visitor(visitor, m_variant);
		}
	}

	template<class Visitor>
	void Visit(Visitor& visitor)
	{
		boost::apply_visitor(visitor, m_variant);
	}

	template<class Visitor>
	void Visit(Visitor& visitor) const
	{
		boost::apply_visitor(visitor, m_variant);
	}

	void GetMemoryStatistics(ICrySizer* pSizer) const
	{
		MemStatistics visitor(pSizer);
		boost::apply_visitor(visitor, m_variant);
	}

	void GetMemoryUsage(ICrySizer* pSizer) const
	{
		GetMemoryStatistics(pSizer);
	}

private:
	friend struct SEqualFlowInputData;

	TFlowInputDataVariant m_variant;

	bool                  m_userFlag : 1;
	bool                  m_locked   : 1;
};

// Header: MadeUp
// _unknown/SInputPortConfig.h
struct SInputPortConfig // Id=8001C40 Size=64
{
    const char *name;
    const char *humanName;
    const char *description;
    const char *sUIConfig;
    TFlowInputData defaultData;

#if 0
    void GetMemoryUsage(ICrySizer *arg0) const;
#endif
};


struct SOutputPortConfig // Id=8001C41 Size=32
{
    const char *name;
    const char *humanName;
    const char *description;
    int type;

#if 0
    void GetMemoryUsage(ICrySizer *arg0) const;
#endif
};

struct IFlowNodeTypeIterator // Id=8001C5F Size=8
{
    struct SNodeType // Id=8001C60 Size=16
    {
        uint16_t typeId;
        const char *typeName;
    };

    virtual ~IFlowNodeTypeIterator();
    virtual void AddRef() = 0;
    virtual void Release() = 0;
    virtual bool Next(IFlowNodeTypeIterator::SNodeType &arg0) = 0;
};


struct SFlowAddress // Id=8000F55 Size=4
{
    uint16_t node;
    uint8_t port;
    bool isOutput;

    SFlowAddress(TFlowNodeId node, TFlowPortId port, bool isOutput)
    {
        this->node = node;
        this->port = port;
        this->isOutput = isOutput;
}
    SFlowAddress()
    {
        node = InvalidFlowNodeId;
        port = InvalidFlowPortId;
        isOutput = true;
    }

    bool operator==(const SFlowAddress& n) const { return node == n.node && port == n.port && isOutput == n.isOutput; }
    bool operator!=(const SFlowAddress& n) const { return !(*this == n); }
};

// Header: MadeUp
// _unknown/IFlowGraphInspector.h
struct IFlowGraphInspector // Id=8001C62 Size=8
{
    struct IFilter // Id=8001C63 Size=8
    {
        enum EFilterResult
        {
            eFR_DontCare = 0,
            eFR_Block = 1,
            eFR_Pass = 2,
        };

        virtual ~IFilter();
        virtual void AddRef() = 0;
        virtual void Release() = 0;
        virtual void AddFilter(_smart_ptr<IFlowGraphInspector::IFilter> arg0) = 0;
        virtual void RemoveFilter(_smart_ptr<IFlowGraphInspector::IFilter> arg0) = 0;
        virtual IFlowGraphInspector::IFilter::EFilterResult Apply(IFlowGraph *arg0, SFlowAddress arg1, SFlowAddress arg2) = 0;
    };

    using IFilter_AutoPtr = _smart_ptr<IFlowGraphInspector::IFilter>;
    using IFilter_AutoArray = std::vector<_smart_ptr<IFlowGraphInspector::IFilter>>;
    using IFilterPtr = _smart_ptr<IFlowGraphInspector::IFilter>;

    virtual ~IFlowGraphInspector();
    virtual void AddRef() = 0;
    virtual void Release() = 0;
    virtual void PreUpdate(IFlowGraph *arg0) = 0;
    virtual void PostUpdate(IFlowGraph *arg0) = 0;
    virtual void NotifyFlow(IFlowGraph *arg0, SFlowAddress arg1, SFlowAddress arg2) = 0;
    virtual void NotifyProcessEvent(IFlowNode::EFlowEvent arg0, IFlowNode::SActivationInfo *arg1, IFlowNode *arg2) = 0;
    virtual void AddFilter(_smart_ptr<IFlowGraphInspector::IFilter> arg0) = 0;
    virtual void RemoveFilter(_smart_ptr<IFlowGraphInspector::IFilter> arg0) = 0;
    virtual void GetMemoryUsage(ICrySizer *arg0) const = 0;
};
struct IFlowGraphModuleListener;
struct IFlowGraphModule;
struct IFlowGraphModuleIterator;

struct IFlowGraphModuleManager // Id=8001C72 Size=8
{
    virtual ~IFlowGraphModuleManager();
    virtual bool RegisterListener(IFlowGraphModuleListener *arg0, const char *arg1) = 0;
    virtual void UnregisterListener(IFlowGraphModuleListener *arg0) = 0;
    virtual bool DeleteModuleXML(const char *arg0) = 0;
    virtual bool RenameModuleXML(const char *arg0, const char *arg1) = 0;
    virtual _smart_ptr<IFlowGraphModuleIterator> CreateModuleIterator() = 0;
    virtual const char *GetStartNodeName(const char *arg0) const = 0;
    virtual const char *GetReturnNodeName(const char *arg0) const = 0;
    virtual const char *GetCallerNodeName(const char *arg0) const = 0;
    virtual void ScanForModules() = 0;
    virtual const char *GetModulePath(const char *arg0) = 0;
    virtual bool SaveModule(const char *arg0, XmlNodeRef arg1) = 0;
    virtual IFlowGraphModule *LoadModuleFile(const char *arg0, const char *arg1, bool arg2) = 0;
    virtual IFlowGraphModule *GetModule(_smart_ptr<IFlowGraph> arg0) const = 0;
    virtual IFlowGraphModule *GetModule(const char *arg0) const = 0;
    virtual IFlowGraphModule *GetModule(unsigned arg0) const = 0;
    virtual unsigned CreateModuleInstance(unsigned arg0, DynArray<TFlowInputData,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > > const &arg1,  Functor2<bool,DynArray<TFlowInputData,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > > const &> const &arg2) = 0;
    virtual unsigned CreateModuleInstance(unsigned arg0, unsigned arg1, uint16_t arg2, DynArray<TFlowInputData,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > > const &arg3, Functor2<bool,DynArray<TFlowInputData,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > > const &> const &arg4) = 0;
    virtual bool CreateModuleNodes(const char *arg0, unsigned arg1) = 0;
};

class IArkGlobalAction;
class IArkGlobalActionManager;

struct IFlowSystemContainer // Id=8001C87 Size=8
{
    virtual ~IFlowSystemContainer();
    virtual void AddItem(TFlowInputData arg0) = 0;
    virtual void AddItemUnique(TFlowInputData arg0) = 0;
    virtual void RemoveItem(TFlowInputData arg0) = 0;
    virtual TFlowInputData GetItem(int arg0) = 0;
    virtual void Clear() = 0;
    virtual void RemoveItemAt(int arg0) = 0;
    virtual int GetItemCount() const = 0;
    virtual void GetMemoryUsage(ICrySizer *arg0) const = 0;
    virtual void Serialize(TSerialize arg0) = 0;
};

struct IFlowSystem // Id=8000F51 Size=8
{
    virtual ~IFlowSystem();
    virtual void Release() = 0;
    virtual void Update() = 0;
    virtual void Reset(bool arg0) = 0;
    virtual void Enable(bool arg0) = 0;
    virtual void ReloadAllNodeTypes() = 0;
    virtual _smart_ptr<IFlowGraph> CreateFlowGraph() = 0;
    virtual uint16_t RegisterType(const char *arg0, _smart_ptr<IFlowNodeFactory> arg1) = 0;
    virtual bool UnregisterType(const char *arg0) = 0;
    virtual const char *GetTypeName(uint16_t arg0) = 0;
    virtual uint16_t GetTypeId(const char *arg0) = 0;
    virtual _smart_ptr<IFlowNodeTypeIterator> CreateNodeTypeIterator() = 0;
    virtual void RegisterInspector(_smart_ptr<IFlowGraphInspector> arg0, _smart_ptr<IFlowGraph> arg1) = 0;
    virtual void UnregisterInspector(_smart_ptr<IFlowGraphInspector> arg0, _smart_ptr<IFlowGraph> arg1) = 0;
    virtual _smart_ptr<IFlowGraphInspector> GetDefaultInspector() const = 0;
    virtual void EnableInspecting(bool arg0) = 0;
    virtual bool IsInspectingEnabled() const = 0;
    virtual bool IsConsoleFlowNodesEnabled() const = 0;
    virtual IFlowGraph *GetGraphById(unsigned arg0) = 0;
    virtual void OnEntityIdChanged(unsigned arg0, unsigned arg1) = 0;
    virtual void GetMemoryUsage(ICrySizer *arg0) const = 0;
    virtual IFlowGraphModuleManager *GetIModuleManager() = 0;
    virtual IArkGlobalActionManager &GetIArkGlobalActionManager() = 0;
    virtual bool CreateContainer(int arg0) = 0;
    virtual void DeleteContainer(int arg0) = 0;
    virtual std::shared_ptr<IFlowSystemContainer> GetContainer(int arg0) = 0;
    virtual void Serialize(TSerialize arg0) = 0;
};

// Header: MadeUp
// _unknown/IFlowGraph.h
struct IFlowGraph : public NFlowSystemUtils::IFlowSystemTyped // Id=8000F53 Size=8
{
	enum EFlowGraphType
	{
		eFGT_Default = 0,
		eFGT_UIAction = 1,
		eFGT_Module = 2,
		eFGT_CustomAction = 3,
		eFGT_MaterialFx = 4,
		eFGT_GlobalAction = 5,
	};

	struct SGraphToken // Id=8001C48 Size=24
	{
		int id;
		string name;
		EFlowDataTypes type;
	};

	virtual void AddRef() = 0;
	virtual void Release() = 0;
	virtual _smart_ptr<IFlowGraph> Clone() = 0;
	virtual void Clear() = 0;
	virtual _smart_ptr<IFlowNodeIterator> CreateNodeIterator() = 0;
	virtual _smart_ptr<IFlowEdgeIterator> CreateEdgeIterator() = 0;
	virtual void SetGraphEntity(unsigned arg0, int arg1) = 0;
	virtual unsigned GetGraphEntity(int arg0) const = 0;
	virtual void SetEnabled(bool arg0) = 0;
	virtual bool IsEnabled() const = 0;
	virtual void SetActive(bool arg0) = 0;
	virtual bool IsActive() const = 0;
	virtual void UnregisterFromFlowSystem() = 0;
	virtual void SetType(IFlowGraph::EFlowGraphType arg0) = 0;
	virtual IFlowGraph::EFlowGraphType GetType() const = 0;
	virtual void Update() = 0;
	virtual bool SerializeXML(XmlNodeRef const& arg0, bool arg1) = 0;
	virtual void Serialize(TSerialize arg0) = 0;
	virtual void PostSerialize() = 0;
	virtual void InitializeValues() = 0;
	virtual void PrecacheResources() = 0;
	virtual void EnsureSortedEdges() = 0;
	virtual SFlowAddress ResolveAddress(const char* arg0, bool arg1) = 0;
	virtual uint16_t ResolveNode(const char* arg0) = 0;
	virtual uint16_t CreateNode(uint16_t arg0, const char* arg1, void* arg2) = 0;
	virtual uint16_t CreateNode(const char* arg0, const char* arg1, void* arg2) = 0;
	virtual IFlowNodeData* GetNodeData(uint16_t arg0) = 0;
	virtual bool SetNodeName(uint16_t arg0, const char* arg1) = 0;
	virtual const char* GetNodeName(uint16_t arg0) = 0;
	virtual uint16_t GetNodeTypeId(uint16_t arg0) = 0;
	virtual const char* GetNodeTypeName(uint16_t arg0) = 0;
	virtual void RemoveNode(const char* arg0) = 0;
	virtual void RemoveNode(uint16_t arg0) = 0;
	virtual void SetUserData(uint16_t arg0, XmlNodeRef const& arg1) = 0;
	virtual XmlNodeRef GetUserData(uint16_t arg0) = 0;
	virtual bool LinkNodes(SFlowAddress arg0, SFlowAddress arg1) = 0;
	virtual void UnlinkNodes(SFlowAddress arg0, SFlowAddress arg1) = 0;
	virtual void RegisterFlowNodeActivationListener(SFlowNodeActivationListener* arg0) = 0;
	virtual void RemoveFlowNodeActivationListener(SFlowNodeActivationListener* arg0) = 0;
	virtual bool NotifyFlowNodeActivationListeners(uint16_t arg0, uint8_t arg1, uint16_t arg2, uint8_t arg3, const char* arg4) = 0;
	virtual void SetEntityId(uint16_t arg0, unsigned arg1) = 0;
	virtual unsigned GetEntityId(uint16_t arg0) = 0;
	virtual _smart_ptr<IFlowGraph> GetClonedFlowGraph() const = 0;
	virtual void GetNodeConfiguration(uint16_t arg0, SFlowNodeConfig& arg1) = 0;
	virtual void SetRegularlyUpdated(uint16_t arg0, bool arg1) = 0;
	virtual void RequestFinalActivation(uint16_t arg0) = 0;
	virtual void ActivateNode(uint16_t arg0) = 0;
	virtual void ActivatePortAny(SFlowAddress arg0, TFlowInputData const& arg1) = 0;
	virtual void ActivatePortCString(SFlowAddress arg0, const char* arg1) = 0;
	virtual bool SetInputValue(uint16_t arg0, uint8_t arg1, TFlowInputData const& arg2) = 0;
	virtual bool IsOutputConnected(SFlowAddress arg0) = 0;
	virtual TFlowInputData const* GetInputValue(uint16_t arg0, uint8_t arg1) = 0;
	virtual bool GetActivationInfo(const char* arg0, IFlowNode::SActivationInfo& arg1) = 0;
	virtual void SetSuspended(bool arg0) = 0;
	virtual bool IsSuspended() const = 0;
	virtual void SetCustomAction(ICustomAction* arg0) = 0;
	virtual ICustomAction* GetCustomAction() const = 0;
	virtual void GetMemoryUsage(ICrySizer* arg0) const = 0;
	virtual void RemoveGraphTokens(bool arg0) = 0;
	virtual bool UpdateGraphToken(int arg0, const char* arg1, EFlowDataTypes arg2) = 0;
	virtual bool LoadGraphToken(int arg0, const char* arg1, EFlowDataTypes arg2) = 0;
	virtual int CloneGraphToken(IFlowGraph::SGraphToken const& arg0) = 0;
	virtual uint64_t GetGraphTokenCount() const = 0;
	virtual IFlowGraph::SGraphToken const* GetGraphToken(uint64_t arg0) const = 0;
	virtual unsigned GetGraphId() const = 0;
	virtual void OnNodeConfigReload(IFlowNodeData& arg0) = 0;
	virtual void SetOwningModule(IFlowGraphModule* arg0) = 0;
	virtual IFlowGraphModule* GetOwningModule() const = 0;
	virtual void FixCreatePhantomRequestEntityIdOutput(SFlowAddress arg0, unsigned arg1) = 0;
	virtual ~IFlowGraph() {};

	template<class T>
	ILINE void ActivatePort(const SFlowAddress output, const T& value)
	{
		DoActivatePort(output, NFlowSystemUtils::Wrapper<T>(value));
	}
	ILINE void ActivatePort(SFlowAddress output, const TFlowInputData& value)
	{
		ActivatePortAny(output, value);
	}

#if 0
	void ActivatePort(SFlowAddress arg0, TFlowInputData const& arg1);
#endif
};

ILINE bool IsPortActive(IFlowNode::SActivationInfo* pActInfo, int nPort)
{
    return pActInfo->pInputPorts[nPort].IsUserFlagSet();
}

ILINE EFlowDataTypes GetPortType(IFlowNode::SActivationInfo* pActInfo, int nPort)
{
    return (EFlowDataTypes)pActInfo->pInputPorts[nPort].GetType();
}

ILINE const TFlowInputData& GetPortAny(IFlowNode::SActivationInfo* pActInfo, int nPort)
{
    return pActInfo->pInputPorts[nPort];
}

ILINE bool GetPortBool(IFlowNode::SActivationInfo* pActInfo, int nPort)
{
    bool* p_x = (pActInfo->pInputPorts[nPort].GetPtr<bool>());
    return (p_x != 0) ? *p_x : 0;
}

ILINE int GetPortInt(IFlowNode::SActivationInfo* pActInfo, int nPort)
{
    int x = *(pActInfo->pInputPorts[nPort].GetPtr<int>());
    return x;
}

ILINE EntityId GetPortEntityId(IFlowNode::SActivationInfo* pActInfo, int nPort)
{
    EntityId x = *(pActInfo->pInputPorts[nPort].GetPtr<EntityId>());
    return x;
}

ILINE float GetPortFloat(IFlowNode::SActivationInfo* pActInfo, int nPort)
{
    float x = *(pActInfo->pInputPorts[nPort].GetPtr<float>());
    return x;
}

ILINE Vec3 GetPortVec3(IFlowNode::SActivationInfo* pActInfo, int nPort)
{
    Vec3 x = *(pActInfo->pInputPorts[nPort].GetPtr<Vec3>());
    return x;
}

ILINE const string& GetPortString(IFlowNode::SActivationInfo* pActInfo, int nPort)
{
    const string* p_x = (pActInfo->pInputPorts[nPort].GetPtr<string>());

    if (p_x)
    {
        return *p_x;
    }
    else
    {
        const static string empty("");
        return empty;
    }
}

ILINE bool IsBoolPortActive(IFlowNode::SActivationInfo* pActInfo, int nPort)
{
    if (IsPortActive(pActInfo, nPort) && GetPortBool(pActInfo, nPort))
        return true;
    else
        return false;
}

template<class T>
ILINE void ActivateOutput(IFlowNode::SActivationInfo* pActInfo, int nPort, const T& value)
{
    SFlowAddress addr(pActInfo->myID, nPort, true);
    pActInfo->pGraph->ActivatePort(addr, value);
}

ILINE bool IsOutputConnected(IFlowNode::SActivationInfo* pActInfo, int nPort)
{
    SFlowAddress addr(pActInfo->myID, nPort, true);
    return pActInfo->pGraph->IsOutputConnected(addr);
}
