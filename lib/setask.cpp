#include <windows.h>
#include <iostream>
#include <fstream>
#include <vector>

int writeResourceA(const char* name, int resID, int size=4000, std::string path="./");

int main () {

    //auto sizeArray = getResourcesLengthArray(1000);
    //auto nameArray = getResourcesNameArray(1001);

    //for (int i=0; i < nameArray.size(); ++i) {
      //  writeResource(nameArray[i].c_str(), 1002+i, sizeArray[i]);
    //}

    std::vector<std::string> files = {"setup.bin"};//.zip"};//, "software.zip"};
    int startID = 1000;
    for (int i=0; i < files.size(); ++i){
        //writeResource(files[i], 1000+i, )
        startID = writeResourceA(files[i].c_str(), startID);
        std::cout << i;
    }

    /*writeResource("software.zip", 1001, sizeArray[0]);
    writeResource("setup.exe", 1002, sizeArray[1]);
    writeResource(".dll", 1003, sizeArray[2]);*/
    
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
    std::fstream FS("t.zip"); // [T] REF #4

    for (int i = 1; i < sizeValue; ++i){
       // if (sData[i] == ' '){
         //   continue;
        //}
        if (sData[i] == ','){
            //std::cout << l <<  " | " << std::__cxx11::stoi(l) << " | " << (byte) std::__cxx11::stoi(l) << "\n"; // [T] Ref #2
            //vPData[i] = std::__cxx11::stoi(l); // [T] Above
            //vPData[i] = toascii(std::__cxx11::stoi(l)); // [T] Above | Ref #1
            //vPData[i-1] = (byte)std::__cxx11::stoi(l); // [T] Above and Ref #1 | Ref #2
            FS.put(std::__cxx11::stoi(l)); // [T] Above | REF #B
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


void writeResource(const char* name,int resID, int size, std::string path = "./"){ // [T] REF and other [T] Above
    wchar_t* resData = (wchar_t*) alloca(size);
    LoadStringW(GetModuleHandle(NULL),resID, resData,size);
    auto FS = std::fstream(path + name);
    std::string b = "";
    for (int i=0; i < size; ++i){
        if (resData[i] == ','){
            FS.put(std::__cxx11::stoi(b)); // [T] REF #B
            b = "";
        }
        b += resData[i];
        
    }
    FS.close();
}


int writeResourceA(const char* name,int resID, int size, std::string path){ // [T] REF and other [T] Above | Copy pasted | modified
    //wchar_t* resData = (wchar_t*) alloca(size);
    //int dataCount = 0;
    //char* resDataC = (char*) alloca(size+1);//size);//+1);
    char* resDataC = (char*) calloc(size+10, '\0'); // REF #RR
   // char* cleanMemory = (char*) calloc(size+10, '\0');

    bool finished = false;
    //auto FS = std::fstream(path + name);
    //auto OS = std::ofstream(path + name);
    auto OS = std::ofstream(path + name, std::ios_base::openmode(4)); // tried with 0 1 2 3 failed,
    //int debugLimit = 0;

    while (!finished){// && debugLimit < 1){
    //    std::cout << "reseting to null terminator\n";
    
    //memcpy(resDataC, (char*) calloc(size+10, '\0'), size+10); // [T] (char*) from REF #RR  | REF #RRR
    
    //memcpy(resDataC, cleanMemory, size+10); // [T] REF #RRR
    
      //  std::cout << "loading";
    //auto e = LoadStringW(GetModuleHandle(NULL),resID, resData,3200);
    LoadStringA(GetModuleHandle(NULL), resID, resDataC, size+10);//+1);//size);//+1); // REF #Y
    //std::cout << resDataC << "\n";
    //LoadStringA(GetModuleHandle(NULL), 1007, resDataC, size+1);  // original was like REF #Y
    //std::cout << resDataC << "\n"; return 0;
    //std::cout << e;
    //std::cout << "loaded";
    //auto FS = std::fstream(path + name);
    std::string b = "";
    for (int i=0; i < size+10;++i){//;++i){//+1; ++i){
//std::cout << resDataC[i] << "\n";
       // std::cout << resDataC[i] << "is it , :" << (resDataC[i] == ',') << "\n";
        //if (resData[i] == ','){
       /* if (resDataC[i] == '\0'){
            resID +=1;
            if (b.c_str() != "," && b.empty()){
                OS.put(std::__cxx11::stoi(b)); // [T] REF #8
            }
            break;

        } */ // Wasn't used 
        // COPY PAST REF #G
        if (resDataC[i] == '\0'){
            //std::cout << "null at" << i << "\n";
            //std::cout << "finished at " << i << std::endl;
            //std::cout << resDataC << std::endl;
            //b="";
            b.clear();
            break;
        }
        if (resDataC[i] == 'A'){
            finished = true;
            //b = "";
            b.clear();
            resID +=1;
            break;
        }
       // if (resID == 10099){
         //   std::cout << resDataC;
        //}
        // END COPY PAST
        
        if (resDataC[i] == ','){
            //std::cout << b << "\n";
           // if (resID == 1019){std::cout << "\n" << resDataC; return 0;} // [T] REF #Q
           // if (resID == 1007){std::cout << "\n" << resDataC; return 0;} // REF #Q
         //   std::cout << b;
        // std::cout <<b;// << " | " << resDataC[i-1] << resDataC[i-2] <<"\n";
            //FS.put(std::__cxx11::stoi(b)); // [T] REF #B
           // if (i < 34){//100){
           // std::cout << b << " | " << std::__cxx11::stoi(b) << "\n"; // [T] REF #8
            //}
            OS.put(std::__cxx11::stoi(b.c_str()));//b)); // [T] REF #8
            //OS.put((long double)10);
            //OS.pword(10);
            //OS.precision(sizeof(char));
            //OS.width(sizeof(char));
            //OS << 10;
            //OS.binary;
            //OS.in = std::
            //OS.app = 2;
            // OS.ate = 2;
            //OS.flags(std::ios_base::_Fmtflags) // [T] description
            //OS.narrow((char)1, 1);
            //OS.widen(10); // [T] description
            
          //  }
            //dataCount += 1;
            //b = "";
            b.clear();
            continue;
        }
        //if (resData[i] == 'A'){
        // REF #G 
        /*
        if (resDataC[i] == 'A'){
            finished = true;
            b = "";
            resID +=1;
            break;
        }
        */ // End REF #G
        //b += resData[i];
        b += resDataC[i];
    }
    //debugLimit+=1;
    resID += 1;
    }
    //FS.close();
    OS.put(0); // TODO: Confirm is it needed?
    OS.close();
    //std::cout << dataCount/8;
    return resID;
}

auto getResourcesLengthArray(int resID){ // [T] REFs and other [T] Above | Modified REF #G
    const int MAX_LENGTH_OF_SIZE_ARRAY = 100;
    //const int MAX_NUMBER_OF_RESOURCES = 10;

    wchar_t* sizeArrayString = (wchar_t*) calloc(MAX_LENGTH_OF_SIZE_ARRAY, 0);
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

auto getResourcesNameArray(int resID){ // [T] REFs and other [T] Above | Copy Pasted | Modified #G
    const int MAX_LENGTH_OF_NAME_ARRAY = 100;
    //const int MAX_NUMBER_OF_RESOURCES = 10;

    wchar_t* nameArrayString = (wchar_t*) calloc(MAX_LENGTH_OF_NAME_ARRAY, 0);
    LoadStringW(GetModuleHandleW(NULL), resID, nameArrayString,MAX_LENGTH_OF_NAME_ARRAY);
    std::string n = "";
    //int size[MAX_NUMBER_OF_RESOURCES] = {0};
    std::vector<std::string> nameArray;
    for (int i=0; i< MAX_LENGTH_OF_NAME_ARRAY; ++i){
        if (nameArrayString[i] == ','){
            nameArray.push_back(n);//std::__cxx11::stoi(n));
            n = "";
        }
        if (nameArrayString[i] == '!'){
            break;
        }
        n += nameArrayString[i];
    }
    return nameArray;
}