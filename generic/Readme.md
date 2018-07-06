# 说明

这个目录下主要包含用于创建程序的两个类族：Application类族和Service类族。

### Application类族

Application类族主要用于程序的主进程，它有一个虚函数run，它的子类需要实现这个函数。
main函数会实例化这个类的子类，然后调用它的run函数启动程序。

### Service类族

Service类族中的类是线程的封装，只要创建一个Service子类的实例，它就会创建一个线程实例。
Service类也有一个虚函数run，它会运行与创建的线程中。
