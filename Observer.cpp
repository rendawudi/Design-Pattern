#include <list>

//考虑到有很多不同的进度条模板，这是一个可能改变的点
//一个进度条接口类
class IprogressBar {
public:
    virtual void doProgress(float value) = 0;
    virtual ~IprogressBar();
};

class DoCV {
private:
    std::list<IprogressBar*> IprogressBarList; //多个观察者

public:
    void addProgressBar(IprogressBar* iprogressBar)
    {
        IprogressBarList.push_back(iprogressBar);
    }

    void delProgressBar(IprogressBar* ipr)
    {
        IprogressBarList.remove(ipr);
    }

    void doRender(float value)
    {
        for (std::list<IprogressBar*>::iterator i = IprogressBarList.begin();
             i != IprogressBarList.end();
             i++) {
            (*i)->doProgress(value);
        }
    }
};