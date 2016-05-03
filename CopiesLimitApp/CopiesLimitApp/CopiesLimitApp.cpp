#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <msclr\marshal_cppstd.h>

int main()
{
    int countLimit = 5;
    std::string name = "CopiesLimitApp";

    printf("Limit apps: %d \n", countLimit);
    printf("Name apps: %s \n", name.c_str());


    HINSTANCE hLib = LoadLibrary(L"ProcLimit.dll");
    if (hLib == NULL)
    {
        cout << "Unable to load library!" << endl;
        return 1;
    }

    cout << "Library is loaded."<< endl;

    int(*CanLocalRun) (int, string);
    CanLocalRun = (int(*) (int, string))GetProcAddress((HMODULE)hLib, "CanLocalRun");

    if (CanLocalRun == NULL)
    {
        cout << "Unable to load function." << endl;
        FreeLibrary((HMODULE)hLib);
        return 1;
    }
    int countCur = CanLocalRun(countLimit, name);
    FreeLibrary((HMODULE)hLib);

    printf("Count apps: %d \n", countCur);

    system("pause");

    return 0;
}


