#pragma once

struct PreditorTime
{
    CTimeValue nTime; //!< Current time since start up
    float flTime; //!< Current time since start up in seconds

    CTimeValue nTimeDelta; //!< Time since last frame
    float flTimeDelta; //!< Time since last frame in seconds
};
