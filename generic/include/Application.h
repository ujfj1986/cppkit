/*
 *
 * @file: Application.h
 * @author: Jiejing Shan
 * @comments: Define Application class.
 * @date: 18-07-03
 *
*/
#ifndef _COM_SHJJ_CPPKIT_APPLICATION_H_
#define _COM_SHJJ_CPPKIT_APPLICATION_H_

#include "util.h"

namespace com {
namespace shjj {
namespace cpplib {

class Application {
public:
    explicit Application():Application(0, nullptr) {}
    explicit Application(IN int argc, IN char* argv[]) ;
    virtual ~Application() {}

    //virtual int init();
    virtual int run() = 0;

protected:
    //Context
    //PropertyBuilderByName(Context, Context, protected)
    //Parameters
    //PropertyBuilderByName(Parameters, Parameters, protected)

};

#define APPLICATION_RUN(cls) \
    int main(IN int argc, IN char const *argv[]) { \
        /* init Context */ \
        /* Context context(argc, argv); */ \
        std::unique_ptr<Application> application = new cls \
        /* application->setContext(context); */ \
        return application->run(); \
    }



}
}
}
#endif /* end of include guard: _COM_SHJJ_CPPKIT_APPLICATION_H_ */
