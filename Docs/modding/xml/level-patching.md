# Level Patching

Chairloader has special handling for level objects in `mission_mission0.xml` file.

## Automatic GUID Generation
There are two major types of level objects: entities and non-entities. Entities have `EntityGUID` attribute (random 64-bit ID in hex). Non-entities don't have that attribute.

Chairloader automatically generates `EntityGUID` for non-entity objects and sets `ch:fakeGuid="true"` attribute. After all mods are merged, auto-generated GUIDs are removed from the file.

## Automatic EntityID Generation
Each level entity must have a unique `EntityId` attribute, which is a sequential 16-bit integer. To prevent conflicts between mods, Chairloader mods are not allowed to specify `EntityId` at all. After all mods are merged, Chairloader automatically assigns Entity IDs to mod entities.

Sometimes you need to know the Entity ID in the XML (e.g. to reference it from a flowgraph). Use values in the format `$(EntityId:[guid])` to reference an entity. This format only works in `mission_mission0.xml` and only references the entities in this file.

```xml
<EntityLinks>
    <Link
        TargetId="$(EntityId:409E604DF4F0F65F)"
        Name="NewLink" />
</EntityLinks>
```

## Automatic serialize.xml generation
`serialize.xml` lists the entities that must be serialized (written in the game's save file). `serialize.xml` references them by `EntityId`. Since EntityIDs are assigned by Chairloader, mods can't modify this file. Instead, set `ch:serialize="true"` attribute on entities that you wish to serialize. After all mods are merged, Chairloader will generate `serialize.xml` for each level based on `ch:serialize` values.

