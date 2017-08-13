#include "testCase.h"

#include "castUtil.h"

#include <sstream>
#include <string>

DEFINE_TEST(CreateErrorMsgFormatsMsgWithFileAndLine)
void run()
{
    std::string expected("ERROR [srcFile.cpp(234)]: An error happened.");

    std::string errMsg(cas::createErrMsg("An error happened.",
                                         "srcFile.cpp",
                                         234));

    CK(expected == errMsg);
}
END_DEF

DEFINE_TEST(CreateMakefileFromTemplateCompletesTheMakefile)

void run()
{
    std::istringstream templ(
        "##### TODO #####\n"
        "# Set TGT to the single target created by this makefile.\n"
        "#\n"
        "# EX:\n"
        "#    TGT := mytest.test\n"
        "################\n"
        "TGT :=\n"
        "\n"
        "##### TODO #####\n"
        "# List test sources here.  Test sources are essentially C++ files which\n"
        "# use the macros ........................................ from\n"
        "# testCase.h to define the TestCase derived classes.  These files have\n"
        "# a .tpp \"extension\" and are processed into .cpp files with the\n"
        "# appropriate \"createTests()\" function appended.  The .cpp file is then\n"
        "# compiled/linked into the test \"application\".  (It's really a shared\n"
        "# library which is loaded from casTest.)  See the docs for more info.\n"
        "#\n"
        "# EX:  \n"
        "#    TSTSRC := mytest.tpp\n"
        "#\n"
        "# NOTE: Due to the way test sources are processed,\n"
        "#       only one test source may be listed.\n"
        "################\n"
        "TSTSRC :=\n"
        "\n");
    
    std::string expected(
        "##### TODO #####\n"
        "# Set TGT to the single target created by this makefile.\n"
        "#\n"
        "# EX:\n"
        "#    TGT := mytest.test\n"
        "################\n"
        "TGT := mytest.test\n"
        "\n"
        "##### TODO #####\n"
        "# List test sources here.  Test sources are essentially C++ files which\n"
        "# use the macros ........................................ from\n"
        "# testCase.h to define the TestCase derived classes.  These files have\n"
        "# a .tpp \"extension\" and are processed into .cpp files with the\n"
        "# appropriate \"createTests()\" function appended.  The .cpp file is then\n"
        "# compiled/linked into the test \"application\".  (It's really a shared\n"
        "# library which is loaded from casTest.)  See the docs for more info.\n"
        "#\n"
        "# EX:  \n"
        "#    TSTSRC := mytest.tpp\n"
        "#\n"
        "# NOTE: Due to the way test sources are processed,\n"
        "#       only one test source may be listed.\n"
        "################\n"
        "TSTSRC := mytest.tpp\n"
        "\n");
    
    std::ostringstream mkFile;

    cas::createMakefileFromTemplate(templ, mkFile, "mytest");

    CK(expected == mkFile.str());
}

END_DEF
