// Header file automatically created from a PDB.
// It contains all enums referenced by files in Prey/GameDll

#pragma once

enum class AKRESULT
{
	AK_NotImplemented = 0,
	AK_Success = 1,
	AK_Fail = 2,
	AK_PartialSuccess = 3,
	AK_NotCompatible = 4,
	AK_AlreadyConnected = 5,
	AK_NameNotSet = 6,
	AK_InvalidFile = 7,
	AK_AudioFileHeaderTooLarge = 8,
	AK_MaxReached = 9,
	AK_InputsInUsed = 10,
	AK_OutputsInUsed = 11,
	AK_InvalidName = 12,
	AK_NameAlreadyInUse = 13,
	AK_InvalidID = 14,
	AK_IDNotFound = 15,
	AK_InvalidInstanceID = 16,
	AK_NoMoreData = 17,
	AK_NoSourceAvailable = 18,
	AK_StateGroupAlreadyExists = 19,
	AK_InvalidStateGroup = 20,
	AK_ChildAlreadyHasAParent = 21,
	AK_InvalidLanguage = 22,
	AK_CannotAddItseflAsAChild = 23,
	AK_UserNotInList = 29,
	AK_NoTransitionPoint = 30,
	AK_InvalidParameter = 31,
	AK_ParameterAdjusted = 32,
	AK_IsA3DSound = 33,
	AK_NotA3DSound = 34,
	AK_ElementAlreadyInList = 35,
	AK_PathNotFound = 36,
	AK_PathNoVertices = 37,
	AK_PathNotRunning = 38,
	AK_PathNotPaused = 39,
	AK_PathNodeAlreadyInList = 40,
	AK_PathNodeNotInList = 41,
	AK_VoiceNotFound = 42,
	AK_DataNeeded = 43,
	AK_NoDataNeeded = 44,
	AK_DataReady = 45,
	AK_NoDataReady = 46,
	AK_NoMoreSlotAvailable = 47,
	AK_SlotNotFound = 48,
	AK_ProcessingOnly = 49,
	AK_MemoryLeak = 50,
	AK_CorruptedBlockList = 51,
	AK_InsufficientMemory = 52,
	AK_Cancelled = 53,
	AK_UnknownBankID = 54,
	AK_IsProcessing = 55,
	AK_BankReadError = 56,
	AK_InvalidSwitchType = 57,
	AK_VoiceDone = 58,
	AK_UnknownEnvironment = 59,
	AK_EnvironmentInUse = 60,
	AK_UnknownObject = 61,
	AK_NoConversionNeeded = 62,
	AK_FormatNotReady = 63,
	AK_WrongBankVersion = 64,
	AK_DataReadyNoProcess = 65,
	AK_FileNotFound = 66,
	AK_DeviceNotReady = 67,
	AK_CouldNotCreateSecBuffer = 68,
	AK_BankAlreadyLoaded = 69,
	AK_RenderedFX = 71,
	AK_ProcessNeeded = 72,
	AK_ProcessDone = 73,
	AK_MemManagerNotInitialized = 74,
	AK_StreamMgrNotInitialized = 75,
	AK_SSEInstructionsNotSupported = 76,
	AK_Busy = 77,
	AK_UnsupportedChannelConfig = 78,
	AK_PluginMediaNotAvailable = 79,
	AK_MustBeVirtualized = 80,
	AK_CommandTooLarge = 81,
	AK_RejectedByFilter = 82,
	AK_InvalidCustomPlatformName = 83,
};

enum class AkNodeCategory
{
	AkNodeCategory_Bus = 0,
	AkNodeCategory_ActorMixer = 1,
	AkNodeCategory_RanSeqCntr = 2,
	AkNodeCategory_Sound = 3,
	AkNodeCategory_SwitchCntr = 4,
	AkNodeCategory_LayerCntr = 5,
	AkNodeCategory_MusicTrack = 6,
	AkNodeCategory_MusicSegment = 7,
	AkNodeCategory_MusicRanSeqCntr = 8,
	AkNodeCategory_MusicSwitchCntr = 9,
	AkNodeCategory_FeedbackBus = 10,
	AkNodeCategory_FeedbackNode = 11,
	AkNodeCategory_AuxBus = 12,
	AkNodeCategory_None = 1000,
};

enum class AkObjectCategory
{
	ObjCategory_Undefined = 0,
	ObjCategory_ActorMixer = 1,
	ObjCategory_Container = 2,
	ObjCategory_Sound = 4,
	ObjCategory_State = 5,
	ObjCategory_Action = 6,
	ObjCategory_Event = 7,
	ObjCategory_Track = 8,
	ObjCategory_MusicNode = 9,
	ObjCategory_FeedbackNode = 10,
	ObjCategory_Bus = 11,
};

enum class ArkAbilityUpgradeState
{
	Locked = 0,
	CantAfford = 1,
	Available = 2,
	Purchased = 3,
};

enum class ArkCharacterEffectType : uint8_t
{
	corrupted = 0,
	damaged = 1,
	destroyed = 2,
	disabled = 3,
	electricity = 4,
	empCast = 5,
	feared = 6,
	fearBlast = 7,
	fire = 8,
	frozenInGoo = 9,
	glitch = 10,
	headExplode = 11,
	kineticBacklashed = 12,
	laserEnergize = 13,
	laserEnergizedExplosion = 14,
	lifetime = 15,
	mindControlledStart = 16,
	mindControlled = 17,
	mindControlledEnd = 18,
	onDeath = 19,
	onHit = 20,
	operatorPreDestruction = 21,
	operatorArmIdleEffect = 22,
	operatorArmEffect = 23,
	operatorArmAttackEffect = 24,
	operatorLaserCharge = 25,
	operatorLaserFlare = 26,
	operatorLevitators = 27,
	phantomAttackGlow = 28,
	psiBlastCast = 29,
	psiSuppressed = 30,
	psychoshockTargeting = 31,
	psychoshockBlast = 32,
	psychoshockCast = 33,
	repelBlast = 34,
	repelBlastCast = 35,
	shiftTelegraph = 36,
	shiftMove = 37,
	shiftOut = 38,
	lurkShiftTelegraph = 39,
	lurkShiftMove = 40,
	lurkShiftOut = 41,
	stun = 42,
	psychoShocked = 43,
	nightmareEtherFormFollow = 44,
	nightmareEtherFormFollowWithVelocity = 45,
	nightmareEtherFormAttack = 46,
	nightmareEtherFormPsiSuppressed = 47,
	nightmareLargeFormIn = 48,
	nightmareLargeFormOut = 49,
	weaverShieldIn = 50,
	weaverShieldDissolve = 51,
	weaverShieldBurst = 52,
	thermalAura = 53,
	electricAura = 54,
	thermogenesisCast = 55,
	thermalAuraCastWarmup = 56,
	poltergeistPsychoscopeBlur = 57,
	poltergeistAppear = 58,
	poltergeistDisappear = 59,
	poltergeistCast = 60,
	poltergeistGlitch = 61,
	raisePhantomFromCorpseStart = 62,
	raisePhantomFromCorpseCast = 63,
	count_ = 64,
};

enum class ArkGameSaveVersion : unsigned
{
	invalid = 0,
	initial = 1,
	enabledVersioning = 2,
	cystoidsEnabled = 3,
	taskLocationUpdate = 4,
	loadingFutureSave = 5,
	consoleSub1 = 6,
	cystoidChanges = 7,
	ragdollFallDamage = 8,
	createPhantomRequest = 9,
	fixPsiScanningState = 10,
	restorePreorderBonus = 11,
	createPhantomRequest2 = 12,
	goodDrunk = 13,
	timedTrialAdded = 14,
	survivalMode = 15,
	storyDifficulty = 16,
	newGamePlus = 17,
	fixNeverDrunk = 18,
};

