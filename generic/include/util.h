/*
 *######################################################################
 *#
 *# @file: util.h
 *# @author: Jiejing Shan
 *# @date: 2018-05-07
 *# @comment:
 *#
 *######################################################################
*/

#ifndef _COM_SHJJ_CPPKIT_UTIL_H_
#define _COM_SHJJ_CPPKIT_UTIL_H_

namespace com {
namespace shjj {
namespace cppkit {

#define IN const
#define OUT

#define PropertyBuilderByName(type, name, access_permission)\
    access_permission: type m##name;\
    public:\
    inline void set##name( IN type v) {\
        m##name = v;\
    }\
    inline type get##name() const{\
        return m##name;\
    }

#define PropertyBuilderByName_NG(type, name, access_permission)\
    access_permission: type m##name;\
    public:\
    inline void set##name(IN type v) {\
        m##name = v; \
    }

#define PropertyBuilderByName_NS(type, name, access_permission)\
    access_permission: type m##name;\
    public:\
    inline type get##name() const{\
        return m##name;\
    }

#define PropertyBuilderByName_NGS(type, name, access_permission)\
    access_permission: type m##name;

#define EXPORT __attribute__( ( visibility( "default" ) ) )


}
}
}
#endif //_COM_SHJJ_CPPKIT_UTIL_H_
