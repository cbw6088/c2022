import React, { useState } from 'react';
import { StyleSheet, ScrollView, View, Image, Dimensions, TouchableOpacity, Text } from 'react-native';

const { width, height } = Dimensions.get('window');



const Menu = ({navigation}) => {
  const [showProfileBox, setShowProfileBox] = useState(false);

  const toggleProfileBox = () => {
    setShowProfileBox(!showProfileBox); // 현재 상태를 반대로 변경
  };

  const googleButton = () =>{
    console.log('googleButton!!');
  }
  const kakaoButton = () =>{
    console.log('kakaoButton!!');
  }
  const naverButton = () =>{
    console.log('naverButton!!');
  }
  const settingButton = () =>{
    console.log('settingButton!!');
    navigation.navigate('Info');
  }
  const contentButton = () =>{
    console.log('contentButton!!');
    navigation.navigate('Content');
  }
  const tempButton = () =>{
    console.log('tempButton!!');
  } 
  const eventButton = () =>{
    console.log('eventButton!!');
  }
  const returnButton = () =>{
    console.log('returnButton!!');
    navigation.navigate('Return');
  }

  return (
    <ScrollView style={styles.scrollView}>
      <View style={styles.container}>
        <Image
          source={require('../assets/background/topBox6.png')}
          style={styles.image}
          resizeMode="contain"
        />
        <View style={styles.header}>
          <Image
            source={require('../assets/logo/logo_test.png')}
            style={styles.logo}
          />
          <View style={styles.topButtons}>
          <TouchableOpacity style={styles.topButton}>
              <Image
                source={require('../assets/icon/notice.png')}
                style={styles.topButtonImage}
              />
            </TouchableOpacity>
            <TouchableOpacity style={styles.button} onPress={toggleProfileBox}>
              <Image
                source={require('../assets/icon/loginProfile.png')}
                style={styles.topButtonImage}
              />
            </TouchableOpacity>
            {showProfileBox && (
              <View style={styles.profileBoxContainer}>
              <Image
                source={require('../assets/background/profileBox4.png')}
                style={styles.profileBoxImage}
              />
              <View style={styles.profileButtons}>
                <TouchableOpacity onPress={this.firstButtonPress}>
                  <Image
                    source={require('../assets/logo/google2.png')}
                    style={styles.profileButtonImage}
                  />
                </TouchableOpacity>
                <TouchableOpacity onPress={this.secondButtonPress}>
                  <Image
                    source={require('../assets/logo/kakao2.png')}
                    style={styles.profileButtonImage}
                  />
                </TouchableOpacity>
                <TouchableOpacity onPress={this.thirdButtonPress}>
                  <Image
                    source={require('../assets/logo/naver2.png')}
                    style={styles.profileButtonImage}
                  />
                </TouchableOpacity>
              </View>
            </View>
            )}
            <TouchableOpacity style={styles.button} onPress={settingButton}>
              <Image
                source={require('../assets/icon/setting.png')}
                style={styles.topButtonImage}
              />
            </TouchableOpacity>
          </View>
        </View>
        <View style={styles.mainButtonContainer}>
          <Image
            source={require('../assets/icon/mainButton2.png')}
            style={styles.mainButton}
            resizeMode="contain"
          />
          <TouchableOpacity
            style={[styles.buttonOverlay, { top: 93, left: 145 }]}
            onPress={contentButton}
            activeOpacity={1.0}
          >
            <Image
              source={require('../assets/icon/mainButton_1.png')}
              style={styles.buttonImage}
            />
          </TouchableOpacity>
          <TouchableOpacity
            style={[styles.buttonOverlay, { top: 10, left: 145 }]}
            onPress={tempButton}
            activeOpacity={1.0}
          >
            <Image
              source={require('../assets/icon/mainButton_2.png')}
              style={styles.buttonImage}
            />
          </TouchableOpacity>
          <TouchableOpacity
            style={[styles.buttonOverlay, { top: 93, left: 10 }]}
            onPress={eventButton}
            activeOpacity={1.0}
          >
            <Image
              source={require('../assets/icon/mainButton_3.png')}
              style={styles.buttonImage}
            />
          </TouchableOpacity>
          <TouchableOpacity
            style={[styles.buttonOverlay, { top: 10, left: 10 }]}
            onPress={returnButton}
            activeOpacity={1.0}
          >
            <Image
              source={require('../assets/icon/mainButton_4.png')}
              style={styles.buttonImage}
            />
          </TouchableOpacity>
        </View>
        <Image
          source={require('../assets/icon/mainImage2.png')}
          style={styles.mainImage}
          resizeMode="contain"
        />
        <Image
          source={require('../assets/background/lidaSlogan3.png')}
          style={styles.lidaSloganImage}
          resizeMode="contain"
        />
        <Image
          source={require('../assets/icon/sun.png')}
          style={styles.sunImage}
          resizeMode="contain"
        />
      </View>
    </ScrollView>
  );
}

const styles = StyleSheet.create({
  scrollView: {
    backgroundColor: '#fff',
  },
  container: {
    alignItems: 'center',
    backgroundColor: '#fff',
  },
  image: {
    marginTop: '5%',
    width: '100%',
    height: 120,
    resizeMode: 'contain',
  },
  header: {
    width: '100%',
    flexDirection: 'row',
    justifyContent: 'space-between',
    alignItems: 'center',
    marginTop: -90,
    paddingHorizontal: 40,
  },
  logo: {
    width: 80,
    height: 80,
    marginTop: '-2%',
    //marginLeft: '5%',
    resizeMode: 'contain',
  },
  topButtons: {
    flexDirection: 'row',
  },
  topButton: {
  },
  topButtonImage: {
    width: 40,
    height: 40,
    marginTop: '-30%',
    resizeMode: 'contain',
  },
  profileBoxContainer: {
    position: 'absolute',
    width: 270,
    height: 110,
    top: 85,
    left: -135,
    alignItems: 'center',
    justifyContent: 'center',
  },
  profileButtons: {
    flexDirection: 'row',
    justifyContent: 'space-evenly',
    width: '100%',
  },
  profileButtonImage: {
    width: 70,
    height: 70,
    top: -75,
    resizeMode: 'contain',
  },
  profileBoxImage: {
    width: 270,
    height: 110,
  },
  mainButtonContainer: {
    position: 'relative',
  },
  buttonOverlay: {
    position: 'absolute',
  },
  buttonImage: {
    width: 125, 
    height: 125,
    top: 216,
    left: 19,
    resizeMode: 'contain',
  },
  mainButton: {
    width: 320,
    height: 220,
    marginTop: '60%',
    resizeMode: 'contain',
    alignSelf: 'center',
  },
  mainImage: {
    marginTop: '60%',
    height: 250,
    width: '100%',
    resizeMode: 'contain',
    alignSelf: 'center',
  },
  lidaSloganImage: {
    marginTop: '60%',
    height: 250,
    width: '80%',
    resizeMode: 'contain',
    alignSelf: 'center',
  },
  sunImage: {
    marginTop: '60%',
    height: 250,
    width: '80%',
    resizeMode: 'contain',
    alignSelf: 'center',
  },
});

export default Menu;