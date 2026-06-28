// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

struct AABB;
namespace CryGame
{
class CPrefab;
} // namespace CryGame
struct IEntity;
struct IRenderNode;

namespace CryGame
{

// CryGame::CRuntimePrefab
// Header:  Prey/GameDll/RuntimePrefab.h
class CRuntimePrefab
{ // Size=136 (0x88)
public:
	Matrix34 m_mat;
	CryGame::CPrefab* m_pPrefab;
	unsigned m_id;
	std::vector<unsigned int> m_lstIDs;
	std::vector<IRenderNode*> m_lstNodes;
	std::vector<CryGame::CRuntimePrefab*> m_lstPrefabs;

	CRuntimePrefab(unsigned id);
	~CRuntimePrefab();
	void Spawn(CryGame::CPrefab& pRef) { FSpawnOv1(this, pRef); }
	void Spawn(IEntity* pEntity, CryGame::CPrefab& pRef, const Matrix34& matOff, AABB& box) { FSpawnOv0(this, pEntity, pRef, matOff, box); }
	void Move() { FMoveOv1(this); }
	void Move(const Matrix34& matOff) { FMoveOv0(this, matOff); }
	void Hide(bool bHide) { FHide(this, bHide); }
	void SpawnEntities(CryGame::CPrefab& pRef, const Matrix34& matSource, AABB& box) { FSpawnEntities(this, pRef, matSource, box); }
	void SpawnBrushes(CryGame::CPrefab& pRef, const Matrix34& matSource, AABB& box) { FSpawnBrushes(this, pRef, matSource, box); }
	void Clear() { FClear(this); }
	void HideComponents(bool bHide) { FHideComponents(this, bHide); }

#if 0
	void Spawn_2(CryGame::CPrefab& _arg0_);
	void Spawn_2(IEntity* _arg0_, CryGame::CPrefab& _arg1_, const Matrix34& _arg2_, AABB& _arg3_);
	CryGame::CPrefab* GetSourcePrefab();
	void SpawnEntities_2(IEntity* _arg0_, CryGame::CPrefab& _arg1_, const Matrix34& _arg2_, AABB& _arg3_);
	void SpawnBrushes_2(IEntity* _arg0_, CryGame::CPrefab& _arg1_, const Matrix34& _arg2_, AABB& _arg3_);
#endif

	static inline auto FCRuntimePrefabOv1 = PreyFunction<void(CryGame::CRuntimePrefab* const _this, unsigned id)>(0x18FD210);
	static inline auto FBitNotCRuntimePrefab = PreyFunction<void(CryGame::CRuntimePrefab* const _this)>(0x18FD270);
	static inline auto FSpawnOv1 = PreyFunction<void(CryGame::CRuntimePrefab* const _this, CryGame::CPrefab& pRef)>(0x18FE080);
	static inline auto FSpawnOv0 = PreyFunction<void(CryGame::CRuntimePrefab* const _this, IEntity* pEntity, CryGame::CPrefab& pRef, const Matrix34& matOff, AABB& box)>(0x18FE340);
	static inline auto FMoveOv1 = PreyFunction<void(CryGame::CRuntimePrefab* const _this)>(0x18FDB90);
	static inline auto FMoveOv0 = PreyFunction<void(CryGame::CRuntimePrefab* const _this, const Matrix34& matOff)>(0x18FD4E0);
	static inline auto FHide = PreyFunction<void(CryGame::CRuntimePrefab* const _this, bool bHide)>(0x18FD3E0);
	static inline auto FSpawnEntities = PreyFunction<void(CryGame::CRuntimePrefab* const _this, CryGame::CPrefab& pRef, const Matrix34& matSource, AABB& box)>(0x18FF270);
	static inline auto FSpawnBrushes = PreyFunction<void(CryGame::CRuntimePrefab* const _this, CryGame::CPrefab& pRef, const Matrix34& matSource, AABB& box)>(0x18FE740);
	static inline auto FClear = PreyFunction<void(CryGame::CRuntimePrefab* const _this)>(0x18FD2A0);
	static inline auto FHideComponents = PreyFunction<void(CryGame::CRuntimePrefab* const _this, bool bHide)>(0x18FD450);
};


} // namespace CryGame
#endif // MOONCRASH
