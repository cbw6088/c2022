import React, { useState } from 'react';
import { Dimensions, Text, View, Image, TextInput, StyleSheet, TouchableOpacity, Button } from 'react-native';

import AsyncStorage from '@react-native-async-storage/async-storage';

const { width, height } = Dimensions.get('window');

const Info = ({ navigation }) => {

  const Logout = async () => {
    try {
      await AsyncStorage.removeItem('userToken');
      console.log('Token removed successfully.');
      navigation.reset({
        index: 0,
        routes: [{ name: 'Login' }],
      });
    } catch (error) {
      console.error('Error removing token:', error);
    }
  };

  const settingsGroups = [
    {
      title: "이용내역",
      options: [
        {
          title: "관심목록",
          onPress: () => navigation.navigate('WatchList'),
        },
        {
          title: "대여내역",
          onPress: () => navigation.navigate('RentalList'),
        },
      ],
    },
    {
      title: "계정관리",
      options: [
        {
          title: "계정정보",
          onPress: () => navigation.navigate('UserInformation'),
        },
        {
          title: "주소지정",
          onPress: () => navigation.navigate('MyAddress'),
        },
      ],
    },
    {
      title: "이용안내",
      options: [
        {
          title: "버전정보",
          onPress: () => console.log("버전정보 클릭"),
        },
        {
          title: "공지사항",
          onPress: () => navigation.navigate('Announcement'),
        },
        {
          title: "약관 및 정책",
          onPress: () => navigation.navigate('Policies'),
        },
      ],
    },
  ];

  return (
    <View style={styles.view}>
      <View style={styles.content}>
        <View style={styles.infoBox}>
          <View style={styles.leftContainer}>
            <Image
              source={{ uri: 'https://scontent-ssn1-1.cdninstagram.com/v/t51.2885-19/417925521_1055214925719194_8607554024942250217_n.jpg?stp=dst-jpg_s320x320&efg=e30&_nc_ht=scontent-ssn1-1.cdninstagram.com&_nc_cat=102&_nc_ohc=bQjTKj9uOj4AX-PABs8&edm=AOQ1c0wBAAAA&ccb=7-5&oh=00_AfBATrzty5BsPIlB47xqDBAhCDLcO3LX9JycvTVQi2Gv9g&oe=65A24640&_nc_sid=8b3546' }}
              style={styles.image}
            />
            <Text style={styles.name}>닉네임</Text>
          </View>
          <TouchableOpacity
            style={styles.profileButton}
            onPress={() => navigation.navigate('Profile')}
          >
            <Text style={styles.profileText}>프로필 보기</Text>
          </TouchableOpacity>

          </View>
          
          <View style={styles.settingsContainer}>
            {settingsGroups.map((group, groupIndex) => (
              <View key={groupIndex} style={styles.optionGroup}>
                <Text style={styles.groupTitle}>{group.title}</Text>
                <View style={styles.titleBorder}></View>
                {group.options.map((option, index) => (
                  <TouchableOpacity key={index} style={styles.settingsButton} onPress={option.onPress}>
                    <Text style={styles.settingsText}>{option.title}</Text>
                  </TouchableOpacity>
                ))}
              </View>
            ))}
          </View>

      </View>
      <View style={styles.logout}>
        <Button title="로그아웃" onPress={Logout} />
      </View>
    </View>
  );
}

const styles = StyleSheet.create({
  view: {
    flex: 1,
    alignItems: 'left',
    marginLeft: height * 0.02,
    marginRight: height * 0.02,
    marginTop: 60,
  },
  content: {
    flex: 1,
  },
  leftContainer: { // 프로필 이미지와 이름을 위치 지정
    flexDirection: 'row',
    alignItems: 'center',
  },
  infoBox: { // "프로필 보기" 박스
    height: height * 0.1,
    flexDirection: 'row',
    justifyContent: 'space-between',
    alignItems: 'center', 
    width: '100%',
  },
  profileButton: { // 프로필 보기 버튼 모양
    backgroundColor: '#A9A9A9',
    padding: 10,
    borderRadius: 10,
    //marginLeft: 10,
  },
  profileText: { // 프로필 보기 버튼 텍스트
    color: 'white',
    fontSize: 12, 
    fontWeight: 'bold',
  },
  image: {
    width: height * 0.05,
    height: height * 0.05,
    borderRadius: 50,
    resizeMode: 'cover',
    marginRight: height * 0.01
  },
  name: {
    fontSize: 20,
    fontWeight: 'bold'
  },
  logout: { // 로그아웃
    position: 'absolute',
    left: 0,
    right: 0,
    bottom: 0,
    alignItems: 'center',
    paddingBottom: 20,
  },
  optionGroup: {
    marginBottom: 10,
    padding: 10,
    borderWidth: 0.5,
    borderColor: '#ddd',
    borderRadius: 5,
    width: width * 0.9,
  },
  groupTitle: {
    fontSize: 16,
    fontWeight: 'bold',
    marginBottom: 5,
    padding: 5,
    width: '100%',
  },
  settingsButton: { // 상자 안 세부 버튼
    padding: 10,
    borderBottomColor: '#ddd',
    marginBottom: 1, 
  },
  titleBorder: {
    borderBottomWidth: 1,
    borderBottomColor: '#ddd',
    marginBottom: 5,
  },
});

export default Info;