enum class ArkMaterialAnimationType : uint8_t
{
	etherIn = 0,
	etherOut = 1,
	hitReaction = 2,
	disintegration = 3,
	laser = 4,
	weaverShieldIn = 5,
	weaverShieldDissolve = 6,
	weaverShieldBurst = 7,
	poltergeistAppear = 8,
	poltergeistDisappear = 9,
	poltergeistPsychscopeOn = 10,
	poltergeistPsychscopeOff = 11,
	nightmareEtherFormIn = 12,
	nightmareEtherFormOut = 13,
	nightmareLargeFormOut = 14,
	nightmareLargeFormIn = 15,
	phantomRaisedFromCorpse = 16,
	alienSpikeDisintegration = 17,
	count_ = 18,
};

namespace ArkNpcCustomHitReaction
{

enum class Type
{
	invalid = 0,
	laserDeath = 1,
	dramaticDeath = 2,
};

} // namespace ArkNpcCustomHitReaction

enum class ArkNpcSpeakerEvent
{
	INVALID = -1,
	onNewTarget = 0,
	onLostTarget = 1,
	onTargetDead = 2,
	onFallDown = 3,
	onStandUp = 4,
	onDeath = 5,
	onTakeDamage = 6,
	onAttack = 7,
	onUsePower = 8,
	onUsed = 9,
	onOuchSmall = 10,
	onOuchBig = 11,
	onWakeUpFromDormant = 12,
	onPlayerApproach = 13,
	onPlayerApproachNear = 14,
	onPlayerApproachFar = 15,
	onPlayerLoiter = 16,
	onPlayerUsePower = 17,
	onNonHostileAIApproach = 18,
	onConversationTrigger = 19,
	onGainedAttentionOnTarget = 20,
	onLostAttentionOnTarget = 21,
	onHuntStart = 22,
	onHuntGaveUp = 23,
	whileSearching = 24,
	whileWandering = 25,
	whilePatrolling = 26,
	onDefeatedPlayer = 27,
	onBumpedPlayerRanged = 28,
	onBumpedPlayerTouch = 29,
	onOperatorCharge = 30,
	onOperatorExploding = 31,
	onBroken = 32,
	onBrokenRepeat = 33,
	onRepaired = 34,
	onMovingToDistractor = 35,
	onStartDistractor = 36,
	onFinishDistractor = 37,
	onNpcBumpSignal = 38,
	onNpcFlee = 39,
	onNpcGlood = 40,
	onNpcKOdByTazer = 41,
	onNpcFireLaserSinged = 42,
	onNpcImmolatedDeath = 43,
	onNpcMineAttached = 44,
	onNpcFearHit = 45,
	onNpcNullWaveHit = 46,
	onNpcEmpHit = 47,
	onNpcFlareHit = 48,
	onNpcLiftStartHit = 49,
	onNpcLiftHeld = 50,
	onNpcFalling = 51,
	onNpcPlayerMindControlled = 52,
	onNpcTelepathMindControlled = 53,
	onNpcRemoteManipulated = 54,
	onNpcGrabbedByMimic = 55,
	onNpcErrorOffNavMesh = 56,
	onNightmareArrived = 57,
	onCorruptHumanApproachSlow = 58,
	onCorruptHumanApproachFast = 59,
	onCorruptRemovedByPlayer = 60,
	onDiagnoseFail = 61,
	numEvents = 62,
};

enum class ArkPDAPage
{
	First = 0,
	MainMenu = 0,
	Inventory = 1,
	Objectives = 2,
	Abilities = 3,
	Status = 4,
	LevelMap = 5,
	StationMap = 6,
	Notes = 7,
	Metadata = 8,
	Codes = 9,
	FabricationPlans = 10,
	AudioLogs = 11,
	Emails = 12,
	Lore = 13,
	SuitMods = 14,
	ScopeMods = 15,
	Last = 16,
};

enum class ArkPDASound
{
	NavUp = 0,
	NavDown = 1,
	NavLR = 2,
	PurchaseSuccess = 3,
	PurchaseFail = 4,
	Last = 5,
};

enum class ArkPDATab
{
	first = 0,
	objectives = 0,
	map = 1,
	inventory = 2,
	neuromods = 3,
	status = 4,
	data = 5,
	last = 6,
};

enum class ArkSignalEffect
{
	TakeDamage = 0,
	GiveHealth = 1,
	GivePsi = 2,
	GiveOxygen = 3,
	Trauma = 4,
	Radiation = 5,
	RemoveTrauma = 6,
	HitAnim = 7,
	Knockdown = 8,
	DeployHelmet = 9,
	DrainPsi = 10,
	DegradeWeapon = 11,
	Kill = 12,
	Last = 13,
};

namespace ArkSignalSystem
{

enum class EArkSignalReceiverType
{
	invalid = 0,
	lua = 1,
	cplusplus = 2,
	flowSignal = 3,
	flowPackage = 4,
	recycle = 5,
};

} // namespace ArkSignalSystem

enum class ArkTyphonStatus
{
	None = 0,
	Partial = 1,
	Full = 2,
};

enum class AsyncState
{
	AsyncFailed = 0,
	AsyncReady = 1,
	AsyncInProgress = 2,
	AsyncComplete = 3,
};

namespace CornerSmoothing
{

enum EPlanExecutionResult
{
	EPER_Failed = 0,
	EPER_Continue = 1,
	EPER_Finished = 2,
};

} // namespace CornerSmoothing

enum class DistractionFailedReason
{
	none = 0,
	noAreas = 1,
	noNpcs = 2,
	simultaneous = 3,
	zeroG = 4,
	noPlayer = 5,
	playerTooFarAway = 6,
	noFail = 7,
};

enum DistractionState
{
	eWaitingToDistract = 0,
	eTryDistract = 1,
	eRequested = 2,
	eInUse = 3,
	eCooldown = 4,
	eUsedNotReuseable = 5,
	eDisabled = 6,
	eUnused = 7,
	eCount = 8,
};

enum class EActionFailure
{
	AF_QueueFull = 0,
	AF_InvalidContext = 1,
};

enum class EAgentForceAvoidanceType
{
	None = 0,
	Agent = 1,
	Obstacle = 2,
};

enum EAirState
{
	eAS_Unset = -1,
	eAS_OnGround = 0,
	eAS_OnObject = 1,
	eAS_OnGroundOrObject = 2,
	eAS_InAir = 3,
};

enum class EArkAccessState
{
	Available = 0,
	Locked = 1,
	Hidden = 2,
};

enum class EArkAiTreeBookendFlags : uint8_t
{
	none = 0,
	resumedInitialized = 1,
	resumedEnabled = 2,
	resumedActivated = 4,
	suspendedInitialized = 8,
	suspendedEnabled = 16,
	suspendedActivated = 32,
	initialized = 9,
	enabled = 18,
	activated = 36,
	resumed = 7,
	suspended = 56,
};

enum class EArkAiTreeCompletionResult
{
	unsuccessful = 0,
	successful = 1,
};

enum class EArkAiTreeSearchReason
{
	indirectAnomaly = 0,
	indirectDanger = 1,
	direct = 2,
};

enum class EArkAiTreeStatus : uint8_t
{
	uninitialized = 0,
	resumedInitialized = 1,
	resumedEnabled = 3,
	resumedActivated = 7,
	suspendedInitialized = 9,
	suspendedEnabled = 11,
	suspendedActivated = 15,
};

enum class EArkAiTreeStatusFlags : uint8_t
{
	uninitialized = 0,
	initialized = 1,
	enabled = 2,
	activated = 4,
	suspended = 8,
};

enum class EArkAiTreeStimulusResult
{
	notConsumed = 0,
	consumed = 1,
};

enum class EArkAttentionChangeReason
{
	initialized = 0,
	cleared = 1,
	demoted = 2,
	drained = 3,
	simpleGain = 4,
	clamped = 5,
	ambient = 6,
	heardAnomaly = 7,
	flashlight = 8,
	heardDanger = 9,
	heardCallForHelp = 10,
	hitByProjectile = 11,
	remotelyManipulated = 12,
	observed = 13,
	etherDuplicate = 14,
	touched = 15,
};

