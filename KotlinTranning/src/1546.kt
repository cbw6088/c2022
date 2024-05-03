fun main(){
    var cnt = readln().toInt()
    var arr = readln().split(" ")
    var list = arrayListOf<Int>()
    for(i in arr){
        list.add(i.toInt())
    }
    var M = list.max()
    var result = 0.0
    for(i in list){
        result += (i.toDouble()/M*100)
    }

    print(result/cnt)
}