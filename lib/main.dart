import 'dart:io';

import 'package:flutter/material.dart';
import 'package:flutter_archive/flutter_archive.dart';

//import 'package:window_manager/window_manager.dart'; // [HISTORY]
//import 'dart:ffi';
void main() {
  runApp(const MainApp());
}

class MainApp extends StatelessWidget {
  const MainApp({super.key});

  @override
  Widget build(BuildContext context) {
    var path = "C://test";
    var softwareDir = "test";

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
      home: Scaffold(
        body: Center(
          child: TextButton.icon(icon: const Icon(Icons.install_desktop, size: 30,),label: const Text("Install", style: TextStyle(color: Colors.white, fontSize: 30),), onPressed: (){
            Directory(path).createSync();
            //var zip = ZipEntry(name: "test", isDirectory: true);
            ZipFile.extractToDirectory(zipFile: File(softwareDir), destinationDir: Directory(path));
            var list = Directory(softwareDir).listSync(recursive: true); // [T] Description of listSync
            for (var file in list) {
              File(file.path).copySync(path + file.path.replaceFirst("$softwareDir\\", ''));
            }
          },),
        ),
      ),
    );
  }
}