enum class EArkAttentionLevel
{
	unknown = 0,
	noticed = 1,
	curious = 2,
	interested = 3,
	known = 4,
	count_ = 5,
};

enum class EArkChimeType
{
	none = 0,
	chime = 1,
	interference = 2,
};

enum class EArkCombatRole
{
	none = 0,
	melee = 1,
	ranged = 2,
	count_ = 3,
};

enum class EArkConditionTriggerType
{
	Force = 0,
	GainedItem = 1,
	LostItem = 2,
	AcquiredChipset = 3,
	HealthAmount = 4,
	PsiAmount = 5,
	ObjectiveStatusChange = 6,
	TaskStatusChange = 7,
	InteractedWith = 8,
	LookingAtNear = 9,
	LookingAtFar = 10,
	PlayerStatus = 11,
	AbilityAcquired = 12,
	TutorialOnCooldown = 13,
	ConditionExecuted = 14,
	FlashlightOn = 15,
	WeaponDurability = 16,
	GameMetric = 17,
	TraumaActive = 18,
	PlayerInCombat = 19,
	DifficultyOption = 20,
};

enum class EArkConversationDominance
{
	lowest = 0,
	normal = 0,
	important = 1,
	transcribe = 2,
	highest = 2,
};

enum class EArkConversationPriority
{
	veryhigh = 0,
	high = 1,
	medium = 2,
	low = 3,
	verylow = 4,
	none = 5,
	last = 6,
};

enum class EArkConversationStatus
{
	not_started = 0,
	started = 1,
	interrupted = 2,
	completed = 3,
	last = 4,
};

enum class EArkConversationType
{
	systemic = 0,
	trackView = 1,
	last = 2,
};

enum class EArkCraftingIngredientType
{
	Organic = 0,
	Mineral = 1,
	Synthetic = 2,
	Exotic = 3,
	Count = 4,
};

enum class EArkCriterionKeyType
{
	responseKey = 0,
	gameToken = 1,
	writeback = 2,
	conversation = 3,
	objective = 4,
	metatag = 5,
	task = 6,
};

enum class EArkCystoidNestState
{
	Invalid = 0,
	Inactive = 1,
	Primed = 2,
	Spawning = 3,
	Depleted = 4,
};

enum EArkCystoidState
{
	eInvalid = 0,
	eRest = 1,
	eFollow = 2,
	eAttack = 3,
	eDead = 4,
	eEnergized = 5,
};

enum class EArkDialogPlayerType
{
	invalid = 0,
	base = 1,
	npc = 2,
	pa = 3,
	transcribe = 4,
	turret = 5,
	last = 6,
};

enum class EArkDifficultyLevel
{
	invalid = -1,
	story = 0,
	easy = 1,
	normal = 2,
	hard = 3,
	nightmare = 4,
	count = 5,
};

enum class EArkDifficultyOption
{
	ironman = 0,
	weaponDegradation = 1,
	allTraumas = 2,
	oxygen = 3,
	count = 4,
};

enum class EArkDispenserError
{
	None = 0,
	MaxedOut = 1,
	LifetimeMaxReached = 2,
	Blocked = 3,
};

enum class EArkDispenserState
{
	Invalid = 0,
	Locked = 1,
	Unlocked = 2,
	Processing = 3,
	Error = 4,
	Overridden = 5,
};

enum class EArkDisposition
{
	none = 0,
	friendly = 1,
	neutral = 2,
	hostile = 3,
	count_ = 4,
};

enum class EArkDockingBay
{
	none = 0,
	bay1 = 1,
	bay2 = 2,
};

enum class EArkDockingState
{
	undocked = 0,
	docking = 1,
	docked = 2,
	undocking = 3,
};

enum class EArkElevatorKioskState
{
	Default = 0,
	Processing = 1,
	Fail = 2,
};

enum class EArkEthericDoppelgangerStage
{
	Casting = 0,
	MovingApart = 1,
	SpawningDoppelgangers = 2,
	Done = 3,
};

enum class EArkExplosiveTankState
{
	Invalid = 0,
	Intact = 1,
	Leaking = 2,
	PreExplode = 3,
	Destroyed = 4,
};

enum class EArkFabricatorState
{
	Invalid = 0,
	PoweredOff = 1,
	StandBy = 2,
	InUse = 3,
	Fabricating = 4,
	ItemReady = 5,
};

enum class EArkFleeCorneredBehavior
{
	none = 0,
	cower = 1,
	fight = 2,
};

enum class EArkGibletType : uint8_t
{
	smallGib = 0,
	mediumGib = 1,
	largeGib = 2,
	limbGib = 3,
	extraLargeGib = 4,
	count_ = 5,
};

enum class EArkHUDTutorialHintChannel
{
	Weapon = 0,
	Tutorial = 1,
	Count = 2,
};

enum class EArkHumanCombatStateId
{
	any = -1,
	null = 0,
	shooting = 1,
	reloading = 2,
	unreachableTargeting = 3,
	count_ = 4,
};

enum class EArkInteractionMode
{
	use = 0,
	holdUse = 1,
	loot = 2,
	special = 3,
	remoteManipulation = 4,
	last = 4,
};

enum class EArkInteractionType
{
	none = 0,
	scriptDefined = 1,
	unavailable = 2,
	codeDefined = 3,
	pickup = 4,
	consume = 5,
	carry = 6,
	hack = 7,
	repair = 8,
	fortify = 9,
	examine = 10,
	equip = 11,
	hoover = 12,
	last = 13,
};

enum class EArkInteractiveScreenType
{
	fabricator = 0,
	keycardReader = 1,
	keypad = 2,
	kiosk = 3,
	operatorDispenser = 4,
	securityStation = 5,
	workstation = 6,
	count = 7,
};

enum class EArkKeycardReaderState
{
	Invalid = 0,
	Locked = 1,
	Unlocked = 2,
	Error = 3,
};

enum class EArkKioskButtonState
{
	Disabled = 0,
	Default = 1,
	Processing = 2,
	Error = 3,
};

enum class EArkLightInterferenceState
{
	rampIn = 0,
	bright = 1,
	rampOut = 2,
	dark = 3,
	none = 4,
};

enum class EArkLoadDisconnectReason
{
	none = 0,
	signout = 1,
	corruptSave = 2,
};

enum class EArkNightmareCombatStateId
{
	any = -1,
	null = 0,
	largeForm = 1,
	meleePosition = 2,
	unreachableTargeting = 3,
	regainLoS = 4,
	avoidDamage = 5,
	debug = 6,
	count_ = 7,
};

enum class EArkNpcAbilityPerformanceResult
{
	failed = 0,
	completed = 1,
	inProgress = 2,
};

enum class EArkNpcAmbientSoundId
{
	living = 0,
	mimicking = 1,
	_count = 2,
};

enum class EArkNpcBodyStateId
{
	any = -1,
	null = 0,
	animated = 1,
	animatedAbility = 2,
	animatedDistraction = 3,
	animatedFall = 4,
	animatedStunned = 5,
	breakout = 6,
	cower = 7,
	dead = 8,
	dissipate = 9,
	dodge = 10,
	fatality = 11,
	frozen = 12,
	gravShaft = 13,
	hitReact = 14,
	hitReactShift = 15,
	hypnotized = 16,
	jump = 17,
	landing = 18,
	lifted = 19,
	lurking = 20,
	lurkOut = 21,
	mantle = 22,
	mimicking = 23,
	notice = 24,
	ragdoll = 25,
	raised = 26,
	react = 27,
	ready = 28,
	rebound = 29,
	resist = 30,
	resistScrunch = 31,
	searchExamine = 32,
	surprised = 33,
	trackview = 34,
	unanimatedAbility = 35,
	count_ = 36,
};

