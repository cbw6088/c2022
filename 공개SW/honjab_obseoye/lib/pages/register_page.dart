import 'package:flutter/material.dart';

class RegisterPage extends StatefulWidget {
  @override
  _RegisterPageState createState() => _RegisterPageState();
}

class _RegisterPageState extends State<RegisterPage> {
  bool isRegistered = false;
  TextEditingController ipController = TextEditingController();

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Row(
          children: [
            SizedBox(width: 16),
            Text(
              'IP 등록하기',
              style: TextStyle(fontSize: 18),
            ),
          ],
        ),
      ),
      body: Center(
        child: Padding(
          padding: const EdgeInsets.all(16.0),
          child: isRegistered
              ? Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              Text(
                '등록이 완료되었습니다.',
                style: TextStyle(
                  fontSize: 20,
                  fontWeight: FontWeight.bold,
                ),
              ),
              SizedBox(height: 20),
              ElevatedButton(
                onPressed: () {
                  Navigator.pop(context); // 로그인 화면으로 되돌아가기
                },
                child: Text('확인'),
              ),
            ],
          )
              : Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              Text(
                'IP 주소를 등록하세요',
                style: TextStyle(
                  fontSize: 20,
                  fontWeight: FontWeight.bold,
                ),
              ),
              SizedBox(height: 20),
              TextField(
                controller: ipController,
                decoration: InputDecoration(
                  labelText: 'IP 주소',
                  border: OutlineInputBorder(),
                ),
              ),
              SizedBox(height: 20),
              ElevatedButton(
                onPressed: () {
                  // 여기에 IP 주소 등록 로직을 추가하세요.
                  setState(() {
                    isRegistered = true;
                  });
                },
                child: Text('등록하기'),
              ),
            ],
          ),
        ),
      ),
    );
  }
}