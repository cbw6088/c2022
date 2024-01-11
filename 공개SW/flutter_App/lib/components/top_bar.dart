import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';

class TopBar extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return AppBar(
      backgroundColor: Colors.white,
      elevation: 1.0,
      actions: [
        GestureDetector(
          onTap: () {
            Navigator.pop(context); // 뒤로 가기 아이콘을 눌렀을 때 이전 화면으로 돌아가기
          },
          child: Row(
            children: [
              Padding(
                padding: const EdgeInsets.only(left: 2),
                child: Icon(
                  CupertinoIcons.back,
                  color: Colors.blueAccent,
                  size: 30,
                ),
              ),
              SizedBox(width: 103),
              Text(
                "한시가급해용",
                style: TextStyle(fontSize: 25, color: Colors.blueAccent),
              ),
            ],
          ),
        ),
        SizedBox(width: 103),
        Padding(
          padding: const EdgeInsets.only(right: 8),
          child: Icon(
            CupertinoIcons.bell,
            color: Colors.blueAccent,
            size: 30,
          ),
        ),
      ],
    );
  }
}
