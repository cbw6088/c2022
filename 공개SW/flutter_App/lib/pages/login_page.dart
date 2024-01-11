import 'package:flutter/material.dart';
import 'package:flutter_login/components/custom_text_form_field.dart';
import 'package:flutter_login/size.dart';
import 'package:flutter_svg/flutter_svg.dart';
import '../components/Logo.dart';
import '../components/custom_form.dart';

class LoginPage extends StatelessWidget {

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Padding(
        padding: const EdgeInsets.all(16.0),
        child: ListView(
          children: [
            SizedBox(height: xlarge_gap),
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
            SizedBox(height: large_gap),
            CustomForm(),
          ],
        ),
      ),
    );
  }
}
