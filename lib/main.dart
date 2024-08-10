//import 'dart:convert';
//import 'dart:io';

//import 'package:archive/archive_io.dart';
import 'package:flutter/material.dart';
import 'package:setask/setask_installer.dart';
//import 'package:archive/archive.dart' as a;
//import 'package:archive/archive_io.dart';

//import 'package:async_zip/async_zip.dart';
//import 'package:flutter_archive/flutter_archive.dart';

//import 'package:window_manager/window_manager.dart'; // [HISTORY]
//import 'dart:ffi';
void main() {
  runApp(const MainApp());
}

class MainApp extends StatelessWidget {
  const MainApp({super.key});

  @override
  Widget build(BuildContext context) {
    //var path = "C://test";
    //var softwareDir = "test";
    //var softwareDir = "software";
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      theme: 
      ThemeData(
        scaffoldBackgroundColor: Colors.black45,
        textButtonTheme: const TextButtonThemeData(style: ButtonStyle(
            backgroundColor: WidgetStatePropertyAll(Colors.amber),
            padding: WidgetStatePropertyAll(EdgeInsets.all(30.0)),
            shape: WidgetStatePropertyAll(RoundedRectangleBorder(borderRadius: BorderRadius.all(Radius.circular(20.0)))),
            textStyle: WidgetStatePropertyAll(TextStyle(color: Colors.white, fontWeight: FontWeight.bold)),
            iconColor: WidgetStatePropertyAll(Colors.white60)))
        ),
      home: installer()
      //LicensePage(applicationName: "Setask") // see info.dart for more information | Ref #L
      //installer() 
      //home: 
      
      /*Scaffold(
        body: Center(
          child: Column(children:[
            TextButton(onPressed: (){
              generateZipFromSoftwareDir(softwareDir);
              generateResourceScript();
              /*
              //var as = a.Archive();
             // var archived = createArchiveFromDirectory(Directory("test"));
              
              var test = a.ZipEncoder();
              //archived.toList().forEach((file){
                //test.addFile(file);
              //});
              var o = OutputFileStream("test.zip");
              test.startEncode(o);
              //test.startEncode(OutputFileStream("test.zip"));
              test.addFile(ArchiveFile.string("test.text", File("test/test.txt").readAsStringSync()));
              test.endEncode();
              o.closeSync();
              print("done");
              //test.startEncode(OutputFileStream("test.zip"));
*/
/*
              var z = ZipFileWriterSync();
              z.create(File("test.zip"));
              z.writeFile("test.txt", File("test/test.txt"));
              z.close();
*/



         /*     ZipFile.createFromDirectory(sourceDir: Directory(softwareDir), zipFile: File("test.zip")).then((r){ // [T] zipFile Description
                String data = File("test.zip").readAsStringSync();
                File("software.rc").writeAsStringSync("STRINGTABLE {\n1000, \"" +  data + "\"\n}");
              }); // [T] zipFile Description*/

            }, child: const Text("Generate")),
            TextButton.icon(icon: const Icon(Icons.install_desktop, size: 30,),label: const Text("Install", style: TextStyle(color: Colors.white, fontSize: 30),), onPressed: (){



/* Directory(path).createSync();
            //var zip = ZipEntry(name: "test", isDirectory: true);
          //  ZipFile.extractToDirectory(zipFile: File(softwareDir), destinationDir: Directory(path));
           // var list = Directory(softwareDir).listSync(recursive: true); // [T] Description of listSync
            //for (var file in list) {
              //File(file.path).copySync(path + file.path.replaceFirst("$softwareDir\\", ''));
            //}
          var iSBase = InputFileStream("software.zip");
          var zipD = ZipDecoder(); // [T] Ref #1
          //zipD.directory = ZipDirectory.read(iSBase);
          var archive = zipD.decodeBuffer(iSBase);
          archive.files.forEach((file){
           // print(path+file.name);
            var o = OutputFileStream(path+"/"+file.name);
            file.writeContent(o);
            o.close();
          });
          iSBase.close();
*/ // SOME PARTS HERE were recreated in setask_installer.dart


          },),
        ])),
      ),*/
    );
  }
}

/* Moved to setask_generator.dart
void generateZipFromSoftwareDir(String softwareDir){
  var zip = ZipEncoder(); // REF #1
  var outputFS = OutputFileStream("software.zip");
  zip.startEncode(outputFS);
  Directory(softwareDir).listSync(recursive: true).forEach((file){
    //print(file.path.replaceFirst(softwareDir + '\\', ''));
    zip.addFile(ArchiveFile.string(file.path.replaceFirst(softwareDir + '\\', ''), File(file.path).readAsStringSync()));
  });
  zip.endEncode();
  outputFS.closeSync();
}


void generateResourceScript(){
  var sData = File("software.zip").readAsBytesSync();
  //print(sData.toString());
  print(sData.toString().length.toString());
  var data = "STRINGTABLE{\n1000, \"" +  sData.toString().replaceAll(' ', '').length.toString() + "\"\n1001, \"" + sData.toString().replaceAll(' ', '') + "\"\n}";
  File("lib/software.rc").writeAsStringSync(data);
}
*/