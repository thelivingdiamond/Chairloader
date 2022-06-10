#pragma once

//! Simple logs of data with low verbosity.
void CryLog(const char *format, ...);

//! CryLog but in yellow and with [Warning] prefix. Different from Engine's CryWarning
void CryWarning(const char *format, ...);

//! CryLog but in red
void CryError(const char *format, ...);

//! Displays error message, logs it to console and file and error message box, tThen terminates execution.
void CryFatalError(const char *format, ...);
