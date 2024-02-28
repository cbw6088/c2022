import React, {useState,useEffect} from 'react';
import { Text,View,Image, TextInput, Button, StyleSheet, Alert, ScrollView,TouchableOpacity, Dimensions } from 'react-native';
import { Calendar } from 'react-native-calendars';
import styleSet, { BottomNav } from './style/style';
import { todayString } from 'react-native-calendars/src/expandableCalendar/commons';
const { width, height } = Dimensions.get('window');


function 세줄점(숫자) {
    let 숫자문자열 = 숫자.toString();
    let 숫자배열 = 숫자문자열.split('');

    for (let i = 숫자배열.length - 3; i > 0; i -= 3) {
        숫자배열.splice(i, 0, ',');
    }
    let 결과 = 숫자배열.join('');
    return 결과;
}


const Detail = ({navigation,route}) => {
    const {num,name,price,image} = route.params;
    //route.params = 이전 경로에서 받아온 데이터

    const extractedPrice = parseInt(price.replace(/[^0-9]/g, ''), 10);

    const [isOption, setIsOption] = useState(false);

    const loadOption = () => {
        setIsOption(!isOption );
    }

    const [selectedStartDate, setSelectedStartDate] = useState(null);
    const [selectedEndDate, setSelectedEndDate] = useState(null);
    const [기간, set기간] = useState(null);

    const 결제정보 = 
        {
            leftBtn : 기간 !== 0 ? 세줄점(기간 * extractedPrice) + '원' : '대여기간을 입력해주세요',
            leftSub : 기간 + '일',
            rightBtn : '결제',
            대여시작 : selectedStartDate,
            대여종료 : selectedEndDate,
        };

        /* 여기 가격 맘대로 가는 버그 화면에 출력 안되게 하는 방법 */
    useEffect(() => {
        const data = (new Date(selectedEndDate).getDate() - new Date(selectedStartDate).getDate());
        if (data>0){
        set기간(data);}
        else{
            set기간(0);
        }
      }, [selectedEndDate]);

    const handleDayPress = (day) => {
        if (!selectedStartDate) {
          setSelectedStartDate(day.dateString);
        }else if(selectedStartDate && selectedEndDate){
            setSelectedStartDate(day.dateString);
            setSelectedEndDate(null);
        }
        else{
            if (day.dateString < selectedStartDate){
                setSelectedEndDate(selectedStartDate);
                setSelectedStartDate(day.dateString);
            }   
            else{
                setSelectedEndDate(day.dateString);
            }
        }
    }
      const markedDates = {};
      if (selectedStartDate) {
        markedDates[selectedStartDate] = { selected: true, startingDay: true, color: 'skyblue' };
      }
      if (selectedEndDate) {
        let colorDate = selectedStartDate;

        while (colorDate <= selectedEndDate) {
            markedDates[colorDate] = { selected: true, marked: true, selectedColor: 'skyblue' };
            colorDate = new Date(colorDate);
            colorDate.setDate(colorDate.getDate() + 1);
            colorDate = colorDate.toISOString().split('T')[0];
          }        
      }

                            
    return (
    <View style={styleSet.page}>
        <ScrollView  contentContainerStyle={{ paddingBottom: height*0.1 }}>
            <View style={styleSet.box}>
                <Image source={{uri:image}} style={styles.image}/>
            </View>
            <View style={styleSet.box}>
                <View>
                    <Text style={[styleSet.Text15Bold, {marginBottom:10}]}>{name}</Text>
                    <Text style={styles.infoPrice}>{price}</Text>
                    {isOption && 
                    <View>
                        <Text>옵션</Text>
                        <Text>detail</Text>
                        <Text>설정</Text>
                    </View>}
                </View>
                <TouchableOpacity onPress={loadOption}>
                    <Text>버튼</Text>
                </TouchableOpacity>
                
            </View>
            <View style={[styleSet.box]}>
                <View style={[styleSet.rowAndBetween]}>
                    <Text style={styleSet.Text20Bold}>대여기간</Text>
                    <Image source={require('../assets/icon/date2.png')} style={styleSet.iconLarge} />
                </View>
                <View>
                    <Calendar
                        onDayPress={handleDayPress}
                        markedDates={markedDates}
                        minDate={new Date()}
                        />
                </View>
            </View>
        </ScrollView>
        <BottomNav info = {결제정보} 
        req = {()=>{
            if (기간 !== 0)
            navigation.navigate('Payment',결제정보)
            else{
                Alert.alert('대여 기간을 설정해주세요!');
            }            
            }}/>
    </View>
    );
}


const styles = StyleSheet.create({
    image:{
        width:'100%',
        height:height*0.3,
    },
    infoName:{
        marginBottom:15,
    },infoPrice:{
        fontSize:15,
    },
    selectBox:{
        width:width,
        height:100,
        flexDirection : 'row',
        justifyContent:'center',
    },
});

export default Detail;