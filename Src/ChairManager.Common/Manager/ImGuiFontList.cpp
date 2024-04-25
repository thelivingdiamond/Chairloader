#include <fmt/format.h>
#include <Manager/ImGuiFontList.h>

void ImGuiFontList::LoadFile(const fs::path& path, const fs::path& rootPath, ILogger* pLog, float dpiScale)
{
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(path.c_str());

    if (!result)
    {
        pLog->LogError(fmt::format("Failed to open {}: {}", path.u8string(), result.description()));
        return;
    }

    LoadXml(doc.first_child(), rootPath, pLog, dpiScale);
}

void ImGuiFontList::LoadXml(pugi::xml_node node, const fs::path& rootPath, ILogger* pLog, float dpiScale)
{
    ImGuiIO& io = ImGui::GetIO();

    io.Fonts->Clear();
    m_FontMap.clear();

    for (pugi::xml_node fontNode : node.children("Font"))
    {
        std::string fontName = fontNode.attribute("name").as_string();

        if (fontName.empty())
        {
            pLog->LogError("Empty font name");
            continue;
        }

        if (m_FontMap.find(fontName) != m_FontMap.end())
        {
            pLog->LogError(fmt::format("Font {}: Duplicate name", fontName));
            continue;
        }

        ImFont* pFont = nullptr;

        auto fnLoadBuiltInFontIfNeedTo = [&]()
        {
            if (!pFont)
            {
                pLog->LogWarning(fmt::format("Font {}: Falling back to built-in font", fontName));
                pFont = io.Fonts->AddFontDefault();
            }
        };

        // Load files
        for (pugi::xml_node fontFileNode : fontNode.children("FontFile"))
        {
            bool isMain = fontFileNode.attribute("main").as_bool();
            if (isMain && pFont)
            {
                // Main already loaded, skip this one
                continue;
            }
            else if (!isMain && !pFont)
            {
                fnLoadBuiltInFontIfNeedTo();
            }

            // Get the path
            fs::path path = fs::u8path(fontFileNode.attribute("path").as_string());

            if (path.empty())
            {
                pLog->LogError(fmt::format("Font {}: Empty path", fontName));
                continue;
            }

            if (path.is_relative())
                path = rootPath / path;

            if (!fs::exists(path))
            {
                pLog->LogError(fmt::format("Font {}: File not found: {}", fontName, path.u8string()));
                continue;
            }

            // ImFontConfig::ImFontConfig() sets the default values in the object.
            // They are used as defaults for XML.
            ImFontConfig config;
            config.OversampleH = fontFileNode.attribute("oversampleH").as_int(config.OversampleH);
            config.OversampleV = fontFileNode.attribute("oversampleV").as_int(config.OversampleV);
            config.PixelSnapH = fontFileNode.attribute("pixelSnapH").as_bool(config.PixelSnapH);
            config.GlyphExtraSpacing.x = fontFileNode.attribute("glyphExtraSpacingX").as_float(config.GlyphExtraSpacing.x);
            config.GlyphOffset.x = fontFileNode.attribute("glyphOffsetX").as_float(config.GlyphOffset.x);
            config.GlyphOffset.y = fontFileNode.attribute("glyphOffsetY").as_float(config.GlyphOffset.y);
            config.GlyphMinAdvanceX = fontFileNode.attribute("glyphMinAdvanceX").as_float(config.GlyphMinAdvanceX);
            config.GlyphMaxAdvanceX = fontFileNode.attribute("glyphMaxAdvanceX").as_float(config.GlyphMaxAdvanceX);
            config.RasterizerMultiply = fontFileNode.attribute("rasterizerMultiply").as_float(config.RasterizerMultiply);

            config.MergeMode = pFont != nullptr;

            // Load glyph ranges
            std::vector<ImWchar>* pGlyphRanges = nullptr;

            for (pugi::xml_node glyphRangeNode : fontFileNode.children("GlyphRange"))
            {
                if (!pGlyphRanges)
                    pGlyphRanges = &m_RangeBuf.emplace_back();

                ImWchar min = glyphRangeNode.attribute("min").as_int();
                ImWchar max = glyphRangeNode.attribute("max").as_int();
                pGlyphRanges->push_back(min);
                pGlyphRanges->push_back(max);
            }

            if (pGlyphRanges)
            {
                // Null-terminate
                pGlyphRanges->push_back(0);
                pGlyphRanges->shrink_to_fit();
            }

            float size = fontFileNode.attribute("size").as_float(14);
            size = floor(size * dpiScale);

            ImFont* pThisFont = io.Fonts->AddFontFromFileTTF(
                path.u8string().c_str(), // filename
                size, // size_pixels
                &config, // font_cfg
                pGlyphRanges ? pGlyphRanges->data() : nullptr // glyph_ranges
            );

            if (!pThisFont)
            {
                pLog->LogError(fmt::format("Font {}: Failed to load: {}", fontName, path.u8string()));
                continue;
            }

            if (isMain)
            {
                assert(!pFont);
                pFont = pThisFont;
            }
        }

        fnLoadBuiltInFontIfNeedTo();
        m_FontMap.insert({ fontName, pFont });
    }
}

ImFont* ImGuiFontList::FindFont(std::string_view name)
{
    auto it = m_FontMap.find(name);
    if (it != m_FontMap.end())
        return it->second;
    else
        return nullptr;
}
