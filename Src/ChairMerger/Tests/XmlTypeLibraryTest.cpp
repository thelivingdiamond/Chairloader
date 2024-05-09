#include <ChairMerger/XmlTypeLibrary.h>

TEST(XmlTypeLibraryTest, ValueValidation)
{
    struct TestCase
    {
        std::string_view typeName;
        std::string_view value;
        bool valid = false;
    };

    static const TestCase testCases[] = {
        // Signed integers
        { "int8",  "",                  false },
        { "int8",  "123",               true  },
        { "int8",  "-123",              true  },
        { "int8",  "asdf",              false },
        { "int8",  "123asdf",           false },
        { "int16", "",                  false },
        { "int16", "12345",             true  },
        { "int16", "-12345",            true  },
        { "int16", "asdf",              false },
        { "int16", "123asdf",           false },
        { "int32", "",                  false },
        { "int32", "1234567890",        true  },
        { "int32", "-1234567890",       true  },
        { "int32", "asdf",              false },
        { "int32", "123asdf",           false },
        { "int64", "",                  false },
        { "int64", "1234567890123456",  true  },
        { "int64", "-1234567890123456", true  },
        { "int64", "asdf",              false },
        { "int64", "123asdf",           false },
        
        // Unsigned integers
        { "uint8",  "",                  false },
        { "uint8",  "123",               true  },
        { "uint8",  "-123",              false },
        { "uint8",  "asdf",              false },
        { "uint8",  "123asdf",           false },
        { "uint16", "",                  false },
        { "uint16", "12345",             true  },
        { "uint16", "-12345",            false },
        { "uint16", "asdf",              false },
        { "uint16", "123asdf",           false },
        { "uint32", "",                  false },
        { "uint32", "1234567890",        true  },
        { "uint32", "-1234567890",       false },
        { "uint32", "asdf",              false },
        { "uint32", "123asdf",           false },
        { "uint64", "",                  false },
        { "uint64", "1234567890123456",  true  },
        { "uint64", "-1234567890123456", false },
        { "uint64", "asdf",              false },
        { "uint64", "123asdf",           false },

        // Float
        { "float", "",           false },
        { "float", "123456.05",  true  },
        { "float", "-123456.05", true  },
        { "float", "1.234e4",    true  },
        { "float", "-1.234e4",   true  },
        { "float", "asdf",       false },
        { "float", "123asdf",    false },

        // String
        { "string", "",          false },
        { "string", "asdf",      true  },

        // Bool (int)
        { "boolInt", "",   false },
        { "boolInt", "0",  true },
        { "boolInt", "1",  true },
        { "boolInt", "2",  false },
        { "boolInt", "-1", false },
        { "boolInt", "0asdf", false },

        // Bool (string)
        { "boolString", "",      false },
        { "boolString", "false", true  },
        { "boolString", "true",  true  },
        { "boolString", "maybe", false },

        // GUID
        { "GuidWithBraces", "",                                       false },
        { "GuidWithBraces", "{A738031A-8DA6-4A4C-B4A9-CA11794FDEC0}", true  },
        { "GuidWithBraces", "{a738031a-8da6-4a4c-b4a9-ca11794fdec0}", true  },
        { "GuidWithBraces", "{a738031a-8da6-4a4c-b4a9-ca11794fdec}",  false },
        { "GuidWithBraces", "a738031a-8da6-4a4c-b4a9-ca11794fdec0",   false },
        { "GuidNoBraces",   "",                                       false },
        { "GuidNoBraces",   "A738031A-8DA6-4A4C-B4A9-CA11794FDEC0",   true  },
        { "GuidNoBraces",   "a738031a-8da6-4a4c-b4a9-ca11794fdec0",   true  },
        { "GuidNoBraces",   "a738031a-8da6-4a4c-b4a9-ca11794fdec",    false },
        { "GuidNoBraces",   "{a738031a-8da6-4a4c-b4a9-ca11794fdec0}", false },
    };

    XmlTypeLibrary typeLib;
    typeLib.LoadTypesFromFile("XmlTypeLibrary.xml");

    for (const TestCase& test : testCases)
    {
        const IXmlType* pType = typeLib.FindType(test.typeName);
        ASSERT_NE(nullptr, pType) << "Type not found: " << test.typeName;

        bool isValid = pType->ValidateValue(test.value);
        EXPECT_EQ(test.valid, isValid) << "Type: " << test.typeName << "; Value: '" << test.value << "'";
    }
}
