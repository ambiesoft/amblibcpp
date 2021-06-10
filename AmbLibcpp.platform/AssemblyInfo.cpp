#include "stdafx.h"

using namespace System;
using namespace System::Reflection;
using namespace System::Runtime::CompilerServices;
using namespace System::Runtime::InteropServices;
using namespace System::Security::Permissions;

[assembly:AssemblyTitleAttribute("AmbLibcpp")];
[assembly:AssemblyDescriptionAttribute("")];
[assembly:AssemblyConfigurationAttribute("")];
[assembly:AssemblyCompanyAttribute("Ambiesoft")];
[assembly:AssemblyProductAttribute("AmbLibcpp")];
[assembly:AssemblyCopyrightAttribute("Copyright (c)  2021")];
[assembly:AssemblyTrademarkAttribute("")];
[assembly:AssemblyCultureAttribute("")];

//

[assembly:AssemblyVersionAttribute("2.0.2.*")];

[assembly:ComVisible(false)];

[assembly:CLSCompliantAttribute(true)];

#if _MSC_VER < 1800
[assembly:SecurityPermission(SecurityAction::RequestMinimum, UnmanagedCode = true)];
#endif