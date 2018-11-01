#include <iostream>
#include<list>
using namespace std;

class Stream {
public:
    virtual void Read();
    virtual void Write();
    virtual ~Stream();
};

class FileStream : public Stream {
public:
    virtual void Read()
    {
        //File相关操作
        Stream::Read();
    }
    virtual void Write()
    {
        //File相关操作
        Stream::Write();
    }
};

class SocketStream : public Stream {
public:
    virtual void Read();
    virtual void Write();
};

/*如上，子类增加的方向跟流方式有关，如果需要扩展功能，比如给流增加保密，缓冲甚至储存等等
与方向无关时
class EncryptFileStream: public FIleStream
{
public:
    virtual void Read()
    {
        //加密操作
        FileStream::Read(); 
    }
}

需要分别给以上每个基类都实现具有扩展功能的子类，这将导致巨大子类数量。
*/

//需要扩展功能时，使用装饰模式，增加一个中间层，利用组合的方式调用以上基类函数，达到减少子类，重复代码的目的
class Decoretor : public Stream {
public:
    Stream* stream;
};

class EncryptStream : public Decoretor {
public:
    virtual void Read()
    {
        //加密
        stream->Read(); //动态绑定几个基类，将扩展和基本稳定方向隔离
    }
};
