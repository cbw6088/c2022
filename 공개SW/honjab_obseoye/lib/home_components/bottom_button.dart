import 'package:flutter/material.dart';

class BottomButton extends StatefulWidget {
  @override
  _BottomButton createState() => _BottomButton();
}

class _BottomButton extends State<BottomButton> {
  bool isButton1Pressed = true;

  @override
  Widget build(BuildContext context) {
    return Column(
      children: [
        Padding(
          padding: const EdgeInsets.all(12),
          child: Row(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              ElevatedButton(
                onPressed: () {
                  setState(() {
                    isButton1Pressed = true;
                  });
                  Navigator.pushNamed(context, '/graph'); // 그래프 페이지로 이동
                },
                style: ElevatedButton.styleFrom(
                  padding: EdgeInsets.symmetric(horizontal: 55, vertical: 8),
                  shape: RoundedRectangleBorder(
                    borderRadius: BorderRadius.circular(25),
                  ),
                  textStyle: TextStyle(fontSize: 25),
                  backgroundColor: Colors.blueAccent, // 항상 파란색으로 설정
                ),
                child: Text('그래프'),
              ),
              SizedBox(width: 10),
              ElevatedButton(
                onPressed: () {
                  setState(() {
                    isButton1Pressed = false;
                  });
                  Navigator.pushNamed(context, '/liveStreaming'); // 동영상 페이지로 이동
                },
                style: ElevatedButton.styleFrom(
                  padding: EdgeInsets.symmetric(horizontal: 55, vertical: 8),
                  shape: RoundedRectangleBorder(
                    borderRadius: BorderRadius.circular(25),
                  ),
                  textStyle: TextStyle(fontSize: 25),
                  backgroundColor: Colors.blueAccent, // 항상 회색으로 설정
                ),
                child: Text('동영상'),
              ),
            ],
          ),
        ),
        SizedBox(height: 20),
      ],
    );
  }
}
