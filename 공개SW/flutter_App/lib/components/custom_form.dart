import 'package:flutter/material.dart';
import 'package:validators/validators.dart';
import '../size.dart';
import 'custom_text_form_field.dart';

class CustomForm extends StatelessWidget {
  final _formKey = GlobalKey<FormState>();

  @override
  Widget build(BuildContext context) {
    return Form(
      key: _formKey,
      child: Column(
        children: [
          CustomTextFormField(
            text : "Email",
            mValide: (value) {
              if(value!.isEmpty){return "Please enter some text.";}
              else if(!isEmail(value)){return "이메일 형식이 아닙니다.";}
              else{return null;}
            },
          ),
          SizedBox(height: medium_gap),
          CustomTextFormField(
            text : "Password",
            mValide: (value) {
              if(value!.isEmpty){return "Please enter some text.";}
              else if(value.toString().length > 20){return "패스워드의 길이를 초과하였습니다.";}
            },
          ),
          SizedBox(height: large_gap),
          TextButton(
            onPressed: (){
              // 유효성 검사 성공 true리턴, 아니면 false 리턴
              if(_formKey.currentState!.validate()){
                Navigator.pushNamed(context, "/home");
              }
            },
            child: Text("Login", style: TextStyle(fontSize: 20)),
          ),
        ],
      ),
    );
  }
}
