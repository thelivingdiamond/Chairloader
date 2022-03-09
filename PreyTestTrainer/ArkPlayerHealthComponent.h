typedef unsigned char   undefined;

typedef unsigned long long    GUID;
typedef unsigned int    ImageBaseOffset32;
typedef unsigned char    bool;
typedef unsigned char    byte;
typedef unsigned int    dword;
typedef long long    longlong;
typedef unsigned long long    qword;
typedef char    sbyte;
typedef signed char    schar;
typedef unsigned char    uchar;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned long long    ulonglong;
typedef unsigned char    undefined1;
typedef unsigned short    undefined2;
typedef unsigned int    undefined4;
typedef unsigned long long    undefined5;
typedef unsigned long long    undefined6;
typedef unsigned long long    undefined8;
typedef unsigned short    ushort;
typedef short    wchar_t;
typedef unsigned short    word;
typedef struct ArkPlayerHealthComponent ArkPlayerHealthComponent, *PArkPlayerHealthComponent;

typedef struct ArkAudioTrigger ArkAudioTrigger, *PArkAudioTrigger;

typedef struct CryStringT<char> CryStringT<char>, *PCryStringT<char>;

typedef struct ArkSimpleTimer ArkSimpleTimer, *PArkSimpleTimer;

typedef struct ArkPlayerHealthFeedback ArkPlayerHealthFeedback, *PArkPlayerHealthFeedback;

typedef struct Vec3_tpl<float> Vec3_tpl<float>, *PVec3_tpl<float>;

typedef struct IParticleEffect IParticleEffect, *PIParticleEffect;

typedef ulonglong __uint64;

typedef struct ArkAudioRtpc ArkAudioRtpc, *PArkAudioRtpc;

struct ArkAudioTrigger {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
};

struct ArkAudioRtpc {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
};

struct ArkPlayerHealthFeedback {
    float m_lowHealth;
    float m_nearDeath;
    float m_prevHealth;
    int m_vfxSlot;
    bool m_bTookDamageThisTick;
    struct IParticleEffect * m_pLowHealthParticle;
    struct IParticleEffect * m_pNearDeathParticle;
    __uint64 m_lowHealthPostEffect;
    __uint64 m_nearDeathPostEffect;
    struct ArkAudioTrigger m_triggerNearDeathStart;
    struct ArkAudioTrigger m_triggerNearDeathStop;
    struct ArkAudioTrigger m_triggerNearDeathStinger;
    struct ArkAudioRtpc m_rtpcNearDeathIntensity;
};

struct CryStringT<char> {
    char * m_str;
};

struct Vec3_tpl<float> {
    float x;
    float y;
    float z;
};

struct ArkSimpleTimer {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    float m_duration;
};

struct ArkPlayerHealthComponent {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    struct ArkAudioTrigger m_damageAudio;
    struct ArkAudioTrigger m_deathAudio;
    struct ArkAudioTrigger m_lastChanceAudio;
    struct ArkAudioTrigger m_regenStartAudio;
    struct ArkAudioTrigger m_regenStopAudio;
    undefined field13_0x1c;
    undefined field14_0x1d;
    undefined field15_0x1e;
    undefined field16_0x1f;
    struct CryStringT<char> m_deathCharacter;
    float m_damageSinceRegen;
    float m_elapsedSinceDamaged;
    struct ArkSimpleTimer m_lastChanceTimeout;
    struct ArkSimpleTimer m_timeRemainingBeforeDeathMenu;
    struct ArkPlayerHealthFeedback m_feedback;
    bool m_bDeathMenuOpened;
    bool m_bRegening;
    undefined field25_0x8a;
    undefined field26_0x8b;
    struct Vec3_tpl<float> m_bWeaponPosition;
    uint m_killer;
    undefined field29_0x9c;
    undefined field30_0x9d;
    undefined field31_0x9e;
    undefined field32_0x9f;
};

struct IParticleEffect {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
};