enum class EArkNpcDamageStateId
{
	any = -1,
	null = 0,
	damaged = 1,
	destroyed = 2,
	disabled = 3,
	undamaged = 4,
	count_ = 5,
};

enum class EArkNpcDesireTargetRefreshResult
{
	noChange = 0,
	positionChanged = 1,
	targetLost = 2,
};

enum class EArkNpcDesireTargetType
{
	none = 0,
	position = 1,
	entity = 2,
	bone = 3,
	offset = 4,
	boundsCenter = 5,
	proxy = 6,
	camera = 7,
	direction = 8,
	attackPos = 9,
};

enum class EArkNpcFacingDesireCallbackEvent
{
	activated = 0,
	deactivated = 1,
	fulfilled = 2,
	failed = 3,
	resumed = 4,
	targetMoved = 5,
	targetLost = 6,
};

enum class EArkNpcFacingDesirePriority
{
	ambient = 0,
	movement = 1,
	distracted = 2,
	following = 3,
	attention = 4,
	search = 5,
	combat = 6,
	surprise = 7,
	escape = 8,
	script = 9,
	flowGraph = 10,
	trackView = 11,
	conversation = 12,
	fullbodyAction = 13,
	reaction = 14,
	ragdollBlend = 15,
	debug = 16,
};

enum class EArkNpcLookDesireCallbackEvent
{
	activated = 0,
	deactivated = 1,
	fulfilled = 2,
	resumed = 3,
	targetMoved = 4,
	targetLost = 5,
};

enum class EArkNpcLookDesirePriority
{
	ambient = 0,
	distracted = 1,
	following = 2,
	attention = 3,
	search = 4,
	combat = 5,
	surprise = 6,
	script = 7,
	flowGraph = 8,
	trackView = 9,
	conversation = 10,
	fullbodyAction = 11,
	reaction = 12,
	ragdollBlend = 13,
	debug = 14,
};

enum class EArkNpcMimicryReason
{
	none = 0,
	ambush = 1,
	escape = 2,
	timid = 3,
	wander = 4,
	_count = 5,
};

enum class EArkNpcMovementDesireCallbackEvent
{
	activated = 0,
	deactivated = 1,
	fulfilled = 2,
	failed = 3,
	resumed = 4,
	destinationMoved = 5,
	destinationLost = 6,
};

enum class EArkNpcMovementDesirePriority
{
	ambient = 0,
	distracted = 1,
	following = 2,
	flowgraphAmbient = 3,
	attention = 4,
	search = 5,
	combat = 6,
	surprise = 7,
	escape = 8,
	script = 9,
	flowGraph = 10,
	trackView = 11,
	conversation = 12,
	fullbodyAction = 13,
	reaction = 14,
	gooed = 15,
	ragdollBlend = 16,
	debug = 17,
};

enum class EArkNpcNoiseState
{
	idle = 0,
	notice = 1,
	stare = 2,
	search = 3,
	combat = 4,
	count_ = 5,
};

enum class EArkNpcNoiseStateDesirePriority
{
	npc = 0,
	notice = 1,
	search = 2,
	combat = 3,
};

enum class EArkNpcSpeedDesireCallbackEvent
{
	activated = 0,
	deactivated = 1,
};

enum class EArkNpcSpeedDesirePriority
{
	ambient = 0,
	distracted = 1,
	following = 2,
	attention = 3,
	search = 4,
	combat = 5,
	escape = 6,
	script = 7,
	flowGraph = 8,
	trackView = 9,
	fullbodyAction = 10,
	reaction = 11,
	debug = 12,
};

enum class EArkNpcSpeedType
{
	normal = 0,
	fast = 1,
	fastest = 2,
};

enum class EArkNpcVisionDirection
{
	cameraBone = 0,
	lookJoint = 1,
	mimic = 2,
	cameraBoneForward = 3,
};

enum class EArkObjectiveState
{
	UNASSIGNED = 0,
	ASSIGNED = 1,
	COMPLETED = 2,
	FAILED = 3,
	CANCELLED = 4,
};

enum class EArkObjectiveTaskState
{
	ACTIVE = 0,
	INACTIVE = 1,
	COMPLETED = 2,
	FAILED = 3,
};

enum class EArkObstacleAvoidanceUrgency
{
	Low = 0,
	High = 1,
};

enum class EArkOptionPlatform
{
	All = 0,
	PC = 1,
	Console = 2,
	Last = 3,
};

enum class EArkPhantomCombatStateId
{
	any = -1,
	null = 0,
	rangedAttacking = 1,
	rangedShifting = 2,
	regainLineOfSight = 3,
	debugState = 4,
	meleeAttacking = 5,
	unreachableTargeting = 6,
	reacquireTargetAngle = 7,
	meleeShifting = 8,
	shiftToRange = 9,
	movingBackIntoRange = 10,
	count_ = 11,
};

enum class EArkPlayerLightPriority
{
	Weapon = 0,
	PsiPower = 1,
	Flashlight = 2,
	Psychoscope = 3,
	Count = 4,
};

enum class EArkPlayerMovementStateId
{
	any = -1,
	null = 0,
	ground = 1,
	death = 2,
	deathByRecyclerGrenade = 3,
	jump = 4,
	fall = 5,
	climb = 6,
	fly = 7,
	smoke = 8,
	zerog = 9,
	cinematic = 10,
	slide = 11,
	mimic = 12,
	gravShaftG = 13,
	gravShaftToG = 14,
	gravShaftZeroG = 15,
	lift = 16,
	shift = 17,
	count_ = 18,
};

enum class EArkPlayerStatus
{
	Invalid = 0,
	Bleeding = 1,
	Blind = 2,
	Burning = 3,
	Concussion = 4,
	Crippled = 5,
	Disruption = 6,
	Exhausted = 7,
	Fear = 8,
	PsychoShock = 9,
	Radiation = 10,
	SuitIntegrity = 11,
	WellFed = 12,
	Drunk = 13,
	GoodDrunk = 14,
	Stun = 15,
	Oxygen = 16,
	Last = 17,
};

enum class EArkPoltergeistVisibilityState
{
	Invisible = 0,
	Visible = 1,
	Appearing = 2,
	Disappearing = 3,
	PsychoscopeAppearing = 4,
	PsychoscopeVisible = 5,
	PsychoscopeDisappearing = 6,
};

enum class EArkPostEffectDataType
{
	Any = -1,
	Boolean = 0,
	Integer = 1,
	Float = 2,
	Color = 3,
	Vector4 = 4,
	Texture = 5,
};

enum class EArkPsiPowerError
{
	None = 0,
	NoTargets = 1,
};

enum class EArkPsiPowers
{
	firstPower = -1,
	electrostaticBurst = 0,
	thermalBlast = 1,
	kineticShield = 2,
	kineticBlast = 3,
	lift = 4,
	remoteManipulation = 5,
	mimic = 6,
	smokeForm = 7,
	fear = 8,
	mindBlast = 9,
	hypnosis = 10,
	cyberkinesis = 11,
	createPhantom = 12,
	shift = 13,
	combatFocus = 14,
	empty = 15,
	last = 16,
};

enum class EArkRecyclerState
{
	Invalid = 0,
	Idle = 1,
	Processing = 2,
	Producing = 3,
};

enum class EArkResponseCompareType
{
	equals = 0,
	greater_than = 1,
	less_than = 2,
	greater_eq = 3,
	less_eq = 4,
	not_equal = 5,
	is_a = 6,
	num_values = 7,
};

