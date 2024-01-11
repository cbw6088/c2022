import 'package:flutter/material.dart';
import 'package:flutter_login/size.dart';
import 'package:validators/validators.dart';

class CustomTextFormField extends StatelessWidget {
  final String text;
  final mValide;

  const CustomTextFormField({required this.text, required this.mValide});

  @override
  Widget build(BuildContext context) {
    return Column(
      crossAxisAlignment: CrossAxisAlignment.start,
      children: [
        Text("$text"),
        SizedBox(height: small_gap),
        TextFormField(
          validator: mValide,
          obscureText: text == "Password" ? true : false,
          decoration: InputDecoration(
            hintText: "Enter $text",
            border: _CustomOutlineInputBorder(
              borderRadius: BorderRadius.circular(20),
              borderSide: BorderSide(color: Colors.blueAccent), // 테두리 색상 및 두께 설정
            ),
            focusedBorder: _CustomOutlineInputBorder(
              borderRadius: BorderRadius.circular(20),
              borderSide: BorderSide(color: Colors.blueAccent), // 포커스된 테두리 색상 및 두께 설정
            ),
            errorBorder: _CustomOutlineInputBorder(
              borderRadius: BorderRadius.circular(20),
              borderSide: BorderSide(color: Colors.blueAccent), // 에러 테두리 색상 및 두께 설정
            ),
            focusedErrorBorder: _CustomOutlineInputBorder(
              borderRadius: BorderRadius.circular(20),
              borderSide: BorderSide(color: Colors.blueAccent), // 에러 포커스된 테두리 색상 및 두께 설정
            ),
          ),
        ),
      ],
    );
  }
}

class _CustomOutlineInputBorder extends OutlineInputBorder {
  final BorderSide borderSide;

  _CustomOutlineInputBorder({
    required BorderRadius borderRadius,
    required this.borderSide,
  }) : super(
    borderRadius: borderRadius,
    borderSide: borderSide,
  );
}
