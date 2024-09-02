#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

int main() {

    char* fPaths = (char *) alloca(1000);
    LoadStringA(GetModuleHandle(NULL), 40000, fPaths, 1000);

    char* folderPaths = (char *) alloca(1000); // [T] Above
    LoadStringA(GetModuleHandle(NULL), 40001, folderPaths, 1000); //
    std::string HfolderPath = "";
    for (int i=0; i < 1000; ++i){
        if (folderPaths[i] == '\0'){
            //return 0;
            break;
        }
        if (folderPaths[i] == ','){
            CreateDirectoryA(HfolderPath.c_str(), NULL);
            std::cout << HfolderPath << std::endl;
            HfolderPath = "";
            continue;
        }
        HfolderPath += folderPaths[i];
    }
    //std::cout << fPaths;
    std::string H = "";
    int startID = 1000;
    bool finished = false;
    int fPathIndex = 0;
    char CH;
    while(!finished){
        H = "";
        for (;fPathIndex < 1000; ++fPathIndex){
            CH = fPaths[fPathIndex];
            if (CH == '\0'){
                //std::cout << "Finished !";
                finished = true;
                break;
            }
            if (CH == ','){
                fPathIndex++;
                break;
            }
            H += fPaths[fPathIndex];
        }
        if (finished){
            break;
        }
        //if (fPathIndex == 1000){
        //    finished = true;
        //}
        //if (H == ""){
        //    std::cout << fPathIndex << "\n";
        //    continue;
        //}

        std::ofstream OS;//(H.c_str());
        std::cout << H << " | " << startID << "\n";

        //CreateDirectoryA(H.c_str(), NULL);
        //CreateFileA(H.c_str(), NULL, NULL ,NULL, NULL, NULL, NULL);
        OS.open(H.c_str(), std::ios_base::openmode(4));
        if (OS.is_open()){
           // H = "";
            bool writeFinished = false;
            while (!writeFinished){
                
                char* bytes = (char *) alloca(4010); // [T] Below
                LoadStringA(GetModuleHandle(NULL), startID, bytes, 4010); // [T] Below
                //std::cout << startID;
                if (bytes[0] == 'A'){
                    writeFinished = true;
                    continue;
                }
                for (int i=0; i < 4010; ++i){
                  //  std::cout << bytes[i];
                    if (bytes[i] == '\0'){
                        break;
                    }
                    if (bytes[i] == ','){
                        //std::cout << H.c_str() << std::endl;
                        //std::cout << startID << std::endl;
                        OS.put(std::__cxx11::stoi(H.c_str()));
                        H = "";
                        continue;
                    }
                    H += bytes[i];
                }
                startID += 1;
            }
            startID += 1;
        } else {
            std::cout << "Failed to create: " << H.c_str() << std::endl;
        }
    }

    //char* bytes = (char *) alloca(4010);
    //LoadStringA(GetModuleHandle(NULL), 1000, bytes, 4010);
    
    
    //ShellExecuteA(GetWindow(NULL,NULL),NULL, "./setup.exe", NULL, "./", SW_SHOW); // TEMP C
    
    return 0;
}