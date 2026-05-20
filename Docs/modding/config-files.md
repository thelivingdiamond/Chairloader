# Config Files
This is about how to setup and handle mod configuration files.

## Config Files and Default Config Files
Config files are very important for more advanced modding. When your mod is loaded into ChairManager, it attempts to locate a default mod config. This process looks for a file in your root mod directory with the corresponding name. This name should be: `YourModName_default.xml`. If this file is present, it will be copied to the config directory. If it is not, then a default blank file will be created in the config directory.

The root XML node should be named the same as your mod name. Each child node will be a config value, and each node must have a type attribute set, as is explained below. An example configuration file would be as follows:
```xml
<TheChair.ExampleMod version="1.0.0">
	<testString type="string" display_name="Test String">The quick brown fox jumped over the lazy dog</testString>
	<testBool type="bool" description="This is a test boolean">true</testBool>
	<testInt type="int" display_name="XXX Value">-200</testInt>
	<testUInt type="uint" display_name="YYY percent" description="Important number for stuff">4294967295</testUInt>
	<testInt64 type="int64">-12369420000000000</testInt64>
	<testUInt64 type="uint64">18446744073709551615</testUInt64>
	<testFloat type="float">68.7199936</testFloat>
	<testXMLNode type="xmlnode">
		<node1 type="string" display_name="Child Node 1">I am a child node</node1>
		<node2 type="string" display_name="Child Node 2">Important Config Details</node2>
	</testXMLNode>
	<testEnum type="enum" display_name="Test Enum Value" description="Hello this is a description">
		<selected>B</selected>
		<option name="Option A" description="Description of this option">A</option>
		<option name="Option B" description="Description of this option">B</option>
		<option name="Option C" description="Description of this option">C</option>
	</testEnum>
</TheChair.ExampleMod>
```

Each node must have a `type` attribute. In addition, each node may have additional special attributes:
- `display_name`: a human readable name
- `description`: a description of the node which is shown when hovering over the value in ChairManager

**It is important that every XML node be named in a way that is a valid variable name in Lua. This means it must consist of letters, underscores, and digits. It may not start with a digit. The names are case sensitive.**

## Value Types
Config values in chairloader are typed. This helps with both providing the correct editing environment for users and more advanced configuration features internally. The types available are:
- `bool`
- `int`
- `unsigned int`
- `enum`
- `int64`
- `unsigned int64`
- `float`
- `string`
- `xmlnode`

### **Boolean (Bool)**
- True/False Value

### **string**
- This is a string of characters, i.e. words and text.

### **enum**
- This is an enumerated value, meaning that it can only be one of several specified values. Currently these can only be string values
- Each value is an `<option>` xml node, and the currently selected is stored in `<selected>`.
- Each value node may have a `name` attribute in addition to a description attribute

### **int**
- 32 bit signed integer (can be negative or positive)

### **unsigned int**
- 32 bit unsigned integer (can only be positive)

### **int64**
- 64 bit signed integer (can be negative or positive)

### **unsigned int64**
- 64 bit unsigned integer (can only be positive)

### **float**
- Floating point decimal number (i.e. `1.5`, `20.62`, etc...)

### xmlnode
- This type indicates that it contains more XML rather than a text value
- These can serve as either folders for other config values or as a way to store a custom format of data in the config file.

## Lua Wildcard Attributes
When creating xml files, it is often useful to have xml attributes that are configurable. To accomplish this Chairloader implements what are called 'Attribute Wildcards'. There are several important specifications to keep in mind when using them:
1. In order to indicate that attributes should be used the attribute string must be in the following form: `xmlAttribute="{{ ExpressionHere }}"`
    - The use of double brackets is critical, as these are the tokens used to find and resolve these in the merging process
2. The expression string implements Lua, and can access config variables from your own mod and others. More details on the Lua and variable access specifications can be found below.
3. While uint64 and int64 are usable in C++, due to Lua limitations they are passed as strings, so they're not usable for calculations easily.

### Lua Syntax and Expressions
The Lua runs in a sandboxed environment that prohibits writing to global variables. This means that config values are constant values that cannot be changed during the merging process. When evaluating an expression, it is expected it will return a value, which is then passed back to the program and into the XML file. If there is no return statement present, then the evaluated Lua expression is: `return ( yourExpressionHere )`. If you would like to perform more complicated operations, you may instead include your own return statement in your expression.

Some of the advantages of this approach is the ability to use operations in your expressions. This means you can use things like boolean operators to combine expressions, comparison operators to test conditions, and more. Math, string concatenation, all of that is possible with just a little bit of Lua knowledge.

## Variable Access
In Attribute Wildcards all variables are stored according to a combination of the mod path and the xml path inside the config file. If the config variable comes from your mod, you only have to put the xml path, which is often just the name of the config node, i.e. just the global variable `valueName`. Nested nodes are accessible as `XmlNode1.Value`. If you are referring to an external mod, the variables are available as `G.ModName.value`.

### Enums
When accessing an enum by name, it returns the currently selected value. There is a second variable added with `_enum` appended to it. This is a table that stores the enumerated options. They are stored as `option0, option1, option2, ...` for as many options as are available.

## Special Functions
There are several functions available to the Lua environment that are specified by Chair Manager. They are:
- `IsModEnabled(string modName)`
    - This returns a boolean value indicating if the specified mod is enabled or not.
- `Random(int lowerBound, int upperBound)`
    - This returns a random integer from the lowerBound up to and including the upper bound.
- `RandomFloat(float lowerBound, float upperBound)`
    - This returns a random float from the lowerBound up to and including the upper bound. 

