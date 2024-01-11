import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';

class TopBar extends StatelessWidget implements PreferredSizeWidget {
  @override
  Size get preferredSize => Size.fromHeight(56.0);

  @override
  Widget build(BuildContext context) {
    return AppBar(
      backgroundColor: Colors.white,
      elevation: 1.0,
      leading: GestureDetector(
        onTap: () {
          Navigator.pop(context); // 뒤로 가기 아이콘을 눌렀을 때 이전 화면으로 돌아가기
        },
        child: Padding(
          padding: const EdgeInsets.only(left: 5),
          child: Icon(
            CupertinoIcons.back,
            color: Colors.blueAccent,
            size: 30,
          ),
        ),
      ),
      title: Row(
        mainAxisAlignment: MainAxisAlignment.center,
        children: [
          //SizedBox(width: 30), // 좌측 여백
          Text(
            "한시가급해용",
            style: TextStyle(fontSize: 25, color: Colors.blueAccent),
          ),
        ],
      ),
      actions: [
        Padding(
          padding: const EdgeInsets.only(right: 20),
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
