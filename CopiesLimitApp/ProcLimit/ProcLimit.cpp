#include "stdafx.h"
#include "ProcLimit.h"

namespace ProcessLimit 
{
    extern "C" __declspec(dllexport) int CanLocalRun(int limit, std::string name)
    {
        msclr::interop::marshal_context context;
        String^ countStr = context.marshal_as<String^>(name);;

        Process^ myProcess = gcnew Process;
        cli::array<Process^>^localByName = Process::GetProcessesByName(countStr);
        Process^ currentProcess = Process::GetCurrentProcess();
        if (localByName->Length > limit) currentProcess->Kill();

        return localByName->Length;
    }

    extern "C" __declspec(dllexport) int CanNetLockalRun(int limit, std::string name, std::string IP)
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

}
