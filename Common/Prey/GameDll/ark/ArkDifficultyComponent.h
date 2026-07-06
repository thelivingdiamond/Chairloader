// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkDifficultyComponent.h>
#include <Prey/GameDll/ark/ui/IArkPauseMenuListener.h>
#include <Prey/GameDll/ark/ArkSignalModifer.h>

class ArkClass;
struct ICVar;

// Header: Exact
// Prey/GameDll/ark/ArkDifficultyComponent.h
class ArkDifficultyComponent : public IArkPauseMenuListener // Id=80166B5 Size=32
{
public:
	int m_currentLevel;
	int m_lowestDifficulty;
	ICVar *m_pDifficultyCVar;
	std::array<bool,4> m_difficultyOptions;
	
	ArkDifficultyComponent();
	~ArkDifficultyComponent();
	void Init() { FInit(this); }
	void Reset() { FReset(this); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void PostSerialize() { FPostSerialize(this); }
	void OnNewGame() { FOnNewGame(this); }
	void OnLevelLoad() { FOnLevelLoad(this); }
	static void ConsoleCVar_PlayerDifficultyChange(ICVar *_pVar) { FConsoleCVar_PlayerDifficultyChange(_pVar); }
	void SetDifficultyOption(EArkDifficultyOption _option, bool _bEnabled) { FSetDifficultyOption(this,_option,_bEnabled); }
	static const char *GetLocStringForDifficultyOption(EArkDifficultyOption _option) { return FGetLocStringForDifficultyOption(_option); }
	static const char *GetDescLocStringForDifficultyOption(EArkDifficultyOption _option) { return FGetDescLocStringForDifficultyOption(_option); }
	void SetDifficulty(int _level, bool _bForce) { FSetDifficulty(this,_level,_bForce); }
	virtual void OnOptionMenuClosed();
	
#if 0
	EArkDifficultyLevel GetDifficulty() const;
	int GetLowestDifficulty() const;
	void UpdateLowestDifficulty();
	bool AnyDifficultyOptionEnabled() const;
	bool IsDifficultyOptionEnabled(EArkDifficultyOption arg0) const;
	static const char *GetLocStringForDifficultyLevel(EArkDifficultyLevel arg0);
#endif
	
	static inline auto FBitNotArkDifficultyComponent = PreyFunction<void(ArkDifficultyComponent *const _this)>(0x12EB870);
	static inline auto FInit = PreyFunction<void(ArkDifficultyComponent *const _this)>(0x12EBDB0);
	static inline auto FReset = PreyFunction<void(ArkDifficultyComponent *const _this)>(0x12EC060);
	static inline auto FSerialize = PreyFunction<void(ArkDifficultyComponent *const _this, TSerialize _ser)>(0x12EC0B0);
	static inline auto FPostSerialize = PreyFunction<void(ArkDifficultyComponent *const _this)>(0x12EC060);
	static inline auto FOnNewGame = PreyFunction<void(ArkDifficultyComponent *const _this)>(0x12EBFF0);
	static inline auto FOnLevelLoad = PreyFunction<void(ArkDifficultyComponent *const _this)>(0x12EBFC0);
	static inline auto FConsoleCVar_PlayerDifficultyChange = PreyFunction<void(ICVar *_pVar)>(0x12EB920);
	static inline auto FSetDifficultyOption = PreyFunction<void(ArkDifficultyComponent *const _this, EArkDifficultyOption _option, bool _bEnabled)>(0x12EC5F0);
	static inline auto FGetLocStringForDifficultyOption = PreyFunction<const char *(EArkDifficultyOption _option)>(0x12EBD70);
	static inline auto FGetDescLocStringForDifficultyOption = PreyFunction<const char *(EArkDifficultyOption _option)>(0x12EBCE0);
	static inline auto FSetDifficulty = PreyFunction<void(ArkDifficultyComponent *const _this, int _level, bool _bForce)>(0x12EC290);
	static inline auto FOnOptionMenuClosed = PreyFunction<void(ArkDifficultyComponent *const _this)>(0x12EC040);
};

// Header: Exact
// Prey/GameDll/ark/arkdifficultycomponent.h
class ArkDifficultyLevel : public ArkReflectedObject // Id=8017655 Size=32
{
public:
	class ArkLevelProperty : public ArkProperty // Id=8017656 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkDifficultyLevel::ArkLevelProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10571E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkDifficultyLevel::ArkLevelProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkDifficultyLevel::ArkLevelProperty s_ArkLevelProperty;
	uint8_t m_Level;
	
	class ArkVisualAttentionScalarProperty : public ArkProperty // Id=8017657 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkDifficultyLevel::ArkVisualAttentionScalarProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328E10);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkDifficultyLevel::ArkVisualAttentionScalarProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328410);
	};

