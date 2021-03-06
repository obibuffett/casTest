// The "Clean And Simple Test" (CAST) software framework, tools, and
// documentation are distributed under the terms of the MIT license a
// copy of which is included with this package (see the file "LICENSE"
// in the CAS poject tree's root directory).  CAST may be used for any
// purpose, including commercial purposes, at absolutely no cost. No
// paperwork, no royalties, no GNU-like "copyleft" restrictions, either.
// Just download it and use it.
// 
// Copyright (c) 2015, 2017 Randall Lee White

#include "castUtil.h"

#include "casStdLib.h"

#include <cstdio>
#include <cstdlib>
#include <string>

namespace cas
{
    std::string createErrMsg(const std::string& errMsg,
                             const char* file,
                             size_t line)
    {
        char buff[256];
        snprintf(buff,
                 256,
                 "ERROR [%s(%lu)]: %s",
                 file,
                 line,
                 errMsg.c_str());
        
        return std::string(buff);
    }

    bool createMakefileFromTemplate(std::istream& mkTemplate,
                                    std::ostream& destMakefile,
                                    const std::string& mkTargetName)
    {
        std::string tgtSrc(mkTargetName);
        tgtSrc += ".tpp";

        std::string buff;
        while(std::getline(mkTemplate, buff))
        {
            if(0 == buff.compare("TGT :="))
            {
                buff += ' ';
                buff += mkTargetName;
                buff += ".test";
            }
            else if(0 == buff.compare("TSTSRC :="))
            {
                buff += ' ';
                buff += mkTargetName;
                buff += ".tpp";
            }

            destMakefile << buff << std::endl;
        }

        return true;
    }

    std::string getCastDir()
    {
        const char* cdir(cas::getEnv("CAST_DIR"));
        
        if(!cdir)
            return "";
        
        return std::string(cdir);
    }
}
