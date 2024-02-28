import React from 'react';
import {Text,View, StyleSheet,TouchableOpacity, Dimensions } from 'react-native';

const { width, height } = Dimensions.get('window');

export const BottomNav = ({info,req}) => {
  return (
    <View style={styleSet.downArea}>
      <View style={styleSet.downLeftInfo}>
        <Text style={styleSet.Text15Bold}>{info.leftBtn}</Text>
        <Text>{info.leftSub}</Text>    
      </View>
    <TouchableOpacity style={styleSet.downRightButton}
      onPress={req}>
      <Text style={styleSet.Text20Bold}>{info.rightBtn}</Text>
    </TouchableOpacity>
    </View>
  );
}


export const styleSet = StyleSheet.create({
    page:{ /* 전체 페이지 기본값 */
        padding:0.03*width,
        flex:1,
    },

    box:{ /* 박스 기본값 */
        width: '100%',
        backgroundColor:'white',
        borderRadius:20,
        marginTop:0.015*height,
        padding:'5%',
        borderWidth:0.2,
        borderColor:'grey',
    },
    
    inBox:{ /* 내부박스 기본값 */
      width: '100%',
      padding:'5%',
      borderColor:'grey',
      borderWidth:0.3,
      borderRadius:20,
      marginTop:0.015*height,
    },

    rowAndBetween:{ /* 가로정렬, spaceBetween */
        flexDirection:'row',
        justifyContent: 'space-between',
    },

    
    downArea:{ /* 하단 고정 영역 */
        width:width,
        height:height*0.07,
        flexDirection:'row',
        position: 'absolute',
        backgroundColor:'white',
        bottom:0,

      },

      downLeftInfo:{ /* 하단 고정 영역 왼쪽  */
        width:'50%',
        alignItems:'center',
        justifyContent:'center',
        height:'100%',
        height:height*0.07,
        
      },
      downRightButton:{ /* 하단 고정 오른쪽 버튼 */
        borderLeftWidth:0.2,
        width:'50%',
        height:height*0.07,
        alignItems:'center',
        justifyContent:'center',
      },

      /* 텍스트 & bold */
      Text15Bold:{ 
        fontSize:15,
        fontWeight:'bold',
      },Text18Bold:{
        fontSize:18,
        fontWeight:'bold',
      },
      Text20Bold:{
          fontSize:20,
          fontWeight:'bold',
      },Text24Bold:{
        fontSize:24,
        fontWeight:'bold',
    },

     /* 지도 API */
    mapBox:{
      height:height*0.3,
      marginTop:height*0.015,
    },

    /* 아이콘 영역 */
    iconArea:{
      width:width*0.08, height:width*0.08,
      justifyContent: 'center',
      alignItems: 'center',
    },
    iconSmall:{
      width:width*0.04,height:width*0.04,
      resizeMode:"contain",
    },
    icon:{
      width:width*0.05,height:width*0.05,
      resizeMode:"contain",
    },
    iconLarge:{
      width:width*0.07,
      height:width*0.07,
      resizeMode:'contain', 
    },

  WH100:{
    width:'100%',height:'100%',
  }

});

export default styleSet;