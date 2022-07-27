// Header file automatically created from a PDB.

#pragma once

class CPlayer;

// Header: FromCpp
// Prey/GameDll/ark/arkcornersmoother3d.h
class CArkCornerSmoother3D // Id=801BF8A Size=2440
{
public:
	static constexpr const int MAX_SAMPLES = 100;
	static constexpr const int MAX_PREDICTIONS_PER_FRAME = 6;
	
	struct SCurveSettings // Id=801BF8B Size=24
	{
		float wrongWaySpeed;
		float speedSmoothTime;
		float walkSmoothTime;
		float walkSpeed;
		float runSmoothTime;
		float runSpeed;
	};

	struct SPredictionSettings // Id=801BF8C Size=64
	{
		CArkCornerSmoother3D::SCurveSettings const *pCurveSettings;
		Vec3 playerPos;
		float oldMovementSpeed;
		Vec3 dir;
		float desiredSpeed;
		Vec3 moveTarget;
		float maxTurnSpeed;
		float travelSpeedRate;
	};

	struct SPrediction // Id=801BF8D Size=1204
	{
		int numSamples;
		Vec3 samples[100];
		
#if 0
		void Reset();
#endif
	};

	static int m_lastPredictionFrameID;
	static int m_numPredictionsThisFrame;
	static CArkCornerSmoother3D::SCurveSettings normalCurveSettings;
	CPlayer *m_pPlayer;
	Vec3 m_oldMoveTarget;
	float m_dirSmoothTime;
	CArkCornerSmoother3D::SPrediction m_prediction;
	CArkCornerSmoother3D::SPrediction m_simplePrediction;
	float m_travelSpeedRate;
	float m_maxTurnSpeed;
	
	void Reset() { FReset(this); }
	void Update(Vec3 const &playerPos, Vec3 const &oldMovementDir, const float oldMovementSpeed, Vec3 const &animBodyDirection, const float desiredSpeed, Vec3 const &desiredMovement, const float distToPathEnd, Vec3 const &moveTarget, const bool hasLockedBodyTarget, const float maxTurnSpeed, const float frameTime, float *const pNewDesiredSpeed, Vec3 *const pNewDesiredMovement) { FUpdate(this,playerPos,oldMovementDir,oldMovementSpeed,animBodyDirection,desiredSpeed,desiredMovement,distToPathEnd,moveTarget,hasLockedBodyTarget,maxTurnSpeed,frameTime,pNewDesiredSpeed,pNewDesiredMovement); }
	static void PredictSmoothTurn(CArkCornerSmoother3D::SPredictionSettings const &settings, CArkCornerSmoother3D::SPrediction *const pPrediction) { FPredictSmoothTurn(settings,pPrediction); }
	static void SimplifyPrediction(Vec3 const &playerPos, CArkCornerSmoother3D::SPrediction const &input, CArkCornerSmoother3D::SPrediction *const pOutput) { FSimplifyPrediction(playerPos,input,pOutput); }
	static float CalculateDirSmoothTime(CArkCornerSmoother3D::SCurveSettings const &settings, const float desiredSpeed, const float distToMoveTarget2D, const float endOfPathDistance) { return FCalculateDirSmoothTime(settings,desiredSpeed,distToMoveTarget2D,endOfPathDistance); }
	
#if 0
	bool IsRunning() const;
	void Cancel();
	void DebugRender(float arg0);
	void SmoothLocalVDir(Vec3 *const arg0, const float arg1) const;
	float GetMaxTurnSpeed() const;
	void PredictAndVerifySmoothTurn(CArkCornerSmoother3D::SPredictionSettings const &arg0);
	static bool CheckWalkability(CArkCornerSmoother3D::SPrediction const &arg0, CPlayer *arg1);
	static bool EnoughTimePassedSinceLastPrediction(const int arg0);
	static void RememberLastPredictionFrameID(const int arg0);
#endif
	
	static inline auto FReset = PreyFunction<void(CArkCornerSmoother3D *const _this)>(0x1421E90);
	static inline auto FUpdate = PreyFunction<void(CArkCornerSmoother3D *const _this, Vec3 const &playerPos, Vec3 const &oldMovementDir, const float oldMovementSpeed, Vec3 const &animBodyDirection, const float desiredSpeed, Vec3 const &desiredMovement, const float distToPathEnd, Vec3 const &moveTarget, const bool hasLockedBodyTarget, const float maxTurnSpeed, const float frameTime, float *const pNewDesiredSpeed, Vec3 *const pNewDesiredMovement)>(0x1422140);
	static inline auto FPredictSmoothTurn = PreyFunction<void(CArkCornerSmoother3D::SPredictionSettings const &settings, CArkCornerSmoother3D::SPrediction *const pPrediction)>(0x1421830);
	static inline auto FSimplifyPrediction = PreyFunction<void(Vec3 const &playerPos, CArkCornerSmoother3D::SPrediction const &input, CArkCornerSmoother3D::SPrediction *const pOutput)>(0x1421EC0);
	static inline auto FCalculateDirSmoothTime = PreyFunction<float(CArkCornerSmoother3D::SCurveSettings const &settings, const float desiredSpeed, const float distToMoveTarget2D, const float endOfPathDistance)>(0x14217C0);
};

