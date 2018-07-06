/*
 *
 * @file: ApplicationParameters.h
 * @author: Jiejing Shan
 * @comments: Define Command line process paramter set.
 * @date: 18-07-05
 *
*/
#ifndef _COM_SHJJ_CPPKIT_APPLICATION_PARAMETERS_H_
#define _COM_SHJJ_CPPKIT_APPLICATION_PARAMETERS_H_

#include "util.h"

#include <string>
#include <map>

namespace com {
namespace shjj {
namespace cppkit {


class ApplicationParameters {
    PropertyBuilderByName_NGS(std::map<std::string, std::string>, KeyShortMap, private)
    PropertyBuilderByName_NGS(std::map<std::string, std::string>, KeyValueMap, private)

public: 
    //explicit Parameters(std::string key);
    explicit ApplicationParameters(IN std::string keystring, IN int argc = 0, IN char* argv[] = nullptr );
    ~ApplicationParameters();

    std::string operator[](IN std::string key);

    int parse(IN int argc, IN char* argv[]);
};

}
}
}
#endif /* end of include guard: _COM_SHJJ_CPPKIT_APPLICATION_PARAMETERS_H_ */
