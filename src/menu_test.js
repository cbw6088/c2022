// import React, { useState } from 'react';
// import { Text, View, Image, ImageBackground, Button,FlatList, StyleSheet, Alert, ScrollView,TouchableOpacity, Dimensions } from 'react-native';
// import styleSet from './style/style.js';

// const { width, height } = Dimensions.get('window');

// const ScrollableImageBox = ({ children, showNoticeBox, toggleNoticeBox }) => {
//   const noticeDetilButton = () => {
//     console.log("Button 1 pressed");
//     toggleNoticeBox(); 
//     console.log("showNoticeBox state after toggle:", showNoticeBox);
//   };
//   return (
//     <ImageBackground
//       source={require('../assets/background/totalMainBox2.png')}
//       style={styles.scrollableBoxBackground}
//     >
//       <ScrollView style={styles.scrollView}>
//         <ImageBackground
//           source={require('../assets/background/noticeLine2.png')}
//           style={styles.noticeLineImage}
//         >
//           <Image
//             source={require('../assets/icon/notice.png')}
//             style={styles.noticeIcon}
//           />
//           <TouchableOpacity onPress={noticeDetilButton} style={{ zIndex: 10, position: 'absolute', top: -25, left: 270 }}>
//             <Image
//               source={showNoticeBox ? require('../assets/icon/arrow2.png') : require('../assets/icon/arrow1.png')}
//               style={styles.noticeLineButton}
//             />
//           </TouchableOpacity>
//         </ImageBackground>
//         <ImageBackground
//           source={require('../assets/background/lidaLine3.png')}
//           style={styles.lidaLineStyle}
//         >
//           <Image
//             source={require('../assets/background/background.png')}
//             style={styles.lidaImageStyle}
//           />
//         </ImageBackground>
//         <Image
//           source={require('../assets/background/introductionLine2.png')}
//           style={styles.introductionLineStyle}
//         />
//         {children}
//       </ScrollView>
//     </ImageBackground>
//   );
// };

// const ProfileBox = ({ isVisible, isLoggedIn }) => {
//   if (!isVisible) return null;

//   return (
//     <View style={styles.profileBox}>
//       <Image
//         source={require('../assets/background/profileBox3.png')}
//         style={styles.profileImage}
//       />
//       {isLoggedIn ? (
//         <Text>로그아웃 상태입니다.</Text>
        
//       ) : (
//         <View style={styles.buttonContainer}>
//           <TouchableOpacity>
//             <Image
//               source={require('../assets/logo/google.png')}
//               style={styles.buttonImage}
//             />
//           </TouchableOpacity>
//           <TouchableOpacity>
//             <Image
//               source={require('../assets/logo/naver.png')}
//               style={styles.buttonImage}
//             />
//           </TouchableOpacity>
//           <TouchableOpacity>
//             <Image
//               source={require('../assets/logo/kakao.png')}
//               style={styles.buttonImage}
//             />
//           </TouchableOpacity>
//         </View>
//       )}
//     </View>
//   );
// };

// const FixedHeader = ( { toggleProfileBox, showProfileBox, isLoggedIn } ) => {
//   const profileButton = () => {
//     console.log("Button 1 pressed");
//     toggleProfileBox();
//   };

//   const settingButton = () => {
//     console.log("Button 2 pressed");
//     // 여기에 버튼 2가 눌렸을 때 실행할 기능을 추가하세요
//   };
//   return (
//       <View style={styles.fixedHeader}>
//         <Image
//           source={require('../assets/background/topBox.png')}
//           style={styles.headerImage}
//         />
//         <View style={styles.headerContent}>
//           <Image
//             source={require('../assets/logo/logo_test.png')}
//             style={styles.lidaLogo}
//           />
//           <View style={styles.headerButtons}>
//             <TouchableOpacity onPress={profileButton}>
//               <Image
//                 source={isLoggedIn ? require('../assets/icon/logoutProfile.png') : require('../assets/icon/loginProfile.png')}
//                 style={styles.profileButton}
//               />
//             </TouchableOpacity>
//             <TouchableOpacity onPress={settingButton}>
//               <Image
//                 source={require('../assets/icon/setting.png')}
//                 style={styles.settignButton}
//               />
//             </TouchableOpacity>
//           </View>
//         </View>
//       </View>
//   );
// };

// const FixedFooter = ( { navigation } ) => {
//   const returnButton = () => {
//     console.log("returnButton Pressed");
//     navigation.navigate('Return');
//   };

//   const rentalButton = () => {
//     console.log("rentalButton Pressed");
//     navigation.navigate('Content');

//   };

//   return (
//     <View style={styles.fixedFooter}>
//       <TouchableOpacity onPress={returnButton}>
//         <Image
//           source={require('../assets/icon/return.png')} 
//           style={styles.footerButton}
//         />
//       </TouchableOpacity>
//       <TouchableOpacity onPress={rentalButton}>
//         <Image
//           source={require('../assets/icon/rental2.png')}
//           style={styles.footerButton}
//         />
//       </TouchableOpacity>
//     </View>
//   );
// };