enum class EArkResponseKey
{
	voice = 0,
	concept = 1,
	random = 2,
	talking = 3,
	itemName = 4,
	entityClassName = 5,
	distance = 6,
	health = 7,
	group = 8,
	damage = 9,
	character = 10,
	location = 11,
	playerHealth = 12,
	corrupted = 13,
	trauma = 14,
	traumaCount = 15,
	attentionLevel = 16,
	playerIsInCombat = 17,
	priority = 18,
	dispositionToPlayer = 19,
	npcIsControlled = 20,
	upgrades = 21,
	durability = 22,
	ammo = 23,
	kills = 24,
	importantConversation = 25,
	isBroken = 26,
	isCowering = 27,
	isFeared = 28,
	isGlooed = 29,
	isLurking = 30,
	playerAbilityTier = 31,
	playerAlternateForm = 32,
	playerNeuromods = 33,
	playerPsi = 34,
	distraction = 35,
	targetCharacter = 36,
	suitIntegrity = 37,
	scansRemaining = 38,
	last = 39,
};

enum class EArkSaveFailure
{
	None = 0,
	Cinematic = 1,
	Dead = 2,
	LowHealth = 3,
	LowOxygen = 4,
	InAir = 5,
	HazardSignal = 6,
	ImpendingDanger = 7,
	InCombat = 8,
	Shifting = 9,
	MimicGrab = 10,
};

enum class EArkSaveFileType
{
	autosave = 0,
	quicksave = 1,
	manual = 2,
	ironman = 3,
	count_ = 4,
};

enum class EArkSaveLoadMode
{
	disabled = 0,
	prompt = 1,
	newGame = 2,
	newGamePlus = 3,
	load = 4,
	save = 5,
	gameOptions = 6,
	loadTransition = 7,
};

enum class EArkSearchFsmStateId
{
	any = -1,
	null = 0,
	debugState = 1,
	investigate = 2,
	examineAnim = 3,
	examineStare = 4,
	hunt = 5,
	count_ = 6,
};

enum class EArkSilhouetteType
{
	MarkedEnemy = 1,
	Pickup = 2,
	PsiTargeting = 4,
};

enum class EArkStationWorldUIState
{
	Invalid = 0,
	Locked = 1,
	RootMenu = 2,
	Email = 3,
	Utility = 4,
	ChildDefined = 5,
};

enum class EArkSurfaceHazardState
{
	Invalid = 0,
	Inert = 1,
	Triggered = 2,
	Hazard = 3,
	Depleted = 4,
};

enum class EArkTaskMarkerStyle
{
	main = 0,
	roster = 1,
	side = 2,
	_count = 3,
};

enum class EArkTechnopathCombatStateId
{
	any = -1,
	null = 0,
	attackingInPlace = 1,
	retreatingFromTarget = 2,
	movingToTarget = 3,
	regainLoS = 4,
	debugState = 5,
	count_ = 6,
};

enum class EArkTelepathCombatStateId
{
	any = -1,
	null = 0,
	attackingInPlace = 1,
	retreatingFromTarget = 2,
	movingToTarget = 3,
	regainLoS = 4,
	debugState = 5,
	count_ = 6,
};

enum class EArkTurretAnimStateId
{
	any = -1,
	null = 0,
	undeployed = 1,
	deploying = 2,
	deployed = 3,
	undeploying = 4,
	destroyed = 5,
	broken = 6,
	searching = 7,
	count_ = 8,
};

enum EArkTurretSFX
{
	eDetect = 0,
	eLostTarget = 1,
	eFire = 2,
	eDestroy = 3,
	eGooStuck = 4,
	eDamagedStart = 5,
	eDamagedStop = 6,
	eDisabledStart = 7,
	eDisabledStopRepaired = 8,
	eDisabledStopDestroyed = 9,
	eStunnedStart = 10,
	eStunnedStop = 11,
	eSize = 12,
};

enum class EArkVitalSign
{
	NoLifeSigns = 0,
	Nominal = 1,
	Error = 2,
	Safe = 3,
	Last = 4,
};

enum class EArkWeaverEscapeStateId
{
	any = -1,
	null = 0,
	attacking = 1,
	movingToRetreatObject = 2,
	spooked = 3,
	done = 4,
	debugState = 5,
	count_ = 6,
};

enum class EArkZoomPriority
{
	none = 0,
	lowest = 1,
	low = 2,
	normal = 3,
	high = 4,
	highest = 5,
};

enum EBodyDamagePIDFlags
{
	eBodyDamage_PID_None = 0,
	eBodyDamage_PID_Headshot = 1,
	eBodyDamage_PID_Foot = 2,
	eBodyDamage_PID_Groin = 4,
	eBodyDamage_PID_Knee = 8,
	eBodyDamage_PID_WeakSpot = 16,
	eBodyDamage_PID_Helmet = 32,
};

enum class EBodyOrientationMode
{
	FullyTowardsMovementDirection = 0,
	FullyTowardsAimOrLook = 1,
	HalfwayTowardsAimOrLook = 2,
};

enum class ECallAndActivateEffectOnNpcsStage
{
	InitializingCall = 0,
	CallingNPCs = 1,
	WaitingToEnd = 2,
};

enum ECardinalDirection
{
	eCD_Invalid = -1,
	eCD_Forward = 0,
	eCD_Back = 1,
	eCD_Left = 2,
	eCD_Right = 3,
	eCD_Ahead = 4,
	eCD_Behind = 5,
	eCD_LeftSide = 6,
	eCD_RightSide = 7,
};

enum EChatMessageType
{
	eChatToTarget = 0,
	eChatToTeam = 1,
	eChatToAll = 2,
};

enum EColliderMode
{
	eColliderMode_Undefined = 0,
	eColliderMode_Disabled = 1,
	eColliderMode_GroundedOnly = 2,
	eColliderMode_Pushable = 3,
	eColliderMode_NonPushable = 4,
	eColliderMode_PushesPlayersOnly = 5,
	eColliderMode_Spectator = 6,
	eColliderMode_NoWorld = 7,
	eColliderMode_COUNT = 8,
	eColliderMode_FF = 255,
};

enum EControlScheme
{
	eControlScheme_NotSpecified = 0,
	eControlScheme_Keyboard = 1,
	eControlScheme_KeyboardMouse = 2,
	eControlScheme_XBoxOneController = 3,
	eControlScheme_PS4Controller = 4,
	eControlScheme_SteamController = 5,
};

enum class ECorruptNpcStage
{
	PreAbilityFacing = 0,
	PlayingCastEffect = 1,
	Casting = 2,
	CorruptionTraveling = 3,
	Done = 4,
};

