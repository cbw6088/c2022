import 'package:flutter/material.dart';

class MiddleButton extends StatefulWidget {
  const MiddleButton({super.key});

  @override
  _MiddleButtonState createState() => _MiddleButtonState();
}

class _MiddleButtonState extends State<MiddleButton> {
  bool isButton1Pressed = true; // 첫 번째 버튼이 눌렸는지 여부

  @override
  Widget build(BuildContext context) {
    return Column(
      children: [
        Row(
          mainAxisAlignment: MainAxisAlignment.center, // 가운데 정렬
          children: [
            ElevatedButton(
              onPressed: () {
                setState(() {
                  isButton1Pressed = true;
                });
              },
              style: ElevatedButton.styleFrom(
                padding: EdgeInsets.symmetric(horizontal: 35, vertical: 10), // 버튼의 패딩 조정
                shape: RoundedRectangleBorder(
                  borderRadius: BorderRadius.circular(25), // 버튼의 모서리를 라운드 지정
                ),
                textStyle: TextStyle(fontSize: 22),
                backgroundColor: isButton1Pressed ? Colors.blueAccent : Colors.grey, // 배경색 변경
              ),
              child: Text('실시간 수치'),
            ),
            SizedBox(width: 10), // 버튼 사이 간격 조정
            ElevatedButton(
              onPressed: () {
                setState(() {
                  isButton1Pressed = false;
                });
              },
              style: ElevatedButton.styleFrom(
                padding: EdgeInsets.symmetric(horizontal: 35, vertical: 10), // 버튼의 패딩 조정
                shape: RoundedRectangleBorder(
                  borderRadius: BorderRadius.circular(25), // 버튼의 모서리를 라운드 지정
                ),
                textStyle: TextStyle(fontSize: 22),
                backgroundColor: isButton1Pressed ? Colors.grey : Colors.blueAccent, // 배경색 변경
              ),
              child: Text('주간 그래프'),
            ),
          ],
        ),
        SizedBox(height: 20), // 간격 추가
      ],
    );
  }
}