//
// Created by theli on 3/26/2023.
//

#ifndef CHAIRLOADER_ATTRIBUTEWILDCARD_H
#define CHAIRLOADER_ATTRIBUTEWILDCARD_H

#include "pugixml.hpp"

//! A structure for finding wildcards
struct AttributeWildcard{
    enum class wildcard_type{
        none,
        apply_if,
        replace,
    };
    enum class match_type{
        none,
        local,
        global,
    };
    pugi::xml_attribute attribute;
    std::string mod_name;
    wildcard_type type = wildcard_type::none;
    match_type match = match_type::none;
    std::string match_value;
    bool has_match_value = false;
    bool apply_if = false;
};
#endif //CHAIRLOADER_ATTRIBUTEWILDCARD_H