enum ECryLobbyError
{
	eCLE_Success = 0,
	eCLE_SuccessContinue = 1,
	eCLE_ServiceNotSupported = 2,
	eCLE_AlreadyInitialised = 3,
	eCLE_NotInitialised = 4,
	eCLE_TooManyTasks = 5,
	eCLE_OutOfMemory = 6,
	eCLE_OutOfSessionUserData = 7,
	eCLE_UserDataNotRegistered = 8,
	eCLE_UserDataTypeMissMatch = 9,
	eCLE_TooManySessions = 10,
	eCLE_InvalidSession = 11,
	eCLE_InvalidRequest = 12,
	eCLE_SPAFileOutOfDate = 13,
	eCLE_ConnectionFailed = 14,
	eCLE_SessionFull = 15,
	eCLE_SessionWrongState = 16,
	eCLE_UserNotSignedIn = 17,
	eCLE_InvalidParam = 18,
	eCLE_TimeOut = 19,
	eCLE_InsufficientPrivileges = 20,
	eCLE_AlreadyInSession = 21,
	eCLE_LeaderBoardNotRegistered = 22,
	eCLE_UserNotInSession = 23,
	eCLE_OutOfUserData = 24,
	eCLE_NoUserDataRegistered = 25,
	eCLE_ReadDataNotWritten = 26,
	eCLE_UserDataMissMatch = 27,
	eCLE_InvalidUser = 28,
	eCLE_PSNContextError = 29,
	eCLE_PSNWrongSupportState = 30,
	eCLE_SuccessUnreachable = 31,
	eCLE_ServerNotDefined = 32,
	eCLE_WorldNotDefined = 33,
	eCLE_SystemIsBusy = 34,
	eCLE_TooManyParameters = 35,
	eCLE_NotEnoughParameters = 36,
	eCLE_DuplicateParameters = 37,
	eCLE_ExceededReadWriteLimits = 38,
	eCLE_InvalidTitleID = 39,
	eCLE_IllegalSessionJoin = 40,
	eCLE_InternetDisabled = 41,
	eCLE_NoOnlineAccount = 42,
	eCLE_NotConnected = 43,
	eCLE_CyclingForInvite = 44,
	eCLE_CableNotConnected = 45,
	eCLE_SessionNotMigratable = 46,
	eCLE_SuccessInvalidSession = 47,
	eCLE_RoomDoesNotExist = 48,
	eCLE_PSNUnavailable = 49,
	eCLE_TooManyOrders = 50,
	eCLE_InvalidOrder = 51,
	eCLE_OrderInUse = 52,
	eCLE_OnlineAccountBlocked = 53,
	eCLE_AgeRestricted = 54,
	eCLE_ReadDataCorrupt = 55,
	eCLE_PasswordIncorrect = 56,
	eCLE_InvalidInviteFriendData = 57,
	eCLE_InvalidJoinFriendData = 58,
	eCLE_InvalidPing = 60,
	eCLE_CDKeyMalformed = 61,
	eCLE_CDKeyUnknown = 62,
	eCLE_CDKeyAuthFailed = 63,
	eCLE_CDKeyDisabled = 64,
	eCLE_CDKeyInUse = 65,
	eCLE_MultipleSignIn = 66,
	eCLE_Banned = 67,
	eCLE_CDKeyTimeOut = 68,
	eCLE_IncompleteLoginCredentials = 69,
	eCLE_WrongVersion = 70,
	eCLE_NoServerAvailable = 71,
	eCLE_ArbitratorTimeOut = 72,
	eCLE_RequiresInvite = 73,
	eCLE_SteamInitFailed = 74,
	eCLE_SteamBlocked = 75,
	eCLE_NothingToEnumerate = 76,
	eCLE_ServiceNotConnected = 77,
	eCLE_GlobalBan = 78,
	eCLE_Kicked = 79,
	eCLE_Cancelled = 79,
	eCLE_UnhandledNickError = 80,
	eCLE_InternalError = 81,
	eCLE_NumErrors = 82,
};

enum ECryLobbyInviteType
{
	eCLIT_InviteToSquad = 0,
	eCLIT_JoinSessionInProgress = 1,
	eCLIT_InviteToSession = 2,
};

enum ECryLobbyService
{
	eCLS_LAN = 0,
	eCLS_Online = 1,
	eCLS_NumServices = 2,
};

enum ECryTCPServiceResult
{
	eCTCPSR_Ok = 0,
	eCTCPSR_Failed = 1,
};

enum EDeferredMfxExplosionState
{
	eDeferredMfxExplosionState_None = 0,
	eDeferredMfxExplosionState_Dispatched = 1,
	eDeferredMfxExplosionState_ProcessingComplete = 2,
	eDeferredMfxExplosionState_ResultImpact = 3,
	eDeferredMfxExplosionState_ResultNoImpact = 4,
};

enum EDifficulty
{
	eDifficulty_Default = 0,
	eDifficulty_Easy = 1,
	eDifficulty_Normal = 2,
	eDifficulty_Hard = 3,
	eDifficulty_Delta = 4,
	eDifficulty_PostHuman = 5,
	eDifficulty_COUNT = 6,
};

enum EDisconnectionCause
{
	eDC_Timeout = 0,
	eDC_ProtocolError = 1,
	eDC_ResolveFailed = 2,
	eDC_VersionMismatch = 3,
	eDC_ServerFull = 4,
	eDC_Kicked = 5,
	eDC_Banned = 6,
	eDC_ContextCorruption = 7,
	eDC_AuthenticationFailed = 8,
	eDC_GameError = 9,
	eDC_NotDX11Capable = 10,
	eDC_NubDestroyed = 11,
	eDC_ICMPError = 12,
	eDC_NatNegError = 13,
	eDC_PunkDetected = 14,
	eDC_DemoPlaybackFinished = 15,
	eDC_DemoPlaybackFileNotFound = 16,
	eDC_UserRequested = 17,
	eDC_NoController = 18,
	eDC_CantConnect = 19,
	eDC_ArbitrationFailed = 20,
	eDC_FailedToMigrateToNewHost = 21,
	eDC_SessionDeleted = 22,
	eDC_KickedHighPing = 23,
	eDC_KickedReservedUser = 24,
	eDC_ClassRegistryMismatch = 25,
	eDC_GloballyBanned = 26,
	eDC_Global_Ban1 = 27,
	eDC_Global_Ban2 = 28,
	eDC_Unknown = 29,
};

enum EERType
{
	eERType_NotRenderNode = 0,
	eERType_Brush = 1,
	eERType_Vegetation = 2,
	eERType_Light = 3,
	eERType_ArkRemoved_01 = 4,
	eERType_Dummy_1 = 5,
	eERType_FogVolume = 6,
	eERType_Decal = 7,
	eERType_ParticleEmitter = 8,
	eERType_WaterVolume = 9,
	eERType_ArkRemoved_02 = 10,
	eERType_Road = 11,
	eERType_DistanceCloud = 12,
	eERType_VolumeObject = 13,
	eERType_Dummy_0 = 14,
	eERType_Rope = 15,
	eERType_PrismObject = 16,
	eERType_TerrainSector = 17,
	eERType_ArkRemoved_03 = 18,
	eERType_RenderProxy = 19,
	eERType_GameEffect = 20,
	eERType_ArkRemoved_04 = 21,
	eERType_Dummy_3 = 22,
	eERType_MergedMesh = 23,
	eERType_GeomCache = 24,
	eERType_ArkBreakableGlass = 25,
	eERType_TypesNum = 26,
};

enum EFlowDataTypes
{
	eFDT_Any = -1,
	eFDT_Void = 0,
	eFDT_Int = 1,
	eFDT_Float = 2,
	eFDT_EntityId = 3,
	eFDT_Vec3 = 4,
	eFDT_String = 5,
	eFDT_Bool = 6,
};

enum class EGameMechanismEvent
{
	kGMEvent_GameRulesInit = 0,
	kGMEvent_GameRulesRestart = 1,
	kGMEvent_GameRulesDestroyed = 2,
	kGMEvent_LocalPlayerInit = 3,
	kGMEvent_LocalPlayerDeinit = 4,
	kGMEvent_LoadGame = 5,
	kGMEvent_SaveGame = 6,
};

enum EGameMode
{
	eGM_INVALID_GAMEMODE = -1,
	eGM_SinglePlayer = 0,
	eGM_AllOrNothing = 1,
	eGM_Assault = 2,
	eGM_BombTheBase = 3,
	eGM_CaptureTheFlag = 4,
	eGM_Countdown = 5,
	eGM_CrashSite = 6,
	eGM_Extraction = 7,
	eGM_InstantAction = 8,
	eGM_TeamInstantAction = 9,
	eGM_PowerStruggle = 10,
	eGM_Gladiator = 11,
	eGM_DeathMatch = 12,
	eGM_NUM_GAMEMODES = 13,
};

enum EGameOverReason
{
	EGOR_TimeLimitReached = 1,
	EGOR_ScoreLimitReached = 2,
	EGOR_ObjectivesCompleted = 3,
	EGOR_NoLivesRemaining = 4,
	EGOR_OpponentsDisconnected = 5,
	EGOR_DrawRoundsResolvedWithMessage = 6,
	EGOR_Unknown = 7,
};

enum EGameResourceType
{
	eGameResourceType_Loadout = 0,
	eGameResourceType_Item = 1,
};

enum EGodModeState
{
	eGMS_None = 0,
	eGMS_GodMode = 1,
	eGMS_TeamGodMode = 2,
	eGMS_DemiGodMode = 3,
	eGMS_NearDeathExperience = 4,
	eGMS_LAST = 5,
};

