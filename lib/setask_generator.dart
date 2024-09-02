import 'dart:io';

import 'package:flutter/material.dart';

class GeneratorPanel extends StatelessWidget{
  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    //throw UnimplementedError();
    return Scaffold(body: Padding(padding: EdgeInsets.all(32.0), child: Center(child: TextButton(onPressed: (){
generateList();
    }, child: Text("Generate")))));
  }
}


generateList({String path="./software"}){
  String list = "";
  String listD = "";
  Directory(path).listSync(recursive: true).forEach((file){
    //print(file.runtimeType);
    if (file.runtimeType.toString() == "_File"){ // [T] Type Desc
    list += file.path;
    list +="\n";
    } else {
      listD += file.path;
      listD += "\n";
    }
});
  //print(list);z
  //list.replaceRange(list.length-1, list.length,'');
  if (list.isNotEmpty){
  //list = list.replaceFirst('\n', '', list.length-1);
  list = list.replaceRange(list.length-1, list.length, ''); // [T] Above
  }
  if (listD.isNotEmpty){ // [T]
    listD = listD.replaceRange(listD.length-1, listD.length, ''); // [T] Above
  }
  list = list.replaceAll('\\', '/');
  listD = listD.replaceAll('\\','/'); // [T] Above

  File("lib/softwareList.txt").writeAsStringSync(listD + "\nF\n" + list);
  return list;
}