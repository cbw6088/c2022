import React from 'react';
import { Text,View,Image, TextInput, Button,FlatList, StyleSheet, Alert, ScrollView,TouchableOpacity, Dimensions, ImageBackground } from 'react-native';
import LottieView from 'lottie-react-native';

const { width, height } = Dimensions.get('window');

const LottieAnimation = () => {
    return (
      <View style={[styles.MenuBox,styles.lottieBox]}>
        <LottieView
          source={require('../animateTest/test.json')} // 애니메이션 JSON 파일 경로
          autoPlay
          loop
          style={styles.lottie}
        />
      </View>
    );
  };
  

const TopView = ({ navigation }) =>{
    const moveToInfo = () => {
        navigation.navigate('Info');
    };
    const moveToProfile = () => {
        navigation.navigate('Profile');
    };
  
  return(
    <ImageBackground
      source={require('../assets/topBox3.png')}
      style={[styles.MenuBox, styles.topView]}
    >
      <View style={styles.topLeftNav}>
        <Image source={require('../assets/lida_logo3.png')} style={styles.topLogo}/>
      </View>
      <View style={styles.topRightNav}>
        <TouchableOpacity style={styles.topRightNavTouch}
          onPress= {moveToProfile}
          >
          <Image source={{ uri: 'https://scontent-ssn1-1.cdninstagram.com/v/t51.2885-19/417925521_1055214925719194_8607554024942250217_n.jpg?stp=dst-jpg_s320x320&efg=e30&_nc_ht=scontent-ssn1-1.cdninstagram.com&_nc_cat=102&_nc_ohc=bQjTKj9uOj4AX-PABs8&edm=AOQ1c0wBAAAA&ccb=7-5&oh=00_AfBATrzty5BsPIlB47xqDBAhCDLcO3LX9JycvTVQi2Gv9g&oe=65A24640&_nc_sid=8b3546' }}
          style={styles.topButtonInfo}
          />
        </TouchableOpacity>
        <TouchableOpacity style={styles.topRightNavTouch}
        onPress={moveToInfo}>
          <Image source={require('../assets/setting2.png')}
          style = {styles.topButtonProfile}
          />
        </TouchableOpacity>
      </View>
    </ImageBackground>
  );
}

const NoticeBox = () => {
    return (
        <View style={[styles.MenuBox, styles.noticeBox]}>
          <Image source={require('../assets/notice4.png')} style={styles.noticeImage} />
        </View>
    );
};

const Menu = ({navigation}) => {

  return (
    <View style={styles.Menu}>
      <TopView navigation={navigation}/>
      <NoticeBox/>
      {/* <LottieAnimation/> */}
      <View style={[styles.MenuBox, styles.imageBox]}>
        <Image
          source={require('../assets/background.png')}
          style={styles.customImage}
        />
      </View>
      <View style={[styles.MenuBox, styles.arrowBox]}>
        <Image source={require('../assets/return5.png')} style={styles.arrowImage} />
        <Image source={require('../assets/rental3.png')} style={styles.arrowImage} />
      </View>
    </View>
  );
}
  
const styles = StyleSheet.create({
    imageBox: {
    height: 0.3 * height, // 높이 설정
    justifyContent: 'center',
    alignItems: 'center',
    borderWidth: 2,
    borderColor: 'black',
  },
  customImage: {
    width: '90%', // 이미지 너비 조정
    height: '90%', // 이미지 높이 조정
    resizeMode: 'contain', // 이미지 비율 유지
  },
  Menu:{
    paddingHorizontal:0.05*width,
  },
  MenuBox: {
    width: '100%',
    backgroundColor: 'white',
    borderRadius: 20,
    marginTop: 0.015 * height,
    flexDirection: 'row',
    alignItems: 'center',
    // borderWidth와 borderColor 속성 제거
  },
  topView:{
    height:height*0.1,
    alignSelf:'center',
    justifyContent:'space-between'
  },
  topLeftNav:{
    width:'33%',
    height:'100%',
  },
  topRightNav:{
    width:'40%',
    flexDirection:'row',
    height:'100%',
    alignItems: 'center',
    paddingHorizontal:30,
  },
  topRightNavTouch:{
    width:0.075*width,
    height:0.075*width,
    marginRight:20,
  },
  topButtonInfo:{
    width:'100%',
    height:'100%',
    borderRadius: 50,
    resizeMode: 'cover',
  },
  topButtonProfile:{
    width:'130%',
    height:'130%',
    marginTop:-5,
  },
  topLogo:{
    width:'100%',
    height:'100%',
    resizeMode:"contain",
    overflow: 'hidden',
  },
  noticeBox: {
    height: height * 0.04,
    backgroundColor: 'white',
    borderRadius: 10,
    justifyContent: 'flex-start',
    alignItems: 'center',
    flexDirection: 'row',
    paddingHorizontal: 5, 
    borderWidth: 2,
    borderColor: 'black',
  },
  noticeImage: {
    width: 30, 
    height: 30,
    resizeMode: 'contain', 
  },
  lottieBox:{
    height:0.42*height,
    overflow: 'hidden',
    borderWidth: 2,
    borderColor: 'black',
  },
  lottie: {
    width: '100%',  
    height: '100%',
  },
  arrowBox:{
    height:'10%',
    justifyContent:'space-between',
    paddingHorizontal:'2%',
    borderWidth: 2,
    borderColor: 'black',
  },
  arrowImage: {
    width: 100, 
    height: 60, 
    resizeMode: 'contain', 
  },
  caption:{
    fontWeight:'bold',
    fontSize:15,
  }
  });

  export default Menu;