enum ELadderLeaveLocation
{
	eLLL_First = 0,
	eLLL_Top = 0,
	eLLL_Bottom = 1,
	eLLL_Drop = 2,
	eLLL_Count = 3,
};

enum class ELaunchCystoidsAttackStage
{
	Casting = 0,
	LaunchingCystoids = 1,
	Done = 2,
};

enum ELoadGameResult
{
	eLGR_Ok = 0,
	eLGR_Failed = 1,
	eLGR_FailedAndDestroyedState = 2,
	eLGR_CantQuick_NeedFullLoad = 3,
	eLGR_CalledTooQuickly = 4,
	eLGR_Streaming = 5,
	eLGR_missingDLC = 6,
	eLGR_NoSavesExist = 7,
	eLGR_IncompatibleVersion = 8,
};

enum class ELookStyle
{
	LOOKSTYLE_DEFAULT = 0,
	LOOKSTYLE_HARD = 1,
	LOOKSTYLE_HARD_NOLOWER = 2,
	LOOKSTYLE_SOFT = 3,
	LOOKSTYLE_SOFT_NOLOWER = 4,
	LOOKSTYLE_COUNT = 5,
};

enum class EMaterialParamFloat
{
	unknown = 0,
	opacity = 1,
	alpha_test = 2,
	smoothness = 3,
	emissive_intensity = 4,
};

enum class EMaterialParamVec3
{
	unknown = 0,
	diffuse_color = 1,
	specular_color = 2,
	emissive_color = 3,
};

enum EModInfoType
{
	eMIT_UNDEFINED = 0,
	eMIT_SPMOD = 1,
	eMIT_MPMOD = 2,
	eMIT_SPANDMPMOD = 3,
	eMIT_SPLEVEL = 4,
};

enum EMovementControlMethod
{
	eMCM_Undefined = 0,
	eMCM_Entity = 1,
	eMCM_Animation = 2,
	eMCM_DecoupledCatchUp = 3,
	eMCM_ClampedEntity = 4,
	eMCM_SmoothedEntity = 5,
	eMCM_AnimationHCollision = 6,
	eMCM_EntityAnimBlend = 7,
	eMCM_COUNT = 8,
	eMCM_FF = 255,
};

enum EMovementTransitionState
{
	eMTS_None = 0,
	eMTS_WaitingForRange = 1,
	eMTS_Preparing = 2,
	eMTS_Requesting_Succeeded = 3,
	eMTS_Requesting_DelayedBecauseControllerRequestFailed = 4,
	eMTS_Requesting_DelayedBecauseAngleOutOfRange = 5,
	eMTS_Requesting_DelayedBecauseWalkabilityFail = 6,
	eMTS_COUNT = 7,
};

enum EPlatform
{
	ePlatform_Unknown = 0,
	ePlatform_PC = 1,
	ePlatform_XBoxOne = 2,
	ePlatform_PS4 = 3,
	ePlatform_COUNT = 4,
};

enum class EPlayerActionPriority
{
	PP_Lowest = 0,
	PP_Movement = 1,
	PP_MovementAction = 2,
	PP_Trackview = 3,
	PP_PlayerAction = 4,
	PP_PlayerActionUrgent = 5,
	PP_HitReactionStagger = 6,
	PP_HitReactionKnockdown = 7,
	PP_InAir = 8,
	PP_InAirRebound = 9,
	PP_Ragdoll = 10,
	PP_Death = 11,
	PP_BlocksRagdoll = 12,
	PP_PostDeath = 13,
};

enum class EPlayerSex
{
	male = 0,
	female = 1,
	count = 2,
};

enum EPostEffectCurve
{
	ePEC_in = 0,
	ePEC_loop = 1,
	ePEC_out = 2,
	ePEC_blendOut = 3,
	ePEC_count = 4,
};

enum class EPriorityComparison
{
	Lower = 0,
	Equal = 1,
	Higher = 2,
};

enum class ERaisePhantomStage
{
	MovingToTarget = 0,
	StartingRaise = 1,
	RaisingPhantom = 2,
	Done = 3,
};

enum class EReactionHitType
{
	knockdown = 0,
	stagger = 1,
	smallHit = 2,
	smallAdditive = 3,
	kill = 4,
	none = 5,
};

enum class EReactionThrowAtType
{
	rail = 0,
	glass = 1,
	ledge = 2,
	breakable = 3,
};

enum class EResponseTrackMethod
{
	none = 0,
	headAndTorsoTrack = 1,
	turnToFace = 2,
	headTrack = 3,
};

enum class EResponseTrackTargetType
{
	noone = 0,
	player = 1,
	character = 2,
};

enum class EStance
{
	STANCE_UNLOCKED = -2,
	STANCE_NULL = -1,
	STANCE_STAND = 0,
	STANCE_SNEAK = 1,
	STANCE_CRAWL = 2,
	STANCE_SMOKE = 3,
	STANCE_PRONE = 4,
	STANCE_RELAXED = 5,
	STANCE_STEALTH = 6,
	STANCE_ALERTED = 7,
	STANCE_SWIM = 8,
	STANCE_ZEROG = 9,
	STANCE_HOVER = 10,
	STANCE_CORRUPTED = 11,
	STANCE_INVESTIGATE_ANOMALY = 12,
	STANCE_INVESTIGATE_DANGER = 13,
	STANCE_INVESTIGATE_VISION = 14,
	STANCE_HUNT = 15,
	STANCE_GUNUP = 16,
	STANCE_CHARGE = 17,
	STANCE_LAST = 18,
};

enum class EStrafeStateId
{
	any = -1,
	null = 0,
	charging = 1,
	swipe = 2,
	count_ = 3,
};

enum class ESwipeStateId
{
	any = -1,
	null = 0,
	facing = 1,
	charging = 2,
	strafe = 3,
	count_ = 4,
};

enum ETextMessageType
{
	eTextMessageCenter = 0,
	eTextMessageConsole = 1,
	eTextMessageError = 2,
	eTextMessageInfo = 3,
	eTextMessageServer = 4,
	eTextMessageAnnouncement = 5,
};

enum ETransitionType
{
	eTT_None = -1,
	eTT_Start = 0,
	eTT_Stop = 1,
	eTT_DirectionChange = 2,
};

enum class EWeaverThreatType
{
	none = 0,
	unseenNearby = 1,
	seenFaraway = 2,
	seenNearby = 3,
};

enum EXBoxKey
{
	eXBK_Invalid = -1,
	eXBK_DPadUp = 0,
	eXBK_DPadDown = 1,
	eXBK_DPadLeft = 2,
	eXBK_DPadRight = 3,
	eXBK_Start = 4,
	eXBK_Back = 5,
	eXBK_ThumbL = 6,
	eXBK_ThumbR = 7,
	eXBK_ShoulderL = 8,
	eXBK_ShoulderR = 9,
	eXBK_A = 10,
	eXBK_B = 11,
	eXBK_X = 12,
	eXBK_Y = 13,
	eXBK_TriggerL = 14,
	eXBK_TriggerR = 15,
	eXBK_ThumbLX = 16,
	eXBK_ThumbLY = 17,
	eXBK_ThumbLUp = 18,
	eXBK_ThumbLDown = 19,
	eXBK_ThumbLLeft = 20,
	eXBK_ThumbLRight = 21,
	eXBK_ThumbRX = 22,
	eXBK_ThumbRY = 23,
	eXBK_ThumbRUp = 24,
	eXBK_ThumbRDown = 25,
	eXBK_ThumbRLeft = 26,
	eXBK_ThumbRRight = 27,
	eXBK_TriggerLBtn = 28,
	eXBK_TriggerRBtn = 29,
};

