import React, { useState, useEffect } from 'react';
import { Alert, View, TextInput, Button, TouchableOpacity, Text, StyleSheet, Image, Dimensions } from 'react-native';
import AsyncStorage from '@react-native-async-storage/async-storage';
import { getUserByUsername, signInWithGithub, recordLogin } from './dataService';
import * as AuthSession from 'expo-auth-session';
import * as AppleAuthentication from 'expo-apple-authentication';
import { makeRedirectUri, useAuthRequest } from 'expo-auth-session';

const { width, height } = Dimensions.get('window');

const saveTokenToStorage = async (token) => {
  try {
    await AsyncStorage.setItem('userToken', token);
  } catch (error) {
    console.error('Error saving token to local storage:', error);
  }
};



const Login = ({ navigation }) => {
  const [username, setUsername] = useState('');
  const [password, setPassword] = useState('');
  
  const handleLogin = async () => {
    try {
      //로그인 유효성 검사
      if (username === 'admin' && password === '') {
        console.log('login OK');
        navigation.reset({
          index: 0,
          routes: [{ name: 'Home' }],
        });
        saveTokenToStorage('tokenvv');//제대로 된 토큰 만들어서 백과 연동 준비..
      } else {
        console.log('Login failed');
      }

    } catch (error) {
      console.error('Login error:', error);
      // 로그인 과정에서 오류 발생 처리
    }
  };

  const navigateToHome = () => {
    navigation.reset({
      index: 0,
      routes: [{ name: 'Home' }],
    });
  };

  const handleButton1Press = async () => {
      console.log('apple 로그인 시도');

    };
    
    
  const naverLogin = async () => {
    const [request, response, promptAsync] = useAuthRequest({
      clientId: 'pFAvCvO60D4PwjXpWLza', 
      redirectUri: AuthSession.makeRedirectUri({ useProxy: true }),
      clientSecret: '7r86Ft9EeA',
    },{
        authorizationEndpoint: 'https://nid.naver.com/oauth2.0/authorize',
        tokenEndpoint: 'https://nid.naver.com/oauth2.0/token',
      });

      useEffect(() => {
        
        if (response && response.type === 'success') {
          console.log(response);
          const { code } = response.params;
        }
      }, [response]);
  };
    
    

  const loginApple = async () => {
    try {
      const credential = await AppleAuthentication.signInAsync({
        requestedScopes: [
          AppleAuthentication.AppleAuthenticationScope.FULL_NAME,
          AppleAuthentication.AppleAuthenticationScope.EMAIL,
        ],        
      });
      const dataSet =  {
        id_token: credential.identityToken,
        provider:'APPLE', 
        name:credential.fullName.nickname,
      };
      console.log(dataSet);
      
      // signed in
    } catch (e) {
      console.log(e);
      //if (e.code === 'ERR_REQUEST_CANCELED') {
      Alert.alert(
        '로그인 실패','잠시 후 다시 시도!',
          [
          {
            text:'확인',
            color:'black',
            onPress: () => console.log("아니라는데"),
          },  { text: "네", onPress: () => console.log("그렇다는데") }, //버튼 제목
        ]);
      
    }
  }

  return (
    <View style={styles.container}>
      <TextInput
        style={styles.input}
        placeholder="Username"
        value={username}
        onChangeText={(text) => setUsername(text)}
      />
      <TextInput
        style={styles.input}
        placeholder="Password"
        secureTextEntry
        value={password}
        onChangeText={(text) => setPassword(text)}
      />
      <Button title="로그인" onPress={handleLogin} />

      <View style={styles.buttonContainer}>
        {/* Apple 로그인 버튼*/}
        <AppleAuthentication.AppleAuthenticationButton
        buttonType={AppleAuthentication.AppleAuthenticationButtonType.SIGN_IN}
        buttonStyle={AppleAuthentication.AppleAuthenticationButtonStyle.BLACK}
        cornerRadius={5}
        style={styles.circleButton}
        onPress={loginApple}
      />

        {/* github 버튼 */}
        <TouchableOpacity style={styles.circleButton} onPress={handleButton1Press}>
          <Image source={require('../assets/logo/git_logo.png')} style={styles.buttonImage} />
        </TouchableOpacity>
        
        {/* Kakao 버튼 */}
        <TouchableOpacity style={styles.circleButton} onPress={naverLogin}>
          <Image source={require('../assets/logo/kakao.png')} style={styles.buttonImage} />
        </TouchableOpacity>
      </View>
    </View>
  );
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
    padding: 16,
  },
  input: {
    width: '100%',
    height: 40,
    borderWidth: 1,
    borderColor: '#ccc',
    marginBottom: 12,
    paddingLeft: 8,
  },

  buttonContainer: {
    flexDirection: 'row', // 가로 방향으로 버튼 배열
    justifyContent: 'center', // 중앙 정렬
    marginTop: 12,
    width:width*0.2,
    height:height*0.2,
  },
  circleButton: { // 원형 버튼
    width: 60,
    height: 60,
    borderRadius: 30,
    justifyContent: 'center',
    alignItems: 'center',
    backgroundColor: 'transparent',
    marginHorizontal: 10, // 좌우 마진
  },
  buttonImage: {
    width: 50, 
    height: 50, 
    resizeMode: 'contain' // 이미지의 비율을 유지하면서 버튼 안에 맞춤
  },
});

export default Login;