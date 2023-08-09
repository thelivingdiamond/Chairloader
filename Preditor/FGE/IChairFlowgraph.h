//
// Created by theli on 10/18/2022.
//

#ifndef CHAIRLOADER_IFLOWGRAPH_H
#define CHAIRLOADER_IFLOWGRAPH_H

#endif // CHAIRLOADER_IFLOWGRAPH_H
#pragma once

struct IChairFlowgraph
{
    struct GraphToken
    {
        int64_t m_ID;
        std::string m_Name;
        int m_Type;
    };
    virtual int64_t GetUniqueID() = 0;
    virtual void AddPin(int64_t id, Pin* pin) = 0;
};