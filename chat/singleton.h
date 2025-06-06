#ifndef SINGLETON_H
#define SINGLETON_H

#include "global.h"

template<typename T>
class Singleton{
public:
     Singleton(const Singleton&)=delete;
     Singleton& operator=(const Singleton&)=delete;
     static std::shared_ptr<T> getInstance(){
         static std::once_flag s_flag;
         std::call_once(s_flag,[&]{
            _pInstance=std::shared_ptr<T>(new T);
         });
         return _pInstance;
     }
     void printAddr(){
         std::cout<<_pInstance.get()<<std::endl;
     }
protected:
    explicit Singleton()=default;
    virtual ~Singleton()=default;
private:
    static std::shared_ptr<T>_pInstance;
};

// 静态成员初始化
template<typename T>
std::shared_ptr<T> Singleton<T>::_pInstance = nullptr;

#endif // SINGLETON_H
