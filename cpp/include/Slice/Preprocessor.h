// **********************************************************************
//
// Copyright (c) 2001
// ZeroC, Inc.
// Huntsville, AL, USA
//
// All Rights Reserved
//
// **********************************************************************

#ifndef PREPROCESSOR_H
#define PREPROCESSOR_H

#include <IceUtil/Config.h>

#ifdef _WIN32
#   ifdef SLICE_API_EXPORTS
#       define SLICE_API __declspec(dllexport)
#   else
#       define SLICE_API __declspec(dllimport)
#   endif
#else
#   define SLICE_API /**/
#endif

namespace Slice
{

class SLICE_API Preprocessor
{
public:

    Preprocessor(const std::string&, const std::string&, const std::string&);
    ~Preprocessor();
    
    FILE* preprocess(bool);
    bool close();

    void printMakefileDependencies();
    
    std::string getBaseName();

private:
    
    bool checkInputFile();
    std::string searchIceCpp();

    const std::string _path;
    const std::string _fileName;
    const std::string _args;
    FILE* _cppHandle;
};

}

#endif
