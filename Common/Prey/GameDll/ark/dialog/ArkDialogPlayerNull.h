#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

class ArkSpeakerBase;
enum class EArkConversationDominance;
enum class EArkDialogPlayerType;
struct IEntity;
struct SDialogParams;

// ArkDialogPlayerNull
// Header:  _unknown/ArkDialogPlayerNull.h
class ArkDialogPlayerNull
{ // Size=8 (0x8)
public:
    virtual EArkDialogPlayerType GetType() const;

#if 0
    ArkDialogPlayerNull(ArkSpeakerBase* _arg0_);
    bool Play(const SDialogParams& _arg0_);
    void Stop(bool _arg0_);
    void Update(const float _arg0_);
    void SetVoiceEffect(unsigned _arg0_);
    void OnGamePause(bool _arg0_);
    bool IsPlaying() const;
    bool AreAllTriggersFree() const;
    void SetDuckAudio(bool _arg0_);
    EArkConversationDominance GetDefaultDominance() const;
    void PostSerialize();
    void OnConversationComplete(bool _arg0_);
    void OnDialogAnimationEvent();
    void SetEntity(IEntity* const _arg0_);
    void SetMute(bool _arg0_);
#endif

    static inline auto FGetType = PreyFunction<EArkDialogPlayerType(const ArkDialogPlayerNull* const _this)>(0x1CBB0B0);
};
#endif


