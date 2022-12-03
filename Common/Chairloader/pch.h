// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.
#pragma once

// Core CryEngine and STL headers
#include <Prey/CryCore/StdAfx.h>
#include <ChairLoader/ValidateCompiler.h>

// add headers that you want to pre-compile here
#include <iostream>
#include <fstream>
#include <boost/variant.hpp>
#include <boost/optional.hpp>
#include <boost/bimap.hpp>
#include <pugixml.hpp>

#include <Prey/ArkEnums.h>
#include <Prey/ArkStubs.h>
#include <ChairLoader/PreyFunction.h>
#include <ChairLoader/ChairloaderEnv.h>
#include <ChairLoader/IChairloader.h>
