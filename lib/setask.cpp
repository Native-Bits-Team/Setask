#include <windows.h>
#include <iostream>
#include <fstream>
#include <vector>



int main () {

    auto sizeArray = getResourcesLengthArray(1000);
    writeResource("software.zip", 1001, sizeArray[0]);
    writeResource("setup.exe", 1002, sizeArray[1]);
    writeResource(".dll", 1003, sizeArray[2]);
    
    //std::ifstream IF("../software.zip");
   // std::string t = "";
   // while(!IF.eof()){
     //   t += IF.get();
       // std::cout << "e";
    //}
    //std::cout << t << std::endl;
/*
    char* size = (char*) calloc(40,0);
    LoadString(GetModuleHandle(NULL), 1000, size, 40);
    std::string s = size;
    int sizeValue = std::__cxx11::stoi(s);// + 1; // [T] Got it from CrowSqlite

    char* data = (char*) alloca(sizeValue);

    LoadString(GetModuleHandle(NULL), 1001, data, sizeValue);

    std::string sData = data;
    std::string sPData = "";
    //byte* vPData = (byte*) alloca(sizeValue);
    std::string l  = "";
    //int countLength = 0;
    std::fstream FS("t.zip"); // [T] see REF #4

    for (int i = 1; i < sizeValue; ++i){
       // if (sData[i] == ' '){
         //   continue;
        //}
        if (sData[i] == ','){
            //std::cout << l <<  " | " << std::__cxx11::stoi(l) << " | " << (byte) std::__cxx11::stoi(l) << "\n"; // [T] Ref #2
            //vPData[i] = std::__cxx11::stoi(l); // see [T] Above
            //vPData[i] = toascii(std::__cxx11::stoi(l)); // see [T] Above | Ref #1
            //vPData[i-1] = (byte)std::__cxx11::stoi(l); // see [T] Above and Ref #1 | Ref #2
            FS.put(std::__cxx11::stoi(l)); // see [T] Above | REF #B
            l = "";
            //countLength+=1;
            continue;
        } else {
            l += sData[i];
        }
        //sPData += byte(sData[i]);
        //vPData[i] = sData[i];
        sPData += sData[i];
    }
    //std::ofstream FS("t.zip"); REF #4
    //FS.write(sPData.c_str(), sizeValue);
    //FS.write((char *)vPData, sPData.length()); // REF #3
   // FS.write((char*)vPData, countLength); // [T] REF #3
    //FS.put(80); // REF #4
    //FS.widen();
    FS.close();
    */
    //std::cout << sizeValue << std::endl;
    //std::cout << vPData << std::endl;
    //auto error = ShellExecuteW(NULL,NULL,L"t.bat", NULL,NULL,SW_SHOW); // REF #A
    //std::cout << error << std::endl;
    ShellExecuteW(NULL,NULL,L"setup.exe",NULL,NULL,SW_SHOW); // [T] REF #A
    return 0;
}


void writeResource(const char* name,int resID, int size, std::string path = "./"){ // [T] SEE REF and other [T] Above
    wchar_t* resData = (wchar_t*) alloca(size);
    LoadStringW(GetModuleHandle(NULL),resID, resData,size);
    auto FS = std::fstream(path + name);
    std::string b = "";
    for (int i=0; i < size; ++i){
        if (resData[i] == ','){
            FS.put(std::__cxx11::stoi(b)); // [T] see REF #B
            b = "";
        }
        b += resData[i];
        
    }
    FS.close();
}

auto getResourcesLengthArray(int resID){ // [T] SEE REFs and other [T] Above
    const int MAX_LENGTH_OF_SIZE_ARRAY = 100;
    const int MAX_NUMBER_OF_RESOURCES = 10;

    wchar_t* sizeArrayString = (wchar_t*) calloc(100, 0);
    LoadStringW(GetModuleHandleW(NULL), resID, sizeArrayString,MAX_LENGTH_OF_SIZE_ARRAY);
    std::string n = "";
    //int size[MAX_NUMBER_OF_RESOURCES] = {0};
    std::vector<int> sizeArray;
    for (int i=0; i< MAX_LENGTH_OF_SIZE_ARRAY; ++i){
        if (sizeArrayString[i] == ','){
            sizeArray.push_back(std::__cxx11::stoi(n));
            n = "";
        }
        if (sizeArrayString[i] == 'A'){
            break;
        }
        n += sizeArrayString[i];
    }
    return sizeArray;
}