import React from 'react';
import { Text,View,Image, TextInput, Button,FlatList, StyleSheet, Alert, ScrollView,TouchableOpacity, Dimensions } from 'react-native';
import styleSet from './style/style.js';


/* 개발용 테스트 데이터셋 모듈 */
import { devData, devImage, devContentContainer} from '../testData/homeContent.js';

const { width, height } = Dimensions.get('window');

const Content = ({navigation}) => {
  return (
  <ScrollView contentContainerStyle={styles.page}>
        <View>
          <Text style={[styleSet.Text24Bold,{marginVertical:height*0.01}]}>구경하기</Text>
        </View>
    {/* 배너 FlatList */}
    <View style = {styleSet.box}>
    <FlatList
        data = {devImage}
        renderItem = {({item}) => (
          //#onPress만들기
            <TouchableOpacity style={styles.bannerImageContainer}>
              <Image source={item.image} style={styles.bannerImage}/>
            </TouchableOpacity>
          )}
        horizontal
        pagingEnabled
        showsHorizontalScrollIndicator={false}
        />
      </View>

    {/* 컨텐츠 FlatList 매핑 */}
    { devContentContainer.map((item,index)=>(
        <View style = {styleSet.box} key={index}>
          <Text style={[styleSet.Text18Bold,styles.marginBottom]}>{item.caption}</Text>
          <FlatList
            data={devData}
            navigation={navigation}
            renderItem={({item}) => (
              <TouchableOpacity style={styles.item} onPress={()=>{navigation.navigate('Detail',item)}} activeOpacity={1}>
                <Image source={{uri:item.image}} style={styles.thumbnail}/>
                <View style={styles.infoBox}>
                  <Text style={styles.infoName}>{item.name}</Text>
                  <Text style={styles.infoPastPrice}>{item.pastPrice}</Text>
                  <Text style={styles.infoPrice}>{item.price}</Text>
                </View>
              </TouchableOpacity>)}
            horizontal
            pagingEnabled
            />
        </View>
      ))
    }
  </ScrollView>
  );
}

const styles = StyleSheet.create({
  page:{
    paddingHorizontal:0.05*width,
  },
  marginBottom:{
    marginBottom:height*0.01,
  },
  bannerImageContainer: {    
    width : (width - 0.05 * 2 * width) * 90 / 100,
    height: 0.35*height,  

  },bannerImage: {
    width: '100%',  
    height: '100%', 
    resizeMode: 'cover',
    overflow:'hidden',
  },
   item: {
      width : (width - 0.05 * 2 * width) * 90 / 100 / 3,
      height: 0.19*height,
      borderRadius:4,
      alignItems:'center',
    },
    thumbnail:{//썸네일 이미지
      width:'80%',
      height:0.11*height, 
      borderRadius:15,
    },
    infoBox:{
      height:0.07*height,
    },
    infoName:{
      fontSize:15,
      fontWeight:'bold',
    },infoPastPrice:{
      textDecorationLine: 'line-through',
      color:'grey',
    },
    infoPrice:{
      fontSize:14,
      fontWeight:'bold',
    },
  });

export default Content;