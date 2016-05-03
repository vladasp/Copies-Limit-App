#include "stdafx.h"
#include "CheckingLimit.h"

CheckingLimit::CheckingLimit()
{

}

CheckingLimit::~CheckingLimit()
{
}

int CheckingLimit::CanLocalRun(int limit, string name)
{
    msclr::interop::marshal_context context;
    String^ countStr = context.marshal_as<String^>(name);;

    Process^ myProcess = gcnew Process;
    cli::array<Process^>^localByName = Process::GetProcessesByName(countStr);
    Process^ currentProcess = Process::GetCurrentProcess();
    if (localByName->Length > limit) currentProcess->Kill();
    return localByName->Length;
}

int CheckingLimit::CanNetLockalRun(int limit, string name, string IP)
{
    msclr::interop::marshal_context context;
    String^ countStr = context.marshal_as<String^>(name);
    msclr::interop::marshal_context cont;
    String^ IPStr = cont.marshal_as<String^>(IP);

    Process^ myProcess = gcnew Process;
    Process^ currentProcess = Process::GetCurrentProcess();
    cli::array<Process^>^ipByName = Process::GetProcessesByName(countStr, IPStr);
    if (ipByName->Length >= limit) currentProcess->Kill();
    return ipByName->Length;
}
