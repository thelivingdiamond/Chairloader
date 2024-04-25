//
// Created by theli on 3/29/2023.
//

#ifndef CHAIRLOADER_PUGIUTILS_H
#define CHAIRLOADER_PUGIUTILS_H
#include <pugixml.hpp>
#include <boost/algorithm/string.hpp>

namespace PugiUtils{
    pugi::xml_node noCaseChild(pugi::xml_node& node, std::string name) {
        for(auto &child : node.children()){
            if(boost::iequals(child.name(), name)){
                return child;
            }
        }
        return {};
    }
}

#endif //CHAIRLOADER_PUGIUTILS_H