	static ArkDifficultyLevel::ArkVisualAttentionScalarProperty s_ArkVisualAttentionScalarProperty;
	float m_VisualAttentionScalar;
	
	class ArkModifiersProperty : public ArkProperty // Id=8017658 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkDifficultyLevel::ArkModifiersProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x12EB220);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkDifficultyLevel::ArkModifiersProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12EB250);
		static inline auto FIsArray = PreyFunction<bool(ArkDifficultyLevel::ArkModifiersProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkDifficultyLevel::ArkModifiersProperty const *const _this, ArkReflectedObject *_pObject)>(0x107C020);
	};

	static ArkDifficultyLevel::ArkModifiersProperty s_ArkModifiersProperty;
	std::vector<ArkSignalModifer> m_Modifiers;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetLevel(uint8_t arg0);
	const uint8_t &GetLevel() const;
	void SetVisualAttentionScalar(float arg0);
	const float &GetVisualAttentionScalar() const;
	std::vector<ArkSignalModifer> &GetModifiers();
	std::vector<ArkSignalModifer> const &GetModifiers() const;
	void Activate();
	void Deactivate();
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x12EB950);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x12EBB50);
};

// Header: Exact
// Prey/GameDll/ark/arkdifficultycomponent.h
class ArkDifficultyLevels : public ArkReflectedLibrary // Id=8017659 Size=32
{
public:
	class ArkLevelsProperty : public ArkProperty // Id=801765A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkDifficultyLevels::ArkLevelsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x12EB270);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkDifficultyLevels::ArkLevelsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12EB2D0);
		static inline auto FIsArray = PreyFunction<bool(ArkDifficultyLevels::ArkLevelsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkDifficultyLevels::ArkLevelsProperty const *const _this, ArkReflectedObject *_pObject)>(0x12EB310);
	};

	static ArkDifficultyLevels::ArkLevelsProperty s_ArkLevelsProperty;
	std::vector<ArkDifficultyLevel> m_Levels;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Init();
	virtual ~ArkDifficultyLevels();
	
