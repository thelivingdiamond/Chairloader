# Meta Sequences
Chairloader mods can include special attributes in XML files. They will be processed by Chairloader when merging.

## Wildcards (expression evaluation)
Modders can add arbitrary Lua expressions into XML attribute and element values. For example, they can reference values in the [mod config](../config-files.md), perform math calculations or string concatenation.

Wildcards are expanded before everything else.

Wildcards must be enclosed in `{{` and `}}` tags.

Examples:
```xml
<Element something="{{ 2 + 2 }}" />
<Element something="{{ valueFromConfig }}" />
```

## Patching/Replacing/Deletion (ch:action)
You can add `ch:action` attribute to specify how XML node should be modded. This attribute replaces `ch:patch_mode` from previous versions of Chairloader.

- `patch` (default)  
  Mod node will be merged into the original node. Specified attributes will be update, while non-specified attributes will stay the same. Child nodes are merged as well.
- `delete`  
  If node is found in the original file, it will be deleted.
- `replace`  
  Mod will completely replace the original node.
- `replaceChildren`  
  Attributes are merged like in `patch`. Child nodes are replaced like in `replace`

## Conditionals (ch:applyIf)
You can add `ch:applyIf` attribute to any XML element. If that attribute is set and contains a "true" value (e.g. `true`, `yes`, `1`) after wildcard expansion, the element will be merged. If the value is false, the element is ignored (as if it doesn't exist in the mod).

Example (from [Touch-Up](https://www.nexusmods.com/prey2017/mods/102)):
```xml
<ArkHacking>
    <DifficultyLevels ch:applyIf="{{ Hacking_TimeChanges }}">
        <DifficultyLevel minTravelDistance="1.0" maxTravelDistance="1.5" timePerPuzzle="12.0" chainLength="1" pathObstacles="2" pathStunObstacles="2" otherStunObstacles="4" />
        <DifficultyLevel minTravelDistance="1.0" maxTravelDistance="1.5" timePerPuzzle="20.0" chainLength="1" pathObstacles="2" pathStunObstacles="2" otherStunObstacles="4" />
        <DifficultyLevel minTravelDistance="1.0" maxTravelDistance="1.5" timePerPuzzle="25.0" chainLength="2" pathObstacles="2" pathStunObstacles="2" otherStunObstacles="4" />
        <DifficultyLevel minTravelDistance="1.0" maxTravelDistance="1.5" timePerPuzzle="30.0" chainLength="2" pathObstacles="2" pathStunObstacles="2" otherStunObstacles="4" />
    </DifficultyLevels>
</ArkHacking>
```

## Based On (ch:basedOn)
`ch:basedOn` allows your mod to create a copy of an existing element (with changes from all other mods) and patch in your custom changes. This attribute used to be called `ch:copy_sibling`.

Value format: `"queryAttribute1=value1,queryAttribute2=value2"`

Example:
```xml
<EntityPrototype
    Name="Mimics.Mimic.TopHat"
    Id="{A6574C2A-284F-4B39-812B-F777ECEAEEAB}"
    ArchetypeId="4932200438019026768"
    ch:basedOn="Name=Mimics.Mimic">
    <Properties
        fileModel="Objects/characters/Aliens/Mimic/TopHat/Mimic_top_hat.cdf"/>
</EntityPrototype>
```
