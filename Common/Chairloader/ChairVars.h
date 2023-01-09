//
// Created by theli on 1/6/2023.
//
#pragma once
#include "pch.h"
#include "../Prey/CryCore/BaseTypes.h"

struct ICVar;
typedef void (* ConsoleVarFunc)(ICVar*);

namespace Internal
{
    //! Create a new console variable that store the value in a string.
    //! \param sName Console variable name.
    //! \param sValue Default value.
    //! \param nFlags User defined flag, this parameter is used by other subsystems and doesn't affect the console variable (basically of user data).
    //! \param help Help text that is shown when you use "<sName> ?" in the console.
    //! \return Pointer to the interface ICVar.
    ICVar* ChairRegisterString(const char* sName, const char* sValue, int nFlags, const char* help = "", ConsoleVarFunc pChangeFunc = 0);

    //! Create a new console variable that store the value in a int.
    //! \param sName Console variable name.
    //! \param iValue Default value.
    //! \param nFlags User defined flag, this parameter is used by other subsystems and doesn't affect the console variable (basically of user data).
    //! \param Help help text that is shown when you use "<sName> ?" in the console.
    //! \return Pointer to the interface ICVar.
    ICVar* ChairRegisterInt(const char* sName, int iValue, int nFlags, const char* help = "", ConsoleVarFunc pChangeFunc = 0);

    //! Create a new console variable that store the value in a int64.
    //! \param sName Console variable name.
    //! \param iValue Default value.
    //! \param nFlags Her defined flag, this parameter is used by other subsystems and doesn't affect the console variable (basically of user data).
    //! \param help - help text that is shown when you use "<sName> ?" in the console.
    //! \return Pointer to the interface ICVar.
    ICVar* ChairRegisterInt64(const char* sName, int64 iValue, int nFlags, const char* help = "", ConsoleVarFunc pChangeFunc = 0);

    //! Create a new console variable that store the value in a float.
    //! \param sName Console variable name.
    //! \param fValue Default value.
    //! \param nFlags User defined flag, this parameter is used by other subsystems and doesn't affect the console variable (basically of user data).
    //! \param help help text that is shown when you use "<sName> ?" in the console.
    //! \return Pointer to the interface ICVar.
    ICVar* ChairRegisterFloat(const char* sName, float fValue, int nFlags, const char* help = "", ConsoleVarFunc pChangeFunc = 0);

    //! Create a new console variable that will update the user defined float.
    //! \param sName Console variable name.
    //! \param src Pointer to the memory that will be updated.
    //! \param nFlags User defined flag, this parameter is used by other subsystems and doesn't affect the console variable (basically of user data).
    //! \param help Help text that is shown when you use "<sName> ?" in the console.
    //! \param allowModify Allow modification through config vars, prevents missing modifications in release mode.
    //! \return pointer to the interface ICVar.
    ICVar* ChairRegister(const char* name, float* src, float defaultvalue, int nFlags = 0, const char* help = "", ConsoleVarFunc pChangeFunc = 0, bool allowModify = true);

    //! Create a new console variable that will update the user defined float.
    //! \param sName Console variable name.
    //! \param src Pointer to the memory that will be updated.
    //! \param nFlags User defined flag, this parameter is used by other subsystems and doesn't affect the console variable (basically of user data).
    //! \param help Help text that is shown when you use "<sName> ?" in the console.
    //! \param allowModify Allow modification through config vars, prevents missing modifications in release mode.
    //! \return pointer to the interface ICVar.
    ICVar* ChairRegister(const char* name, int* src, int defaultvalue, int nFlags = 0, const char* help = "", ConsoleVarFunc pChangeFunc = 0, bool allowModify = true);

    //! Create a new console variable that will update the user defined float.
    //! \param sName Console variable name.
    //! \param src Pointer to the memory that will be updated.
    //! \param nFlags User defined flag, this parameter is used by other subsystems and doesn't affect the console variable (basically of user data).
    //! \param help Help text that is shown when you use "<sName> ?" in the console.
    //! \param allowModify Allow modification through config vars, prevents missing modifications in release mode.
    //! \return pointer to the interface ICVar.
    ICVar* ChairRegister(const char* name, const char** src, const char* defaultvalue, int nFlags = 0, const char* help = "", ConsoleVarFunc pChangeFunc = 0, bool allowModify = true);
}