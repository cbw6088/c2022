import 'package:flutter/material.dart';

// primaryColor: 앱의 브랜드 색상
// secondary color(accent color) : 앱의 버튼이나, 상호작용 하는 이벤트 색상
ThemeData theme() {
  return ThemeData(
    fontFamily: "PatuaOne",
    primaryColor: Colors.blue,
    appBarTheme: AppBarTheme(
        backgroundColor: Colors.white,
        iconTheme: IconThemeData(
          color: Colors.blue,
        )),
  );
}
