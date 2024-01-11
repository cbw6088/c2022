import 'package:flutter/material.dart';
import 'package:flutter_login/pages/home_page.dart';
import 'package:flutter_login/pages/login_page.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      theme: ThemeData(
        textButtonTheme: TextButtonThemeData(
          style: TextButton.styleFrom( // 버튼에 스타일 변경 할 시 styleFrom이 가장 보편적
            backgroundColor: Colors.blueAccent, // 버튼 색상
            primary: Colors.white, // 버튼 텍스트 색상
            shape: RoundedRectangleBorder(
              borderRadius: BorderRadius.circular(30), // 버튼 라운드
            ),
            minimumSize: Size(400, 60), // 버튼 사이즈
          ),
        ),
      ),
      initialRoute: "/login",
      routes: {
        "/login" : (contest) => LoginPage(),
        "/home" : (context) => HomePage(),
      },
    );
  }
}

