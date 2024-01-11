import 'package:flutter/material.dart';

class ImageCheck extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Padding(
      padding: const EdgeInsets.all(10),
      child: Column( // 세로로 배치하기 위해 Column 사용
        crossAxisAlignment: CrossAxisAlignment.start, // 왼쪽 정렬
        children: [
          Container(
            width: 100, // 원하는 너비 값으로 설정
            height: 30, // 원하는 높이 값으로 설정
            decoration: BoxDecoration(
              color: Colors.blueAccent, // 사각 박스의 배경색
              borderRadius: BorderRadius.circular(8), // 라운드 지정
            ),
            child: Center(
              child: Text(
                "이미지",
                style: TextStyle(fontSize: 20, color: Colors.white), // 텍스트 스타일 설정
              ),
            ),
          ),
          SizedBox(height: 10), // 이미지와 사각 박스 사이의 간격 조정
          Image.asset(
            'assets/img.png', // 이미지 추가, 파일 경로를 수정해야 합니다
            width: 360, // 원하는 너비 값으로 설정
            height: 250, // 원하는 높이 값으로 설정
            fit: BoxFit.contain, // 이미지의 적합한 크기 설정 옵션
          ),
        ],
      ),
    );
  }
}