// const Menu = ({navigation}) => {
//   const [isLoggedIn, setIsLoggedIn] = useState(true); // login 확인 : true / false

//   const [showProfileBox, setShowProfileBox] = useState(false);
//   const toggleProfileBox = () => {
//     setShowProfileBox(!showProfileBox);
//   };

//   const [showNoticeBox, setShowNoticeBox] = useState(false);
//   const toggleNoticeBox = () => {
//     setShowNoticeBox(!showNoticeBox);
//   };

//   return (
//     <>
//       <FixedHeader showProfileBox={showProfileBox} toggleProfileBox={toggleProfileBox} isLoggedIn={isLoggedIn} />
//       <ProfileBox isVisible={showProfileBox} isLoggedIn={isLoggedIn} /> 
//       <View style={styleSet.page}>
//         <ScrollableImageBox showNoticeBox={showNoticeBox} toggleNoticeBox={toggleNoticeBox}/>
//         <FixedFooter navigation={navigation}/> 
//       </View>
//     </>
//   );
// }

// const styles = StyleSheet.create({
//   scrollableBoxBackground: {
//     width: width/1.1,
//     height: height/1.2,
//     position: 'absolute',
//     top: 30,
//     left: 19,
//     resizeMode: 'cover',
//   },
//   scrollView: {
//     flex: 1,
//     width: '100%',
//     //backgroundColor: 'rgba(255, 0, 0, 0.2)',
//   },
//   fixedHeader: {
//     width: '100%', 
//     height: '53%', 
//     position: 'absolute',
//     top: '-20%',
//     left: 0,
//     zIndex: 1,
//     flexDirection: 'row', 
//     justifyContent: 'space-between',
//     alignItems: 'center',
//   },
//   headerImage: {
//     width: width/1.07,
//     height: '25%',
//     marginTop: '2%',
//     marginLeft: '4%',
//     resizeMode: 'cover',
//     backgroundColor: 'transparent',
//     //backgroundColor: 'rgba(255, 0, 0, 0.2)',
//   },
//   headerContent: {
//     resizeMode: 'cover',
//   },
//   lidaLogo: {
//     width: '100%',
//     height: '20%',
//     top: '12%',
//     left: '-400%',
//     resizeMode: 'contain',
//     // backgroundColor: 'rgba(255, 0, 0, 0.2)',
//   },
//   headerButtons: {
//     flexDirection: 'row',
//     left: 10,
//     top: 55,
//     //backgroundColor: 'rgba(255, 0, 0, 0.2)',
//   },
//   profileButton: {
//     width: 40,
//     height: 60,
//     left: '-300%',
//     top: '-120%',
//     resizeMode: 'contain',
//   },
//   settignButton: {
//     width: 45,
//     height: 65,
//     left: '-250%',
//     top: '-125%',
//     resizeMode: 'contain',
    
//   },
//   profileBox: {
//     position: 'absolute',
//     height: 100,
//     zIndex: 1,
//     top: 75,
//     left: -50,
//     right: 10,
//     padding: 10,
//   },
//   profileImage: {
//     width: "120%",
//     height: "180%",
//     resizeMode: 'contain', 
//   },
//   buttonContainer: {
//     flexDirection: 'row',
//     justifyContent: 'space-evenly',
//     alignItems: 'center',
//   },
//   buttonImage: {
//     width: 80,
//     height: '100%',
//     marginHorizontal: -40,
//     top: -100,
//     left: 40,
//     resizeMode: 'contain',
//   },
//   noticeLineImage: {
//     width: '93%',
//     height: 45,
//     top: '23%',
//     left: '53%',
//     flexDirection: 'row',
//     justifyContent: 'space-between',
//     alignItems: 'center',
//   },
//   noticeIcon: {
//     width: 35, 
//     height: 35,
//     top: '4%',
//     left: '8%',
//     resizeMode: 'contain',
//   },
//   noticeLineButton: {
//     width: 60,
//     height: 25,
//     top: '200%',
//     left: '-40%',
//     resizeMode: 'contain',
//   },
//   lidaLineStyle: {
//     width: '93%',
//     height: '100%',
//     top: 95,
//     left: 25,
//   },
//   lidaImageStyle: {
//     width: '92%',
//     height: '500%',
//     top: 20,
//     left: 1,
//   },  
//   introductionLineStyle: {
//     width: '85%',
//     height: '260%',
//     top: 290,
//     left: 27,
//     //backgroundColor: 'rgba(255, 0, 0, 0.2)',
//   },
//   fixedFooter: {
//     position: 'absolute',
//     bottom: -115,
//     left: 13,
//     width: '100%',
//     height: 200,
//     flexDirection: 'row',
//     justifyContent: 'space-between',
//     paddingHorizontal: 25,
//   },
//   footerButton: {
//     width: 80,
//     height: 60,
//   },
// });

// export default Menu;