enum class EXPReason
{
	k_XPRsn_EPP_FirstBlood = 0,
	k_XPRsn_EPP_KickedCar = 1,
	k_XPRsn_EPP_QuinKill = 2,
	k_XPRsn_EPP_QuadKill = 3,
	k_XPRsn_EPP_TripleKill = 4,
	k_XPRsn_EPP_DoubleKill = 5,
	k_XPRsn_EPP_StealthKill = 6,
	k_XPRsn_EPP_StealthKillWithSPModule = 7,
	k_XPRsn_EPP_Recovery = 8,
	k_XPRsn_EPP_BlindKill = 9,
	k_XPRsn_EPP_Blinding = 10,
	k_XPRsn_EPP_Flushed = 11,
	k_XPRsn_EPP_DualWeapon = 12,
	k_XPRsn_EPP_NearDeathExperience = 13,
	k_XPRsn_EPP_KillJoy = 14,
	k_XPRsn_EPP_Intervention = 15,
	k_XPRsn_EPP_GotYourBack = 16,
	k_XPRsn_EPP_Guardian = 17,
	k_XPRsn_EPP_Retaliation = 18,
	k_XPRsn_EPP_Piercing = 19,
	k_XPRsn_EPP_Rumbled = 20,
	k_XPRsn_EPP_MeleeTakedown = 21,
	k_XPRsn_EPP_Headshot = 22,
	k_XPRsn_EPP_AirDeath = 23,
	k_XPRsn_EPP_TeamRadar = 24,
	k_XPRsn_EPP_MicrowaveBeam = 25,
	k_XPRsn_EPP_SuitBoost = 26,
	k_XPRsn_EPP_Swarmer = 27,
	k_XPRsn_EPP_EMPBlast = 28,
	k_XPRsn_EPP_BlindAssist = 29,
	k_XPRsn_EPP_FlushedAssist = 30,
	k_XPRsn_EPP_SuitSuperChargedKill = 31,
	k_XPRsn_EPP_Incoming = 32,
	k_XPRsn_EPP_Pang = 33,
	k_XPRsn_EPP_AntiAirSupport = 34,
	k_XPRsn_EGRST_PlayerKill = 35,
	k_XPRsn_EGRST_PlayerKillAssist = 36,
	k_XPRsn_EGRST_PlayerKillAssistTeam1 = 37,
	k_XPRsn_EGRST_PlayerKillAssistTeam2 = 38,
	k_XPRsn_EGRST_PlayerTeamKill = 39,
	k_XPRsn_EGRST_Suicide = 40,
	k_XPRsn_EGRST_Tagged_PlayerKillAssist = 41,
	k_XPRsn_EGRST_SingleHanded = 42,
	k_XPRsn_EGRST_FlagAssist = 43,
	k_XPRsn_EGRST_CaptureObjectiveHeld = 44,
	k_XPRsn_EGRST_CaptureObjectiveTaken = 45,
	k_XPRsn_EGRST_CaptureObjectiveCompleted = 46,
	k_XPRsn_EGRST_CaptureObjectivesDefended = 47,
	k_XPRsn_EGRST_AON_Win = 48,
	k_XPRsn_EGRST_AON_Draw = 49,
	k_XPRsn_EGRST_CarryObjectiveTaken = 50,
	k_XPRsn_EGRST_CarryObjectiveRetrieved = 51,
	k_XPRsn_EGRST_CarryObjectiveCarrierKilled = 52,
	k_XPRsn_EGRST_CarryObjectiveDefended = 53,
	k_XPRsn_EGRST_CarryObjectiveCompleted = 54,
	k_XPRsn_EGRST_BombTheBaseCompleted = 55,
	k_XPRsn_EGRST_KingOfTheHillObjectiveHeld = 56,
	k_XPRsn_EGRST_HoldObj_OffensiveKill = 57,
	k_XPRsn_EGRST_HoldObj_DefensiveKill = 58,
	k_XPRsn_EGRST_CombiCapObj_Att_PlayerKill = 59,
	k_XPRsn_EGRST_CombiCapObj_Def_PlayerKill = 60,
	k_XPRsn_EGRST_CombiCapObj_Win = 61,
	k_XPRsn_EGRST_CombiCapObj_Def_Win_IntelRemainBonus_Max = 62,
	k_XPRsn_EGRST_CombiCapObj_Att_Lost_IntelDownloadedBonus_Max = 63,
	k_XPRsn_EGRST_CombiCapObj_Def_Lost_TimeRemainBonus_Max = 64,
	k_XPRsn_EGRST_CombiCapObj_Capturing_PerSec = 65,
	k_XPRsn_EGRST_Extraction_AttackingKill = 66,
	k_XPRsn_EGRST_Extraction_DefendingKill = 67,
	k_XPRsn_EGRST_Extraction_ObjectiveReturnDefend = 68,
	k_XPRsn_EGRST_Gladiator_KillAsSoldier = 69,
	k_XPRsn_EGRST_Gladiator_KillAsGladiator = 70,
	k_XPRsn_EGRST_Gladiator_ActivateDisruptor = 71,
	k_XPRsn_EGRST_Predator_KillAsSoldier = 72,
	k_XPRsn_EGRST_Predator_KillAsPredator = 73,
	k_XPRsn_EGRST_Predator_FinalKillAsPredator = 74,
	k_XPRsn_EGRST_Predator_LastMarineStanding = 75,
	k_XPRsn_EGRST_Predator_TwoMarinesRemaining = 76,
	k_XPRsn_EGRST_Predator_ThreeMarinesRemaining = 77,
	k_XPRsn_EGRST_Predator_SurviveTimePeriod = 78,
	k_XPRsn_EGRST_Predator_SurviveToEnd = 79,
	k_XPRsn_EGRST_PowerStruggle_CaptureSpear = 80,
	k_XPRsn_EGRST_PowerStruggle_CaptureGiantSpear = 81,
	k_XPRsn_MatchBonus = 82,
	k_XPRsn_Cheat = 83,
	k_XPRsn_PreOrder = 84,
	k_XPRsn_Unknown = 85,
	k_XPRsn_SkillAssessment = 86,
	k_XPRsn_Num = 87,
};

enum class EncounterRepopStrategy
{
	consider_managed_population = 0,
	consider_total_hostile_population = 1,
};

enum class NpcActionStage
{
	start = 0,
	middle = 1,
	end = 2,
	complete = 3,
};

enum class ValidTargetResult
{
	valid = 0,
	mimicking = 1,
	dead = 2,
	hidden = 3,
	notHostile = 4,
	noAttention = 5,
	notValidUnknown = 6,
};

enum eGeometrySlot
{
	eIGS_FirstPerson = 0,
	eIGS_ThirdPerson = 1,
	eIGS_Owner = 2,
	eIGS_OwnerAnimGraph = 3,
	eIGS_OwnerAnimGraphLooped = 4,
	eIGS_Aux0 = 5,
	eIGS_Destroyed = 6,
	eIGS_Aux1 = 7,
	eIGS_ThirdPersonAux = 8,
	eIGS_Last = 9,
	eIGS_LastAnimSlot = 5,
	eIGS_LastLayerSlot = 2,
};

enum class ArkTutorialType
{
	Contextual = 0x0,
	Card = 0x1,
	Nag = 0x2,
};

enum class EArkLogType
{
	Unspecified = 0x0,
	ItemPickup = 0x1,
	SneakAttack = 0x2,
	CriticalAttack = 0x3,
	MimicHit = 0x4,
	Chipset = 0x5,
	EntitlementUnlock = 0x6,
	Airlock = 0x7,
};

// Same as SInputSymbol::EType
// Optimizer?
enum class ArkUtilityType
{
	Button = 0x0,
	Toggle = 0x1,
	RawAxis = 0x2,
	Axis = 0x3,
	Trigger = 0x4,
};

enum class ENavigationIDTag
{
	MeshIDTag = 0x0,
	AgentTypeIDTag = 0x1,
	VolumeIDTag = 0x2,
	ArkSpaceGridIDTag = 0x3,
};

// Optimizer?
using EArkComparisonType = EArkVitalSign;
