#include <fstream>
#include <iostream>
#include <string>

int main () {
    std::ifstream FS("./softwareList.txt");
    if (FS.is_open()){
    
    int startID = 1000;
    std::string RC = "STRINGTABLE {";
    std::ofstream OS;//("./software.rc");//, std::ios_base::openmode(4));
    OS.open("./software.rc"); // [T] Above
    OS.write(RC.c_str(),RC.size());
    //std::string H = "";
    std::string fPaths = "\n40000,\"";
    std::string folderPaths = "\n40001,\"";
    bool fileType = false;
    char * filePath = (char *) alloca(255);
    while (!FS.eof()) {
        FS.getline(filePath, 255);
        //FS.getline();
        std::cout << filePath << std::endl;
        if (filePath[0] == 'F'){
            fileType = true;
            continue;
        }
        if (!fileType){
            folderPaths += filePath;
            folderPaths += ',';
            continue;
        }
        std::ifstream FS_RC;//(filePath);
        FS_RC.open(filePath, std::ios_base::openmode(4)); // [T] Above
        if (FS_RC.is_open()){
            fPaths += filePath;
            while (!FS_RC.eof()){
            RC = "\n";
            RC += std::to_string(startID);
            RC += ",\"";
            
            OS.write(RC.c_str(), RC.size());
            //while (!FS_RC.eof()){
                for (int i = 0; i < 4000;){
                //if (FS_RC.eof()){break;}
                //H 
                RC = std::to_string(FS_RC.get());
                if (FS_RC.eof()){break;} // NOTE: maybe we could use -1 instead of 'A'
                //std::cout << FS_RC.get();
                //OS.put(std::to_string(FS_RC.get()).c_str()[]);
                OS.write(//H
                RC.c_str(), //H
                RC.size());

                OS.put(',');
                i += RC.size() + 1;
                }
                if (FS_RC.eof()){OS.put('"'); startID+=1; break;} // [T] Below
                OS.put('"');
                startID+=1;
            }
            //OS.put('"');
            
            //OS.write(RC.)
            RC = "\n";
            RC += std::to_string(startID);
            startID+=1;
            RC += ",\"A\"";
            OS.write(RC.c_str(), RC.size());
            fPaths += ",";
            //OS.put('\n');
            //RC = 
            FS_RC.close();
        } else {
            std::cout << "Failed to open File: " << filePath << std::endl;
        }
    }
    //OS.put('\n');
    fPaths += "\"\n";
    folderPaths += "\"\n"; // [T] Above
    OS.write(fPaths.c_str(), fPaths.size());
    OS.write(folderPaths.c_str(), folderPaths.size()); // [T] Above
    //OS.put('\n');
    OS.put('}');
    OS.close();
    } else {
        std::cout << "Failed to Open List File" << std::endl;
    }
    return 0;
}