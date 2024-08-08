import 'package:flutter/material.dart';
//import 'package:window_manager/window_manager.dart'; // [HISTORY]

void main() {
  runApp(const MainApp());
}

class MainApp extends StatelessWidget {
  const MainApp({super.key});

  @override
  Widget build(BuildContext context) {
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
            
          },),
        ),
      ),
    );
  }
}