#if 0
	std::vector<ArkDifficultyLevel> &GetLevels();
	std::vector<ArkDifficultyLevel> const &GetLevels() const;
	boost::optional<ArkDifficultyLevel> Find(int arg0) const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x12EB990);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x12EBBF0);
	static inline auto FInit = PreyFunction<bool(ArkDifficultyLevels *const _this)>(0x12EBDD0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSignalModifer.h>
#include <Prey/GameDll/ark/ui/IArkPauseMenuListener.h>

class ArkClass;
enum class EArkDifficultyLevel;
class IArkValueBase;
struct ICVar;

// ArkDifficultyComponent
// Header:  Prey/GameDll/ark/ArkDifficultyComponent.h
class ArkDifficultyComponent : public IArkPauseMenuListener
{ // Size=24 (0x18)
public:
	int m_currentLevel;
	int m_lowestDifficulty;
	ICVar* m_pDifficultyCVar;

	ArkDifficultyComponent();
	~ArkDifficultyComponent();
	void Init() { FInit(this); }
	void Reset() { FReset(this); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void PostSerialize() { FPostSerialize(this); }
	void OnNewGame() { FOnNewGame(this); }
	void OnLevelLoad() { FOnLevelLoad(this); }
	static void ConsoleCVar_PlayerDifficultyChange(ICVar* _pVar) { FConsoleCVar_PlayerDifficultyChange(_pVar); }
	void SetDifficulty(int _level, bool _bForce) { FSetDifficulty(this, _level, _bForce); }
	virtual void OnOptionMenuClosed();

#if 0
	EArkDifficultyLevel GetDifficulty() const;
	int GetLowestDifficulty() const;
	void UpdateLowestDifficulty();
	static const char* GetLocStringForDifficultyLevel(EArkDifficultyLevel _arg0_);
#endif

	static inline auto FArkDifficultyComponentOv1 = PreyFunction<void(ArkDifficultyComponent* const _this)>(0x139F3B0);
	static inline auto FBitNotArkDifficultyComponent = PreyFunction<void(ArkDifficultyComponent* const _this)>(0x139F420);
	static inline auto FInit = PreyFunction<void(ArkDifficultyComponent* const _this)>(0x139F750);
	static inline auto FReset = PreyFunction<void(ArkDifficultyComponent* const _this)>(0x139FA10);
	static inline auto FSerialize = PreyFunction<void(ArkDifficultyComponent* const _this, TSerialize _ser)>(0x139FA60);
	static inline auto FPostSerialize = PreyFunction<void(ArkDifficultyComponent* const _this)>(0x139FA10);
	static inline auto FOnNewGame = PreyFunction<void(ArkDifficultyComponent* const _this)>(0x139F9A0);
	static inline auto FOnLevelLoad = PreyFunction<void(ArkDifficultyComponent* const _this)>(0x139F970);
	static inline auto FConsoleCVar_PlayerDifficultyChange = PreyFunction<void(ICVar* _pVar)>(0x139F4A0);
	static inline auto FSetDifficulty = PreyFunction<void(ArkDifficultyComponent* const _this, int _level, bool _bForce)>(0x139FB00);
	static inline auto FOnOptionMenuClosed = PreyFunction<void(ArkDifficultyComponent* const _this)>(0x139F9F0);
};

// ArkDifficultyLevel
// Header:  Prey/GameDll/ark/ArkDifficultyComponent.h
class ArkDifficultyLevel : public ArkReflectedObject
{ // Size=32 (0x20)
public:
	// ArkDifficultyLevel::ArkLevelProperty
	// Header:  Prey/GameDll/ark/ArkDifficultyComponent.h
	class ArkLevelProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLevelProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDifficultyLevel::ArkLevelProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B2A90);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDifficultyLevel::ArkLevelProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkDifficultyLevel::ArkVisualAttentionScalarProperty
	// Header:  Prey/GameDll/ark/ArkDifficultyComponent.h
	class ArkVisualAttentionScalarProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkVisualAttentionScalarProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDifficultyLevel::ArkVisualAttentionScalarProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13BD3C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDifficultyLevel::ArkVisualAttentionScalarProperty* const _this, ArkReflectedObject* const _pObject)>(0x14035E0);
	};

	// ArkDifficultyLevel::ArkModifiersProperty
	// Header:  Prey/GameDll/ark/ArkDifficultyComponent.h
	class ArkModifiersProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkModifiersProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDifficultyLevel::ArkModifiersProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x139EEB0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDifficultyLevel::ArkModifiersProperty* const _this, ArkReflectedObject* const _pObject)>(0x139EEE0);
		static inline auto FIsArray = PreyFunction<bool(const ArkDifficultyLevel::ArkModifiersProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkDifficultyLevel::ArkModifiersProperty* const _this, ArkReflectedObject* _pObject)>(0x139EF00);
	};

	static inline auto s_ArkLevelProperty = PreyGlobal<ArkDifficultyLevel::ArkLevelProperty>(0x2D50188);
	uint8_t m_Level;
	static inline auto s_ArkVisualAttentionScalarProperty = PreyGlobal<ArkDifficultyLevel::ArkVisualAttentionScalarProperty>(0x2D501A8);
	float m_VisualAttentionScalar;
	static inline auto s_ArkModifiersProperty = PreyGlobal<ArkDifficultyLevel::ArkModifiersProperty>(0x2D501C8);
	std::vector<ArkSignalModifer> m_Modifiers;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetLevel(uint8_t _arg0_);
	const uint8_t& GetLevel() const;
	void SetVisualAttentionScalar(float _arg0_);
	const float& GetVisualAttentionScalar() const;
	std::vector<ArkSignalModifer>& GetModifiers();
	const std::vector<ArkSignalModifer>& GetModifiers() const;
	ArkDifficultyLevel();
	void Activate();
	void Deactivate();
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x139F4D0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x139F570);
};

// ArkDifficultyLevels
// Header:  Prey/GameDll/ark/ArkDifficultyComponent.h
class ArkDifficultyLevels : public ArkReflectedLibrary
{ // Size=32 (0x20)
public:
	// ArkDifficultyLevels::ArkLevelsProperty
	// Header:  Prey/GameDll/ark/ArkDifficultyComponent.h
	class ArkLevelsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkLevelsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDifficultyLevels::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x139EF10);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDifficultyLevels::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject)>(0x139EF70);
		static inline auto FIsArray = PreyFunction<bool(const ArkDifficultyLevels::ArkLevelsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkDifficultyLevels::ArkLevelsProperty* const _this, ArkReflectedObject* _pObject)>(0x139EFB0);
	};

	static inline auto s_ArkLevelsProperty = PreyGlobal<ArkDifficultyLevels::ArkLevelsProperty>(0x2D501E8);
	std::vector<ArkDifficultyLevel> m_Levels;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();

#if 0
	ArkDifficultyLevels();
	std::vector<ArkDifficultyLevel>& GetLevels();
	const std::vector<ArkDifficultyLevel>& GetLevels() const;
	boost::optional<ArkDifficultyLevel> Find(int _arg0_) const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x139F510);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x139F610);
	static inline auto FInit = PreyFunction<bool(ArkDifficultyLevels* const _this)>(0x139F770);
};
#endif // !MOONCRASH
