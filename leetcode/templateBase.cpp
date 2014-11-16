#include <iostream>
using namespace std;

class CompanyA
{
    public:
        void sendClearMsg() { cout << "call company A sendClear " << endl;}
        void sendEncryptedMsg() { cout << "call company A sendEncryptedMsg " << endl;}

};

class CompanyB
{
    public:
        void sendClearMsg() { cout << "call company B sendClear " << endl;}
        void sendEncryptedMsg() { cout << "call company B sendEncryptedMsg " << endl;}

};

//companyC only send encrypted Msg
class CompanyC
{
    public:
        void sendEncryptedMsg() { cout << "call company C sendEncryptedMsg " << endl;}

};

class MsgInfo {};

template<class Company>
class MsgSender
{
    public:
        void sendClear()
        {
            cout << "call MsgSender sendClear ... " << endl;
            Company c;
            c.sendClearMsg();
        }
        void sendEncrypted()
        {
            cout << "call MsgSender sendEncrypted ... " << endl;
            Company c;
            c.sendEncryptedMsg();
        }
};

//针对CompanyC的特化版本
template<>
class MsgSender<CompanyC>
{
    public:
        void sendClear()
        {
            cout << "call MsgSender sendClear ... " << endl;
        }
        void sendEncrypted()
        {
            cout << "call MsgSender sendEncrypted ... " << endl;
        }
};

//log the Message
template<class Company>
class LogSendMsg : public MsgSender<Company>
{
public:
    void Log()
    {
        cout << "call LogSendMsg log ..." << endl;
    //    sendClear();
        //error: there are no arguments to 'sendClear' that depend on a template parameter, so a declaration of 'sendClear' must be available|
        cout << "call LogSendMsg log end... " << endl;

    }

};

template<class T>
class Base
{
    public:
        void printBase() {cout << "call Base printBase() ..." << endl;}
};

template<class T>
class Derived : public Base<T>
{
    public:
        void printDerived()
        {
            cout << "call Derived printDerived() ... " << endl;
            printBase();
        }
};



int main()
{

}
