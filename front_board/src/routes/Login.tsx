import styled, {createGlobalStyle} from "styled-components";
import React, { useState } from "react";
import { useNavigate } from "react-router-dom";
import { useAuth } from "../security/AuthContext"; // 가정: AuthContext가 로그인 상태를 관리
import google from '../../assets/logo/google2.png'; 
import naver from '../../assets/logo/naver.png'; 

const GlobalStyle = createGlobalStyle`
  html, body {
    margin: 0;
    padding: 0;
    overflow-x: hidden;
  }
  #root {
    width: 100vw;
    height: 100vh;
    overflow: hidden;
  }
`;
const Wrapper = styled.div`
  height: 100vh;
  width: 100vw;
`;
const CenterBox = styled.div`
  display: flex;
  flex-direction: column;
  justify-content: center;
  align-items: center;
  position: absolute;
  top: 50%;
  left: 50%;
  transform: translate(-50%, -50%);
  width: 35%;
  max-width: '100%';
  height: auto;
  background-color: rgba(255, 255, 255, 0.8);
  box-shadow: 1px 1px 3px rgba(0,0,0,0.5);
  border-radius: 10px;
  padding: 20px;
`;
const WelcomeMessage = styled.h1`
  font-size: 3.5vw;
  color: #0e6be5;
  text-shadow: 2px 2px 4px rgba(0,0,0,0.4);
  white-space: nowrap;
  margin-bottom: 10px;
`;
const ImageButtonContainer = styled.div`
  display: flex;
  justify-content: center;
  gap: 20px;
  margin-bottom: 20px;
`;
const ImageButton = styled.button<ImageButtonProps>`
  background-image: url(${props => props.image});
  background-color: transparent;
  border: none;
  width: 80px;
  height: 80px;
  cursor: pointer;
  background-position: center;
  background-repeat: no-repeat;
  background-size: contain;
  &:focus {
    outline: none;
  }
`;
const Form = styled.form`
  align-items: center;
  display: flex;
  flex-direction: column;
  width: 100%;
`;
const Input = styled.input`
  width: 60%;
  margin-bottom: 1rem;
  padding: 0.5rem;
  background-color: white;
  /* border: 1px solid #ccc; */
  border: none;
  border-radius: 4px;
  box-shadow: inset 0 2px 4px rgba(0, 0, 0, 0.1);

  &:focus {
    outline: none;
    box-shadow: inset 0 2px 4px rgba(0, 0, 0, 0.1);
  }
`;
const SubmitButton = styled(Input).attrs({ type: 'submit' })`
  font-size: 1.5vw;
  border-radius: 20px;
  width: 30%;
  //height: 5vh;
  font-size: 12px;
  background-color: #0e6be5;
  color: white;
  cursor: pointer;
  border: 1px solid #0e6be5;
  margin-bottom: 1rem;

  &:hover {
    background-color: #0056b3;
    border: 1px solid #0056b3;
    color: white;
  }
`;
const SignupButton = styled.button`
  font-size: 1vw;
  padding: 0;
  /* width: 85%;
  height: 5vh; */
  font-size: 12px;
  color: #0e6be5;
  background-color: transparent;
  cursor: pointer;
  border: none;

  &:hover {
    background-color: transparent;
    color: #0056b3;
  }
`;

type ImageButtonProps = {
  image: string;
  onClick?: () => void;
};

export default function Login() {
  const navigate = useNavigate();
  const auth = useAuth(); // 가정: useAuth()는 현재 로그인한 사용자의 정보를 반환
  const [userId, setUserId] = useState("");
  const [password, setPassword] = useState("");

  const onSubmit = async (event: React.FormEvent<HTMLFormElement>) => {
    event.preventDefault(); // 기본 동작 막기
    console.log("로그인 요청");
  
    const userAccount = {
      "username": userId,
      "password": password
    }
    try {
      const success = await auth.login(userAccount)
      if(success){
        console.log(auth.username, auth.token)
        navigate("articles")
      }
      else{
        window.alert("아이디 또는 비밀번호가 일치하지 않습니다!!")
      }
    } catch (error) {
      window.alert("아이디 또는 비밀번호가 일치하지 않습니다.")
    }
  }
  
  const onChange = (e: React.ChangeEvent<HTMLInputElement>) => {
    const { name, value } = e.target;
    if (name === "userId") {
      setUserId(value);
    } else if (name === "password") {
      setPassword(value);
    }
  };

  const onSignup = () => {
    console.log("회원가입 페이지로 이동");
    navigate('/signup')
  };
  const googleButton = () => {
    console.log("googleButton");
  }
  const naverButton = () => {
    console.log("naverButton");
  }

  return (
    <>
    <GlobalStyle/>
      <Wrapper>
        <CenterBox>
          <>
            <Form onSubmit={onSubmit}>
              <WelcomeMessage>Welcome!</WelcomeMessage>
              <ImageButtonContainer>
                <ImageButton image={google} onClick={googleButton} />
                <ImageButton image={naver} onClick={naverButton} />
              </ImageButtonContainer>
              <Input
                name="userId"
                value={userId}
                placeholder="UserId"
                type="text"
                required
                onChange={onChange}
              />
              <Input
                name="password"
                value={password}
                placeholder="Password"
                type="password"
                required
                onChange={onChange}
              />
              <SubmitButton value="SIGN IN" />
              <SignupButton onClick={onSignup}>SIGN UP</SignupButton>
            </Form>    
          </>
        </CenterBox>
      </Wrapper>
    </>
  );
}