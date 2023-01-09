Script.ReloadScript("Scripts/Entities/Actor/ArkNpc.lua")
Script.ReloadScript("Scripts/Entities/Actor/BasicActor.lua")
Script.ReloadScript("Scripts/Entities/AI/Shared/BasicAI.lua")
ArkNpcPlayer = {}
CreateActor(ArkNpcPlayer)
ArkNpcPlayer = CreateAI(ArkNpcPlayer)
CreateArkNpc(ArkNpcPlayer)
ArkNpcPlayer:Expose()
