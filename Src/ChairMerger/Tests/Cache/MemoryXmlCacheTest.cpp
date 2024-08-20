#include "Cache/MemoryXmlCache.h"

TEST(MemoryXmlCache, Create)
{
    MemoryXmlCache cache;

    {
        IXmlCache::WriteLock lock;
        pugi::xml_document& doc = cache.OpenXmlForWriting("test.xml", lock);
        doc.append_child("TestNode");
        ASSERT_TRUE(doc.child("TestNode"));
    }

    {
        IXmlCache::ReadLock lock;
        const pugi::xml_document& doc = cache.OpenXmlForReading("test.xml", lock);
        ASSERT_TRUE(doc.child("TestNode"));
    }
}

TEST(MemoryXmlCache, FlagMismatch)
{
    MemoryXmlCache cache;

    {
        IXmlCache::WriteLock lock;
        pugi::xml_document& doc = cache.OpenXmlForWriting("test.xml", lock, pugi::parse_default);
        doc.append_child("TestNode");
        ASSERT_TRUE(doc.child("TestNode"));
    }

    {
        IXmlCache::ReadLock lock;
        const pugi::xml_document* pDoc = nullptr;
        ASSERT_EQ(IXmlCache::EOpenResult::ParseFlagsMismatch, cache.TryOpenXmlForReading("test.xml", &pDoc, lock, pugi::parse_full));
    }
}

TEST(MemoryXmlCache, LockedRead)
{
    MemoryXmlCache cache;

    IXmlCache::WriteLock lock;
    pugi::xml_document& doc = cache.OpenXmlForWriting("test.xml", lock);
    doc.append_child("TestNode");
    ASSERT_TRUE(doc.child("TestNode"));

    auto fn = [&]()
    {
        IXmlCache::ReadLock lock;
        const pugi::xml_document* pDoc = nullptr;
        return cache.TryOpenXmlForReading("test.xml", &pDoc, lock);
    };

    ASSERT_EQ(IXmlCache::EOpenResult::Locked, std::async(std::launch::async, fn).get());
}

TEST(MemoryXmlCache, DoubleRead)
{
    MemoryXmlCache cache;

    {
        IXmlCache::WriteLock lock;
        pugi::xml_document& doc = cache.OpenXmlForWriting("test.xml", lock);
        doc.append_child("TestNode");
        ASSERT_TRUE(doc.child("TestNode"));
    }


    IXmlCache::ReadLock lock;
    const pugi::xml_document& doc = cache.OpenXmlForReading("test.xml", lock);

    auto fn = [&]()
        {
            IXmlCache::ReadLock lock;
            const pugi::xml_document* pDoc = nullptr;
            return cache.TryOpenXmlForReading("test.xml", &pDoc, lock);
        };

    ASSERT_EQ(IXmlCache::EOpenResult::Success, std::async(std::launch::async, fn).get());
}

TEST(MemoryXmlCache, LockedWrite)
{
    MemoryXmlCache cache;

    {
        IXmlCache::WriteLock lock;
        pugi::xml_document& doc = cache.OpenXmlForWriting("test.xml", lock);
        doc.append_child("TestNode");
        ASSERT_TRUE(doc.child("TestNode"));
    }


    IXmlCache::ReadLock lock;
    const pugi::xml_document& doc = cache.OpenXmlForReading("test.xml", lock);

    auto fn = [&]()
        {
            IXmlCache::WriteLock lock;
            pugi::xml_document* pDoc = nullptr;
            return cache.TryOpenXmlForWriting("test.xml", &pDoc, lock);
        };

    ASSERT_EQ(IXmlCache::EOpenResult::Locked, std::async(std::launch::async, fn).get());
}
