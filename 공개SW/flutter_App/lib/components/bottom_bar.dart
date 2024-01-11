import 'package:flutter/material.dart';

class BottomBar extends StatelessWidget {

  @override
  Widget build(BuildContext context) {
    return Padding(
      padding: const EdgeInsets.all(20),
      child: Container(
        height: 60.0, // 사각 박스의 높이
        decoration: BoxDecoration(
          color: Colors.white, // 사각 박스의 배경색 (흰색)
          borderRadius: BorderRadius.circular(30), // 라운드 지정
          border: Border.all(
            color: Colors.blueAccent, // 테두리 색깔
            width: 2, // 테두리 두께
          ),
        ),
        child: Row(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            Icon(Icons.person, color: Colors.blueAccent, size: 45),
            SizedBox(width: 80), // 아이콘 사이의 간격
            Icon(Icons.home, color: Colors.blueAccent, size: 45),
            SizedBox(width: 80), // 아이콘 사이의 간격
            Icon(Icons.settings, color: Colors.blueAccent, size: 45),
          ],
        ),
      ),
    );
  }
}
