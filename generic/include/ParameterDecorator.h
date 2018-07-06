/*
 *
 * @file: ParameterDecorator.h
 * @author: Jiejing Shan
 * @comments: Application decorator. Parse command line.
 * @date: 18-07-05
 *
*/
#ifndef _COM_SHJJ_CPPKIT_PARAMETER_DECORATOR_H_
#define _COM_SHJJ_CPPKIT_PARAMETER_DECORATOR_H_

#include "Application.h"
#include "util.h"
#include "ApplicationParameters.h"

#include <string>

namespace com {
namespace shjj {
namespace cppkit {

class ParameterDecorator : public virtual Application {
    PropertyBuilderByName_NS(std::shared_ptr<Application>, Application, private)
    // Parameters
    PropertyBuilderByName_NS(ApplicationParameters, Parameters, protected)

public: 
    explicit ParameterDecorator(IN std::shared_ptr<Application> app,
        IN std::string optstr,
        IN std::string usage,
        IN int argc = 0,
        IN char* argv[] = nullptr);
    virtual int run() ;

};

}
}
}
#endif /* end of include guard: _COM_SHJJ_CPPKIT_PARAMETER_DECORATOR_H_ */
