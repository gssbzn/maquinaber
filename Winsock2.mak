# Microsoft Developer Studio Generated NMAKE File, Format Version 4.20
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

!IF "$(CFG)" == ""
CFG=Winsock2 - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to Winsock2 - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Winsock2 - Win32 Release" && "$(CFG)" !=\
 "Winsock2 - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "Winsock2.mak" CFG="Winsock2 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Winsock2 - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Winsock2 - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 
################################################################################
# Begin Project
# PROP Target_Last_Scanned "Winsock2 - Win32 Debug"
RSC=rc.exe
CPP=cl.exe
MTL=mktyplib.exe

!IF  "$(CFG)" == "Winsock2 - Win32 Release"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
OUTDIR=.\Release
INTDIR=.\Release

ALL : "$(OUTDIR)\Winsock2.exe"

CLEAN : 
	-@erase "$(INTDIR)\DGModeless.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\VWSocket.obj"
	-@erase "$(INTDIR)\Winsock2.obj"
	-@erase "$(INTDIR)\Winsock2.pch"
	-@erase "$(INTDIR)\Winsock2.res"
	-@erase "$(INTDIR)\Winsock2Doc.obj"
	-@erase "$(OUTDIR)\Winsock2.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MT /W3 /GX /Od /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MT /W3 /GX /Od /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_MBCS" /Fp"$(INTDIR)/Winsock2.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Release/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/Winsock2.res" /d "NDEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/Winsock2.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)/Winsock2.pdb" /machine:I386 /out:"$(OUTDIR)/Winsock2.exe" 
LINK32_OBJS= \
	"$(INTDIR)\DGModeless.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\VWSocket.obj" \
	"$(INTDIR)\Winsock2.obj" \
	"$(INTDIR)\Winsock2.res" \
	"$(INTDIR)\Winsock2Doc.obj"

"$(OUTDIR)\Winsock2.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Winsock2 - Win32 Debug"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
OUTDIR=.\Debug
INTDIR=.\Debug

ALL : "$(OUTDIR)\Winsock2.exe"

CLEAN : 
	-@erase "$(INTDIR)\DGModeless.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(INTDIR)\VWSocket.obj"
	-@erase "$(INTDIR)\Winsock2.obj"
	-@erase "$(INTDIR)\Winsock2.pch"
	-@erase "$(INTDIR)\Winsock2.res"
	-@erase "$(INTDIR)\Winsock2Doc.obj"
	-@erase "$(OUTDIR)\Winsock2.exe"
	-@erase "$(OUTDIR)\Winsock2.ilk"
	-@erase "$(OUTDIR)\Winsock2.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_MBCS" /Fp"$(INTDIR)/Winsock2.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/"\
 /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/Winsock2.res" /d "_DEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/Winsock2.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)/Winsock2.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)/Winsock2.exe" 
LINK32_OBJS= \
	"$(INTDIR)\DGModeless.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\VWSocket.obj" \
	"$(INTDIR)\Winsock2.obj" \
	"$(INTDIR)\Winsock2.res" \
	"$(INTDIR)\Winsock2Doc.obj"

"$(OUTDIR)\Winsock2.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

################################################################################
# Begin Target

# Name "Winsock2 - Win32 Release"
# Name "Winsock2 - Win32 Debug"

!IF  "$(CFG)" == "Winsock2 - Win32 Release"

!ELSEIF  "$(CFG)" == "Winsock2 - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\Winsock2.cpp
DEP_CPP_WINSO=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\VWSocket.h"\
	".\Winsock2.h"\
	".\Winsock2Doc.h"\
	

"$(INTDIR)\Winsock2.obj" : $(SOURCE) $(DEP_CPP_WINSO) "$(INTDIR)"\
 "$(INTDIR)\Winsock2.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "Winsock2 - Win32 Release"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MT /W3 /GX /Od /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS"\
 /Fp"$(INTDIR)/Winsock2.pch" /Yc"stdafx.h" /Fo"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\Winsock2.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "Winsock2 - Win32 Debug"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_MBCS" /Fp"$(INTDIR)/Winsock2.pch" /Yc"stdafx.h" /Fo"$(INTDIR)/"\
 /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\Winsock2.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\MainFrm.cpp
DEP_CPP_MAINF=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\Winsock2.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\Winsock2.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Winsock2Doc.cpp
DEP_CPP_WINSOC=\
	".\StdAfx.h"\
	".\Winsock2.h"\
	".\Winsock2Doc.h"\
	

"$(INTDIR)\Winsock2Doc.obj" : $(SOURCE) $(DEP_CPP_WINSOC) "$(INTDIR)"\
 "$(INTDIR)\Winsock2.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Winsock2.rc
DEP_RSC_WINSOCK=\
	".\res\Toolbar.bmp"\
	".\res\Winsock2.ico"\
	".\res\Winsock2.rc2"\
	".\res\Winsock2Doc.ico"\
	

"$(INTDIR)\Winsock2.res" : $(SOURCE) $(DEP_RSC_WINSOCK) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\VWSocket.cpp
DEP_CPP_VWSOC=\
	".\dgmodeless.h"\
	".\StdAfx.h"\
	".\VWSocket.h"\
	".\Winsock2.h"\
	

"$(INTDIR)\VWSocket.obj" : $(SOURCE) $(DEP_CPP_VWSOC) "$(INTDIR)"\
 "$(INTDIR)\Winsock2.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\DGModeless.cpp
DEP_CPP_DGMOD=\
	".\dgmodeless.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\DGModeless.obj" : $(SOURCE) $(DEP_CPP_DGMOD) "$(INTDIR)"\
 "$(INTDIR)\Winsock2.pch"


# End Source File
# End Target
# End Project
################################################################################
