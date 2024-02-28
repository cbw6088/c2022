
import {useState, useEffect} from 'react';
import { Text, View, Image, TextInput, Button,FlatList, StyleSheet, Alert, ScrollView,TouchableOpacity, Dimensions } from 'react-native';
import Maps from './Maps.js';
import styleSet, {BottomNav} from './style/style.js';
import Loading from './loading.js';


const { width, height } = Dimensions.get('window');

const devProduct = {
  name:'애플워치5',
  대여기간 : '24.02.19 ~ 24.02.22',
  randTime:'15:00',
  returnTime:'16:00',   
}

const Return = () => {
  
  const [product, setProduct] = useState(null); //devtestData
  const [isProduct, setIsProduct] = useState(false);
  const [isMap, setIsMap] = useState(false);
  const [isArrowClicked, setIsArrowClicked] = useState(false);

  const loadProduct = () => {
    setProduct(devProduct);
    setIsProduct(!isProduct);
  }
  const loadMap = () => {
    setIsMap(!isMap);
  }
  const handleArrowClick = () => {
    setIsArrowClicked(!isArrowClicked);
    loadProduct();
  }


  const [isLoading, setIsLoading] = useState(true); 

  useEffect(() => {
    setTimeout(() => {
      setIsLoading(false); // 3초 후 로딩 상태를 false로 변경
    }, 3000);
  }, []);

  if (isLoading) {
    return <Loading />; // 로딩 중이면 로딩 화면 렌더링
  }
  
    return (
      <View style={styleSet.page}>
        <View>
          <Text style={[styleSet.Text24Bold,{marginVertical:height*0.01}]}>반납하기</Text>
        </View>
        <View style = {styleSet.box}>
          <View style={styleSet.rowAndBetween}>
            <Text style={styleSet.Text20Bold}>돌려줄 물건</Text>
            <TouchableOpacity onPress={handleArrowClick} style={styleSet.iconArea}>
              <Image 
                source={isArrowClicked ? require('../assets/icon/arrow2.png') : require('../assets/icon/arrow1.png')} 
                style={styleSet.icon} 
              />
            </TouchableOpacity>
          </View>

        {isProduct && (
        <View style={styleSet.inBox}>
          <Text>{product.name}</Text>
          <Text>{product.대여기간}</Text>
        </View>
        )}
        </View>
        <View style = {styleSet.box}>        
          <View style = {styleSet.rowAndBetween}>
            <Text style={styleSet.Text20Bold}>돌려줄 곳</Text>
            <TouchableOpacity style={styleSet.iconArea} onPress = {loadMap}>
              <Image source = {require('../assets/icon/map.png')} style={[styleSet.iconSmall,styleSet.WH100]}/>
            </TouchableOpacity>
          </View>
          {isMap && (
            <View style={styleSet.mapBox}>
              <Maps/> 
            </View>
          )}
        </View>    
        <BottomNav info = {{
          leftBtn : '반납해야할 물건',
          leftSub : '00시 00분까지',
          rightBtn: '돌려주기',
          }} req = {reqReturn}/>
      </View>
    );
  }

  const reqReturn = (item) => {
    // # 반납 요청 : 정보 정리 및 확인/취소 -> DB에 확정, 로그 남기기
    
    return(
      Alert.alert(
        '알림',
        `@@일 @@시 @@분에 '@@@'을 돌려주실 건가요?`,
        [
          {
            text: '취소',
            style: 'cancel',
          },
          {
            text: '확인',
            onPress: () => {
              // 확인 버튼이 눌렸을 때 실행할 동작을 추가할 수 있습니다.
              console.log('확인 버튼이 눌렸습니다.');
            },
          },
        ],
        { cancelable: false }
      )

    );
  }
  
const styles = StyleSheet.create({

  });

  export default Return;