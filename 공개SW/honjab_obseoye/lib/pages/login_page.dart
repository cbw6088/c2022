import 'package:flutter/material.dart';
import 'package:flutter_svg/flutter_svg.dart';
import '../home_components/custom_form.dart';

class LoginPage extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Padding(
        padding: const EdgeInsets.all(16.0),
        child: ListView(
          children: [
            SizedBox(height: 100.0),
            Container(
              width: 150,
              height: 80,
              decoration: BoxDecoration(
                color: Colors.white,
                borderRadius: BorderRadius.circular(50),
                border: Border.all(
                  color: Colors.blueAccent, // 테두리 색상 설정
                  width: 2.0, // 테두리 두께 설정
                ),
              ),
              child: Center(
                child: Text(
                  "한 시 가 급 해 용",
                  style: TextStyle(
                    color: Colors.blueAccent,
                    fontSize: 24,
                    fontWeight: FontWeight.bold,
                  ),
                ),
              ),
            ),
            SizedBox(height: 20),  // 여백 추가
            Column(
              mainAxisAlignment: MainAxisAlignment.center,  // 세로 중앙 정렬 추가
              crossAxisAlignment: CrossAxisAlignment.center, // 가로 중앙 정렬 추가
              children: [
                CustomForm(),
                SizedBox(height: 20),  // 버튼 위 여백 추가
                GestureDetector(
                  onTap: () {
                    Navigator.pushNamed(context, '/register');  // IP 등록 페이지로 이동
                  },
                  child: Text(
                    'IP 등록하기',
                    style: TextStyle(
                      fontSize: 15,
                      color: Colors.blueAccent,
                      decoration: TextDecoration.underline,
                    ),
                  ),
                ),
              ],
            ),
          ],
        ),
      ),
    );
  }
}
