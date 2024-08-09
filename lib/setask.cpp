#include <windows.h>
#include <iostream>
#include <fstream>



int main () {
    std::ifstream IF("../software.zip");
   // std::string t = "";
   // while(!IF.eof()){
     //   t += IF.get();
       // std::cout << "e";
    //}
    //std::cout << t << std::endl;

    char* size = (char*) alloca(40);
    LoadString(GetModuleHandle(NULL), 1000, size, 40);
    std::string s = size;
    int sizeValue = std::__cxx11::stoi(s);// + 1; // [T] Got it from CrowSqlite

    char* data = (char*) alloca(sizeValue);

    LoadString(GetModuleHandle(NULL), 1001, data, sizeValue);

    std::string sData = data;
    std::string sPData = "";
    byte* vPData = (byte*) alloca(sizeValue);
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
            FS.put(std::__cxx11::stoi(l)); // see [T] Above
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
    
    //std::cout << sizeValue << std::endl;
    //std::cout << vPData << std::endl;
    return 0;
}